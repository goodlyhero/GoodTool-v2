#include <lua/LuaEngine.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include "Memory/MemoryGameData.h"
#include "Ability/AbilityAddress.h"
export module APIIterators;

export DWORD GetUnitAbilityData(DWORD punit)
{
	DWORD pAddr1 = punit + 476;
	DWORD pAddr2 = punit + 480;
	if (pAddr1 == NULL or pAddr2 == NULL or pAddr1 && pAddr2 == 0xFFFFFFFF) return 0;
	//mlog::Debug("Reading offset: ", IntToHex(pAddr1), " ", IntToHex(pAddr1));
	return GetSomeAddressForAbility(ReadRealMemory(pAddr1), ReadRealMemory(pAddr2));
}

export DWORD GetCurrAbilityData(DWORD curr, DWORD& id)
{
	if (curr == NULL)
	{
		id = NULL;
		return NULL;
	}
	id = GetAddressAbilityTypeId(curr);
	return GetSomeAddressForAbility(ReadRealMemory(curr + 36), ReadRealMemory(curr + 40));
}

