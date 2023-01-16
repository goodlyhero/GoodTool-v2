#include <Functions.h>
#include <Warcraft Functions.h>
#include <Additional Native Constants.h>
#include <rcmp.hpp>
export module HookOnTick;
import EVENTS;
import EVENT_ON_TICK;

bool OnTickHooked = false;
bool OnTickHookedEx = false;
bool OnTickHookInit = false;
bool OnTickHookExInit = false;


export void HookOnTick(bool mode)
{
	OnTickHooked = mode;
	if (mode) {
		if (OnTickHookInit) return;
		OnTickHookInit = true;
		rcmp::hook_function<int(__thiscall*) (DWORD, DWORD)>(pOnTick, [](auto original,DWORD pNetData, DWORD Unk)
			{
				if (OnTickHooked && EVENT_ON_TICK.IsActive())
				{
					EVENT_ON_TICK.SendEvent(std::make_shared<EventDataOnTick>((int)pNetData));
				}
				return original(pNetData,Unk);
			}
		);
	}
}

void OnTickExEventRun(void* pNetData) {
	if (OnTickHookedEx && EVENT_ON_TICK.IsActive())
	{
		EVENT_ON_TICK.SendEvent(std::make_shared<EventDataOnTick>((int)pNetData));
	}
}

void __declspec(naked) __cdecl OnTickEx()
{
	__asm MOV        ECX, EBX;
	__asm SUB        EDI, 0x1;


	__asm push EBP;
	__asm push ECX;
	__asm push EDX;
	__asm push EAX;
	__asm push EBX;
	__asm mov EBP, ESP;
	{
		void* pCNetData;
		__asm mov ecx, [esp + 0x14 + 0x8];
		__asm mov pCNetData, ecx;
		if(OnTickHookedEx) OnTickExEventRun(pCNetData);
	}
	__asm pop EBX;
	__asm pop EAX;
	__asm pop EDX;
	__asm pop ECX;
	__asm pop EBP;
	__asm
	{
		jmp pExtendedTickHookRet;
	}
}

export void HookOnTickEx(bool mode) {
	OnTickHookedEx = mode;
	if (mode) {

		if (OnTickHookExInit) return;

		OnTickHookExInit = true;
		PlantDetourJMP((BYTE*)(pExtendedTickHook), (BYTE*)OnTickEx,5);
		/*rcmp::hook_function<int(__thiscall*) (DWORD, DWORD)>(pOnTick, [](auto original, DWORD pNetData, DWORD Unk)
			{
				if (EVENT_ON_TICK.IsActive())
				{
					EVENT_ON_TICK.SendEvent(std::make_shared<EventDataOnTick>((int)pNetData));
				}
				return original(pNetData, Unk);
			}
		);*/
	}
}