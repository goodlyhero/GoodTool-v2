#include <BasicConstants.h>
#include <Functions.h>
#include <Calls.h>
#include <Jass Natives.h>
#include <Additional Native Constants.h>
#include <Extern Natives.h>



DWORD GetRealPlayerById(int i)
{
    DWORD pladdr = ReadRealMemory(pGlobalPlayerClass);

        if (pladdr > 0)
        {
            return ReadRealMemory(pladdr + (i * 4) + 0x58);
        }

    return 0;
}

DWORD GetLocalPlayerIdReal(void)
{
    DWORD pladdr = ReadRealMemory(pGlobalPlayerClass);

        if (pladdr > 0)
        {
            return ReadRealMemory(pladdr + 0xA);
        }

    return -1;
}

DWORD GetLocalPlayerReal(void)
{
    return GetRealPlayerById(GetLocalPlayerIdReal());
}

DWORD GetPlayerSelectedUnitReal(DWORD realplayer)
{
    DWORD pladdr = ReadRealMemory(realplayer + 0x34);

        if (pladdr > 0)
        {
            return ReadRealMemory(pladdr + 0x1E0);
        }

    return 0;
}

DWORD GetLocalSelectedRealUnit()
{
    return GetPlayerSelectedUnitReal(GetRealPlayerById(jGetPlayerId(jGetLocalPlayer())));
}