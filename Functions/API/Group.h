#pragma once
#include <BasicConstants.h>

DWORD GetAddressGroupUnitCount(DWORD pObj);
DWORD GetAddressGroupAddressUnitByIndex(DWORD pObj, int index);
DWORD GetGroupUnitCount(jHANDLE g);
jHANDLE GetUnitFromGroupByIndex(jHANDLE g, int index);
jHANDLE GetRandomUnitFromGroup(jHANDLE g);
jHANDLE ForEach(jHANDLE g);