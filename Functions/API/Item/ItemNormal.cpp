#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Memory/MemoryObjectData.h>
#include <API/Memory/MemoryGameData.h>

void StartAddressItemCooldown(int pUnit, int pItem, float cd)
{
    DWORD pInv = 0;

        if (pUnit > 0 && pItem > 0)
        {
            pInv = ReadRealMemory(pUnit + 0x1F8);

            if (pInv > 0)
            {
                this_call(pStartItemCD, pInv, pItem, (DWORD)&cd, (DWORD)&cd);
            }
        }
}

void SetAddressItemIdType(int pItem, int id)
{
    DWORD oldId = 0;

        if (pItem > 0)
        {
            oldId = ReadRealMemory(pItem + 0x30);

            if (oldId > 0)
            {
                WriteRealMemory(pItem + 0x30, id);
            }
        }
}

void SetAddressItemModel(int pItem, const char* model)
{
    SetObjectModel(pItem, model);
}

float GetAddressItemLife(int pItem)
{
    if (pItem > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pItem + 0x58));
    }

    return 0.;
}

void SetAddressItemLife(int pItem, float life)
{
    if (pItem > 0)
    {
        WriteRealMemory(pItem + 0x58, SetRealIntoMemory(life));
    }
}

float GetAddressItemMaxLife(int pItem)
{
    if (pItem > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pItem + 0x60));
    }

    return 0.;
}

void SetAddressItemMaxLife(int pItem, float life)
{
    if (pItem > 0)
    {
        WriteRealMemory(pItem + 0x60, SetRealIntoMemory(life));
    }
}

void StartItemCooldown(jHANDLE u, jHANDLE it, float cd)
{
    StartAddressItemCooldown(ConvertHandle(u), ConvertHandle(it), cd);
}

void SetItemIdType(jHANDLE it, int id)
{
    SetAddressItemIdType(ConvertHandle(it), id);
}

void SetItemModel(jHANDLE it, const char* model)
{
    SetAddressItemModel(ConvertHandle(it), model);
}

float GetItemLife(jHANDLE it)
{
    return GetAddressItemLife(ConvertHandle(it));
}

void SetItemLife(jHANDLE it, float life)
{
    SetAddressItemLife(ConvertHandle(it), life);
}

float GetItemMaxLife(jHANDLE it)
{
    return GetAddressItemMaxLife(ConvertHandle(it));
}

void SetItemMaxLife(jHANDLE it, float life)
{
    SetAddressItemMaxLife(ConvertHandle(it), life);
}