#include <BasicConstants.h>
#include <Windows.h>
#include <iostream>
#include <Functions.h>
#include <Logs/Log.h>
#include <Warcraft Functions.h>
#include <Extern Natives.h>
#include <From MemHack.h>
#include <Additional Native Constants.h>
#include <Mem_restorer.h>
#include <States.h>
//export module WarcraftFunctions;
void SetTls()
{
	DWORD Data = *(DWORD *)(dwGameDll + 0xACEB4C);
	DWORD TlsIndex = *(DWORD *)(dwGameDll + 0xAB7BF4);

	if (TlsIndex)
	{
		DWORD v5 = **(DWORD **)(*(DWORD *)(*(DWORD *)(dwGameDll + 0xACEB5C) + 4 * Data) + 44);
		TlsSetValue(TlsIndex, *(LPVOID *)(v5 + 520));
	}
}

void TextPrint(const char *szText, float fDuration)
{
	DWORD dwDuration = *((DWORD*)&fDuration);
	LogS() << "[message]: " << szText << std::endl;
	if (IsInGame())
	{
		__asm
		{
			PUSH	0xFFFFFFFF
			PUSH	dwDuration
			PUSH	szText
			PUSH	0x0
			PUSH	0x0
			MOV		ECX, [GAME_GlobalClass]
			MOV		ECX, [ECX]
			CALL	GAME_PrintToScreen
		}
	}
}

void TextPrintNoLog(char* szText, float fDuration)
{
	if (IsInGame())
	{
		DWORD dwDuration = *((DWORD*)&fDuration);
		__asm
		{
			PUSH	0xFFFFFFFF
			PUSH	dwDuration
			PUSH	szText
			PUSH	0x0
			PUSH	0x0
			MOV		ECX, [GAME_GlobalClass]
			MOV		ECX, [ECX]
			CALL	GAME_PrintToScreen
		}
	}
}

void TextPrintEx(char *szText, ...)
{
	char szTextEx[8192] = {NULL};

	va_list Args;
	va_start(Args, szText);
	vsprintf_s(szTextEx, szText, Args);
	va_end(Args);

	TextPrint(szTextEx);
	LogS() << "[message]: " << szTextEx << std::endl;
}

void cTextPrint(int count, ...)
{
	va_list tlist;
	if (count > 0)
	{
		va_start(tlist, count);
		char* buffer = copystr(va_arg(tlist, char*));
		char* temp;
		for (int i = 1; i < count; i++)
		{
			temp = va_arg(tlist, char*);
			char* t = newstr(buffer, temp);
			delete[] buffer;
			buffer = t;
		}
		TextPrint(buffer);
		LogS() << "[message]: " << buffer << std::endl;
	}
	return;
}

DWORD WarcraftVersion()
{
	DWORD dwHandle = NULL;
	DWORD dwLen    = GetFileVersionInfoSize("Game.dll", &dwHandle);

	LPVOID lpData = new char[dwLen];
	GetFileVersionInfo("Game.dll", dwHandle, dwLen, lpData);

	LPBYTE lpBuffer = NULL;
	UINT   uLen     = NULL;
	VerQueryValue(lpData, "\\", (LPVOID *)&lpBuffer, &uLen);

	VS_FIXEDFILEINFO *Version = (VS_FIXEDFILEINFO *)lpBuffer;

	return LOWORD(Version->dwFileVersionLS);
}

float GetMouseWorldX()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x310);
}

float GetMouseWorldY()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x314);
}

float GetMouseWorldZ()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x318);
}

int GetNativesCnt()
{
	return ReadRealMemory(pnativescnt);
}

int getfunccnt()
{
	DWORD jVM = GetJassVM(1);
	DWORD pfunclist = jVM + 10376;
	DWORD funcnt = ReadRealMemory(pfunclist);
	return ((DWORD*)funcnt)[1];
}

DWORD RegisterFunction(DWORD* func)
{
	return jRegisterFunction((DWORD)GetJassVM(1), (DWORD)func);
}

DWORD DRegisterFunction(DWORD func)
{
	return jRegisterFunction((DWORD)GetJassVM(1), (DWORD)func);
}

DWORD* CreateJassNcallFunction1arg(int n,DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x01\x04\x00\x0C");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x01\x00\x00\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x00\x00\x00\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x00\x00\x00\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}

DWORD* CreateJassFcallFunction1arg(int n,DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x16");//�������� ��������� ���������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}

/*
DWORD* CreateJassAction(int n, DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}*/

DWORD* CreatePureFunc()
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[1] = 0;
	return buffer;
}

/*
DWORD* CreateJassCondition(int n, DWORD func)
{
	DWORD* buffer = new DWORD[10];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;

	return buffer;
}*/
/*
void pTMPselectUnit(int unit, bool flag)
{
	DisplayTextToPlayer(GetLocalPlayer(), 0, 0, I2S(flag));
	jSelectUnit(unit,flag);
}*/

void UnlockChat()
{
	PatchSecure(dwGameDll + 0x2FDEC0, "\xEB\x1B", 2);
	PatchSecure(dwGameDll + 0x2FDB59, "\xEB\x08", 2);
}

