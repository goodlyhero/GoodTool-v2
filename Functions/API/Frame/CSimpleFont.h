#pragma once
#include <BasicConstants.h>

DWORD CreateCSimpleFont(DWORD pParent);
DWORD GetCSimpleFontByName(const char* name, int id);
const char* GetCSimpleFontTextByName(const char* name, int id);
DWORD SetCSimpleFontStringScale(DWORD pFrame, float scale);
DWORD SetCSimpleFontStringFont(DWORD pFrame, const char* filename, float height, int flag);
float GetCSimpleFontStringHeight(DWORD pFrame);
int SetCSimpleFontText(DWORD pFrame, const char* text);