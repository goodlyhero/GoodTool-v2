#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

DWORD SetCEditBoxFocus(DWORD pFrame, bool flag)
{
	if (GetFrameType(pFrame) == 6)
	{
		return this_call(pSetCEditBoxFocus, pFrame, flag);
	}

	return 0;
}

DWORD SetCEditBoxFont(DWORD pFrame, const char* filename, float height, int flag)
{
	DWORD fid = GetFrameType(pFrame);

		if (pSetCEditBoxFont > 0)
		{
			if (fid == 6)
			{
				return this_call(pSetCEditBoxFont, pFrame, (DWORD)filename, SetRealIntoMemory(height), flag);
			}
		}

	return 0;
}

const char* GetCEditBoxText(DWORD pFrame)
{
	DWORD fid = GetFrameType(pFrame);

		if (pGetCEditBoxText > 0)
		{
			if (fid == 6)
			{
				return (char*)(this_call(pGetCEditBoxText, pFrame));
			}
		}

	return NULL;
}

DWORD SetCEditBoxText(DWORD pFrame, const char* text)
{
	DWORD fid = GetFrameType(pFrame);

		if (pSetCEditBoxText > 0)
		{
			if (fid == 6 || fid == 36 || fid == 37)
			{
				return this_call(pSetCEditBoxText, pFrame, (DWORD)text, 1) > 0;
			}
		}

	return 0;
}