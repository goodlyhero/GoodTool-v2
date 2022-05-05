#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <CNatives.h>
#include <Calls.h>

int GetUnitAbilityReal(int pUnit, int aid, int unk1, int unk2, int unk3, int unk4)
{
    if (pUnit > 0 && aid > 0)
    {
        return this_call(pGetUnitAbility, pUnit, aid, unk1, unk2, unk3, unk4);
    }

    return 0;
}

int GetUnitAbilityData(jHANDLE u, int aid, int flag)
{
    DWORD pUnit;

        if (u != NULL && aid > 0)
        {
            pUnit = ConvertHandle(u);

            if (pUnit > 0)
            {
                return GetUnitAbilityReal(pUnit, aid, 0, flag, 1, 1);
            }
        }

    return 0;
}

int GetUnitAbility(jHANDLE u, int aid)
{
    if (GetUnitAbilityLevel(u, aid) > 0)
    {
        return GetUnitAbilityData(u, aid, 1);
    }

    return 0;
}

int GetUnitAbilityBase(jHANDLE u, int aid)
{
    return GetUnitAbilityData(u, aid, 0);
}

int GetUnitAbilityOrderId(jHANDLE u, int aid)
{
    return GetAddressAbilityOrderId(GetUnitAbility(u, aid));
}

bool IsUnitAbilityOnCooldown(jHANDLE u, int aid)
{
    return IsAddressAbilityOnCooldown(GetUnitAbility(u, aid));
}

bool IsUnitAbilitySafe(jHANDLE u, int aid)
{
    return IsAddressAbilitySafe(GetUnitAbility(u, aid));
}

bool IsUnitAbilityUsable(jHANDLE u, int aid)
{
    return IsAddressAbilityUsable(GetUnitAbility(u, aid));
}

float GetUnitAbilityCastpoint(jHANDLE u, int aid)
{
    return GetAddressAbilityCastpoint(GetUnitAbility(u, aid));
}

void SetUnitAbilityCastpoint(jHANDLE u, int aid, float dur)
{
    SetAddressAbilityCastpoint(GetUnitAbility(u, aid), dur);
}

float GetUnitAbilityBackswing(jHANDLE u, int aid)
{
    return GetAddressAbilityBackswing(GetUnitAbility(u, aid));
}

void SetUnitAbilityBackswing(jHANDLE u, int aid, float dur)
{
    SetAddressAbilityBackswing(GetUnitAbility(u, aid), dur);
}

int GetUnitAbilityManaCost(jHANDLE u, int aid, int level)
{
    return GetAddressAbilityManaCost(GetUnitAbility(u, aid), level);
}

void SetUnitAbilityManaCost(jHANDLE u, int aid, int level, int mc)
{
    SetAddressAbilityManaCost(GetUnitAbility(u, aid), level, mc);
}

float GetUnitAbilityCooldownStamp(jHANDLE u, int aid)
{
    //This actually returns the timestamp, not the cooldown. To get the real cooldown you need to subtract this from the current game time.
    return GetAddressAbilityCooldownStamp(GetUnitAbility(u, aid));
}

float GetUnitAbilityCurrentCooldown(jHANDLE u, int aid)
{
    //This value holds the base cooldown of the ability at the last time it was casted. It�s used to calculate the % of elapsed cooldown.
    //This is completely irrelevant for the gameplay, it�s used only to determine which frame of the cooldown model will be displayed.
    return GetAddressAbilityCurrentCooldown(GetUnitAbility(u, aid));
}

void SetUnitAbilityCooldown(jHANDLE u, int aid, float seconds, int mode)
{
    SetAddressAbilityCooldown(GetUnitAbility(u, aid), seconds, mode);
}

void AddUnitAbilityCooldown(jHANDLE u, int aid, float seconds)
{
    SetUnitAbilityCooldown(u, aid, seconds, cool_mode_minus);
}

void ReduceUnitAbilityCooldown(jHANDLE u, int aid, float seconds)
{
    SetUnitAbilityCooldown(u, aid, seconds, cool_mode_plus);
}

void ResetUnitAbilityCooldown(jHANDLE u, int aid)
{
    SetUnitAbilityCooldown(u, aid, -1., cool_mode_equal);
}

void StartUnitAbilityCooldown(jHANDLE u, int aid, float cd)
{
    StartAddressAbilityCooldown(GetUnitAbility(u, aid), cd);
}

float GetUnitAbilityCastTime(jHANDLE u, int aid)
{
    return GetAddressAbilityCastTime(GetUnitAbility(u, aid));
}

void SetUnitAbilityCastTime(jHANDLE u, int aid, float r)
{
    SetAddressAbilityCastTime(GetUnitAbility(u, aid), r);
}

void SetUnitAbilityDisabled(jHANDLE u, int aid, int count)
{
    // not safe unless used with PauseUnit. Button will be blacked, but current casts of that ability won�t be interrupted.
    SetAddressAbilityDisabled(GetUnitAbility(u, aid), count);
}

int GetUnitAbilityDisabled(jHANDLE u, int aid)
{
    return GetAddressAbilityDisabled(GetUnitAbility(u, aid));
}

void SetUnitAbilityHidden(jHANDLE u, int aid, int count)
{
    // This one is 100% safe. This hides the ability button, && order can�t be issued.
    SetAddressAbilityHidden(GetUnitAbility(u, aid), count); // -1 = unhide | 1 = hide;
}

void AddUnitAbilityHidden(jHANDLE u, int aid, int count)
{
    AddAddressAbilityHidden(GetUnitAbility(u, aid), count);
}

int GetUnitAbilityDisabledEx(jHANDLE u, int aid)
{
    // This one is used by Orb of Slow. Button is blacked, but cooldown is stil displayed.
    return GetAddressAbilityDisabledEx(GetUnitAbility(u, aid));
}

void SetUnitAbilityDisabledEx(jHANDLE u, int aid, int count)
{
    // This one is used by Orb of Slow. Button is blacked, but cooldown is stil displayed.
    SetAddressAbilityDisabledEx(GetUnitAbility(u, aid), count); // -1 = unhide | 1 = hide;
}

void SilenceUnitAbility(jHANDLE u, int aid)
{
    SilenceAddressAbility(GetUnitAbility(u, aid));
}

void UnsilenceUnitAbility(jHANDLE u, int aid)
{
    UnsilenceAddressAbility(GetUnitAbility(u, aid));
}

void ShowUnitAbility(jHANDLE u, int aid, bool flag)
{
    ShowAddressAbility(GetUnitAbility(u, aid), flag);
}
