#pragma once
#include <Windows.h>
int MyWindows(HINSTANCE hInstance);
void DestroyWindows();
bool GetCheckBoxState(HWND checkbox);
extern HWND Code1;
extern HWND LuaMode;
extern HWND InstantMode;