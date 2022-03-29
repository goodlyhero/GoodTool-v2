#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <CNatives.h>
#include <Logs/Log.h>
DWORD ConvertHandleId(jHANDLE handleid)
{
    if (handleid > 0)
    {
        DWORD maxid = (ReadRealMemory(ReadRealMemory(pGameState) + 0x1C) + 0x198);
        if ((maxid*0xC+0x2FFFFF*4)<handleid) return 0;
        return ReadRealMemory(ReadRealMemory(ReadRealMemory(ReadRealMemory(pGameState) + 0x1C) + 0x19C) + handleid * 0xC - 0x2FFFFF * 4);
    }

    return 0;
}

DWORD CountHandles()
{
    return (ReadRealMemory(ReadRealMemory(pGameState) + 0x1C) + 0x198);
}

DWORD ConvertHandle(DWORD h)
{
    return ConvertHandleId(h);
}

DWORD HandleIdToObject(jHANDLE handleid)
{
    int pData = this_call(pGetHandleId, ReadRealMemory(pGameState));

        if (pData > 0)
        {
            return this_call(pHandleIdToObject, pData, handleid);
        }

    return 0;
}
jHANDLE ObjectToHandleId(int address)
{
    int pData = this_call(pGetHandleId, ReadRealMemory(pGameState));

        if (pData > 0)
        {
            return this_call(pObjectToHandleId, pData, address, 0);
        }

    return 0;
}

DWORD GetJassVM(int id)
{
    int JassVM = 0;
    if (pJassEnvAddress > 0) {
        if (JassVM <= 0) {
            JassVM = ReadRealMemory(ReadRealMemory(ReadRealMemory(ReadRealMemory(pJassEnvAddress) + 0x14) + 0x90) + 0x4 * id);
        }
    }

    return JassVM;
}

DWORD GetJassTable()
{
    integer jvm = GetJassVM(1);

    if (jvm > 0) {
        return ReadRealMemory(ReadRealMemory(ReadRealMemory(jvm + 0x28A4)) + 0x19C);
    }

    return 0;
}

DWORD GetStringAddress(pString s)
{
    int jvm = GetJassVM(1);

    if (jvm > 0)
        return ReadRealMemory(ReadRealMemory(ReadRealMemory(ReadRealMemory(jvm + 0x2874) + 0x8) + s * 0x10 + 0x8) + 0x1C);

    return 0;
}

DWORD GetString(pString s)
{
    int jvm = GetJassVM(1);

    if (jvm > 0)
        return ReadRealMemory(ReadRealMemory(jvm + 0x2874) + 0x8) + s * 0x10;

    return 0;
}

DWORD GetAgentType(jHANDLE h)
{
    // returns code of the handle"s type
    // +w3u for unit, +tmr for timer, +trg for trigger, +arg for region, etc...

    DWORD func = ReadRealMemory(ReadRealMemory(ConvertHandle(h)) + 0x1C);
    return ReadRealMemory(func) / 0x100 + ReadRealMemory(func + 0x4) * 0x1000000;
}

jHANDLE ObjectToAbility(DWORD pObject)
{
    DWORD pAbil = 0;

        if (pObject > 0)
        {
            pAbil = ObjectToHandleId(pObject);

            if (pAbil > 0)
            {
                return pAbil;
            }
        }

    return NULL;
}

jHANDLE ObjectToUnit(DWORD pObject)
{
    DWORD pUnit = 0;
        if (pObject > 0)
        {
            pUnit = fast_call(pToJUnit, pObject);

            if (pUnit > 0)
            {
                return pUnit;
            }
        }

    return NULL;
}

DWORD GetAgentBaseDataById(DWORD pAgentDataNode, DWORD agentId)
{
    DWORD pData = 0;

        if (agentId > 0)
        {
            pData = this_call(pGetDataNode, (DWORD)&agentId);

            if (pData != 0)
            {
                return this_call(pGetAgentBaseData, pAgentDataNode, pData, (DWORD)&agentId);
            }
        }

    return 0;
}

DWORD GetUnitAddressFloatsRelated(DWORD pConvertedHandle, DWORD step)
{
    DWORD pOffset1 = pConvertedHandle + step;
    DWORD pOffset2;

        if (pConvertedHandle > 0)
        {
            pOffset2 = ReadRealMemory(pGameClass1);
            pOffset1 = ReadRealMemory(pOffset1);
            pOffset2 = ReadRealMemory(pOffset2 + 0xC);
            pOffset2 = ReadRealMemory((pOffset1 * 0x8) + pOffset2 + 0x4);
            return pOffset2;
        }

    return 0;
}

DWORD GetUnitAddress(jHANDLE u)
{
    return this_call(pGetUnitAddress, GetHandleId(u));
}


DWORD GetSomeAddress(DWORD pAddr1, DWORD pAddr2)
{
    DWORD pOff1 = 0x2C;

        if (BitwiseAnd(pAddr1, pAddr2) == -1)
        {
            return 0;
        }

    if (pAddr1 >= 0)
    {
        pOff1 = 0xC;
    }

    pOff1 = ReadRealMemory(pGameClass1) + pOff1;
    pOff1 = ReadRealMemory(pOff1);

    if (pOff1 == 0)
    {
        return 0;
    }
   // mlog::Debug("Reading offset: ", IntToHex(pOff1 + 8 * pAddr1 + 0x4));
    pOff1 = ReadRealMemory(pOff1 + 8 * pAddr1 + 0x4);

    if (pOff1 == 0 || ReadRealMemory(pOff1 + 0x18) != pAddr2)
    {
                return 0;
    }

    return pOff1;
}

DWORD GetSomeAddressForAbility(DWORD pAddr1, DWORD pAddr2)
{
    DWORD pOff1 = GetSomeAddress(pAddr1, pAddr2);

        if (pOff1 == 0 || ReadRealMemory(pOff1 + 0x20) != 0)
        {
            return 0;
        }

    return ReadRealMemory(pOff1 + 0x54);
}

void Nodesync()
{
    WriteRealMemory(dwGameDll + 0x551808, 0xD28513EB);
}

