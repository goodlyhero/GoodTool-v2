#pragma once
#include <BasicConstants.h>

int CreateCSimpleButton(int pParent);
bool DestroyCSimpleButton(DWORD pButton);
bool SetCSimpleButtonStateTexture(DWORD pButton, int state, const char* texturepath);
bool SetCSimpleButtonState(DWORD pButton, int state);