#include <lua.hpp>
#include <set>
#include <memory>
#include <iostream>
#include "DataNode Info Types.h"
#include <fstream>
#include <Logs\Log.h>
#pragma comment(lib,"LUA.lib")

#define cout std::cout
#define endl std::endl

export module LuaObserver;

import Dispatcher;
export import EventTransporters;
export import EventDispatcherBase;
import EventData;
//import GeneralDispatcher;

constexpr const char* DISPATCHER_NAME = "__DISPATCHER";
constexpr const char* EVENTTABLE_NAME = "__EVENTTABLE_REF";

export class LuaObserver :public ObserverBase
{
private:
	lua_State* l;
	int eventtable;
public:
	int callback;
	LuaObserver(lua_State* _l) :l(_l),callback(LUA_REFNIL), eventtable(LUA_REFNIL) ,ObserverBase()
	{
		int top = lua_gettop(l);
		lua_getglobal(l, EVENTTABLE_NAME);
		if (lua_isnumber(l, -1))
		{
			eventtable = lua_tointeger(l, -1);
		}
		lua_settop(l, top);
	}
	void AcceptMessage(std::shared_ptr<EventData> data)
	{
		int top = lua_gettop(l);
		lua_rawgeti(l, LUA_REGISTRYINDEX, callback);
		lua_pushlightuserdata(l, data.get());
		lua_rawgeti(l, LUA_REGISTRYINDEX, eventtable);
		//cout << "getted event table, type is: " << lua_type(l, -1) << endl;
		lua_setmetatable(l, -2);
		if (lua_getmetatable(l, -1))
		{
			//cout << "metatable exists" << endl;
			lua_pop(l, 1);
		}
		else
		{
			//cout << "metatable does not exists" << endl;
		}
		const char* result = (char*)lua_pcall(l, 1, 0, 0);
		if (result)
		{
			mlog::Error(lua_tostring(l, -1));
		}
		lua_settop(l, top);

	}
	void SetCallback(int _callback)
	{
		int top = lua_gettop(l);
		if (callback != LUA_REFNIL) luaL_unref(l, LUA_REGISTRYINDEX, callback);
		callback = _callback;
		lua_settop(l, top);
	}
	
	~LuaObserver()
	{
		luaL_unref(l, LUA_REGISTRYINDEX, callback);
		callback = -1;
		Disconnect();
	}
};



int lua_getEventId(lua_State* l)
{
	luaL_checkstack(l, 3, "1 argument expected");
	EventData* obs = (EventData*)lua_touserdata(l, 1);
	if (!obs) return luaL_error(l, "Unable to get data(is not userdata)");
	lua_pushnumber(l, obs->EventId());
	return 1;
}

export int lua_getDataWithId(lua_State* l)
{
	luaL_checkstack(l, 3, "2 arguments expected");
	luaL_checkinteger(l, 2);
	EventData* event = (EventData*)lua_touserdata(l, 1);
	if (!event) return luaL_error(l, "Unable to get userdata");
	int id = lua_tointeger(l, 2);
	switch (event->InfoTypeAt(id))
	{
	case(DATANODE_TYPE_INT):
		lua_pushnumber(l, event->DataAtToInt(id));
		return 1;
	case(DATANODE_TYPE_FLOAT):
	{
		lua_pushnumber(l, event->DataAtToFloat(id));
		return 1;
	}
	case(DATANODE_TYPE_CSTR):
	case(DATANODE_TYPE_STRING):
		lua_pushstring(l, event->DataAtToCString(id));
		return 1;
	}
	return 0;
}

export int lua_SetDataAt(lua_State* l)
{
	luaL_checkstack(l, 3, "3 arguments expected");
	EventData* event = (EventData*)lua_touserdata(l, 1);
	if (!event) return luaL_error(l, "Unable to get userdata");
	luaL_checknumber(l, 2);
	int id = lua_tointeger(l, 2);
	switch (lua_type(l, 3))
	{
	case(LUA_INT_TYPE):
		lua_pushboolean(l, event->SetDataAt(id, (int)lua_tointeger(l, 3)));
		return 1;
	case(LUA_FLOAT_TYPE):
		lua_pushboolean(l, event->SetDataAt(id, lua_tonumber(l, 3)));
		return 1;
	case(LUA_TSTRING):
		lua_pushboolean(l, event->SetDataAt(id, std::string(lua_tostring(l, 3))));
		return 1;
	default:
		lua_pushboolean(l, false);
		return 1;
	}
	return 0;
}

export int lua_CancelEvent(lua_State* l)
{
	luaL_checkstack(l, 1, "1 argument expected");
	EventData* event = (EventData*)lua_touserdata(l, 1);
	if (!event) return luaL_error(l, "Unable to get userdata");
	event->Cancel();
	return 0;
}

export int lua_ObserveEvent(lua_State* l)
{
	luaL_checknumber(l, 2);
	if (!lua_isfunction(l, 3))
	{
		return luaL_error(l, "Callback must be function");
	}
	//cout << "event:new calling" << endl;
	if (!lua_istable(l, 1)) return luaL_error(l, "eventObserver:new(id) must be called with metatable");
	int id = lua_tonumber(l, 2);
	int args = lua_gettop(l);
	lua_getglobal(l, DISPATCHER_NAME);
	int dispatcherpos = lua_gettop(l);
	EventDispatcherBase* dispatcher = (EventDispatcherBase*)lua_touserdata(l, dispatcherpos);
	if (!dispatcher) return luaL_error(l, "incorrect dispatcher, may be corrupted");
	LuaObserver* obs = new LuaObserver(l);
	//cout << "trying to add observer" << endl;
	if (!dispatcher->AddObserver(id, obs))
	{
		//cout << "Unable to connect with event" << id << endl;
		delete obs;
		return 0;
	}
	//cout << "adding observer was completed successfully" << endl;
	lua_pushvalue(l, args);
	obs->SetCallback(luaL_ref(l, LUA_REGISTRYINDEX));
	LuaObserver** ref = (LuaObserver **)lua_newuserdata(l, sizeof(EventDispatcherBase*));
	*ref = obs;
	//lua_pushlightuserdata(l, obs);
	int obspos = lua_gettop(l);
	lua_pushvalue(l, 1);
	lua_setmetatable(l, obspos);
	lua_settop(l, obspos);
	return 1;
}

export int lua_HasEventWithId(lua_State* l)
{
	luaL_checkstack(l, 1, "1 argument expected");
	luaL_checknumber(l, -1);
	int id = lua_tonumber(l, -1);
	int top = lua_gettop(l);
	lua_getglobal(l, DISPATCHER_NAME);
	EventDispatcherBase* dispatcher = (EventDispatcherBase*)lua_touserdata(l, -1);
	lua_settop(l, top);
	lua_pushboolean(l, dispatcher->GetEventWithId(id)!=nullptr);
	return 1;
}

export int lua_CountListeners(lua_State* l)
{
	luaL_checkstack(l, 1, "1 argument expected");
	luaL_checknumber(l, -1);
	int id = lua_tonumber(l, -1);
	int top = lua_gettop(l);
	lua_getglobal(l, DISPATCHER_NAME);
	EventDispatcherBase* dispatcher = (EventDispatcherBase*)lua_touserdata(l, -1);
	lua_settop(l, top);
	lua_pushnumber(l, dispatcher->CountListeners(id));
	return 1;
}

export int lua_RemoveObserver(lua_State* l)
{
	//cout << "Destroying observer" << endl;
	LuaObserver** obs = (LuaObserver**)lua_touserdata(l, 1);
	mlog::Debug("Destroying observer");
	if (!obs) return luaL_error(l, "incorrect observer");

	luaL_unref(l, LUA_REGISTRYINDEX, ( * obs)->callback);
	delete *obs;
	return 0;
}

export int lua_Disconnect(lua_State* l)
{
	//cout << "Destroying observer" << endl;
	LuaObserver** obs = (LuaObserver**)lua_touserdata(l, 1);
	if (!obs) return luaL_error(l, "incorrect observer");
	(* obs)->Disconnect();
	return 0;
}

export int InitEventData(lua_State* l)
{
	int top = lua_gettop(l);
	int ref = LUA_REFNIL;
	lua_newtable(l);
	int table = lua_gettop(l);
	//mlog::Debug("table initialized");
	lua_pushcclosure(l, lua_getEventId, 0);
	lua_setfield(l, table, "id");
	//mlog::Debug("EventId Initialized");
	lua_pushcclosure(l, lua_getDataWithId, 0);
	lua_setfield(l, table, "getData");
	//mlog::Debug("GetData Initialized");
	lua_pushcclosure(l, lua_SetDataAt, 0);
	lua_setfield(l, table, "setData");
	//mlog::Debug("setData Initialized");
	lua_pushcclosure(l, lua_CancelEvent, 0);
	lua_setfield(l, table, "cancel");
	//mlog::Debug("cancel Initialized");
	ref = luaL_ref(l, LUA_REGISTRYINDEX);
	//mlog::Debug("ref was created");
	lua_rawgeti(l, LUA_REGISTRYINDEX, ref);
	lua_setfield(l, -1, "__index");
	//mlog::Debug("setting __index field in metatable");
	lua_pushnumber(l, ref);
	lua_setglobal(l, EVENTTABLE_NAME);
	//mlog::Debug("setting eventtable ref global");
	lua_settop(l, top);
	//mlog::Debug("Restoring stack");
	return ref;
}

export LUAMOD_API int luaopen_events(lua_State* l)
{
	int top = lua_gettop(l);
	lua_newtable(l);
	int table = lua_gettop(l);
	lua_pushcclosure(l, lua_RemoveObserver, 0);
	lua_setfield(l, table, "__gc");
	lua_pushcclosure(l, lua_ObserveEvent, 0);
	lua_setfield(l, table, "new");
	lua_pushcclosure(l, lua_HasEventWithId, 0);
	lua_setfield(l, table, "hasEventWithId");
	lua_pushcclosure(l, lua_CountListeners, 0);
	lua_setfield(l, table, "countListeners");
	lua_pushcclosure(l, lua_Disconnect, 0);
	lua_setfield(l, table, "disconnect");
	lua_settop(l, table);
	lua_setglobal(l, "event");
	lua_settop(l, top);
	return 1;
}