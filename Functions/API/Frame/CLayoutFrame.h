#pragma once
#include <BasicConstants.h>

int SetCLayoutFrameAbsolutePoint(DWORD pFrame, int point, float offsetX, float offsetY);

int SetCLayoutFrameCageMouse(DWORD pFrame, bool flag);

int ClearCLayoutFrameAllPoints(DWORD pFrame);

int SetCLayoutFrameWidth(DWORD pFrame, float width);

int SetCLayoutFrameHeight(DWORD pFrame, float height);

int SetCLayoutFrameAllPoints(DWORD pFrame, int relativeframe);
int SetCLayoutFrameSize(DWORD pFrame, float width, float height);

int SetCLayoutFramePoint(DWORD pFrame, int point, int pParentFrame, int relativePoint, float x, float y);
int SetCLayoutFrameScale(DWORD pFrame, float scale);

float GetCLayoutFrameHeight(DWORD pFrame);
