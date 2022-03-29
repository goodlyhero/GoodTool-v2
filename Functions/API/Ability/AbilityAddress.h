#pragma once
#include <BasicConstants.h>


int GetAbilityBaseDataByAddress(DWORD pAbil);

int GetAddressAbilityTypeId(DWORD pAbil);

int GetAddressAbilityBaseId(DWORD pAbil);

int GetAddressAbilityOrderId(DWORD pAbil);

bool IsAddressAbilityOnCooldown(DWORD pAbil);

bool IsAddressAbilitySafe(DWORD pAbil);

bool IsAddressAbilityUsable(DWORD pAbil);

float GetAddressAbilityCastpoint(DWORD pAbil);

void SetAddressAbilityCastpoint(DWORD pAbil, float dur);

float GetAddressAbilityBackswing(DWORD pAbil);

void SetAddressAbilityBackswing(DWORD pAbil, float dur);

int GetAddressAbilityManaCost(DWORD pAbil, int level);

void SetAddressAbilityManaCost(DWORD pAbil, int level, int mc);

float GetAddressAbilityCooldownStamp(DWORD pAbil);

float GetAddressAbilityCurrentCooldown(DWORD pAbil);
#define cool_mode_plus 0
#define cool_mode_minus 1
#define cool_mode_equal 2
void SetAddressAbilityCooldown(DWORD pAbil, float seconds, int mode);

bool StartAddressAbilityCooldown(DWORD pAbil, float cd);

float GetAddressAbilityCastTime(DWORD pAbil);

void SetAddressAbilityCastTime(DWORD pAbil, float r);

void SetAddressAbilityDisabled(DWORD pAbil, int count);

int GetAddressAbilityDisabled(DWORD pAbil);

void SetAddressAbilityHidden(DWORD pAbil, int count);

void AddAddressAbilityHidden(DWORD pAbil, int d);
int GetAddressAbilityDisabledEx(DWORD pAbil);
void SetAddressAbilityDisabledEx(DWORD pAbil, int count);
void ShowAddressAbility(DWORD pAbil, bool flag);
void SilenceAddressAbility(DWORD pAbil);
void UnsilenceAddressAbility(DWORD pAbil);
int GetAddressAbilityOwner(DWORD pAbil);