#pragma once

#include <BasicConstants.h>


float GetWindowWidth(void);

float GetWindowHeight(void);
DWORD GetWindowX(DWORD hwnd);

DWORD GetWindowY(DWORD hwnd);
float GetWindowCenterX(void);

float GetWindowCenterY(void);

int GetWarcraftWindow(void);

float FromPixelX(int i);

float FromPixelY(int i);