#pragma once
#include <BasicConstants.h>

DWORD SetCEditBoxFocus(DWORD pFrame, bool flag);
DWORD SetCEditBoxFont(DWORD pFrame, const char* filename, float height, int flag);
const char* GetCEditBoxText(DWORD pFrame);
DWORD SetCEditBoxText(DWORD pFrame, const char* text);