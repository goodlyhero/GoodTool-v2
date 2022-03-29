#include <Functions.h>
#include "Memory/MemoryGameUI.h"
#include <Calls.h>
#include "MHport Common.h"

export module CursorAPI;



export bool IsSelectMode()
{
	DWORD pGameUI = GetGameUI(0, 0);
	if (pGameUI != 0)
	{
		return ReadRealMemory(pGameUI + 0x1BC) == 0;
	}
	return false;
}

export DWORD GetCurrentCursor()
{
	DWORD pGameUI = GetGameUI(0, 0);
	if (pGameUI != 0)
	{
		return ReadRealMemory(pGameUI + 0x1B4);
	}
	return 0;
}

export DWORD GetCurrentCursorOrder()
{
	DWORD pCursor = GetCurrentCursor();
	if (pCursor != 0)
	{
		return ReadRealMemory(pCursor + 0x10);
	}
	return 0;
}
export void SetCurrentCursorOrder(DWORD order)
{
	DWORD pCursor = GetCurrentCursor();
	if (pCursor != 0)
	{
		return WriteRealMemory(pCursor + 0x10,order);
	}
}

export void CancelCurrentMode()
{
	DWORD pGameUI = GetGameUI(0, 0);
	if (pGameUI == NULL || !IsSelectMode)  return;
	this_call(pCancelCurrentMode, pGameUI);
}