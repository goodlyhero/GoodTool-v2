#pragma once

#include <BasicConstants.h>

int GetUnitAbilityReal(int pUnit, int aid, int unk1, int unk2, int unk3, int unk4);

int GetUnitAbilityData(jHANDLE u, int aid, int flag);

int GetUnitAbility(jHANDLE u, int aid);

int GetUnitAbilityBase(jHANDLE u, int aid);

int GetUnitAbilityOrderId(jHANDLE u, int aid);

bool IsUnitAbilityOnCooldown(jHANDLE u, int aid);

bool IsUnitAbilitySafe(jHANDLE u, int aid);

bool IsUnitAbilityUsable(jHANDLE u, int aid);

float GetUnitAbilityCastpoint(jHANDLE u, int aid);

void SetUnitAbilityCastpoint(jHANDLE u, int aid, float dur);

float GetUnitAbilityBackswing(jHANDLE u, int aid);

void SetUnitAbilityBackswing(jHANDLE u, int aid, float dur);

int GetUnitAbilityManaCost(jHANDLE u, int aid, int level);

void SetUnitAbilityManaCost(jHANDLE u, int aid, int level, int mc);

float GetUnitAbilityCooldownStamp(jHANDLE u, int aid);

float GetUnitAbilityCurrentCooldown(jHANDLE u, int aid);

void SetUnitAbilityCooldown(jHANDLE u, int aid, float seconds, int mode);

void AddUnitAbilityCooldown(jHANDLE u, int aid, float seconds);

void ReduceUnitAbilityCooldown(jHANDLE u, int aid, float seconds);

void ResetUnitAbilityCooldown(jHANDLE u, int aid);

void StartUnitAbilityCooldown(jHANDLE u, int aid, float cd);

float GetUnitAbilityCastTime(jHANDLE u, int aid);

void SetUnitAbilityCastTime(jHANDLE u, int aid, float r);

void SetUnitAbilityDisabled(jHANDLE u, int aid, int count);

int GetUnitAbilityDisabled(jHANDLE u, int aid);

void SetUnitAbilityHidden(jHANDLE u, int aid, int count);

void AddUnitAbilityHidden(jHANDLE u, int aid, int count);

int GetUnitAbilityDisabledEx(jHANDLE u, int aid);

void SetUnitAbilityDisabledEx(jHANDLE u, int aid, int count);

void SilenceUnitAbility(jHANDLE u, int aid);

void UnsilenceUnitAbility(jHANDLE u, int aid);

void ShowUnitAbility(jHANDLE u, int aid, bool flag);
