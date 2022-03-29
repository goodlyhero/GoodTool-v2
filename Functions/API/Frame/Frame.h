#pragma once
#include <BasicConstants.h>

int GetFrameByName(const char* name, int id);

int CreateFrameEx(const char* baseframe, DWORD parent, int point, int relativepoint, int id);

int CreateFrame(const char* baseframe, DWORD parent, int id);

int CreateSimpleFrame(int parent);

bool GetUnitFramePosition(DWORD pUnit);

int HideFrame(DWORD pFrame);

int ShowFrame(DWORD pFrame);

int SetFrameAlpha(DWORD pFrame, DWORD alpha);

int SetLayerFont(DWORD pFrame, const char* filename, float height, int flag);

int SetFrameTooltip(DWORD pFrame, int pTooltip);

int SetFrameFocus(DWORD pFrame, bool flag);

int SetFrameCageMouse(DWORD pFrame, bool flag);

int SetFrameAbsolutePoint(DWORD pFrame, int point, float x, float y);

int SetFramePoint(DWORD pFrame, int point, DWORD pParentFrame, int relativePoint, float x, float y);

int ClearFrameAllPoints(DWORD pFrame);

int SetFrameWidth(DWORD pFrame, float width);

int SetFrameHeight(DWORD pFrame, float height);

int SetFrameAllPoints(DWORD pFrame, int relativeframe);

int SetFrameSize(DWORD pFrame, float width, float height);

int SetLayoutFrameScale(DWORD pFrame, float scale);

int SetFrameVertexColour(DWORD pFrame, int colour);

int SetFrameVertexColourEx(DWORD pFrame, int alpha, int red, int blue, int green);

int GetFrameSkinByName(const char* name, int id);

int DestroyFrame(DWORD pFrame);

bool GetFrameState(DWORD pFrame, int state);

bool IsFrameEnabled(DWORD pFrame);

int SetFrameState(DWORD pFrame, bool flag);
int EnableFrame(DWORD pFrame);

int DisableFrame(DWORD pFrame);

const char* GetFrameTextByName(const char* name, int id);

int SetFrameTextColour(DWORD pFrame, DWORD colour);

int SetFrameTextColourEx(DWORD pFrame, int alpha, int red, int blue, int green);

int FindLayerUnderCursor(void);

int ClickFrame(DWORD pFrame);

int SetFrameModel(DWORD pFrame, const char* model, int modeltype, bool flag);

int GetFrameAlpha(DWORD pFrame);

int UpdateFrame(DWORD pFrame);

void SetFrameStepValue(DWORD pFrame, float step);

int GetFrameParent(DWORD pFrame);

int SetFrameParent(DWORD pFrame, int pParentFrame);

const char* GetFrameName(DWORD pFrame);

int SetFrameTexture(DWORD pFrame, const char* texturepath, bool flag);

int SetFrameScale(DWORD pFrame, float scale);

float GetFrameValue(DWORD pFrame);

int SetFrameValue(DWORD pFrame, float value);

int SetFrameMinMaxValue(DWORD pFrame, float minval, float maxval);
//===========================================

// Frame Point API Engine
int SetFrameFont(DWORD pFrame, const char* filename, float height, int flag);

float GetFrameWidth(DWORD pFrame);

float GetFrameHeight(DWORD pFrame);

int GetFramePoint(DWORD pFrame, int point);

int GetFramePointParent(DWORD pFrame, int point);

int GetFramePointRelativePoint(DWORD pFrame, int point);

float GetFramePointX(DWORD pFrame, int point);

float GetFramePointY(DWORD pFrame, int point);
//===========================================

// Frame Text API Engine
int GetFrameTextMaxLength(DWORD pFrame);

void SetFrameMaxTextLength(DWORD pFrame, int length);

int GetFrameTextLength(DWORD pFrame);

const char* GetFrameText(DWORD pFrame);

int SetFrameText(DWORD pFrame, const char* text);
//===========================================

bool IsReplay(void);

void SetAllyCheckbox(int mode);

void EnableAllyCheckbox(void);

void DisableAllyCheckbox(void);

void DisableSaveGameMenu(void); 