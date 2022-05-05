#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>

int SetCStatusBarArt(DWORD pFrame, const char* model, int modeltype)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCStatusBarArt > 0)
    {
        if (fid == 40)
        {
            return this_call(pSetCStatusBarArt, pFrame, (DWORD)model, modeltype);
        }
    }

    return 0;
}

int SetCStatusBarValue(DWORD pFrame, float value)
{
    DWORD fid = GetFrameType(pFrame);
    float minval = 0.;
    float maxval = 0.;
    float curval = 0.;
    float newval = 0.;

    if (fid == 40)
    { // FUNCTION_CStatusBar__SetValue => 1.27a = 0x0AA870
        minval = GetRealFromMemory(ReadRealMemory(pFrame + 0x1B4));
        maxval = GetRealFromMemory(ReadRealMemory(pFrame + 0x1B8));
        curval = GetRealFromMemory(ReadRealMemory(pFrame + 0x1BC));

        if (value <= minval)
        {
            value = minval;
        }

        WriteRealMemory(pFrame + 0x1BC, SetRealIntoMemory(value));
        return 1;
        //return CallThisCallWith2Args( ReadRealMemory( pFrame + 0xEC ), pFrame, 0 ) ?
    }

    return 0;
}

int SetCStatusBarMinMaxValue(DWORD pFrame, float minval, float maxval)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCStatusBarMinMaxValue > 0)
    {
        if (fid == 40)
        {
            return this_call(pSetCStatusBarMinMaxValue, pFrame, SetRealIntoMemory(minval), SetRealIntoMemory(maxval));
        }
    }

    return 0;
}
