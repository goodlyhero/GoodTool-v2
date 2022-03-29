#include "KeyHook.h"
#include <BasicConstants.h>
#include <LuaStates.h>
#include <LuaBridge.h>
#include <Windows.h>
bool KeyboardHooked = false;
HHOOK keyboardhook;
