#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int LoadCBackDropFrameTexture(const char* texturepath, bool create)
{
	if (pLoadCBackDropFrameTexture > 0)
	{
		if (texturepath != NULL)
		{
			return std_call(pLoadCBackDropFrameTexture, (DWORD)texturepath, create);
		}
	}

	return 0;
}

int SetCBackDropFrameTexture(DWORD pFrame, const char* texturepath, bool flag)
{
	DWORD fid = GetFrameType(pFrame);

		if (pSetCBackDropFrameTexture > 0)
		{
			if (fid == 1)
			{
				return this_call(pSetCBackDropFrameTexture, pFrame, (DWORD)texturepath, 0,flag, 0, 1);
			}
		}

	return 0;
}