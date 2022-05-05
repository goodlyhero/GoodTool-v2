#include <Functions.h>
#include <Calls.h>
#include <Additional Native Constants.h>
export module APITimerEx;

export float TimerExGetTimeElapsed(DWORD ptimer, DWORD id)
{
	if (ptimer == NULL) return 0;
	DWORD buffer = id;
	float* result = (float*)this_call(pGetExTimerTimeElapsed, ptimer, (DWORD) & (buffer));
	if (result == nullptr) return 0;
	return *result;
}

export float AnyTimerGetTimeElapsed(DWORD ptimer, DWORD id)
{
	if (ptimer == NULL) return 0;
	DWORD buffer = id;
	DWORD pVFtable = ReadRealMemory(ptimer);
	if (!pVFtable) return 0;
	DWORD pFunc = ReadRealMemory(pVFtable + 0x18);
	float* result = (float*)this_call(pFunc, ptimer, (DWORD) & (buffer));
	if (result == nullptr) return 0;
	return *result;
}