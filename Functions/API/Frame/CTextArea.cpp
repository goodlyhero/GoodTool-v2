#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>

int SetCTextAreaText(DWORD pFrame, const char* text)
{
    DWORD fid = GetFrameType(pFrame);

    if (pSetCTextAreaText > 0)
    {
        if (fid == 27)
        {
            return this_call(pSetCTextAreaText, pFrame, (DWORD)text) > 0;
        }
    }

    return 0;
}
