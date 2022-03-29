#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCSliderCurrentValue(DWORD pFrame, float value)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSliderCurrentValue > 0)
	{
		if (fid == 24)
		{
			return this_call(pSetCSliderCurrentValue, pFrame, SetRealIntoMemory(value), 1);
		}
	}

	return 0;
}
