#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>

int SetCSimpleStatusBarTexture(DWORD pFrame, const char* texturepath, bool flag)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleStatusBarTexture > 0)
	{
		if (fid == 39)
		{
			return this_call(pSetCSimpleStatusBarTexture, pFrame, (DWORD)texturepath, flag);
		}
	}

	return 0;
}

int SetCSimpleStatusBarValue(DWORD pFrame, float value)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleStatusBarValue > 0)
	{
		if (fid == 39)
		{
			return this_call(pSetCSimpleStatusBarValue, pFrame, SetRealIntoMemory(value));
		}
	}

	return 0;
}

int SetCSimpleStatusBarMinMaxValue(DWORD pFrame, float minval, float maxval)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleStatusBarMinMaxValue > 0)
	{
		if (fid == 39)
		{
			return this_call(pSetCSimpleStatusBarMinMaxValue, pFrame, SetRealIntoMemory(minval), SetRealIntoMemory(maxval));
		}
	}

	return 0;
}
