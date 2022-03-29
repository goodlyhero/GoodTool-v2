#include <Windows.h>
#include <Functions.h>
HWND  hwndwc;
DWORD dwGameDll;
DWORD pGameDLL;
DWORD dwStormDll;
DWORD pEventEngine;
HINSTANCE GoodToolDll;
void InitBasicConstants()
{
	dwGameDll = (DWORD)GetModuleHandle("Game.dll");
	pGameDLL = dwGameDll;
	hwndwc = (HWND)ReadRealMemory(pGameDLL + 0xAD147C);
	dwStormDll = (DWORD)GetModuleHandle("Storm.dll");
	pEventEngine = dwGameDll + 0xACEAFC;
}

DWORD RefindGameWindow()
{
	hwndwc = (HWND)ReadRealMemory(pGameDLL + 0xAD147C);
	return (DWORD)hwndwc;
}