#include <Functions.h>
#include <Warcraft Functions.h>
#include <Additional Native Constants.h>
#include <rcmp.hpp>
export module RenderHook;

bool WorldFrameRenderHooked = false;

namespace RenderHook
{

	const int minstage = 0;
	const int maxstage = 24;
	export int Skybox = 0;
	export int Terrain = 1;
	export int FogOfWar = 2;
	export int TerrainShadow = 3;
	export int WaterShadow = 4;
	export int Unknown1 = 5;
	export int Weather = 6;
	export int SelectionCircle = 7;
	export int Indicator = 8;
	export int Footprexport = 9;
	export int Decoration = 10;
	export int Unit = 11;
	export int Unknown2 = 12;
	export int Destructible = 13;
	export int Water = 14;
	export int SelectionBox = 15;
	export int Unknown3 = 16;
	export int OcclusionMask = 17;
	export int Building = 18;
	export int Ubersplat = 19;
	export int Lightning = 20;
	export int FloatingText = 21;
	export int CineFilter = 22;
	export int UI = 23;
	export int Unknown = 24;
	export int none = -1;

	integer renderstages[] = { true,true,true,true,true,true,true,true,true,true, true,true,true,true,true, true,true,true,true,true, true,true,true,true,true};


}

export void HookRender(bool mode)
{
	WorldFrameRenderHooked = mode;
	if (mode) {
		WorldFrameRenderHooked = mode;
		rcmp::hook_function<int(__thiscall*) (DWORD, DWORD, int, int, int)>(pRenderWorldObjects, [](auto original,DWORD pWorldFrame, DWORD stage, int LightPreset, int FogPreset, int binmenu)
			{
				if (WorldFrameRenderHooked)
				{
					if (stage >= RenderHook::minstage && stage <= RenderHook::maxstage && (RenderHook::renderstages[stage]))
					{
						return original(pWorldFrame, stage, LightPreset, FogPreset, binmenu);
					}
					return 0;
				}
				else return original(pWorldFrame,stage,LightPreset, FogPreset, binmenu);
			}
		);
	}
}

export void RenderStageEnable(DWORD stage, bool flag)
{
	if (stage >= RenderHook::minstage && stage <= RenderHook::maxstage)
	{
		RenderHook::renderstages[stage] = flag;
	}
}

export bool GetStageMode(DWORD stage)
{
	if (stage >= RenderHook::minstage && stage <= RenderHook::maxstage)
	{
		return RenderHook::renderstages[stage];
	}
	return false;
}