#include "LuaStates.h"
#include <States.h>
#include <API/InitGameUI.h>
#include <API/bindapi.h>
#include <API/Frame/initframetypes.h>
#include <../main.h>
#include <DefineConstants.h>
#include "../../3rd party/wxlua/include/luamodule.h"
import JassLuaThreadInteraction;
extern void lua::LuaInitCustomFunctions(lua::TLua& Lua);
extern void lua::InitLuaJNatives(lua::TLua& Lua);
bool todetach = false;


import GeneralDispatcher;
namespace lua
{
	TLua *GlobalState = NULL;
	TLua *LocalState = NULL;
	TLua* GetGlobalState()
	{
		return GlobalState;
	}
	 TLua* GetLocalState()
	{
		return LocalState;
	}

	void InitLua()
	{
		GlobalState = new TLua("Global",&GeneralDispatcher);
		initgameui();
		initframetypes();
		mlog::Debug("G was initialized");
		if (GlobalState != NULL)
		{
			LuaInitCustomFunctions(*GlobalState);
			mlog::Debug("Initialized custom functions in G");
			InitLuaJNatives(*GlobalState);
			mlog::Debug("Initialized lua jass natives in G");
			bindapi(*GlobalState);
			mlog::Debug("API functions binded in G");
			BindConsts(*GlobalState);
			mlog::Debug("Constants were defined to G");
			BindKeyConst(*GlobalState);
			mlog::Debug("VK consts defined to G");
			SetCommonJass(*GlobalState);
			mlog::Debug("Default jass consts were defined in G");
			//InitGlobalScripts(*GlobalState);
			//mlog::Debug("Initialized global scripts in G");
			//luaopen_wx(GlobalState->lua);
		}
		LocalState = new TLua("Local", &GeneralDispatcher);
		mlog::Debug("L was initialized");
		if (LocalState != NULL)
		{
			LuaInitCustomFunctions(*LocalState);
			mlog::Debug("Initialized custom functions in L");
			InitLuaJNatives(*LocalState);
			mlog::Debug("Initialized lua jass natives in L");
			BindConsts(*LocalState);
			mlog::Debug("Constants were defined to L");
			bindapi(*LocalState);
			mlog::Debug("API functions binded in L");
			BindKeyConst(*LocalState);
			mlog::Debug("VK consts defined to L");
			SetCommonJass(*LocalState);
			mlog::Debug("Default jass consts were defined in L");
			//luaopen_wx(LocalState->lua);
		}
	}

	void RecreateLocalLua()
	{
		if (LocalState != NULL)
		{
			delete LocalState;
			LocalState = new TLua("Local", &GeneralDispatcher);
			InitJassLuaCallbacks();
		}
		if (LocalState != NULL)

		{
			LuaInitCustomFunctions(*LocalState);
			InitLuaJNatives(*LocalState);
			BindConsts(*LocalState);
			bindapi(*LocalState);
			BindKeyConst(*LocalState);
			SetCommonJass(*LocalState);
		}
	}

	bool istodetach()
	{
		return GoodToolSimple;
	}

	void CallLocalGlobal(const char* name)
	{
		if (GlobalState !=NULL)
		{
			GlobalState->CallNoArgsNoRet(name);
		}
		if (LocalState != NULL)
		{
			LocalState->CallNoArgsNoRet(name);
		}
	}
	bool __declspec(dllexport)  __stdcall LocalLuaDoCString(DWORD str)
	{
		TLua* state = GetLocalState();
		bool res = false;
		mlog::Debug("Running external string: \n", (char*)str);
		if (state != NULL)
		{
			lua_State* lua = state->lua;
			int top = lua_gettop(lua);

			res = state->DoStr((char*)str);
			if (res)
			{
				const char* result = lua_tostring(lua, lua_gettop(lua));
				if (result)
				{
					mlog::Error("Error in external run of function", result);
				}
				else
				{
					mlog::Error("Unknown in external run of function");
				}
				
			}
			lua_settop(lua, top);
		}
		return res;
	}

	bool LocalLuaDoFile(const char* file)
	{
		TLua* state = GetLocalState();
		bool res = false;
		if (state != NULL)
		{
			state->DoFile(file);
			res = state->GetTop();
		}
		return res;
	}
}