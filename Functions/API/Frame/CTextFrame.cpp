#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCTextFrameTextColour(DWORD pFrame, int colour)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCTextFrameTextColour > 0)
    {
        if (fid == 6 || fid == 29)
        {
            return this_call(pSetCTextFrameTextColour, pFrame, colour); // ARGB colour;
        }
    }

    return 0;
}

int SetCTextFrameTextColourEx(DWORD pFrame, int alpha, int red, int blue, int green)
{
    return SetCTextFrameTextColour(pFrame, CreateInteger1(alpha, red, green, blue));
}

float GetCTextFrameHeight(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (pGetCTextFrameHeight > 0)
    {
        if (fid == 29)
        {
            return GetRealFromMemory(this_call(pGetCTextFrameHeight, pFrame));
        }
    }

    return 0.;
}

int SetCTextFrameText(DWORD pFrame, const char* text)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCTextFrameText > 0)
    {
        if (fid == 28 || fid == 33 || fid == 29 || fid == 38)
        {
            if (fid == 28 || fid == 33)
            {
                pFrame = ReadRealMemory(pFrame + 0x1E4);
            }

            return this_call(pSetCTextFrameText, pFrame, (DWORD)text) > 0;
        }
    }

    return 0;
}
