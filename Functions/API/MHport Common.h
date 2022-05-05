#pragma once
#include <map>
#include <string>
#include "Agent/agent.h"
#include "Player.h"
#include "Memory/Memory.h"
#include "Calls.h"
#include "Unit/UnitNormal.h"
#include "Unit/UnitBase.h"
#include "Item/item.h"
#include "Group.h"
#include "Ability/ability.h"
#include "Frame/Frame Include.h"
#include "UI.h"
#include "WindowsApi funcs.h"
#include "FPS.h"
#include "Also.h"
#include "Keys.h"
#include "KeyHook.h"
import CIconCover;

extern std::map<DWORD, DWORD> MemHackTable_FrameVT;
extern std::map<DWORD, std::string> MemHackTable_FrameVT_name;