#pragma once
#include <Windows.h>
#include <BasicConstants.h>
void SetTls();

void TextPrint(const char *szText, float fDuration = 5.0f);
void TextPrintNoLog(char* szText, float fDuration = 5.0f);
void TextPrintEx(char *szText, ...);
void cTextPrint(int count, ...);

float GetMouseWorldX();
float GetMouseWorldY();
float GetMouseWorldZ();

DWORD WarcraftVersion();
int GetNativesCnt();
DWORD RegisterFunction(DWORD* func);
DWORD* CreateJassNcallFunction1arg(int n, DWORD func);
//void pTMPselectUnit(int unit, bool flag);
DWORD* CreatePureFunc();
DWORD* CreateJassFcallFunction1arg(int n, DWORD func);
DWORD DRegisterFunction(DWORD func);
void UnlockChat();
int FirstLocalSelected();