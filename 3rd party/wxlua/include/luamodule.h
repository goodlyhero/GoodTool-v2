#pragma once
#include <lua.h>
#include <wx/include/wx/app.h>
wxApp* GetLuaModuleApp();
int luaopen_wx(lua_State* L);