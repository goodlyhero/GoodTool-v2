#pragma once
#include <BasicConstants.h>

DWORD ConvertHandleId(jHANDLE handleid);
DWORD ConvertHandle(DWORD h);
DWORD HandleIdToObject(jHANDLE handleid);
jHANDLE ObjectToHandleId(int address);
DWORD GetJassVM(int id);
DWORD GetJassTable();
DWORD GetStringAddress(pString s);
DWORD GetString(pString s);


DWORD GetAgentType(jHANDLE h);
jHANDLE ObjectToAbility(DWORD pObject);
jHANDLE ObjectToUnit(DWORD pObject);
DWORD GetAgentBaseDataById(DWORD pAgentDataNode, DWORD agentId);
DWORD GetUnitAddressFloatsRelated(DWORD pConvertedHandle, DWORD step);
DWORD GetUnitAddress(jHANDLE u);
DWORD GetSomeAddress(DWORD pAddr1, DWORD pAddr2);
DWORD GetSomeAddressForAbility(DWORD pAddr1, DWORD pAddr2);
DWORD CountHandles();
void Nodesync();