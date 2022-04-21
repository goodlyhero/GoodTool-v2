#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <cmath>
//#include <stringstream>
////////////////////////////////////
#include "Functions/Lua/LuaStates.h"
#include "Functions/Lua/Events.h"
#include <BasicConstants.h>
#include <Hook Text Messages.h>
#include <HookChat.h>
#include <Logs/Log.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Additional Native Functions.h>
#include <Jass Natives.h>
#include <Warcraft Functions.h>
#include <Menu.h>
#include "Functions/API/InitGameUI.h"
#include "Functions/Lua/LuaStates.h"
#include <Lua/LuaEngine.h>
#include <From MemHack.h>
#include "Utilities/PeriodicEventData.h"
#include "Utilities/Cleanup.h"
import UnlimitMapSize;
import ClassInfoGame;
import EVENTS;

HMODULE ThisLib;
#pragma comment(lib, "version.lib")
#pragma comment(lib, "Urlmon.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Wininet.lib")
//#pragma comment(lib, "libcmtd.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "Rpcrt4.lib")
#pragma comment(lib, "Urlmon.lib")
#pragma comment(lib, "Shell32.lib")
//////////////////////////////////
#pragma comment(lib, "rcmp.lib")
#pragma comment(lib, "lua.lib")


//#pragma comment(lib, "LuaBridge.lib")

bool GoodToolSimple;
extern void CommandsInitHook();
extern void RestoreSpecial();

void detachLibrary()
{
	Sleep(1000);
	FreeLibraryAndExitThread(ThisLib,0);
}

void DetachPreparations()
{
	RestoreSpecial();
	if (!GoodToolSimple)
	{
		DetachMapErrorHook();
		DetachInterestingTextHook();
		detachNetMsgInitHook();

		menu::DestroyWindows();
	}
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)detachLibrary, NULL, NULL, NULL);
	return;
}

void detach()
{
	DetachPreparations();
}

void InitConsole()
{
	bool allocated = AllocConsole();
	HANDLE console = GetConsoleWindow();
	SetStdHandle(STD_OUTPUT_HANDLE, console);
	//SetStdHandle(STD_ERROR_HANDLE, console);
	if (allocated)
	{
		std::cout << "GoodTool Injected!" << std::endl;
	}
}

void InitConsoleWait()
{
	Sleep(100);

	InitConsole();

	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)conssoledebug, NULL, NULL, NULL);

	ExitThread(0);

	return;
}

void SetWindowName()
{
	SetWindowTextA(hwndwc, "Warcraft 3");
}
//void WaitSomeTimeBeforeLoad()
//{
//	Sleep(1000);
//	if (WarcraftVersion() == 6401)
//	{
//		JassNativesInit();
//
//		initChatHook();
//	}
//	ExitThread(0);
//	return;
//}

void mCreateWindow()
{
	menu::MyWindows(ThisLib);

}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case (DLL_PROCESS_ATTACH):
		DisableThreadLibraryCalls(hModule);
		/*CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WaitSomeTimeBeforeLoad, NULL, NULL, NULL);*/
		GoodToolDll = hModule;
		InitLogs();
		if (FileExists("GoodTool\\Console"))
		{
			mlog::Debug("Opening console");
			if (AllocConsole())
			{
				freopen("CONOUT$", "wt", stdout);
				freopen("CONIN$", "rt", stdin);
				std::ios::sync_with_stdio(1);

			}
			HWND console = GetConsoleWindow();
			HMENU hMenu = GetSystemMenu(console, false);
			int cnt = GetMenuItemCount(hMenu);

			std::cout << "Items: " << cnt << std::endl;
			for (int i = 0; i < cnt; i++)
				RemoveMenu(hMenu, i, MF_BYPOSITION);
			printf("Hello World! \n");

		}
		if (GetModuleHandle("game.dll") == NULL)
		{
			mlog::Error("cannot find game.dll");
			printf("cannot find game.dll\n");
			//std::cout << "cannot find game.dll" << std::endl;
			FreeLibraryAndExitThread(GoodToolDll, -1);
			return -1;
		}
		if (GetModuleHandle("worldedit121.exe") != NULL || GetModuleHandle("worldedit.exe") != NULL)
		{
			mlog::Error("Running with worldedit, unloading");
			printf("Running with worldedit, unloading\n");
			//std::cout << "cannot find game.dll" << std::endl;
			FreeLibraryAndExitThread(GoodToolDll, -1);
			return -1;
		}
		if (WarcraftVersion() != 6401)
		{
			mlog::Error("Unknow version of Warcraft 3");
			std::cout << "Unknow version of Warcraft 3" << std::endl;
			FreeLibraryAndExitThread(GoodToolDll, -1);
			return -1;
		}
		InitBasicConstants();
		//InitializeDreamUI((HMODULE)dwGameDll, (HWND)dwStormDll);
		InitNativeConstants();
		InitNativeFunctions();
		JassNativesInit();
		InitEvents();
		InitClassInfoGame();
		lua::InitLua();
		mlog::State("Lua initialized");
		lua::InitEventHooks();
		mlog::State("Event Hooks Initialized");
		if (GetModuleHandleA("Loader.dll")!=NULL)
		{
			FromLoader = true;
		}
		else
		{
			FromLoader = false;
		}
		if ((GetModuleHandleA("Loader.dll") != NULL) && (!FileExists("GoodTool\\GOODTOOL_FORCE")))
		{

			mlog::Debug("Simple mode");
			AddEvent(EVENT_CODE_INIT_SIMPLE, NULL);
			GoodToolSimple = true;
		}
		else
		{
			
			mlog::Debug("Not Simple mode");
			GoodToolSimple = false;
			UnlockChat();
			mlog::Debug("Chat unlocked");
			AddEvent(EVENT_CODE_INIT_WX, NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)mCreateWindow, NULL, NULL, NULL);
		}


		mlog::State("Loading Completed");
		break;
	case (DLL_PROCESS_DETACH):
		mlog::State("Detaching");
		CloseLogs();
		if(FromLoader) cleanup::Cleanup();
		break;
	}

	return TRUE;
}
