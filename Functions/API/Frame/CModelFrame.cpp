#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int AddCModelFrameModel(DWORD pFrame, const char* model, int modeltype)
{
	DWORD fid = GetFrameType(pFrame);

	if (pAddCModelFrameModel > 0)
	{
		if (fid == 15)
		{
			return this_call(pAddCModelFrameModel, pFrame,(DWORD) model, modeltype);
		}
	}

	return 0;
}

float GetCModelFrameHeight(DWORD pFrame)
{
	DWORD fid = GetFrameType(pFrame);

	if (pGetCModelFrameHeight > 0)
	{
		if (fid == 15)
		{
			return GetRealFromMemory(this_call(pGetCModelFrameHeight, pFrame));
		}
	}

	return 0.;
}
