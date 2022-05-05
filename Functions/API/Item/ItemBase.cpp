#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <CNatives.h>

int GetItemBaseDataById(int iid)
{
    if (iid > 0)
    {
        return GetAgentBaseDataById(pItemDataNode, iid);
    }   

    return 0;
}

int GetItemBaseData(jHANDLE Item)
{
    return GetItemBaseDataById(GetItemTypeId(Item));
}

int GetItemBaseDataByIdCaching(int iid)
{
    // DEF_ADR_ITEM_DATA = 4
    DWORD pItem = 0;

        if (iid > 0)
        {
            /*if (HaveSavedInteger(htObjectDataPointers, 4, iid))
            {
                return LoadInteger(htObjectDataPointers, 4, iid);
            }*/

            pItem = GetItemBaseDataById(iid);
            if (pItem > 0)
            {
                //SaveInteger(htObjectDataPointers, 4, iid, pItem);
            }

            return pItem;
        }

    return 0;
}

int GetItemBaseDataCaching(jHANDLE it)
{
    return GetItemBaseDataByIdCaching(GetItemTypeId(it));
}

int GetItemBaseTypeIdById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x14);
        }

    return 0;
}
//===========================================

int GetItemBaseTypeId(jHANDLE it)
{
    return GetItemBaseTypeIdById(GetItemTypeId(it));
}

int GetItemBaseGoldCostById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x20);
        }

    return 0;
}

int GetItemBaseGoldCost(jHANDLE it)
{
    return GetItemBaseGoldCostById(GetItemTypeId(it));
}

void SetItemBaseGoldCostById(int iid, int cost)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            WriteRealMemory(pData + 0x20, cost);
        }
}

void SetItemBaseGoldCost(jHANDLE it, int cost)
{
    SetItemBaseGoldCostById(GetItemTypeId(it), cost);
}

int GetItemBaseLumberCostById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x24);
        }

    return 0;
}

int GetItemBaseLumberCost(jHANDLE it)
{
    return GetItemBaseLumberCostById(GetItemTypeId(it));
}

void SetItemBaseLumberCostById(int iid, int cost)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            WriteRealMemory(pData + 0x24, cost);
        }
}

void SetItemBaseLumberCost(jHANDLE it, int cost)
{
    SetItemBaseLumberCostById(GetItemTypeId(it), cost);
}

int GetItemBaseLevelById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x38);
        }

    return 0;
}

int GetItemBaseLevel(jHANDLE it)
{
    return GetItemBaseLevelById(GetItemTypeId(it));
}

void SetItemBaseLevelById(int iid, int level)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            WriteRealMemory(pData + 0x38, level);
        }
}

void SetItemBaseLevel(jHANDLE it, int lvl)
{
    SetItemBaseLevelById(GetItemTypeId(it), lvl);
}

bool IsItemBaseSellableById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x50) > 1;
        }

    return false;
}

bool IsItemBaseSellable(jHANDLE it)
{
    return IsItemBaseSellableById(GetItemTypeId(it));
}

bool IsItemBasePawnableById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x54) > 1;
        }

    return false;
}

bool IsItemBasePawnable(jHANDLE it)
{
    return IsItemBasePawnableById(GetItemTypeId(it));
}

bool IsItemBaseDroppableById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x60) > 1;
        }

    return false;
}

bool IsItemBaseDroppable(jHANDLE it)
{
    return IsItemBaseDroppableById(GetItemTypeId(it));
}

bool IsItemBaseDroppedOnDeathById(int iid)
{
    DWORD pData = GetItemBaseDataById(iid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + 0x64) > 1;
        }

    return false;
}

bool IsItemBaseDroppedOnDeath(jHANDLE it)
{
    return IsItemBaseDroppedOnDeathById(GetItemTypeId(it));
}