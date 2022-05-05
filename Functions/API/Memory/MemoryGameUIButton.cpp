#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <API/Memory/MemoryGameUI.h>
#include <Logs/Log.h>
#include <API/Memory/FrameTypeHT.h>

bool IsCommandButton(DWORD pButton)
{
    return GetFrameType(pButton) == 4;
}

DWORD GetButtonData(DWORD pCommandButton)
{
    if (IsCommandButton(pCommandButton))
    {
        return ReadRealMemory(pCommandButton + 0x190);
    }

    return 0;
}

DWORD GetButtonGoldCost(DWORD pCommandButton)
{
    DWORD pButton = GetButtonData(pCommandButton);

        if (pButton > 0)
        {
            return ReadRealMemory(pButton + 0x58C);
        }

    return 0;
}

DWORD GetButtonLumberCost(DWORD pCommandButton)
{
    DWORD pButton = GetButtonData(pCommandButton);

        if( pButton > 0)
        {
            return ReadRealMemory(pButton + 0x590);
        }

    return 0;
}

DWORD GetButtonManaCost(DWORD pCommandButton)
{
    DWORD pButton = GetButtonData(pCommandButton);

        if( pButton > 0)
        {
            return ReadRealMemory(pButton + 0x594);
        }

    return 0;
}

float GetButtonCooldown(int pCommandButton)
{
    DWORD pAbil = 0;
    char* pAbilId = 0;
    char* pOrderId = 0;
    DWORD goldcost = 0;
    DWORD pAbilVal2 = 0;
    DWORD pButton = 0;
    float prAbilVal1 = 0.;
    float prAbilVal2 = 0.;

        if (IsCommandButton(pCommandButton))
        {
            pButton = ReadRealMemory(pCommandButton + 0x190);

            if (pButton > 0)
            {
                pAbil = ReadRealMemory(pButton + 0x6D4);
                pAbilId = (char*)ReadRealMemory(pButton + 0x4);
                pOrderId = (char*)ReadRealMemory(pButton + 0x8);
                goldcost = ReadRealMemory(pButton + 0x58C);

                //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "pButton = " + IntToHex( pButton ) )
                //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "pButton + 0x6D4 = " + IntToHex( pAbil ) )

                if ((pAbil > 0) && !strcmp(pAbilId,"AHer") && !strcmp(pAbilId, "Amai")&& !strcmp(pAbilId, "Asei")&& !strcmp(pAbilId, "Asel"))
                { //  && goldcost == 0
                    pAbil = ReadRealMemory(pAbil + 0xDC);
                    //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "pAbil + 0xDC = " + IntToHex( pAbil ) )

                    if (pAbil > 0)
                    {
                        pAbilVal2 = ReadRealMemory(pAbil + 0x0C);
                        //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "ReadRealMemory( pAbil + 0x0C ) = " + IntToHex( pAbilVal2 ) )

                        if (pAbilVal2 > 0)
                        {
                            prAbilVal1 = GetRealFromMemory(ReadRealMemory(pAbil + 0x04));
                            prAbilVal2 = GetRealFromMemory(ReadRealMemory(pAbilVal2 + 0x40));

                            //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "prAbilVal1 = " + R2S( pAbilVal2 ) )
                            //call DisplayTextToPlayer( GetLocalPlayer( ), 0, 0, "prAbilVal2 = " + R2S( pAbilVal2 ) )
                            return prAbilVal1 - prAbilVal2;
                        }
                    }
                }
            }
        }

    return 0.;
}

bool IsButtonOnCooldown(int pCommandButton)
{
    return GetButtonCooldown(pCommandButton) > 0;
}

void AddFrameType(const char* name, DWORD vtype, DWORD pVtable, DWORD pVTableObj)
{
    //mlog::Debug("Initializing Frame with name: ",name);
    if (pVtable != NULL)
    {
        MemHackTable_FrameVT[pGameDLL + pVtable] = vtype;
        //mlog::Debug("First adress: ", pGameDLL + pVtable, " type: ", MemHackTable_FrameVT[pGameDLL + pVtable]);
        MemHackTable_FrameVT_name[pGameDLL + pVtable] = name;
    }
    if (pVTableObj != NULL)
    {
        MemHackTable_FrameVT[pGameDLL + pVTableObj] = vtype;

        //mlog::Debug("Second adress: ", pGameDLL + pVTableObj, " type: ",MemHackTable_FrameVT[pGameDLL + pVTableObj]);
        MemHackTable_FrameVT_name[pGameDLL + pVTableObj] = name;
    }
   //mlog::Debug("Frame type initialized: ", std::to_string(pGameDLL + pVtable), " ", pGameDLL + pVTableObj, " with type: ", name);
}
