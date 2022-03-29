#include <Windows.h>
#include <rcmp.hpp>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
bool iswidesceenenabled = false;
float CustomFovFix = 1.0f;
void EnableWidescreen(bool mode)
{
	if (iswidesceenenabled == mode) return;
	if (mode)
	{
		rcmp::hook_function<int (__fastcall*)(float*, int, float, float, float, float)>(pSetAreaFOV, [](auto original, float* matrix, int i, float minx, float miny, float maxx, float maxy)
			{
				float ScreenX = *(float*)WindowXoffset;
				float ScreenY = *(float*)WindowYoffset;

				float v1 = 1.0f / sqrt(miny * miny + 1.0f);
				float v2 = tan(v1 * minx * 0.5f);

				float v3 = v2 * maxx;
				float v4 = v3 * miny;


				matrix[0] = ((maxx * (4.0f / 3.0f)) / (ScreenX / ScreenY) * CustomFovFix) / v4; // Fix 4:3 to WindowX/WindowY
				matrix[1] = 0.0f;
				matrix[2] = 0.0f;
				matrix[3] = 0.0f;
				matrix[4] = 0.0f;

				matrix[5] = maxx / v3;
				matrix[6] = 0.0f;
				matrix[7] = 0.0f;
				matrix[8] = 0.0f;
				matrix[9] = 0.0f;

				matrix[10] = (maxx + maxy) / (maxy - maxx);
				matrix[11] = 1.0f;
				matrix[12] = 0.0f;
				matrix[13] = 0.0f;


				matrix[14] = maxx * (maxy * -2.0f) / (maxy - maxx);
				matrix[15] = 0.0f;


				return NULL;
			}
		);
	}
	else
	{

	}
}

void SetCustomFovFix(float fix)
{
	CustomFovFix = fix;
}

