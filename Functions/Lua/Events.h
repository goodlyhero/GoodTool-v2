#pragma once
#include <stdio.h>
#include "LuaEngine.h"
namespace lua
{
	void InitEventHooks();
}
void HookKeyboard(bool to);
