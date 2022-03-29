#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCSpriteFrameArt(DWORD pFrame, const char* model, int modeltype, bool flag)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSpriteFrameArt > 0)
	{
		if (fid == 25)
		{
			return this_call(pSetCSpriteFrameArt, pFrame, (DWORD)model, modeltype, flag);
		}
	}

	return 0;
}

float GetCSpriteFrameHeight(DWORD pFrame)
{
	DWORD fid = GetFrameType(pFrame);

	if (pGetCSpriteFrameHeight > 0)
	{
		if (fid == 25)
		{
			return GetRealFromMemory(this_call(pGetCSpriteFrameHeight, pFrame));
		}
	}

	return 0.;
}

int SetCSpriteFrameScale(DWORD pFrame, float scale)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSpriteFrameScale > 0)
	{
		if (fid == 25)
		{
			return this_call(pSetCSpriteFrameScale, pFrame, SetRealIntoMemory(scale));
		}
	}

	return 0;
}
