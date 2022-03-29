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

#define ANCHOR_TOPLEFT 0
#define ANCHOR_TOP 1
#define ANCHOR_TOPRIGHT 2
#define ANCHOR_LEFT 3
#define ANCHOR_CENTER 4
#define ANCHOR_RIGHT 5
#define ANCHOR_BOTTOMLEFT 6
#define ANCHOR_BOTTOM 7
#define ANCHOR_BOTTOMRIGHT 8