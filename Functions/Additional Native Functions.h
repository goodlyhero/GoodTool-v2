#pragma once
#include <Windows.h>
#include <BasicConstants.h>
void InitNativeFunctions();
typedef int (__thiscall* TYPE_ChatCheckForSpecial) (DWORD*, char* msg);
extern TYPE_ChatCheckForSpecial ChatCheckForSpecial;
void InitNativeFunctions();