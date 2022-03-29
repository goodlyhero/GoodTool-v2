#include <Functions.h>
#include "LuaEngine.h"
#include <From MemHack.h>
import APIIterators;
export module LuaApiFuncs;

namespace lua
{
	int LGetCurrAbilityData(lua_State* L)
	{
		//mlog::Debug("Running GetAbilDataIter(n)");
		luaL_checkinteger(L, lua_upvalueindex(1));
		//mlog::Debug("Checked");
		DWORD curr = lua_tointeger(L, lua_upvalueindex(1));
		//mlog::Debug("Curr: ", curr);
		if (curr < 500) return 0;
		DWORD id;
		DWORD next = GetCurrAbilityData(curr, id);
		//mlog::Debug("Getting abil data: ",curr," id: ",id);
		if (next == NULL) return 0;
		lua_newtable(L);
		lua_pushnumber(L, curr);
		lua_setfield(L, -2, "ptr");
		lua_pushnumber(L, id);
		lua_setfield(L, -2, "id");
		lua_pushnumber(L, next);
		lua_replace(L, lua_upvalueindex(1));
		return 1;
	}
	export int GetAllUnitAbilitiesIterator(lua_State* L)
	{
		luaL_checkinteger(L, 1);
		DWORD punit = ConvertHandle(lua_tointeger(L, 1));
		if (punit == NULL) return 0;
		DWORD pabil = GetUnitAbilityData(punit);
		if (pabil == NULL) return 0;
		lua_pushinteger(L, pabil);
		lua_pushcclosure(L, LGetCurrAbilityData, 1);
		return 1;
	}
}