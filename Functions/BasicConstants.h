#pragma once
#include <Windows.h>
extern HWND  hwndwc;
extern DWORD dwGameDll;
extern DWORD pGameDLL;
extern DWORD dwStormDll;
extern DWORD pEventEngine;
extern HINSTANCE GoodToolDll;
typedef unsigned int(pString);
typedef int (integer);
typedef unsigned int (jSTRING);
typedef unsigned int (jHANDLE);
typedef unsigned int (jCODE);
typedef int(*Func_iChar) (char* string);
void InitBasicConstants();
void InitBasicConstants();
DWORD RefindGameWindow();