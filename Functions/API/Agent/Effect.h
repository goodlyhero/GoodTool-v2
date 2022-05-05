#pragma once
#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>


bool IsEffectHidden(jHANDLE e);
void ShowEffect(jHANDLE e, bool flag);
void SetEffectAlpha(jHANDLE e, int alpha);
int GetEffectColour(jHANDLE e);
void SetEffectColour(jHANDLE e, int colour);
void SetEffectColourEx(jHANDLE e, int red, int green, int blue, int alpha);
void SetEffectVertexColour(jHANDLE e, int red, int green, int blue, int alpha);
int GetEffectColourA(jHANDLE e);
void SetEffectColourA(jHANDLE e, int alpha);
int GetEffectColourR(jHANDLE e);
void SetEffectColourR(jHANDLE e, int red);
int GetEffectColourG(jHANDLE e);
void SetEffectColourG(jHANDLE e, int green);
int GetEffectColourB(jHANDLE e);
void SetEffectColourB(jHANDLE e, int blue);
void SetEffectAnimationByIndex(jHANDLE e, int index);
void SetEffectModel(jHANDLE e, const char* model);
float GetEffectX(jHANDLE e);
void SetEffectX(jHANDLE e, float x);
float GetEffectY(jHANDLE e);
void SetEffectY(jHANDLE e, float y);
float GetEffectZ(jHANDLE e);
void SetEffectZ(jHANDLE e, float z);
void SetEffectPosition(jHANDLE e, float x, float y, float z);
float GetEffectTimeScale(jHANDLE e);
void SetEffectTimeScale(jHANDLE e, float speed);
float GetEffectScale(jHANDLE e);
void SetEffectScale(jHANDLE e, float scale);
void SetEffectScaleEx(jHANDLE e, float x, float y, float z);
void SetEffectSpaceRotation(jHANDLE e, float yaw, float pitch, float roll);
float GetEffectRoll(jHANDLE e);
void SetEffectRoll(jHANDLE e, float angle);
float GetEffectPitch(jHANDLE e);
void SetEffectPitch(jHANDLE e, float angle);
float GetEffectFacing(jHANDLE e);
void SetEffectFacing(jHANDLE e, float angle);
void ResetEffectMatrix(jHANDLE e);