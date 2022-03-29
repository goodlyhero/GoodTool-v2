#pragma once
#include <BasicConstants.h>
DWORD FindCLayerUnderCursorEx(DWORD pActiveLayer, int pMouseEvent);

DWORD FindCLayerUnderCursor(void);

DWORD SetCLayerOwner(DWORD pFrame, DWORD pParentFrame);

int HideCLayer(DWORD pFrame);

int ShowCLayer(DWORD pFrame);

int SetCLayerAlpha(DWORD pFrame, int alpha);

int SetCLayerFont(DWORD pFrame, const char* filename, float height, int flag);

int SetCLayerTooltip(DWORD pFrame, int pTooltip);
