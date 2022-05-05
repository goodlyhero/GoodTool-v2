#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>
#include <API/Memory/MemoryStormDLL.h>
#include <API/Frame/Frame.h>
#include "CFrame.h"

DWORD CreateCSimpleFrame(DWORD pParent)
{
    DWORD baseobj = 0;

    if (pCreateCSimpleFrame > 0)
    {
        baseobj = StormAllocateMemory(0x124, "", 0, 0);

        if (baseobj > 0)
        {
            return this_call(pCreateCSimpleFrame, baseobj, pParent);
        }
    }

    return 0;
}

DWORD CreateCSimpleConsole(const char* baseCSimpleConsole, DWORD parent, int id)
{
    if (pCreateCSimpleConsole > 0)
    {
        if (baseCSimpleConsole != NULL)
        {
            return fast_call(pCreateCSimpleConsole, (DWORD)baseCSimpleConsole, parent, id);
        }
    }

    return 0;
}

DWORD GetCSimpleFrameByName(const char* name, int id)
{
    if (pGetCSimpleFrameByName > 0)
    {
        if (name != NULL)
        {
            return fast_call(pGetCSimpleFrameByName, (DWORD)name, id);
        }
    }

    return 0;
}

DWORD SetCSimpleFrameScale(DWORD pCSimpleFrame, float scale)
{
    DWORD fid = GetFrameType(pCSimpleFrame);

    if (pSetCSimpleFrameScale > 0)
    {
        if (fid == 22 || fid == 23 || fid == 39)
        {
            return this_call(pSetCSimpleFrameScale, pCSimpleFrame, SetRealIntoMemory(scale));
        }
    }

    return 0;
}

int SetCSimpleFramePriority(int pCSimpleFrame, int priority)
{
    DWORD fid = GetFrameType(pCSimpleFrame);

    if (pSetCSimpleFramePriority > 0)
    {
        if (fid > 0)
        {
            if (IsFrameLayout(pCSimpleFrame))
            {
                return this_call(pSetCSimpleFramePriority, pCSimpleFrame, priority);
            }
            else
            {
                WriteRealMemory(pCSimpleFrame + 0xA8, priority);
                return 1;
            }
        }
    }

    return 0;
}

DWORD SetCSimpleFrameParent(DWORD pCSimpleFrame, int pParentCSimpleFrame)
{
    if (pSetCSimpleFrameParent > 0)
    {
        if (IsFrameLayout(pCSimpleFrame) && IsFrameLayout(pParentCSimpleFrame))
        {
            return this_call(pSetCSimpleFrameParent, pCSimpleFrame, pParentCSimpleFrame);
        }
    }

    return 0;
}
