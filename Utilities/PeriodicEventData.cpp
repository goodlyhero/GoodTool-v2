#include <list>
#include <memory>
#include <Menu.h>
#include <lua/LuaStates.h>
#include "Properties.h"
#include "PeriodicEventData.h"
#include "HookChat.h"
#include <LuaFunctions.h>
import JassLuaThreadInteraction;
import UnlimitMapSize;
namespace pEvent_Data
{

	class PeriodicEventData
	{
	public:
		struct EventMSG
		{
			int code;
			void* data;
		};
	
		bool availiable;
		std::list< EventMSG*> msgs;
		int cnt;
		PeriodicEventData()
		{
			availiable = true;
			cnt = 0;
		}
		bool check()
		{
			return availiable;
		}
		void lock()
		{
			availiable = false;
		}
		void unlock()
		{
			availiable = true;
		}
		int getcnt()
		{
			return cnt;
		}
		void AddEvent(int code, void* data)
		{
			EventMSG* temp = new EventMSG;
			temp->code = code;
			temp->data = data;
			msgs.push_back(temp);
			cnt = cnt + 1;
		}
		void* GetFirstEvent(int& _code)
		{
			if (cnt > 0)
			{
				auto begin = *msgs.begin();
				_code = (begin)->code;
				return (begin->data);
			}
			_code = 0;
			return NULL;
		}
		void ClearFirstEvent()
		{
			if (cnt > 0)
			{
				auto begin = *msgs.begin();
				msgs.remove(begin);
				cnt = cnt - 1;
			}
		}
		~PeriodicEventData()
		{
			for (auto a : msgs)
			{
				delete a->data;
			}
		}

	private:

	};
}
pEvent_Data::PeriodicEventData Periodic_Events;
bool ProcessEvent(pEvent_Data::PeriodicEventData::EventMSG* event)
{
	if (event != NULL)
	{
		int code = event->code;
		void* data = event->data;
		switch (code)
		{
		case EVENT_CODE_RUN_LUA:
		{
			size_t len = GetWindowTextLength(Code1);
			char* buffer = new char[len + 1];
			GetWindowTextA(Code1, buffer, len + 1);
			mlog::Lua("Trying To run code from menu:\n", buffer);
			bool globalstate = GetCheckBoxState(LuaMode);
			lua::TLua* state;
			if (globalstate)
			{
				state = lua::GetGlobalState();
				//mlog::Debug("Getting Global State");
			}
			else
			{
				state = lua::GetLocalState();
				//mlog::Debug("Getting Local State");
			}
			if (state == NULL)
			{
				//mlog::Debug("state==NULL");
			}
			if (buffer == NULL)
			{
				//mlog::Debug("buffer==NULL");
			}
			if (state != NULL && buffer != NULL)
			{
				char* error = state->DoStr(buffer);
				if (error != NULL)
				{
					TextPrint(error);
					mlog::Lua("error, when running code from menu: ", error);
				}

			}
			else
			{
				//mlog::Debug("Buffer == NULL or cant find State");
			}
			delete[] buffer;
			return true;
			break;
		}
		case EVENT_CODE_INIT_WX:
		{
			mlog::Debug("Running sheduled init: ");
			auto b = lua::GetGlobalState();
			if (b != NULL)
			{
				b->InitWX();
			}
			mlog::Debug("Hooking chat");
			initChatHook();
			mlog::Debug("Unlocked map size");
			UnlockMapSize();
			mlog::State("Loading settings");
			LoadSettings();
			mlog::State("Loading mods");
			LoadMods();
			mlog::Debug("Initializing callbacks");
			InitJassLuaCallbacks();
			mlog::Debug("Initializing global scripts");
			lua::InitGlobalScripts(*b);
			mlog::Debug("Sheduled init was completed");

			return true;
		}
		case EVENT_CODE_INIT_SIMPLE:
		{
			mlog::Debug("Hooking chat");
			initChatHook();
			mlog::Debug("Unlocked map size");
			UnlockMapSize();
			mlog::Debug("Initializing callbacks");
			InitJassLuaCallbacks();
			return true;
		}
		default:
			return true;
		}
	}
	return false;
}

void ProcessPeriodic()
{
	if (Periodic_Events.availiable)
{
		Periodic_Events.lock();
		std::list< pEvent_Data::PeriodicEventData::EventMSG*> toclear;
		for (auto a : Periodic_Events.msgs)
		{
			if (ProcessEvent(a))
			{
				toclear.push_back(a);
			}
		}
		for (auto var : toclear)
		{
			Periodic_Events.msgs.remove(var);
		}
		Periodic_Events.unlock();
	}
}

void AddEvent(int code, void* data)
{
	Periodic_Events.AddEvent(code, data);
}