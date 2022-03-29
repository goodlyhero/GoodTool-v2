#include <Functions.h>
#include <LuaEngine.h>
import JassNamesMemory;
export module JassRef;
const char* lua_reftable = "__REFTABLE";
const char* len_field = "len";
bool CallbackNativeInitialized = false;
namespace lua
{
	DWORD GoodCallback2(DWORD local, DWORD id)
	{

	}
	export void InitLuaJassCode(TLua* state)
	{
		if (state == NULL) return;
		lua_State* L = state->lua;
		lua_newtable(L);
		lua_pushnumber(L, 0);
		lua_setfield(L, -2, len_field);
		lua_setglobal(L, lua_reftable);
	}
}