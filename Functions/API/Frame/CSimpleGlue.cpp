#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryGameUI.h>

DWORD SetCSimpleGlueFrameScale(DWORD pFrame, float scale)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleGlueFrameScale > 0)
	{
		if( fid == 21)
		{
			return this_call(pSetCSimpleGlueFrameScale, pFrame, SetRealIntoMemory(scale));
		}
	}

	return 0;
}
