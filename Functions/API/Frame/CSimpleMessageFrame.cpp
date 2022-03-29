#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCSimpleMessageFrameFont(DWORD pFrame, const char* filename, float height, int flag)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleMessageFrameFont > 0)
	{
		if (fid == 23)
		{
			return this_call(pSetCSimpleMessageFrameFont, pFrame, (DWORD)filename, SetRealIntoMemory(height), flag);
		}
	}

	return 0;
}
