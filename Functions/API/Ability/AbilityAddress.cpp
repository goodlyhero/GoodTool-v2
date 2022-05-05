#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>

int GetAbilityBaseDataByAddress(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return ReadRealMemory(pAbil + 0x54);
    }

    return 0;
}

int GetAddressAbilityTypeId(DWORD pAbil)
{
    DWORD base = 0;

    if (pAbil > 0)
    {
        ReadRealMemory(pAbil + 0x34);
    }

    return 0;
}

int GetAddressAbilityBaseId(DWORD pAbil)
{
    DWORD base = 0;

    if (pAbil > 0)
    {
        base = GetAbilityBaseDataByAddress(pAbil);

        if ((base > 0) && ReadRealMemory(pAbil + 0x6C) > 0)
        {
            return ReadRealMemory(base + 0x30);
        }
    }

    return 0;
}

int GetAddressAbilityOrderId(DWORD pAbil)
{
    DWORD pOffset2 = 0;
    DWORD base = 0;

    if (pAbil > 0)
    {
        base = GetAbilityBaseDataByAddress(pAbil);

        if (base > 0)
        {
            base = ReadRealMemory(base + 0x30);

            if (base > 0)
            {
                if (strcmp((char*)base, "ANcl"))
                {
                    return ReadRealMemory(pAbil + 0x124);
                }
                else
                {
                    return cdecl_call(ReadRealMemory(ReadRealMemory(pAbil) + 0x308), 0);
                }
            }
        }
    }

    return 0;
}

bool IsAddressAbilityOnCooldown(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return IsFlagBitSet(ReadRealMemory(pAbil + 0x20), 512);
    }

    return false;
}

bool IsAddressAbilitySafe(DWORD pAbil)
{
    DWORD base = GetAddressAbilityBaseId(pAbil);
    DWORD order = 0;

    if (base > 0)
    {
        if (strcmp((char*)base, "ANcl"))
        {
            order = ReadRealMemory(pAbil + 0x124);
        }
        else
        {
            order = GetAddressAbilityOrderId(pAbil);
        }

        if ((strcmp((char*)base, "AOre")) || (strcmp((char*)base, "Aexh")))
        {
            return true;
        }

        return ((order > 0) && (!strcmp((char*)base, "ANeg")));
    }

    return false;
}

bool IsAddressAbilityUsable(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return this_call(ReadRealMemory(ReadRealMemory(pAbil) + 0x1D8), pAbil) == 1 || (ReadRealMemory(pAbil + 0x6C) != 0 && strcmp((char*)GetAddressAbilityBaseId(pAbil), "ANcl"));
    }

    return false;
}

float GetAddressAbilityCastpoint(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pAbil + 0x8C));
    }

    return 0.;
}

void SetAddressAbilityCastpoint(DWORD pAbil, float dur)
{
    if (pAbil > 0)
    {
        WriteRealMemory(pAbil + 0x8C, SetRealIntoMemory(dur));
    }
}

float GetAddressAbilityBackswing(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pAbil + 0x94));
    }

    return 0.;
}

void SetAddressAbilityBackswing(DWORD pAbil, float dur)
{
    if (pAbil > 0)
    {
        WriteRealMemory(pAbil + 0x94, SetRealIntoMemory(dur));
    }
}

int GetAddressAbilityManaCost(DWORD pAbil, int level)
{
    if (pAbil > 0)
    {
        pAbil = GetAbilityBaseDataByAddress(pAbil);

        if (pAbil > 0)
        {
            return ReadRealMemory(pAbil + level * 0x68);
        }
    }

    return 0;
}

void SetAddressAbilityManaCost(DWORD pAbil, int level, int mc)
{
    if (pAbil > 0)
    {
        pAbil = GetAbilityBaseDataByAddress(pAbil);

        if (pAbil > 0)
        {
            WriteRealMemory(pAbil + level * 0x68, mc);
        }
    }
}

float GetAddressAbilityCooldownStamp(DWORD pAbil)
{
    if (pAbil > 0)
    {
        pAbil = ReadRealMemory(pAbil + 0xDC);

        if (pAbil > 0)
        {
            return GetRealFromMemory(ReadRealMemory(pAbil + 0x4));
        }
    }

    return 0.;
}

float GetAddressAbilityCurrentCooldown(DWORD pAbil)
{
    float cd = 0.;

    if (pAbil > 0)
    {
        pAbil = ReadRealMemory(pAbil + 0xDC);

        if (pAbil > 0)
        {
            cd = GetRealFromMemory(ReadRealMemory(pAbil + 0x4));
            pAbil = ReadRealMemory(pAbil + 0xC);

            if (pAbil > 0)
            {
                pAbil = ReadRealMemory(pAbil + 0x40);

                if (pAbil > 0)
                {
                    return cd - GetRealFromMemory(pAbil);
                }
            }
        }
    }

    return .0;
}
#define cool_mode_plus 0
#define cool_mode_minus 1
#define cool_mode_equal 2
void SetAddressAbilityCooldown(DWORD pAbil, float seconds, int mode)
{
    float cd = 0.;

    if (pAbil > 0)
    {
        pAbil = ReadRealMemory(pAbil + 0xDC);

        if (pAbil > 0)
        {
            cd = GetRealFromMemory(ReadRealMemory(pAbil + 0x4));
            if (mode == cool_mode_plus)
            {
                seconds = cd + seconds;
            }
            else
            {
                if (mode == cool_mode_minus)
                {
                    seconds = cd - seconds;
                }

                //call WriteRealMemory( ReadRealMemory( ConvertHandle( a ) + 0xB4 ), SetRealIntoMemory( seconds ) )
                WriteRealMemory(pAbil + 4, SetRealIntoMemory(seconds));
            }
        }
    }
}

bool StartAddressAbilityCooldown(DWORD pAbil, float cd)
{
    if (IsAddressAbilitySafe(pAbil))
    {
        if (pAbil > 0)
        {
            this_call(pStartAbilityCD, pAbil, (DWORD)&cd);
            return IsAddressAbilityOnCooldown(pAbil);
        }
    }

    return false;
}

float GetAddressAbilityCastTime(DWORD pAbil)
{
    if (pAbil > 0)
    {
        pAbil = ReadRealMemory(pAbil + 0x84);

        if (pAbil > 0)
        {
            return GetRealFromMemory(ReadRealMemory(pAbil));
        }
    }

    return 0.;
}

void SetAddressAbilityCastTime(DWORD pAbil, float r)
{
    if (pAbil > 0)
    {
        pAbil = ReadRealMemory(pAbil + 0x84);

        if (pAbil > 0)
        {
            WriteRealMemory(pAbil, SetRealIntoMemory(r));
        }
    }
}

void SetAddressAbilityDisabled(DWORD pAbil, int count)
{
    if (pAbil > 0)
    {
        WriteRealMemory(pAbil + 0x3C, count);
    }
}

int GetAddressAbilityDisabled(DWORD pAbil)
{
    return ReadRealMemory(pAbil + 0x3C);
}

void SetAddressAbilityHidden(DWORD pAbil, int count)
{
    if (pAbil > 0)
    {
        WriteRealMemory(pAbil + 0x40, count);
    }
}

void AddAddressAbilityHidden(DWORD pAbil, int d)
{
    WriteRealMemory(pAbil + 0x40, ReadRealMemory(pAbil + 0x40) + d);
}

int GetAddressAbilityDisabledEx(DWORD pAbil)
{
    if (pAbil > 0)
    {
        return ReadRealMemory(pAbil + 0x44);
    }

    return 0;
}

void SetAddressAbilityDisabledEx(DWORD pAbil, int count)
{
    if (pAbil > 0)
    {
        WriteRealMemory(pAbil + 0x44, count);
    }
}

void ShowAddressAbility(DWORD pAbil, bool flag)
{
    if (pAbil > 0)
    {
        if (ReadRealMemory(pAbil) > 0)
        {
            WriteRealMemory(pAbil + 0x40, not flag);
        }
    }
}

void SilenceAddressAbility(DWORD pAbil)
{
    if (pAbil > 0)
    {
        this_call(pSilenceAbility, pAbil, 0, 1);
    }
}

void UnsilenceAddressAbility(DWORD pAbil)
{
    if (pAbil > 0)
    {
        this_call(pUnsilenceAbility, pAbil, 0, 1);
    }
}

int GetAddressAbilityOwner(DWORD pAbil)
{
    if (pAbil == NULL) return 0;
    return ReadRealMemory(pAbil + 0x30);
}