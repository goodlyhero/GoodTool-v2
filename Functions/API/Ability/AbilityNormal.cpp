#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <Calls.h>

int GetAbilityBaseUI(jHANDLE abil)
{
    return GetAbilityBaseUIById(GetAddressAbilityTypeId(ConvertHandle(abil)));
}

int GetAbilityBaseId(jHANDLE a)
{
    return GetAddressAbilityBaseId(ConvertHandle(a));
}

int GetAbilityOrderId(jHANDLE a)
{
    return GetAddressAbilityOrderId(ConvertHandle(a));
}

bool IsAbilityOnCooldown(jHANDLE a)
{
    return IsAddressAbilityOnCooldown(ConvertHandle(a));
}

bool IsAbilitySafe(jHANDLE a)
{
    return IsAddressAbilitySafe(ConvertHandle(a));
}

bool IsAbilityUsable(jHANDLE a)
{
    return IsAddressAbilityUsable(ConvertHandle(a));
}

float GetAbilityCastpoint(jHANDLE a)
{
    return GetAddressAbilityCastpoint(ConvertHandle(a));
}

void SetAbilityCastpoint(jHANDLE a, float dur)
{
    SetAddressAbilityCastpoint(ConvertHandle(a), dur);
}

float GetAbilityBackswing(jHANDLE a)
{
    return GetAddressAbilityBackswing(ConvertHandle(a));
}

void SetAbilityBackswing(jHANDLE a, float dur)
{
    SetAddressAbilityBackswing(ConvertHandle(a), dur);
}

int GetAbilityManaCost(jHANDLE a, int level)
{
    return GetAddressAbilityManaCost(ConvertHandle(a), level);
}

void SetAbilityManaCost(jHANDLE a, int level, int mc)
{
    SetAddressAbilityManaCost(ConvertHandle(a), level, mc);
}

float GetAbilityCooldownStamp(jHANDLE a)
{
    //This actually returns the timestamp, not the cooldown. To get the real cooldown you need to subtract this from the current game time.
    return GetAddressAbilityCooldownStamp(ConvertHandle(a));
}

float GetAbilityCurrentCooldown(jHANDLE a)
{
    //This value holds the base cooldown of the ability at the last time it was casted. It’s used to calculate the % of elapsed cooldown.
    //This is completely irrelevant for the gameplay, it’s used only to determine which frame of the cooldown model will be displayed.
    return GetAddressAbilityCurrentCooldown(ConvertHandle(a));
}

void SetAbilityCooldown(jHANDLE a, float seconds, int mode)
{
    SetAddressAbilityCooldown(ConvertHandle(a), seconds, mode);
}

void AddAbilityCooldown(jHANDLE a, float seconds)
{
    SetAbilityCooldown(a, seconds, cool_mode_plus);
}

void ReduceAbilityCooldown(jHANDLE a, float seconds)
{
    SetAbilityCooldown(a, seconds, cool_mode_minus);
}

void ResetAbilityCooldown(jHANDLE a)
{
    SetAbilityCooldown(a, -1., cool_mode_equal);
}

void StartAbilityCooldown(jHANDLE a, float cd)
{
    StartAddressAbilityCooldown(ConvertHandle(a), cd);
}

float GetAbilityCastTime(jHANDLE a)
{
    return GetAddressAbilityCastTime(ConvertHandle(a));
}

void SetAbilityCastTime(jHANDLE a, float r)
{
    SetAddressAbilityCastTime(ConvertHandle(a), r);
}

void SetAbilityDisabled(jHANDLE a, int count)
{
    // not safe unless used with PauseUnit. Button will be blacked, but current casts of that ability won’t be interrupted.
    SetAddressAbilityDisabled(ConvertHandle(a), count);
}

int GetAbilityDisabled(jHANDLE a)
{
    return GetAddressAbilityDisabled(ConvertHandle(a));
}

void SetAbilityHidden(jHANDLE a, int count)
{
    // This one is 100% safe. This hides the ability button, && order can’t be issued.
    SetAddressAbilityHidden(ConvertHandle(a), count); // -1 = unhide | 1 = hide;
}

void AddAbilityHidden(jHANDLE a, int count)
{
    AddAddressAbilityHidden(ConvertHandle(a), count);
}

int GetAbilityDisabledEx(jHANDLE a)
{
    // This one is used by Orb of Slow. Button is blacked, but cooldown is stil displayed.
    return GetAddressAbilityDisabledEx(ConvertHandle(a));
}

void SetAbilityDisabledEx(jHANDLE a, int count)
{
    // This one is used by Orb of Slow. Button is blacked, but cooldown is stil displayed.
    SetAddressAbilityDisabledEx(ConvertHandle(a), count);// -1 = unhide | 1 = hide;
}

void SilenceAbility(jHANDLE a)
{
    SilenceAddressAbility(ConvertHandle(a));
}

void UnsilenceAbility(jHANDLE a)
{
    UnsilenceAddressAbility(ConvertHandle(a));
}

void ShowAbility(jHANDLE a, bool flag)
{
    ShowAddressAbility(ConvertHandle(a), flag);
}

DWORD RealUnitAddAbilityEx(DWORD pUnit, DWORD id,DWORD u1, DWORD u2, DWORD u3)
{
    if (pUnit == NULL) return 0;
    return fast_call(pRealUnitAddAbilityAdv, pUnit, id, u1, u2, u3);
}

DWORD RealUnitAddAbility2(DWORD pUnit, DWORD id)
{
    return RealUnitAddAbilityEx(pUnit, id, 0, 0, 0);
}
DWORD UnitAddAbility2(DWORD Unit, DWORD id)
{
    if (Unit == NULL) return 0;
    DWORD pUnit = ConvertHandle(Unit);
    if (pUnit == NULL) return 0;
    return RealUnitAddAbility2(pUnit, id);
}