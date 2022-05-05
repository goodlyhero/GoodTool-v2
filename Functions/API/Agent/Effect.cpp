#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <API/Memory/MemoryGameData.h>
#include <API/Memory/MemoryObjectData.h>

bool IsEffectHidden(jHANDLE e)
{
	return IsObjectHidden(ConvertHandle(e));
}

void ShowEffect(jHANDLE e, bool flag)
{
	ShowObject(ConvertHandle(e), flag);
}

void SetEffectAlpha(jHANDLE e, int alpha)
{
	SetObjectAlpha(ConvertHandle(e), alpha);
}

int GetEffectColour(jHANDLE e)
{
	return GetObjectColour(ConvertHandle(e));
}

void SetEffectColour(jHANDLE e, int colour)
{
	SetObjectColour(ConvertHandle(e), colour);
}

void SetEffectColourEx(jHANDLE e, int red, int green, int blue, int alpha)
{
	SetObjectColourEx(ConvertHandle(e), red, green, blue, alpha);
}

void SetEffectVertexColour(jHANDLE e, int red, int green, int blue, int alpha)
{
	DWORD pObject = ConvertHandle(e);

		if (pObject > 0)
		{
			SetObjectColourEx(pObject, red, green, blue, alpha);
			SetObjectAlpha(pObject, alpha);
		}
}

int GetEffectColourA(jHANDLE e)
{
	return GetObjectColourA(ConvertHandle(e));
}

void SetEffectColourA(jHANDLE e, int alpha)
{
	SetObjectColourA(ConvertHandle(e), alpha);
}

int GetEffectColourR(jHANDLE e)
{
	return GetObjectColourR(ConvertHandle(e));
}

void SetEffectColourR(jHANDLE e, int red)
{
	SetObjectColourR(ConvertHandle(e), red);
}

int GetEffectColourG(jHANDLE e)
{
	return GetObjectColourG(ConvertHandle(e));
}

void SetEffectColourG(jHANDLE e, int green)
{
	SetObjectColourG(ConvertHandle(e), green);
}

int GetEffectColourB(jHANDLE e)
{
	return GetObjectColourB(ConvertHandle(e));
}

void SetEffectColourB(jHANDLE e, int blue)
{
	SetObjectColourB(ConvertHandle(e), blue);
}

void SetEffectAnimationByIndex(jHANDLE e, int index)
{
	SetObjectAnimationByIndex(ConvertHandle(e), index);
}

void SetEffectModel(jHANDLE e, const char* model)
{
	SetObjectModel(ConvertHandle(e), model);
}

float GetEffectX(jHANDLE e)
{
	return GetObjectX(ConvertHandle(e));
}

void SetEffectX(jHANDLE e, float x)
{
	SetObjectX(ConvertHandle(e), x);
}

float GetEffectY(jHANDLE e)
{
	return GetObjectY(ConvertHandle(e));
}

void SetEffectY(jHANDLE e, float y)
{
	SetObjectY(ConvertHandle(e), y);
}

float GetEffectZ(jHANDLE e)
{
	return GetObjectZ(ConvertHandle(e));
}

void SetEffectZ(jHANDLE e, float z)
{
	SetObjectZ(ConvertHandle(e), z);
}

void SetEffectPosition(jHANDLE e, float x, float y, float z)
{
	SetObjectPosition(ConvertHandle(e), x, y, z);
}

float GetEffectTimeScale(jHANDLE e)
{
	return GetObjectTimeScale(ConvertHandle(e));
}

void SetEffectTimeScale(jHANDLE e, float speed)
{
	SetObjectTimeScale(ConvertHandle(e), speed);
}

float GetEffectScale(jHANDLE e)
{
	return GetObjectScale(ConvertHandle(e));
}

void SetEffectScale(jHANDLE e, float scale)
{
	SetObjectScale(ConvertHandle(e), scale);
}

void SetEffectScaleEx(jHANDLE e, float x, float y, float z)
{
	SetObjectScaleEx(ConvertHandle(e), x, y, z);
}

void SetEffectSpaceRotation(jHANDLE e, float yaw, float pitch, float roll)
{
	SetObjectSpaceRotation(ConvertHandle(e), yaw, pitch, roll);
}

float GetEffectRoll(jHANDLE e)
{
	return GetObjectRoll(ConvertHandle(e));
}

void SetEffectRoll(jHANDLE e, float angle)
{
	SetObjectRoll(ConvertHandle(e), angle);
}

float GetEffectPitch(jHANDLE e)
{
	return GetObjectPitch(ConvertHandle(e));
}

void SetEffectPitch(jHANDLE e, float angle)
{
	SetObjectPitch(ConvertHandle(e), angle);
}

float GetEffectFacing(jHANDLE e)
{
	return GetObjectFacing(ConvertHandle(e));
}

void SetEffectFacing(jHANDLE e, float angle)
{
	SetObjectFacing(ConvertHandle(e), angle);
}

void ResetEffectMatrix(jHANDLE e)
{
	ResetObjectMatrix(ConvertHandle(e));
}