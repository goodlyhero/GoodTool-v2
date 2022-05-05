#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>
#include <API/Memory/MemoryStormDLL.h>

DWORD CreateCSimpleFont(DWORD pParent)
{
    DWORD baseobj = 0;

        if (pCreateCSimpleFont > 0)
        {
            baseobj = StormAllocateMemory(0xC4, "", 0, 0);

            if( baseobj > 0)
            {
                return this_call(pCreateCSimpleFont, baseobj, pParent, 2, 1);
            }
        }

    return 0;
}

DWORD GetCSimpleFontByName(const char* name, int id)
{
    if (pGetCSimpleFontByName > 0)
    {
        if (name != NULL)
        {
            return fast_call(pGetCSimpleFontByName, (DWORD)name, id);
        }
    }

    return 0;
}

const char* GetCSimpleFontTextByName(const char* name, int id)
{
    DWORD pFrame = GetCSimpleFontByName(name, id);

        // GetFrameTextMaxLength = 0x94
        // GetFrameTextLength = 0x98
        if (pFrame > 0)
        {
            return (char*)(ReadRealMemory(pFrame + 0x9C));
        }

    return NULL;
}

DWORD SetCSimpleFontStringScale(DWORD pFrame, float scale)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCSimpleFontStringScale > 0)
    {
        if (fid == 19)
        {
            return this_call(pSetCSimpleFontStringScale, pFrame, SetRealIntoMemory(scale));
        }
    }

    return 0;
}

DWORD SetCSimpleFontStringFont(DWORD pFrame, const char* filename, float height, int flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCSimpleFontStringFont > 0)
    {
        if( fid == 19)
        {
            return this_call(pSetCSimpleFontStringFont, pFrame, (DWORD)filename, SetRealIntoMemory(height), flag);
        }
    }

    return 0;
}

float GetCSimpleFontStringHeight(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (pGetCSimpleFontStringHeight > 0)
    {
        if (fid == 19)
        {
            return GetRealFromMemory(this_call(pGetCSimpleFontStringHeight, pFrame));
        }
    }

    return 0.;
}

int SetCSimpleFontText(DWORD pFrame, const char* text)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCSimpleFontText > 0)
    {
        if( fid == 19)
        {
            return this_call(pSetCSimpleFontText, pFrame, (DWORD)text) > 0;
        }
    }

    return 0;
}
