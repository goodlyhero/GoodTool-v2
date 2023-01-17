#include <list>
#include <memory>
//#include <Menu.h>
#include <lua/LuaStates.h>
#include "PeriodicEventData.h"
#include "HookChat.h"
#include <LuaFunctions.h>

#include "SystemMessages.h"
#include "GoodToolRun.h"
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
		std::cout << code << std::endl;
		switch (code)
		{
		case EVENT_CODE_RUN_LUA_LOCAL:
		case EVENT_CODE_RUN_LUA_GLOBAL:
		{
			std::cout << "running code" << std::endl;

			const char* script = (const char*)event->data;
			lua::TLua* state;
			if (code == EVENT_CODE_RUN_LUA_GLOBAL)
			{
				state = lua::GetGlobalState();
			}
			else
			{
				state = lua::GetLocalState();
			}
			if (state != NULL)
			{
				state->DoStr(script, "external script");
			}
			delete[] script;
			return true;
			break;
		}
		break;
		case EVENT_CODE_INIT_WX:
		case EVENT_CODE_INIT_SIMPLE:
		{
			mlog::Debug("Hooking chat");
			initChatHook();
			mlog::Debug("Unlocked map size");
			UnlockMapSize();
			mlog::Debug("Initializing callbacks");
			InitJassLuaCallbacks();
			if (code == EVENT_CODE_INIT_WX) {
				mlog::Debug("Initializing global scripts");
				auto b = lua::GetGlobalState();
				if (b != NULL) lua::InitGlobalScripts(*b);
			}
			mlog::Debug("Sheduled init was completed");

			return true;
		}
		break;
		default:
			return true;
		}
	}
	return true;
}

void ProcessPeriodic()
{
	//ProcessSystemMessage();
	if (Periodic_Events.availiable)
{
		Periodic_Events.lock();
		std::list< pEvent_Data::PeriodicEventData::EventMSG*> toclear;
		while (Periodic_Events.msgs.size() > 0) {
			auto iter = Periodic_Events.msgs.begin();
			auto a = *iter;
			if (ProcessEvent(a)) {
				mlog::Debug("Event processed: ", a->code);
			}
			else {
				mlog::Debug("Event not processed: ", a->code);
			}
			Periodic_Events.msgs.erase(iter);
		}
		Periodic_Events.unlock();
	}
}

void AddEvent(int code, void* data)
{
	Periodic_Events.AddEvent(code, data);
}