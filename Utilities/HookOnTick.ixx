#include <Functions.h>
#include <Warcraft Functions.h>
#include <Additional Native Constants.h>
#include <rcmp.hpp>
export module HookOnTick;
import EVENTS;
import EVENT_ON_TICK;

bool OnTickHooked = false;

export void HookOnTick(bool mode)
{
	if (mode) {
		OnTickHooked = mode;
		rcmp::hook_function<int(__thiscall*) (DWORD, DWORD)>(pOnTick, [](auto original,DWORD pNetData, DWORD Unk)
			{
				if (EVENT_ON_TICK.IsActive())
				{
					EVENT_ON_TICK.SendEvent(std::make_shared<EventDataOnTick>((int)pNetData));
				}
				return original(pNetData,Unk);
			}
		);
	}
}
