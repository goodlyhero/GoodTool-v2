#include <Functions.h>
#include <LuaEngine.h>
import JassNamesMemory;
export module JassRef;
const char* lua_reftable = "__REFTABLE";
const char* len_field = "len";
bool CallbackNativeInitialized = false;
namespace lua
{
	
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