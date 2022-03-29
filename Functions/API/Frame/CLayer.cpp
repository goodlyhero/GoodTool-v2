#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

DWORD FindCLayerUnderCursorEx(DWORD pActiveLayer, int pMouseEvent)
{
    DWORD pData = 0;
    DWORD value = 0;

    if (pActiveLayer > 0)
    {
        pData = ReadRealMemory(pActiveLayer);

        if (pData > 0)
        {
            pData = this_call(pFindCLayerUnderCursor, pData, pMouseEvent);

            if (pData > 0)
            {
                if (ReadRealMemory(pData) != pWorldFrameWar3UI)
                {
                    return pData;
                }
            }
        }
    }

    return 0;
}

DWORD FindCLayerUnderCursor(void)
{
    return FindCLayerUnderCursorEx(pActiveCLayer, pGlobalMouseEvent);
}

DWORD SetCLayerOwner(DWORD pFrame, DWORD pParentFrame)
{
    if (pSetCLayerOwner > 0)
    {
        if ((pFrame > 0) && pParentFrame > 0)
        {
            return this_call(pSetCLayerOwner, pFrame, pParentFrame, 1, 0);
        }
    }

    return 0;
}

int HideCLayer(DWORD pFrame)
{
    if (pHideCLayer > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pHideCLayer, pFrame);
        }
    }

    return 0;
}

int ShowCLayer(DWORD pFrame)
{
    if (pShowCLayer > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pShowCLayer, pFrame);
        }
    }

    return 0;
}

int SetCLayerAlpha(DWORD pFrame, int alpha)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayerAlpha > 0)
    {
        if ((fid > 0) && fid != 6)
        {
            return this_call(pSetCLayerAlpha, pFrame, alpha, 0);
        }
    }

    return 0;
}

int SetCLayerFont(DWORD pFrame, const char* filename, float height, int flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayerFont > 0)
    {
        if (fid != 6 && fid != 19 && fid != 23)
        {
            if (! IsFrameLayoutByType(pFrame, fid))
            {
                return this_call(pSetCLayerFont, pFrame, (DWORD)filename, SetRealIntoMemory(height), flag);
            }
        }
    }

    return 0;
}

int SetCLayerTooltip(DWORD pFrame, int pTooltip)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCLayerTooltip > 0)
    {
        if (fid > 0)
        {
            if (pTooltip > 0)
            {
                WriteRealMemory(pFrame + 0x230, 1);
                this_call(pClearCLayoutFrameAllPoints, pTooltip + 0xB4, 1);
            }

            return this_call(pSetCLayerTooltip, pFrame, pTooltip);
        }
    }

    return 0;
}
