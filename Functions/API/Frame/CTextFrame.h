#pragma once
#include <BasicConstants.h>

int SetCTextFrameTextColour(DWORD pFrame, int colour);

int SetCTextFrameTextColourEx(DWORD pFrame, int alpha, int red, int blue, int green);

float GetCTextFrameHeight(DWORD pFrame);

int SetCTextFrameText(DWORD pFrame, const char* text);
