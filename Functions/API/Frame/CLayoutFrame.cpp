#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCLayoutFrameAbsolutePoint(DWORD pFrame, int point, float offsetX, float offsetY)
{
    if (pSetCLayoutFrameAbsolutePoint > 0)
    {
        if (GetFrameLayout(pFrame) > 0)
        {
            return this_call(pSetCLayoutFrameAbsolutePoint, pFrame, point, SetRealIntoMemory(offsetX), SetRealIntoMemory(offsetY), 1);
        }
    }

    return 0;
}

int SetCLayoutFrameCageMouse(DWORD pFrame, bool flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayoutFrameCageMouse > 0)
    {
        if (fid > 0)
        {
            return this_call(pSetCLayoutFrameCageMouse, pFrame,flag);
        }
    }

    return 0;
}

int ClearCLayoutFrameAllPoints(DWORD pFrame)
{
    if (pClearCLayoutFrameAllPoints > 0)
    {
        pFrame = GetFrameLayout(pFrame);

        if (pFrame > 0)
        {
            return this_call(pClearCLayoutFrameAllPoints, pFrame, 1);
        }
    }

    return 0;
}

int SetCLayoutFrameWidth(DWORD pFrame, float width)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayoutFrameWidth > 0)
    {
        if (fid > 0)
        {
            return this_call(pSetCLayoutFrameWidth, pFrame, SetRealIntoMemory(width));
        }
    }

    return 0;
}

int SetCLayoutFrameHeight(DWORD pFrame, float height)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayoutFrameHeight > 0)
    {
        if (fid > 0)
        {
            return this_call(pSetCLayoutFrameHeight, pFrame, SetRealIntoMemory(height));
        }
    }

    return 0;
}

int SetCLayoutFrameAllPoints(DWORD pFrame, int relativeframe)
{
    if (pSetCLayoutFrameAllPoints > 0)
    {
        pFrame = GetFrameLayout(pFrame);

        if ((pFrame > 0) && GetFrameLayout(relativeframe) > 0)
        {
            return this_call(pSetCLayoutFrameAllPoints, pFrame, relativeframe, 1);
        }
    }

    return 0;
}

int SetCLayoutFrameSize(DWORD pFrame, float width, float height)
{
    DWORD fid = GetFrameLayout(pFrame);

    if (pSetCLayoutFrameWidth > 0 && pSetCLayoutFrameHeight > 0)
    {
        if (fid > 0)
        {
            return this_call(pSetCLayoutFrameWidth, fid, SetRealIntoMemory(width)) > 0 && this_call(pSetCLayoutFrameHeight, fid, SetRealIntoMemory(height)) > 0;
        }
    }

    return 0;
}

int SetCLayoutFramePoint(DWORD pFrame, int point, int pParentFrame, int relativePoint, float x, float y)
{
    if (pSetCLayoutFramePoint > 0)
    {
        if ((pFrame > 0) && pParentFrame > 0)
        {
            return this_call(pSetCLayoutFramePoint, pFrame, point, pParentFrame, relativePoint, SetRealIntoMemory(x), SetRealIntoMemory(y), 1);
        }
    }

    return 0;
}

int SetCLayoutFrameScale(DWORD pFrame, float scale)
{
    pFrame = GetFrameLayout(pFrame);

    if (pSetCLayoutFrameScale > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pSetCLayoutFrameScale, pFrame, SetRealIntoMemory(scale));
        }
    }

    return 0;
}


float GetCLayoutFrameHeight(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (pGetCLayoutFrameHeight > 0)
    {
        if (fid != 15 && fid != 19 && fid != 25 && fid != 29)
        {
            pFrame = GetFrameLayoutByType(pFrame, fid);

            if (pFrame > 0)
            {
                return GetRealFromMemory(this_call(pGetCLayoutFrameHeight, pFrame));
            }
        }
    }

    return 0.;
}
