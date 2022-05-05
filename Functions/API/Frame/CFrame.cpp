#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>

DWORD LoadTOCFile(const char* filename)
{
    DWORD retval = 0;

        if (pStringManager > 0 && pFDFHashTableList > 0 && pStringHashNodeGrowListArray > 0 && pBaseFrameHashNodeGrowListArray > 0 && pReadFDFFile > 0 && pDefaultCStatus > 0)
        {
            if (ReadRealMemory(pStringManager + 0x14) < 0xFFFF)
            { // if 1.29+ + 0x18
                this_call(pStringHashNodeGrowListArray, pStringManager, 0xFFFF);
            }

            if (ReadRealMemory(pFDFHashTableList + 0x14) < 0xFFFF)
            { // if 1.29+ + 0x18
                this_call(pBaseFrameHashNodeGrowListArray, pFDFHashTableList, 0xFFFF);
            }

            retval = fast_call(pReadFDFFile, (DWORD)filename, pStringManager, pFDFHashTableList, pDefaultCStatus);
        }

    return retval;
}

DWORD GetCFrameByName(const char* name, int id)
{
    if (pGetCFrameByName > 0)
    {
        if (name!=NULL)
        {
            return fast_call(pGetCFrameByName, (DWORD)name, id);
        }
    }

    return 0;
}

int CreateCFrameEx(const char* baseframe, int parent, int point, int relativepoint, int id)
{
    if (pCreateCFrame > 0)
    {
        if (baseframe != NULL)
        {
            return fast_call(pCreateCFrame, (DWORD)baseframe, parent, point, relativepoint, id);
        }
    }

    return 0;
}

int CreateCFrame(const char* baseframe, int parent, int id)
{
    return CreateCFrameEx(baseframe, parent, 0, 0, id);
}

int GetFrameLayoutByType(int pFrame, int fid)
{
    bool case1 = fid == 4 || fid == 10 || fid == 12 || (fid >= 18 && fid <= 23);
    bool case2 = fid == 26 || fid == 30 || fid == 39 || (fid >= 41 && fid <= 45);
    bool case3 = fid == 47 || (fid >= 49 && fid <= 64);

        if( fid != 0)
        {
            if (case1 || case2 || case3)
            {
                            return pFrame;
            }
            else
            {
                return pFrame + 0xB4; // if 1.29+ 0xBC;
            }
        }

    return 0;
}

int GetFrameLayout(int pFrame)
{
    return GetFrameLayoutByType(pFrame, GetFrameType(pFrame));
}

bool IsFrameLayoutByType(int pFrame, int fid)
{
    return GetFrameLayoutByType(pFrame, fid) == pFrame;
}

bool IsFrameLayout(int pFrame)
{
    return GetFrameLayout(pFrame) == pFrame;
}

