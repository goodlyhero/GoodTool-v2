#pragma once

#include <BasicConstants.h>

#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>

bool IsCommandButton(DWORD pButton);

DWORD GetButtonData(DWORD pCommandButton);

DWORD GetButtonGoldCost(DWORD pCommandButton);

DWORD GetButtonLumberCost(DWORD pCommandButton);

DWORD GetButtonManaCost(DWORD pCommandButton);

float GetButtonCooldown(int pCommandButton);

bool IsButtonOnCooldown(int pCommandButton);

void AddFrameType(const char* name, DWORD vtype, DWORD pVtable, DWORD pVTableObj);
