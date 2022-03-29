#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <cmath>
#include <Deg2Rad.h>

int GetARGBColour(char alpha, char red, char green, char blue)
{
    return CreateInteger1(alpha, red, green, blue);
}

float GetSpriteDataOffsetAddressR(int pObject, int offset)
{
    if (pObject > 0)
    {
        return ReadRealMemory(ReadRealMemory(pObject + 0x28) + offset);
    }

    return 0.;
}

void SetSpriteDataOffsetAddressR(int pObject, int offset, float r)
{
    if (pObject > 0)
    {
        WriteRealMemory(ReadRealMemory(pObject + 0x28) + offset, (DWORD)&r);
    }
}

bool IsObjectHidden(int pObject)
{
    if (pObject > 0)
    {
        return IsFlagBitSet(ReadRealMemory(pObject + 0x20), 1);
    }

    return false;
}

void ShowObject(int pObject, bool flag)
{
    if (pObject > 0)
    {
        WriteRealMemory(pObject + 0x20, ! flag);
    }
}

int GetObjectTypeId(int pObj)
{
    // Do NOT use this with effects || trackables, since they do not have TypeId
    if (pObj > 0)
    {
        return ReadRealMemory(pObj + 0x30);
    }

    return 0;
}

void UpdateObjectColour(int pObject)
{
    DWORD pData = 0;
    DWORD flag = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject + 0x28);

        if (pData > 0)
        {
            WriteRealMemory(pData + 0x140, 0);
            WriteRealMemory(pData + 0x13C, 0);
            flag = ReadRealMemory(pData + 0x138);

            if (! IsFlagBitSet(flag, 0x800))
            {
                WriteRealMemory(pData + 0x138, flag + 0x800);
            }
        }
    }
}

void SetObjectAlpha(int pObject, int alpha)
{
    // Does not work on items/units/destructables/doodads
    DWORD pData = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject + 0x28);

        if (pData > 0)
        {
            if (alpha >= 0x00 && alpha <= 0xFF)
            {
                fast_call(pSetObjectAlpha, pData, alpha, 0);
            }
        }
    }
}

int GetObjectColour(int pObject)
{
    DWORD pData = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject + 0x28);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x148);
        }
    }

    return 0;
}

void SetObjectColour(int pObject, int colour)
{
    // Does not work on items.
    DWORD pData = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject + 0x28);

        if (pData > 0)
        {
            //call WriteRealMemory( pData + 0x144, SetRealIntoMemory( fadetime ) )
            WriteRealMemory(pData + 0x148, colour);
            UpdateObjectColour(pObject);
        }
    }
}

void SetObjectColourEx(int pObject, int red, int green, int blue, int alpha)
{
    if (pObject > 0)
    {
        SetObjectColour(pObject, CreateInteger1(alpha, red, green, blue));
    }
}

void SetObjectVertexColour(int pObject, int red, int green, int blue, int alpha)
{
    SetObjectColourEx(pObject, red, green, blue, alpha);
    SetObjectAlpha(pObject, alpha);
}

int GetObjectColourA(int pObject)
{
    if (pObject > 0)
    {
        return GetByteFromInteger(GetObjectColour(pObject), 1);
    }

    return -1;
}

void SetObjectColourA(int pObject, int alpha)
{
    DWORD colour = 0;

    if (pObject > 0)
    {
        colour = GetObjectColour(pObject);
        SetObjectColour(pObject, CreateInteger1(alpha, GetByteFromInteger(colour, 2), GetByteFromInteger(colour, 3), GetByteFromInteger(colour, 4)));
    }
}

int GetObjectColourR(int pObject)
{
    if (pObject > 0)
    {
        return GetByteFromInteger(GetObjectColour(pObject), 2);
    }

    return -1;
}

void SetObjectColourR(int pObject, int red)
{
    DWORD colour = 0;

    if (pObject > 0)
    {
        colour = GetObjectColour(pObject);
        SetObjectColour(pObject, CreateInteger1(GetByteFromInteger(colour, 1), red, GetByteFromInteger(colour, 3), GetByteFromInteger(colour, 4)));
    }
}

int GetObjectColourG(int pObject)
{
    if (pObject > 0)
    {
        return GetByteFromInteger(GetObjectColour(pObject), 3);
    }

    return -1;
}

void SetObjectColourG(int pObject, int green)
{
    DWORD colour = 0;

    if (pObject > 0)
    {
        colour = GetObjectColour(pObject);
        SetObjectColour(pObject, CreateInteger1(GetByteFromInteger(colour, 1), GetByteFromInteger(colour, 2), green, GetByteFromInteger(colour, 4)));
    }
}

int GetObjectColourB(int pObject)
{
    if (pObject > 0)
    {
        return GetByteFromInteger(GetObjectColour(pObject), 4);
    }

    return -1;
}

void SetObjectColourB(int pObject, int blue)
{
    DWORD colour = 0;

    if (pObject > 0)
    {
        colour = GetObjectColour(pObject);
        SetObjectColour(pObject, CreateInteger1(GetByteFromInteger(colour, 1), GetByteFromInteger(colour, 2), GetByteFromInteger(colour, 3), blue));
    }
}

void SetObjectAnimationByIndex(int pObject, int index)
{
    // Does not work on items.
    DWORD pData = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject + 0x28);

        if (pData > 0)
        {
            fast_call(pSetObjectAnimation, pData, index, 0);
        }
    }
}

void SetObjectModel(int pObject, const char* model)
{
    // Works on every handle, even items.
    DWORD pData = 0;

    if (pObject > 0)
    {
        pData = ReadRealMemory(pObject) + 0x88;

        if (pData > 0)
        {
            pData = ReadRealMemory(pData);

            if (pData > 0)
            {
                this_call(pData, pObject, (DWORD)model, 1);
            }
        }
    }
}

float GetObjectX(int pObject)
{
    return GetSpriteDataOffsetAddressR(pObject, 0xC0);
}

void SetObjectX(int pObject, float x)
{
    SetSpriteDataOffsetAddressR(pObject, 0xC0, x);
}

float GetObjectY(int pObject)
{
    return GetSpriteDataOffsetAddressR(pObject, 0xC4);
}

void SetObjectY(int pObject, float y)
{
    SetSpriteDataOffsetAddressR(pObject, 0xC4, y);
}

float GetObjectZ(int pObject)
{
    return GetSpriteDataOffsetAddressR(pObject, 0xC8);
}

void SetObjectZ(int pObject, float z)
{
    SetSpriteDataOffsetAddressR(pObject, 0xC8, z);
}

void SetObjectPosition(int pObject, float x, float y, float z)
{
    if (pObject > 0)
    {
        SetSpriteDataOffsetAddressR(pObject, 0xC0, x);
        SetSpriteDataOffsetAddressR(pObject, 0xC4, y);
        SetSpriteDataOffsetAddressR(pObject, 0xC8, z);
    }
}

float GetObjectTimeScale(int pObject)
{
    return GetSpriteDataOffsetAddressR(pObject, 0x190);
}

void SetObjectTimeScale(int pObject, float speed)
{
    SetSpriteDataOffsetAddressR(pObject, 0x190, speed);
}

float GetObjectScale(int pObject)
{
    return GetSpriteDataOffsetAddressR(pObject, 0xE8);
}

void SetObjectScale(int pObject, float scale)
{
    SetSpriteDataOffsetAddressR(pObject, 0xE8, scale);
}

void SetObjectScaleEx(int pObject, float x, float y, float z)
{
    if (pObject > 0)
    {
        SetSpriteDataOffsetAddressR(pObject, 0x108, x);
        SetSpriteDataOffsetAddressR(pObject, 0x118, y);
        SetSpriteDataOffsetAddressR(pObject, 0x128, z);
    }
}

void SetObjectSpaceRotation(int pObject, float yaw, float pitch, float roll)
{
    if (pObject > 0)
    {
        yaw = Deg2Rad(yaw);
        pitch = Deg2Rad(pitch);
        roll = Deg2Rad(roll);

        SetSpriteDataOffsetAddressR(pObject, 0x108, cos(yaw) * cos(pitch));
        SetSpriteDataOffsetAddressR(pObject, 0x10C, (cos(yaw) * sin(pitch) * sin(roll)) - (sin(yaw) * cos(roll)));
        SetSpriteDataOffsetAddressR(pObject, 0x110, (cos(yaw) * sin(pitch) * cos(roll)) + (sin(yaw) * sin(roll)));
        SetSpriteDataOffsetAddressR(pObject, 0x114, sin(yaw) * cos(pitch));
        SetSpriteDataOffsetAddressR(pObject, 0x118, (sin(yaw) * sin(pitch) * sin(roll)) + (cos(yaw) * cos(roll)));
        SetSpriteDataOffsetAddressR(pObject, 0x11C, (sin(yaw) * sin(pitch) * cos(roll)) - (cos(yaw) * sin(roll)));
        SetSpriteDataOffsetAddressR(pObject, 0x120, -sin(pitch));
        SetSpriteDataOffsetAddressR(pObject, 0x124, cos(pitch) * sin(roll));
        SetSpriteDataOffsetAddressR(pObject, 0x128, cos(pitch) * cos(roll));
    }
}

float GetObjectRoll(int pObject)
{
    return Rad2Deg(asin(GetSpriteDataOffsetAddressR(pObject, 0x11C)));
}

void SetObjectRoll(int pObject, float angle)
{
    if (pObject > 0)
    {
        angle = Deg2Rad(angle);
        SetSpriteDataOffsetAddressR(pObject, 0x108, 1.);
        SetSpriteDataOffsetAddressR(pObject, 0x10C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x110, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x114, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x118, cos(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x11C, sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x120, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x124, -sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x128, cos(angle));
    }
}

float GetObjectPitch(int pObject)
{
    return Rad2Deg(asin(GetSpriteDataOffsetAddressR(pObject, 0x120)));
}

void SetObjectPitch(int pObject, float angle)
{
    if (pObject > 0)
    {
        angle = Deg2Rad(angle);
        SetSpriteDataOffsetAddressR(pObject, 0x108, cos(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x10C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x110, -sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x114, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x118, 1.);
        SetSpriteDataOffsetAddressR(pObject, 0x11C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x120, sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x124, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x128, cos(angle));
    }
}

float GetObjectFacing(int pObject)
{
    return Rad2Deg(acos(GetSpriteDataOffsetAddressR(pObject, 0x108)));
}

void SetObjectFacing(int pObject, float angle)
{
    if (pObject > 0)
    {
        angle = Deg2Rad(angle);
        SetSpriteDataOffsetAddressR(pObject, 0x108, cos(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x10C, sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x110, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x114, -sin(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x118, cos(angle));
        SetSpriteDataOffsetAddressR(pObject, 0x11C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x120, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x124, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x128, 1.);
    }
}

void ResetObjectMatrix(int pObject)
{
    if (pObject > 0)
    {
        SetSpriteDataOffsetAddressR(pObject, 0x108, 1.);
        SetSpriteDataOffsetAddressR(pObject, 0x10C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x110, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x114, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x118, 1.);
        SetSpriteDataOffsetAddressR(pObject, 0x11C, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x120, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x124, 0.);
        SetSpriteDataOffsetAddressR(pObject, 0x128, 1.);
    }
}