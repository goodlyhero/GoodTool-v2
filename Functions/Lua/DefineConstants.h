#pragma once
#include <LuaEngine.h>
namespace lua
{
	void BindConsts(TLua& Lua);
	void BindKeyConst(TLua& Lua);
	void SetCommonJass(TLua& Lua);
}