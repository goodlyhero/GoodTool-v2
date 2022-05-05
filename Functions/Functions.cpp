#include <Windows.h>
#include <Extern Natives.h>
#include <iostream>
#include <Warcraft Functions.h>
#include <iomanip>
#include <sstream>
#include "Functions.h"

void HideDll(HMODULE hModule)
{
	DWORD dwPEB_LDR_DATA = NULL;

	_asm
	{
		pushad;
		pushfd;
		mov eax, fs:[30h]
		mov eax, [eax+0Ch]
		mov dwPEB_LDR_DATA, eax

		//InLoadOrderModuleList:
			mov esi, [eax+0Ch]
			mov edx, [eax+10h]

		LoopInLoadOrderModuleList:
			lodsd
			mov esi, eax
			mov ecx, [eax+18h]
			cmp ecx, hModule
			jne SkipA
			mov ebx, [eax]
			mov ecx, [eax+4]
			mov [ecx], ebx
			mov [ebx+4], ecx
			jmp InMemoryOrderModuleList

		SkipA:
			cmp edx, esi
			jne LoopInLoadOrderModuleList

		InMemoryOrderModuleList:
			mov eax, dwPEB_LDR_DATA
			mov esi, [eax+14h]
			mov edx, [eax+18h]

		LoopInMemoryOrderModuleList:
			lodsd
			mov esi, eax
			mov ecx, [eax+10h]
			cmp ecx, hModule
			jne SkipB
			mov ebx, [eax]
			mov ecx, [eax+4]
			mov [ecx], ebx
			mov [ebx+4], ecx
			jmp InInitializationOrderModuleList

		SkipB:
			cmp edx, esi
			jne LoopInMemoryOrderModuleList

		InInitializationOrderModuleList:
			mov eax, dwPEB_LDR_DATA
			mov esi, [eax+1Ch]
			mov edx, [eax+20h]

		LoopInInitializationOrderModuleList:
			lodsd
			mov esi, eax
			mov ecx, [eax+08h]
			cmp ecx, hModule
			jne SkipC
			mov ebx, [eax]
			mov ecx, [eax+4]
			mov [ecx], ebx
			mov [ebx+4], ecx
			jmp Finished

		SkipC:
			cmp edx, esi
			jne LoopInInitializationOrderModuleList

		Finished:
			popfd;
			popad;
	}
}

void Patch(DWORD dwBaseAddress, const char *szData, size_t iSize)
{
	DWORD dwOldProtection = NULL;
	
	VirtualProtect((LPVOID)dwBaseAddress, iSize, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	CopyMemory((LPVOID)dwBaseAddress, szData, iSize);
	VirtualProtect((LPVOID)dwBaseAddress, iSize, dwOldProtection, NULL);
}

void WriteInt(DWORD dest, int what)
{
	DWORD dwOldProtection = NULL;
	VirtualProtect((LPVOID)dest, 4, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	*(int*)dest = what;
	VirtualProtect((LPVOID)dest, 4, dwOldProtection, NULL);
	return;
}

void WriteDWORD(DWORD dest, DWORD what)
{
	DWORD dwOldProtection = NULL;
	VirtualProtect((LPVOID)dest, 4, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	*(DWORD*)dest = what;
	VirtualProtect((LPVOID)dest, 4, dwOldProtection, NULL);
	return;
}

void PlantDetourCall(BYTE *bSource, BYTE *bDestination, int iLength)
{
	DWORD dwOldProtection = NULL;

	BYTE *bJump = (BYTE *)malloc(iLength + 5);

	VirtualProtect(bSource, iLength, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	memcpy(bJump + 3, bSource, iLength);

	bJump[0] = 0x58;
	bJump[1] = 0x59;
	bJump[2] = 0x50;
	bJump[iLength + 3] = 0xE9;
	*(DWORD *)(bJump + iLength + 4) = (DWORD)((bSource + iLength) - (bJump + iLength + 3)) - 5;

	bSource[0] = 0xE8;
	*(DWORD *)(bSource + 1) = (DWORD)(bDestination - (bSource)) - 5;

	for (int i = 5; i < iLength; i++)
		bSource[i] = 0x90;

	VirtualProtect(bSource, iLength, dwOldProtection, NULL);
}

void WriteJmp(DWORD dest, DWORD to)
{
	Patch(dest, "\xE9", 1);
	WriteDWORD(dest + 1, to - dest - 5);
	return;
}

void WriteCall(DWORD dest, DWORD to)
{
	Patch(dest, "\xE8", 1);
	WriteDWORD(dest + 1, to - dest - 5);
	return;
}

void PlantDetourJump(BYTE *bSource, BYTE *bDestination, int iLength)
{
	DWORD dwOldProtection = NULL;

	BYTE *bJump = (BYTE *)malloc(iLength + 5);

	VirtualProtect(bSource, iLength, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	memcpy(bJump, bSource, iLength);

	bJump[iLength] = 0xE9;
	*(DWORD *)(bJump + iLength) = (DWORD)((bSource + iLength) - (bJump + iLength)) - 5;

	bSource[0] = 0xE9;
	*(DWORD *)(bSource + 1) = (DWORD)(bDestination - bSource) - 5;

	for (int i = 5; i < iLength; i++)
		bSource[i] = 0x90;

	VirtualProtect(bSource, iLength, dwOldProtection, NULL);
}

BOOL PlantDetourJMP(BYTE* source, const BYTE* destination, size_t length)
{

	DWORD oldProtection;
	BOOL bRet = VirtualProtect(source, length, PAGE_EXECUTE_READWRITE, &oldProtection);

	if (bRet == FALSE)
		return FALSE;

	source[0] = 0xE9;
	*(DWORD*)(source + 1) = (DWORD)(destination - source) - 5;

	for (unsigned int i = 5; i < length; i++)
		source[i] = 0x90;

	VirtualProtect(source, length, oldProtection, &oldProtection);
	FlushInstructionCache(GetCurrentProcess(), source, length);
	return TRUE;
}

std::string i642s(unsigned long i)
{
	char buffer[50];
	int a = *(int*)&i;
	itoa(a, buffer, 16);
	std::string s = buffer;
	a = *(int*)((&i)+1);
	itoa(a, buffer, 16);
	s += buffer;
	return s;
}

bool FileExists(const char *szFile)
{
  FILE *pFile;
  fopen_s(&pFile, szFile, "r");

  if (pFile != NULL)
  {
	  fclose(pFile);
	  return true;
  }

  return false;
}

char* sstrcat(const char* a,const char * b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	char* result = new char[len1 + len2+1];
	result[0] = 0;
	strcat(result, a);
	strcat(result, b);
	return result;
}

void cTextPrintEx(int n,...)
{
	va_list params;
	va_start(params, n);
	char* result = new char[1];
	result[0] = 0;
	char* tempstr;
	char* tc;
	float duration = 5.0f;
	for (int i = 0; i < n; i++)
	{
		tempstr = va_arg(params, char*);
		TextPrint(tempstr);
		tc = result;
		result = sstrcat(result, tempstr);
		delete[] tc;
		break;
	}
	if (result[0] != 0)
	{
		TextPrint(result, duration);
	}
	delete[] result;
	va_end(params);
}


int GetPlayerSelection(const int player)
{
	int g = jCreateGroup();
	jGroupEnumUnitsSelected(g, player, NULL);
	//char buffer[20];
	//TextPrint(itoa(g,buffer,10));
	return g;
}

void ApplyGroupForSelection(const int SelectionGroup)
{
	jClearSelection();
	int newGroup = jCreateGroup();
	//char buffer[20];
	//TextPrint(itoa(SelectionGroup,buffer,10));
	int first = jFirstOfGroup(SelectionGroup);
	while (first != NULL)
	{
		jSelectUnit(first, true);
		jGroupRemoveUnit(SelectionGroup, first);
		jGroupAddUnit(newGroup, first);
		first = jFirstOfGroup(SelectionGroup);
	}
	first = jFirstOfGroup(newGroup);
	while (first != NULL)
	{
		jGroupRemoveUnit(newGroup, first);
		jGroupAddUnit(SelectionGroup, first);
		first = jFirstOfGroup(newGroup);
	}
	jDestroyGroup(newGroup);
	return;
}

bool IsUnitHero(int unit)
{
	return jIsUnitType(unit, jConvertUnitType(6));
}

void ReviveFirstHeroOfPlayer(int player)
{
	int g = jCreateGroup();
	jGroupEnumUnitsOfPlayer(g, player, NULL);
	int first = jFirstOfGroup(g);
	jGroupRemoveUnit(g,first);
	while ((first != NULL) && (!IsUnitHero(first)))
	{
		first = jFirstOfGroup(g);
		jGroupRemoveUnit(g,first);
	}
	if (first != NULL)
	{
		float x = jGetUnitX(first);
		float y = jGetUnitY(first);
		jReviveHero(first,&x, &y,false);
	}
	jDestroyGroup(g);
}

int GetIntFromString(char* enterefString)
{
	int value = 0;
	char* temp = enterefString;
	while ((*temp != 0) && (*temp != ' '))
	{
		temp++;
	}
	if (*temp == 0)
	{
		throw 16;
	}
	else
	{
		temp++;
		int len = 0;
		char* ttemp = temp;
		while ((*ttemp >= '0') && (*ttemp <= '9'))
		{
			len++;
			ttemp++;
		}
		if (len == 0)
		{
			throw 16;
		}
		else
		{
			char* buffer = new char[len + 1];
			for (int i = 0; i < len; i++)
			{
				buffer[i] = *(temp + i);
			}
			buffer[len] = 0;
			value = atoi(buffer);
			delete[] buffer;
		}
	}
	return value;
}

char* newstr(const char* a, const char* b)
{
	const char* t1 = a;
	const char* t2 = b;
	int len1 = 0;
	int len2 = 0;
	char* buffer;
	while (*t1 != 0)
	{
		len1++;
		t1++;
	}
	while (*t2 != 0)
	{
		len2++;
		t2++;
	}
	buffer = new char[len1 + len2 + 1];
	for (int i = 0; i < len1; i++)
	{
		buffer[i] = *a;
		a++;
	}
	for (int i = 0; i < len2; i++)
	{
		buffer[i + len1] = *b;
		b++;
	}
	buffer[len1 + len2] = 0;
	return buffer;
}

char* copystr(const char* what)
{
	char* n = (char*)what;
	int len = 0;
	while (*n != 0)
	{
		n++;
		len++;
	}
	n = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		n[i] = what[i];
	}
	n[len] = 0;
	return n;
}

void TextToClipboard(const char* text)
{
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		char* hBuff = (char*)GlobalAlloc(GMEM_FIXED, strlen(text) + 1);
		if (hBuff != NULL)
		{
			strcpy(hBuff, text);
			SetClipboardData(CF_TEXT, hBuff);
			CloseClipboard();
		}

	}
}

std::string IntToHex(DWORD i)
{
	std::stringstream stream;
	stream << "0x" << std::hex << i;
	return stream.str();
}

void ptoclip(DWORD i)
{
	TextToClipboard(IntToHex(i).c_str());
}

std::string Int2Id(int i)
{
	char buffer[5];
	buffer[4] = 0;
	buffer[3] = i % 256;i /= 256;
	buffer[2] = i % 256;i /= 256;
	buffer[1] = i % 256;i /= 256;
	buffer[0] = i % 256;i /= 256;
	std::string s(buffer);
	return s;
}

int Id2Int(const char* id)
{
	int tmp = 0;
	for (int i = 0; i < 4;i++)
	{
		if (id[i] == 0) return 0;
		tmp = tmp * 256 + id[i];
	}
	return tmp;
}

DWORD GetProc(DWORD handle,DWORD ord)
{
	return (DWORD)GetProcAddress((HMODULE)handle, (const char*)ord);
}


void WriteFloat(int addr, float value)
{
	//*(DWORD*)addr = *(DWORD*)&value;
	WriteRealMemory(addr, *(DWORD*)&value);
}


float ReadFloat(DWORD address)
{
	DWORD a = ReadRealMemory(address);
	return *(float*)&a;
}

DWORD SetRealIntoMemory(float a)
{
	float* b = &a;
	return *(DWORD*)b;
}