#pragma once
#include <BasicConstants.h>

int GetAbilityBaseUI(jHANDLE abil);

int GetAbilityBaseId(jHANDLE a);

int GetAbilityOrderId(jHANDLE a);

bool IsAbilityOnCooldown(jHANDLE a);

bool IsAbilitySafe(jHANDLE a);

bool IsAbilityUsable(jHANDLE a);

float GetAbilityCastpoint(jHANDLE a);

void SetAbilityCastpoint(jHANDLE a, float dur);

float GetAbilityBackswing(jHANDLE a);

void SetAbilityBackswing(jHANDLE a, float dur);

int GetAbilityManaCost(jHANDLE a, int level);

void SetAbilityManaCost(jHANDLE a, int level, int mc);

float GetAbilityCooldownStamp(jHANDLE a);

float GetAbilityCurrentCooldown(jHANDLE a);

void SetAbilityCooldown(jHANDLE a, float seconds, int mode);

void AddAbilityCooldown(jHANDLE a, float seconds);

void ReduceAbilityCooldown(jHANDLE a, float seconds);

void ResetAbilityCooldown(jHANDLE a);

void StartAbilityCooldown(jHANDLE a, float cd);

float GetAbilityCastTime(jHANDLE a);

void SetAbilityCastTime(jHANDLE a, float r);

void SetAbilityDisabled(jHANDLE a, int count);

int GetAbilityDisabled(jHANDLE a);

void SetAbilityHidden(jHANDLE a, int count);

void AddAbilityHidden(jHANDLE a, int count);

int GetAbilityDisabledEx(jHANDLE a);

void SetAbilityDisabledEx(jHANDLE a, int count);

void SilenceAbility(jHANDLE a);

void UnsilenceAbility(jHANDLE a);

void ShowAbility(jHANDLE a, bool flag);

DWORD RealUnitAddAbilityEx(DWORD pUnit, DWORD id, DWORD u1, DWORD u2, DWORD u3);

DWORD RealUnitAddAbility2(DWORD pUnit, DWORD id);

DWORD UnitAddAbility2(DWORD Unit, DWORD id);