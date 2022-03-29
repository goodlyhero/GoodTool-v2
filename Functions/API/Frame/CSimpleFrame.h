#pragma once
#include <BasicConstants.h>
DWORD CreateCSimpleFrame(DWORD pParent);
DWORD CreateCSimpleConsole(const char* baseCSimpleConsole, DWORD parent, int id);
DWORD GetCSimpleFrameByName(const char* name, int id);
DWORD SetCSimpleFrameScale(DWORD pCSimpleFrame, float scale);
int SetCSimpleFramePriority(int pCSimpleFrame, int priority);
DWORD SetCSimpleFrameParent(DWORD pCSimpleFrame, int pParentCSimpleFrame);