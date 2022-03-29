#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

bool IsTrackableHidden(jHANDLE track)
{
    return IsObjectHidden(ConvertHandle(track));
}

void ShowTrackable(jHANDLE track, bool flag)
{
    ShowObject(ConvertHandle(track), flag);
}

void SetTrackableAlpha(jHANDLE track, int alpha)
{
    SetObjectAlpha(ConvertHandle(track), alpha);
}

int GetTrackableColour(jHANDLE track)
{
    return GetObjectColour(ConvertHandle(track));
}

void SetTrackableColour(jHANDLE track, int colour)
{
    SetObjectColour(ConvertHandle(track), colour);
}

void SetTrackableColourEx(jHANDLE track, int red, int green, int blue, int alpha)
{
    SetObjectColourEx(ConvertHandle(track), red, green, blue, alpha);
}

void SetTrackableVertexColour(jHANDLE track, int red, int green, int blue, int alpha)
{
    DWORD pObject = ConvertHandle(track);

        if (pObject > 0)
        {
            SetObjectColourEx(pObject, red, green, blue, alpha);
            SetObjectAlpha(pObject, alpha);
        }
}

int GetTrackableColourA(jHANDLE track)
{
    return GetObjectColourA(ConvertHandle(track));
}

void SetTrackableColourA(jHANDLE track, int alpha)
{
    SetObjectColourA(ConvertHandle(track), alpha);
}

int GetTrackableColourR(jHANDLE track)
{
    return GetObjectColourR(ConvertHandle(track));
}

void SetTrackableColourR(jHANDLE track, int red)
{
    SetObjectColourR(ConvertHandle(track), red);
}

int GetTrackableColourG(jHANDLE track)
{
    return GetObjectColourG(ConvertHandle(track));
}

void SetTrackableColourG(jHANDLE track, int green)
{
    SetObjectColourG(ConvertHandle(track), green);
}

int GetTrackableColourB(jHANDLE track)
{
    return GetObjectColourB(ConvertHandle(track));
}

void SetTrackableColourB(jHANDLE track, int blue)
{
    SetObjectColourB(ConvertHandle(track), blue);
}

void SetTrackableAnimationByIndex(jHANDLE track, int index)
{
    SetObjectAnimationByIndex(ConvertHandle(track), index);
}

void SetTrackableModel(jHANDLE track, const char* model)
{
    SetObjectModel(ConvertHandle(track), model);
}

float GetTrackableX(jHANDLE track)
{
    return GetObjectX(ConvertHandle(track));
}

void SetTrackableX(jHANDLE track, float x)
{
    SetObjectX(ConvertHandle(track), x);
}

float GetTrackableY(jHANDLE track)
{
    return GetObjectY(ConvertHandle(track));
}

void SetTrackableY(jHANDLE track, float y)
{
    SetObjectY(ConvertHandle(track), y);
}

float GetTrackableZ(jHANDLE track)
{
    return GetObjectZ(ConvertHandle(track));
}

void SetTrackableZ(jHANDLE track, float z)
{
    SetObjectZ(ConvertHandle(track), z);
}

void SetTrackablePosition(jHANDLE track, float x, float y, float z)
{
    SetObjectPosition(ConvertHandle(track), x, y, z);
}

float GetTrackableTimeScale(jHANDLE track)
{
    return GetObjectTimeScale(ConvertHandle(track));
}

void SetTrackableTimeScale(jHANDLE track, float speed)
{
    SetObjectTimeScale(ConvertHandle(track), speed);
}

float GetTrackableScale(jHANDLE track)
{
    return GetObjectScale(ConvertHandle(track));
}

void SetTrackableScale(jHANDLE track, float scale)
{
    SetObjectScale(ConvertHandle(track), scale);
}

void SetTrackableScaleEx(jHANDLE track, float x, float y, float z)
{
    SetObjectScaleEx(ConvertHandle(track), x, y, z);
}

void SetTrackableSpaceRotation(jHANDLE track, float yaw, float pitch, float roll)
{
    SetObjectSpaceRotation(ConvertHandle(track), yaw, pitch, roll);
}

float GetTrackableRoll(jHANDLE track)
{
    return GetObjectRoll(ConvertHandle(track));
}

void SetTrackableRoll(jHANDLE track, float angle)
{
    SetObjectRoll(ConvertHandle(track), angle);
}

float GetTrackablePitch(jHANDLE track)
{
    return GetObjectPitch(ConvertHandle(track));
}

void SetTrackablePitch(jHANDLE track, float angle)
{
    SetObjectPitch(ConvertHandle(track), angle);
}

float GetTrackableFacing(jHANDLE track)
{
    return GetObjectFacing(ConvertHandle(track));
}

void SetTrackableFacing(jHANDLE track, float angle)
{
    SetObjectFacing(ConvertHandle(track), angle);
}

void ResetTrackableMatrix(jHANDLE track)
{
    ResetObjectMatrix(ConvertHandle(track));
}