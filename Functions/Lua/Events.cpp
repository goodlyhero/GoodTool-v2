#include "Events.h"
#include "LuaStates.h"
#include "rcmp.hpp"
#include <DmgEventData.h>
#include <PeriodicEventData.h>
#include <Windows.h>
#include <PrintDmg.h>
#include <CNatives.h>
#include <../main.h>
#include <Cleanup.h>
#include "Events.h"
#include <LuaBridge.h>
#include <sstream>
#include <json/json.hpp>
#include <iostream>
import JassLuaThreadInteraction;
import EVENTS;
import EVENT_UNIT_DAMAGED;
import EVENT_KEY_INPUT;


std::string settings = "GoodTool\\Settings.json";
using json = nlohmann::json;
extern void DetachPreparations();
namespace lua
{
	void InitEventHooks()
	{
		/*rcmp::hook_function<bool(__thiscall*)(void* it, int a, int b,int c)>(dwGameDll + 0x3aef80, [](auto original, void* it,int a, int b,int c) {
			mlog::State("Running Script");
			int r = original(it,a,b,c);
			CallLocalGlobal("OnInitBegin");
			return r;
		});
		rcmp::hook_function<bool(__stdcall*)()>(dwGameDll + 0x3b54b0, [](auto original) {
			mlog::State("running script");
			CallLocalGlobal("onrunningscript");
			return original();
		});*/
		rcmp::hook_function<int(__fastcall*)(int, int)>(dwGameDll + 0x39f150, [](auto original, int a, int b) {
			mlog::State("Script Loaded");
			InitJassLuaCallbacks();
			mlog::State("Running goodtool scripts");
			if (!FileExists("GoodTool\\GOODTOOL_NOSCRIPT"))
			{
				std::string s = StormGetFileAsString(settings.c_str());
				if (!s.empty())
				{
					try
					{
						auto MapSettings = json::parse(s);
						auto scripts = MapSettings["scripts"];
						for (auto a : scripts)
						{
							if (!a.is_string())
							{
								mlog::State("When paring ", settings, " unable to parse: ", a);
							}
							else
							{
								LuaDoFileFromMPQ(a.get<std::string>().c_str());
							}
						}
					}
					catch (std::exception exceprtion)
					{
						mlog::State("Exception when loading script: ", exceprtion.what());
					}
				}
				else
				{
					mlog::State("Unable to find ", settings, " , or this file is empty");
				}
			}
			EVENT_SCRIPT_LOADED.SendEvent(std::shared_ptr<EventData>(nullptr));
			return  original(a,b);
		});
		/*rcmp::hook_function<void(__thiscall*)(void* it,char c)>(dwGameDll + 0x399860, [](auto original, void* it,char c) {
			
		});*/
		rcmp::hook_function<void(__cdecl*)()>(dwGameDll + 0x6c4e10, [](auto original) {
			if (EVENT_SCREEN_UPDATE.IsActive())
			{
				EVENT_SCREEN_UPDATE.SendEvent(std::shared_ptr<EventData>(nullptr));
			}
			ProcessPeriodic();
			original();
		});//performance cnt
		rcmp::hook_function<DWORD(__thiscall*)(DWORD it, DWORD* dmgeventdata1, DWORD* dmgeventdata2, DWORD param_3, DWORD param_4)>(dwGameDll + 0x2a40d0, [](auto original, DWORD it, DWORD* dmgeventdata1, DWORD* dmgeventdata2, DWORD param_3, DWORD param_4) {
			//EventDataUnitDamaged data((int&)dmgeventdata2[0], (int&)it, (int&)dmgeventdata2[3], (int&)dmgeventdata2[8], (int&)dmgeventdata2[5], (float&)(((float*)(dmgeventdata2))[4]));
			//std::shared_ptr< EventData> event = std::shared_ptr< EventData>(&data);
			if (EVENT_UNIT_DAMAGED.IsActive())
			{
			auto event = std::make_shared< EventDataUnitDamaged>((int&)dmgeventdata2[0], (int&)it, (int&)dmgeventdata2[3], (int&)dmgeventdata2[8], (int&)dmgeventdata2[5], (float&)(((float*)(dmgeventdata2))[4]));
			EVENT_UNIT_DAMAGED.SendEvent(event);
			}
			DWORD target;
			float live1;
			float live2;
			if (printdmgmode)
			{
				target = GetTargetHandle();
				live1 = GetWidgetLife(target);
			}
			DWORD ret = original(it, dmgeventdata1, dmgeventdata2, param_3, param_4);
			if (printdmgmode)
			{
				live2 = GetWidgetLife(target);
				printdmg(target, live2 - live1);
			}
			return ret;
		});
		rcmp::hook_function<int(__fastcall*)(int a)>(dwGameDll + 0x3a17f0, [](auto original,int a) {
			LogS() << "[state]: Game Ended" << std::endl;
			if (EVENT_GAME_ENDED.IsActive())
			{
			EVENT_GAME_ENDED.SendEvent(std::shared_ptr<EventData>(nullptr));
			}
			UnloadResources();
			RecreateLocalLua();
			if (istodetach())
			{
				cleanup::Cleanup();
				DetachPreparations();

			}
			return original(a);
		});
	}
}

bool OnKeyEvent(int key, int state)
{
	if (EVENT_KEY_INPUT.IsActive())
	{
		auto event = std::make_shared< EventDataKeyInput>(key, state);
		//auto eventt = std::shared_ptr<EventData>(event);
		//mlog::Debug("Pressed key with info: ", eventt->InfoTypeAt(207), " ", eventt->InfoTypeAt(208));
		EVENT_KEY_INPUT.SendEvent(event);
		return !event->IsCanceled();
	}
	else
	{
		return true;
	}
}
bool iskeyboardhooked = false;
void HookKeyboard(bool to)
{
	if (!iskeyboardhooked)
	{
		iskeyboardhooked = to;
		rcmp::hook_function<void(__fastcall*)(int, int, int, int)>(pGameDLL + 0x630ec0, [](auto original,int key, int a, int b, int c)
		{
			if (OnKeyEvent(key, 1))
			{
				original(key, a, b, c);
			}

		});
		rcmp::hook_function<void(__fastcall*)(int, int, int, int)>(pGameDLL + 0x630f10, [](auto original, int key, int a, int b, int c)
		{
			if (OnKeyEvent(key, 0))
			{
				original(key, a, b, c);
			}
		});
	}
}