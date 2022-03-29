#pragma once
#include <BasicConstants.h>

int CreateCSimpleTexture(int pParent);

int FillCSimpleTexture(DWORD pFrame, int colour);

int GetCSimpleTextureByName(const char* name, int id);

int SetCSimpleTextureTexture(DWORD pFrame, const char* texturepath, bool flag);
