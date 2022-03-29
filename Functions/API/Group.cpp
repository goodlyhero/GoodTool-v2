#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <CNatives.h>

DWORD GetAddressGroupUnitCount(DWORD pObj)
{
    if (pObj > 0)
    {
        return ReadRealMemory(pObj + 0x34);
    }

    return 0;
}

DWORD GetAddressGroupAddressUnitByIndex(DWORD pObj, int index)
{
    if (pObj > 0)
    {
        return this_call(pGroupGetUnitByIndex, pObj + 0x24, index);
    }

    return 0;
}

DWORD GetGroupUnitCount(jHANDLE g)
{
    return GetAddressGroupUnitCount(ConvertHandle(g));
}

jHANDLE GetUnitFromGroupByIndex(jHANDLE g, int index)
{
    DWORD pObj = GetAddressGroupAddressUnitByIndex(ConvertHandle(g), index);

        if (pObj > 0)
        {
            pObj = ObjectToHandleId(pObj);

            if (pObj > 0)
            {
                return pObj;
            }
        }

    return NULL;
}

jHANDLE GetRandomUnitFromGroup(jHANDLE g)
{
    DWORD pObj = ConvertHandle(g);
    DWORD count = 0;

        if (pObj > 0)
        {
            count = GetAddressGroupUnitCount(pObj);
            if (count > 0)
            {
                pObj = GetAddressGroupAddressUnitByIndex(pObj, GetRandomInt(0, count - 1));

                if (pObj > 0)
                {
                    pObj = ObjectToHandleId(pObj);

                    if (pObj > 0)
                    {
                        return pObj;
                    }
                }
            }
        }

    return NULL;
}

jHANDLE ForEach(jHANDLE g)
{
    DWORD iGroupIterator = 0;
    DWORD pObj = GetAddressGroupAddressUnitByIndex(ConvertHandle(g), iGroupIterator);

        if (pObj > 0)
        {
            iGroupIterator = iGroupIterator + 1;
            pObj = ObjectToHandleId(pObj);

            if (pObj > 0)
            {
                return pObj;
            }
        }
        else
        {
            iGroupIterator = 0;
        }

    return NULL;
}