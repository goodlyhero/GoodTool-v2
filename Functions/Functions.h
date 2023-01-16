#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
void HideDll(HMODULE hModule);

void Patch(DWORD dwBaseAddress, const char *szData, size_t iSize);
void WriteInt(DWORD dest, int what);
void WriteDWORD(DWORD dest, DWORD what);
void WriteJmp(DWORD dest, DWORD to);
void WriteCall(DWORD dest, DWORD to);

void PlantDetourCall(BYTE *bSource, BYTE *bDestination, int iLength);
void PlantDetourJump(BYTE *bSource, BYTE *bDestination, int iLength);

bool FileExists(const char *szFile);
void cTextPrintEx(int n, ...);
int GetPlayerSelection(int player);
void ApplyGroupForSelection(int SelectionGroup);
int GetIntFromString(const char* enterefString);
char* newstr(const char* a, const char* b);
char* copystr(const char* what);
void TextToClipboard(const char* text);
std::string Int2Id(int i);
std::string IntToHex(DWORD i);
void ptoclip(DWORD i);
int Id2Int(const char* id);
char* sstrcat(const char* a, const char* b);

inline void WriteRealMemory(DWORD addr, DWORD value)
{
	if (addr < 500) return;
	*(DWORD*)addr = value;
	//Patch(addr, (char*)value, 4);
}

inline DWORD ReadRealMemory(DWORD address)
{
	return *(int*)(address);
}

void WriteFloat(int addr, float value);

float ReadFloat(DWORD address);

inline int CreateInteger(char a, char b, char c, char d)
{
	return a + b * 0x100 + c * 0x10000 + d * 0x1000000;
}

inline int CreateInteger1(char a, char b, char c, char d)
{
	return a + b * 0x100 + c * 0x10000 + d * 0x1000000;
}

inline int GetByteFromInteger(int a, int byteid)
{
	switch (byteid)
	{
	case 1:
		return a & 0xff;
	case 2:
		return a & 0xff00;
	case 3:
		return a & 0xff0000;
	case 4:
		return a & 0xff000000;
	}
	return 0;
}

inline bool IsFlagBitSet(DWORD flag,DWORD what)
{
	return ((flag & what) > 0);
}

DWORD SetRealIntoMemory(float a);

inline DWORD BitwiseAnd(DWORD a, DWORD b)
{
	return a & b;
}

inline float GetRealFromMemory(DWORD f)
{
	return *(float*)&f;
}
std::string i642s(unsigned long i);
DWORD GetProc(DWORD handle, DWORD ord);
BOOL PlantDetourJMP(BYTE* source, const BYTE* destination, size_t length);
bool ZipFile(const char* source, const char* target);