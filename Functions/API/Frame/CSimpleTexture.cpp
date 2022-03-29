#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int CreateCSimpleTexture(int pParent)
{
    DWORD baseobj = 0;

        if (pCreateCSimpleTexture > 0)
        {
            baseobj = StormAllocateMemory(0xE8, "", 0, 0);

            if (baseobj > 0)
            {
                return this_call(pCreateCSimpleTexture, baseobj, pParent, 2, 1);
            }
        }

    return 0;
}

int FillCSimpleTexture(DWORD pFrame, int colour)
{
    if (pFillCSimpleTexture > 0)
    {
        return this_call(pFillCSimpleTexture, pFrame, (DWORD)&colour) == 0;
    }

    return 0;
}

int GetCSimpleTextureByName(const char* name, int id)
{
    if (pGetCSimpleTextureByName > 0)
    {
        if (name != NULL)
        {
            return fast_call(pGetCSimpleTextureByName,(DWORD) name, id);
        }
    }

    return 0;
}

int SetCSimpleTextureTexture(DWORD pFrame, const char* texturepath, bool flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCSimpleTextureTexture > 0)
    {
        if( fid == 64)
        {
            return this_call(pSetCSimpleTextureTexture, pFrame, (DWORD)texturepath,flag);
        }
    }

    return 0;
}
