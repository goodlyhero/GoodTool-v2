#pragma once
#include "LuaEngine.h"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#define _geti(number,var) \
int var;\
if (lua_isnumber(io_luaState, number))\
{\
	var = (int)lua_tointeger(io_luaState, number);\
}\
else if (lua_isstring(io_luaState, number))\
{\
	var = Id2Int((char*)lua_tostring(io_luaState, number));\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be of integer or string id (like \"AInv\") type",__func__,number);\
}

#define _getDwEx(number,var) int var; \
if (lua_isnumber(io_luaState, number))\
{\
	var = (int)lua_tointeger(io_luaState, number);\
}\
else if (lua_isstring(io_luaState, number))\
{\
	var = (int)lua_tostring(io_luaState, number);\
}\
else if (lua_isboolean(io_luaState, number))\
{\
	var = (int)lua_toboolean(io_luaState, number);\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be of integer or string or boolean", __func__, number); \
};

#define _getH(number, var) \
int var;\
if (lua_isnumber(io_luaState, number))\
{\
var = (int)lua_tointeger(io_luaState, number);\
}\
else\
{\
return luaL_error(io_luaState, "function %s Argument#%d should be of jHANDLE(int) type", __func__, number);\
}

#define _getC(number, var) \
int var;\
if (lua_isnumber(io_luaState, number))\
{\
var = (int)lua_tointeger(io_luaState, number);\
}\
else\
{\
return luaL_error(io_luaState, "function %s Argument#%d should be of jHANDLE(int) type", __func__, number);\
}

#define _gets(number,var) \
char* var;\
if (lua_isstring(io_luaState, number))\
{\
	var = (char*)lua_tostring(io_luaState, number);\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be of string type",__func__,number);\
}

#define _getf(number,var) \
float var;\
if (lua_isnumber(io_luaState, number))\
{\
	var = (float)lua_tonumber(io_luaState, number);\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be of float type",__func__,number);\
}

#define _getb(number,var) \
bool var;\
if (lua_isboolean(io_luaState, number))\
{\
	var = lua_toboolean(io_luaState, number);\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be of bool type",__func__,number);\
}

#define _getfunccb(number,var,refhandler) \
int var;\
if (lua_isfunction(io_luaState, number))\
{\
	int top = lua_gettop(io_luaState);\
	lua_settop(io_luaState, number);\
	var = AddCallbackHandled(io_luaState, refhandler);\
	lua_settop(io_luaState,top);\
}\
else if(lua_type(io_luaState,number)==LUA_TNIL)\
{\
	var = 0;\
}\
else\
{\
	return luaL_error(io_luaState, "function %s Argument#%d should be function or nill",__func__,number);\
}
namespace lua
{
	inline void InitGlobalScripts(TLua& Lua)
	{
		if ((fs::exists("GoodTool\\Lua\\Init.lua")))
		{
			Lua.DoFile("GoodTool\\Lua\\Init.lua");
		}
	}
	void LuaInitCustomFunctions(TLua& Lua);
}

