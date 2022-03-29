#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>
export module MemoryCNetData;
export DWORD GetEngineDataPointersWithId(DWORD id)
{
	return this_call(pGetEngineDataPointers, id);
}

export DWORD GetCNetData()
{
	DWORD d = GetEngineDataPointersWithId(0xd);
	if (d < 500) return 0;
	return ReadRealMemory(ReadRealMemory(d + 0x10)+0x8);
}

export DWORD GetIdleTurnIdFromSyncData(DWORD pNetData)
{
	if (pNetData < 500) return 0;
	return ReadRealMemory(pNetData + 0x1c68);
}

export DWORD GetTurnIdFromSyncData(DWORD pNetData)
{
	if (pNetData < 500) return 0;
	return ReadRealMemory(pNetData + 0x1c70);
}

export void SetGameSpeedMultiplier(DWORD pNetData,DWORD mult)
{
	WriteRealMemory(pNetData + 0x22b4, mult);
}
export void SetGameSpeedDivider(DWORD pNetData,DWORD mult)
{
	WriteRealMemory(pNetData + 0x22b8, mult);
}
export DWORD GetGameSpeedMultiplier(DWORD pNetData,DWORD mult)
{
	return ReadRealMemory(pNetData + 0x22b4);
}
export DWORD GetGameSpeedDivider(DWORD pNetData,DWORD mult)
{
	return ReadRealMemory(pNetData + 0x22b8);
}