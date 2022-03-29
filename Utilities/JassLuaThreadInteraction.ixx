#include <rcmp.hpp>
#include <Additional Native Constants.h>
#include <Warcraft Functions.h>
#include <LuaEngine.h>
#include <map>
#include <Logs/Log.h>
#include <Warcraft Functions.h>
#include <Jass Natives.h>
#include <vector>
#include <list>
#include <LuaBridge.h>
#include <LuaStates.h>
#include <States.h>
#include <From MemHack.h>
#include <set>
extern T_RegisterNative RegisterNative;
export module JassLuaThreadInteraction;
import JassNamesMemory;

bool isjrunhooked = false;
bool isjhookenabled = false;



#define THREAD_RESULT_OK 1
#define THREAD_RESULT_Yield 3

#define NATIVE_NAME_RunNow "NATIVE_RunNow"
#define NATIVE_NAME_Restore "NATIVE_Restore"

#define LUA_CALLBACKS_TABLE_NAME "_LUA_JASS_CALLBACKS"

int JIdThreadRun = 0;
int JIdThreadContinue = 0;

namespace jcallbackcode
{
	using handlerefilist = std::set<int>;
	export luabridge::LuaRef LCheckTable(lua_State* L)
	{
		auto table = luabridge::getGlobal(L, LUA_CALLBACKS_TABLE_NAME);
		if (!table.isTable())
		{
			table = table.newTable(L);
			luabridge::setGlobal(L, table, LUA_CALLBACKS_TABLE_NAME);
			return table;
		}
		return table;
	}

	export struct JCallback
	{
		DWORD setreg = 0x0c000401;
		DWORD id;
		DWORD push = 0x13000001;
		DWORD regid = 0;
		DWORD ncall = 0x15000000; //ncall 
		DWORD funcid; //our function id
		DWORD ret = 0x27000000; //ret
		DWORD retreg = 0;
		bool isglobal = false;
		DWORD jassid = 0;
	};


	export class CCallbacks
	{
	public:
		std::vector< JCallback*> callbacks;
		std::list<int> callbackstorestore;
		std::vector<int> refs;
		std::map<int, handlerefilist*> handleidrefs;
	public:
		
		void callbackaddref(int id)
		{
			int len = refs.size();
			if(id>=0 && len>=id) 
			{
				//correct id
				refs[id] ++;
			}
			else
			{
				mlog::Debug("Incorrect id to add");
			}
		}
		JCallback* callbackremoveref(int id)
		{
			int len = refs.size();
			if (id >= 0 && len >= id)
			{
				//correct id
				int refcnt = (--refs[id]);
				if (refcnt <= 0)
				{
					JCallback* callback = callbacks[id];
					callbacks[id] = nullptr;
					callbackstorestore.push_back(id);
					return callback;
				}
			}
			else
			{
				mlog::Debug("Incorrect id to remove",id);
			}
			return nullptr;
		}

		void AddRefFromHandle(int handle, int id)
		{
			handlerefilist* reflist;
			auto reflistiter = handleidrefs.find(handle);
			if (reflistiter == handleidrefs.end())
			{
				reflist = new handlerefilist();
				handleidrefs[handle] = reflist;
			}
			else
			{
				reflist =  ( * reflistiter).second;
			}
			if (reflist->find(id) == reflist->end())
			{
				reflist->insert(id);
			}
		}

		void RemoveCallbackWithId(int id)
		{
			delete callbackremoveref(id);
		}

		void RemoveRefsFromHandle(int handle)
		{
			auto reflistiter = handleidrefs.find(handle);
			if (reflistiter == handleidrefs.end()) return;
			auto reflist = reflistiter->second;
			if (reflist == 0) return;
			for (auto ref : *reflist)
			{
				delete callbackremoveref(ref);
			}
			delete reflist;
			handleidrefs.erase(handle);
		}

		int CAddCallback(int funcid,bool isglobal)
		{
			JCallback* callback = new JCallback;
			//mlog::Debug("Created new callback");
			callback->funcid = JIdThreadRun; //создаем новый коллбек.
			//mlog::Debug("Native was setted for this callback");
			int id;
			if (callbackstorestore.size() > 0)
			{
				//mlog::Debug("Exists at least 1 callback to recreate");
				id = *(callbackstorestore.begin());
				callbacks[id] = callback;
				callbackstorestore.remove(id);
			}
			else
			{
				//mlog::Debug("Setting callback to nes slot");
				size_t mlen = callbacks.capacity();
				if (mlen <= callbacks.size())
				{
					//mlog::Debug("Reached length of callbacks table, reserving new memory");
					callbacks.reserve(mlen + 1000);
					refs.reserve(mlen + 1000);
				}
				callbacks.push_back(callback);
				id = callbacks.size()-1;
			}
			//mlog::Debug("callback id: ",id);
			callback->id = id;
			callback->funcid = funcid;
			callback->setreg = 0x0c000401;
			callback->push = 0x13000001;
			callback->regid = 0;
			callback->ncall = 0x15000000;
			callback->retreg = 0;
			callback->isglobal = isglobal;
			DWORD setreg = 0x0c000401;
			//mlog::Debug("callback function id: ",funcid);
			refs[id] = 1;
			//mlog::Debug("Setting reference to callback");
			int jassid = RegisterFunction((DWORD*)callback);
			callback->jassid = jassid;
			return id;
		}

		int LCheckCallback(lua_State* L,luabridge::LuaRef func)
		{
			auto reftable = LCheckTable(L);
			auto id = reftable[func];
			if (!id.isNumber()) return -1;
			return id.cast<int>();
		}

		int LSetCallback(lua_State* L, luabridge::LuaRef func, int funcid)
		{
			int id = LCheckCallback(L, func);
			if (id == -1)
			{
				//mlog::Debug("Unable to find cashed callback, creating new");
				auto reftable = LCheckTable(L);
				//mlog::Debug("Table was checked");
				id = CAddCallback(funcid,L==lua::GlobalState->lua);
				//mlog::Debug("C part of callback was added");
				reftable[id] = func;
				reftable[func] = id;
			}
			else
			{
				//mlog::Debug("Callback already exists and have id: ", id);
				callbackaddref(id);
			}
			return id;
		}

		luabridge::LuaRef LGetCallback(lua_State* L, int id)
		{
			auto reftable = LCheckTable(L);
			luabridge::LuaRef result = reftable[id];
			return result;
		}

		bool LRunCallback(int id)
		{
			JCallback* callback = callbacks[id];
			if (callback != nullptr)
			{
				lua::TLua* state;
				if (callback->isglobal)
				{
					state = lua::GlobalState;
				}
				else
				{
					state = lua::LocalState;
				}
				if (state == nullptr)
				{
					return false;
					mlog::Debug("Enable find state to run callback");
				}
				lua_State* l = state->lua;
				auto cfunc = LGetCallback(l, id);
				if (cfunc.isFunction())
				{
					cfunc.push(l);
					if (lua_pcall(l, 0, 1, NULL))
					{
						lua::LogErrors(lua_tostring(l, -1));
						TextPrint(lua_tostring(l, -1));
					}
					else
					{
						return lua_toboolean(l, -1);
					}
				}
				else
				{
					mlog::Debug("Callback is not function, id: ", id," type: ",cfunc.type());
				}
			}
			return false;

		}

		void LRemoveCallback(lua_State* L, int id)
		{
			auto reftable = LCheckTable(L);
			auto callback = reftable[id];
			reftable[callback] = luabridge::Nil();
			reftable[id] = luabridge::Nil();
		}

		void luaRemoveCallback(int id)
		{
			JCallback* callback = callbackremoveref(id);
			if (callback != 0)
			{	
				lua::TLua* Tstate;
				if (callback->isglobal)
				{
					Tstate = lua::GlobalState;
				}
				else
				{
					Tstate = lua::LocalState;
				}
				if (Tstate == nullptr)
				{
					mlog::Debug("Unable to find state");
					return;
				}
				lua_State* lua = Tstate->lua;
				LRemoveCallback(lua, id);
				delete callback;
			}

		}

		int AddCallback(lua_State* L)
		{
			auto func = luabridge::LuaRef::fromStack(L);
			return LSetCallback(L, func, JIdThreadRun);

		};

		int AddCallbackFromState(lua_State* l)
		{
			int id = AddCallback(l);
			JCallback* pcallback = callbacks[id];
			return pcallback->jassid;
		}

		int AddCallbackHandled(lua_State* l, int handle)
		{
			int id = AddCallback(l);
			JCallback* pcallback = callbacks[id];
			AddRefFromHandle(handle,pcallback->id);
			return pcallback->jassid;
		}
		~CCallbacks()
		{
			for (auto a : callbacks)
			{
				if (a != NULL) delete a;
			}
			callbacks.clear();
			callbackstorestore.clear();
		};

	};

	export CCallbacks Ccalbacks;
	bool NATIVE_RunNow(int id)
	{
		return Ccalbacks.LRunCallback(id);
	}
	bool NATIVE_Restore(int id)
	{
		return false;
	}

}


export int AddCallbackFromState(lua_State* l)
{
	return jcallbackcode::Ccalbacks.AddCallbackFromState(l);
}

export int AddCallbackHandled(lua_State* l,int handle)
{
	return jcallbackcode::Ccalbacks.AddCallbackHandled(l,handle);
}

export void RemoveRefsFromHandle(int handle)
{
	return jcallbackcode::Ccalbacks.RemoveRefsFromHandle(handle);
}
export void RemoveCallbackWithId(int id)
{
	return jcallbackcode::Ccalbacks.RemoveCallbackWithId(id);
}

export void InitJassLuaCallbacks()
{
	if (IsInGame())
	{
		mlog::Debug("In game, initializeing callbacks");
		int id = FindJassNameHandle(NATIVE_NAME_RunNow);
		if (id == 0)
		{
			mlog::Debug("Run now native was not initialized, initializing now");
			mlog::Debug("Registring native: ",RegisterNative((DWORD)&jcallbackcode::NATIVE_RunNow, NATIVE_NAME_RunNow, "(I)B"));
			mlog::Debug("Registring Name: ", NATIVE_NAME_RunNow);
			RegisterStr(NATIVE_NAME_RunNow);
			id = FindJassNameHandle(NATIVE_NAME_RunNow);
			mlog::Debug("Finded id: ", id);
		}
		mlog::Debug("Run Now Native was initialized");
		if (id != 0) JIdThreadRun = id;
		id = FindJassNameHandle(NATIVE_NAME_Restore);
		if (id == 0)
		{
			RegisterNative((DWORD)&jcallbackcode::NATIVE_Restore, NATIVE_NAME_Restore, "(I)B");
			RegisterStr(NATIVE_NAME_Restore);
			id = FindJassNameHandle(NATIVE_NAME_Restore);
		}
		if (id != 0) JIdThreadContinue = id;
		mlog::Debug("Callbacks were initialized");
	}
}

//export void HookJassRun(bool flag)
//{
//	isjhookenabled = flag;
//	if (!flag) return ;
//	if (!isjrunhooked)
//	{
//		rcmp::hook_function<DWORD(__thiscall*)(DWORD, DWORD, DWORD, DWORD,DWORD)>(pJThreadRun, [](auto original, DWORD pThread, DWORD pfunc, DWORD a, DWORD b,DWORD c) {
//			ptoclip(c);
//			switch (c)
//			{
//			case THREAD_ID_Callback:
//			{
//				TextPrint("Thread id callback!");
//				return (DWORD)1;
//			}
//			case THREAD_ID_TimerCallback:
//			{
//				//return CallCallback();
//				break;
//			}
//			case THREAD_ID_TriggerAction:
//			{
//				//return CallCallback();
//				break;
//			}
//			case THREAD_ID_TriggerCondition:
//			{
//				//return CallCallback();
//				break;
//			}
//			case THREAD_ID_RestoreThread:
//			{
//				//return CallCallback();
//				break;
//			}
//			case THREAD_ID_RunNow:
//			{
//				//return CallCallback();
//				break;
//			}
//			}
//			return original(pThread,pfunc,a,b,c);
//			});
//	}
//}

