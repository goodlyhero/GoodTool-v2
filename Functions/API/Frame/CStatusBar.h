#pragma once

#include <BasicConstants.h>

int SetCStatusBarArt(DWORD pFrame, const char* model, int modeltype);

int SetCStatusBarValue(DWORD pFrame, float value);

int SetCStatusBarMinMaxValue(DWORD pFrame, float minval, float maxval);
