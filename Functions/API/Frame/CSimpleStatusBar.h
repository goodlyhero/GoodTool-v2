#pragma once
#include <BasicConstants.h>

int SetCSimpleStatusBarTexture(DWORD pFrame, const char* texturepath, bool flag);

int SetCSimpleStatusBarValue(DWORD pFrame, float value);

int SetCSimpleStatusBarMinMaxValue(DWORD pFrame, float minval, float maxval);