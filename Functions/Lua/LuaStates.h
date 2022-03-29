#pragma once
#include "LuaFunctions.h"
#include "LuaNatives.h"
namespace lua
{
	TLua* GetGlobalState();
	TLua* GetLocalState();
	void InitLua();
	void CallLocalGlobal(const char* name);
	bool istodetach();
	bool __declspec(dllexport) __stdcall LocalLuaDoCString(DWORD str);
	bool LocalLuaDoFile(const char* file);
	void RecreateLocalLua();
	extern TLua* GlobalState;
	extern TLua* LocalState;
}

