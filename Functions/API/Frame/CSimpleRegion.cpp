#include <BasicConstants.h>
#include <Windows.h>
#include <Functions.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>

int SetCSimpleRegionVertexColour(DWORD pFrame, int colour)
{
	DWORD fid = GetFrameType(pFrame);

	if (pSetCSimpleRegionVertexColour > 0)
	{
		if( fid == 19 || fid == 39 || fid == 64)
		{
			if( fid == 39)
			{
				pFrame = ReadRealMemory(pFrame + 0x134);
				}

				if (pFrame > 0)
				{
					return this_call(pSetCSimpleRegionVertexColour, pFrame,(DWORD) &colour);
				}
			}
		}

		return 0;
	}

	int SetCSimpleRegionVertexColourEx(DWORD pFrame, int alpha, int red, int blue, int green)
	{
		return SetCSimpleRegionVertexColour(pFrame, GetARGBColour(alpha, red, blue, green));
	}
