#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int CreateCSimpleButton(int pParent)
{
    DWORD baseobj = 0;

        if (pCreateCSimpleButton > 0)
        {
            baseobj = StormAllocateMemory(0x168, "", 0, 0);

            if (baseobj > 0)
            {
                return this_call(pCreateCSimpleButton, baseobj, pParent);
            }
        }

    return 0;
}

bool DestroyCSimpleButton(DWORD pButton)
{
    if (pButton > 0)
    {
        return this_call(ReadRealMemory(pButton + 0x8), pButton, 1) > 0;
    }

    return false;
}

bool SetCSimpleButtonStateTexture(DWORD pButton, int state, const char* texturepath)
{
    if (pSetCSimpleButtonStateTexture > 0)
    {
        if (pButton > 0)
        {
            return this_call(pSetCSimpleButtonStateTexture, pButton, state, (DWORD)texturepath) > 0;
        }
    }

    return false;
}

bool SetCSimpleButtonState(DWORD pButton, int state)
{
    if( pSetCSimpleButtonState > 0)
    {
        if (pButton > 0)
        {
            return this_call(pSetCSimpleButtonState, pButton, state) > 0;
        }
    }

    return false;
}
