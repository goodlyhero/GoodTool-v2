#include "LuaEngine.h"
#include <Logs\Log.h>
constexpr const char* DISPATCHER_NAME = "__DISPATCHER";

import LuaObserver;
import Dispatcher;


static void* l_alloc(void* ud, void* ptr, size_t osize, size_t nsize) {
    (void)ud; (void)osize;  /* not used */
    if (nsize == 0) {
        free(ptr);
        return NULL;
    }
    else
        return realloc(ptr, nsize);
}


static int panic_s(lua_State* L) {
    const char* msg = lua_tostring(L, -1);
    if (msg == NULL) msg = "error object is not a string";
    mlog::Error("PANIC: unprotected error in call to Lua API (%s)\n",
        msg);
    return 0;  /* return to Lua to abort */
}


/*
** Warning functions:
** warnfoff: warning system is off
** warnfon: ready to start a new message
** warnfcont: previous message is to be continued
*/
static void warnf(void* ud, const char* message, int tocont)
{
    mlog::Debug("lua warning: ", message);
};

LUALIB_API lua_State* luaL_newstate_s(void) {
    lua_State* L = lua_newstate(l_alloc, NULL);
    if (L) {
        lua_atpanic(L, &panic_s);
        lua_setwarnf(L, warnf, L);  /* default is warnings off */
    }
    return L;
}


namespace lua
{

    
        TLua::TLua(const char* _name, EventDispatcherBase* dispatcher):lua(luaL_newstate_s())
        {
            name = _name;

            if (lua == NULL)
            {
                TextPrint("Lua was not initialized");
            }
            int top = lua_gettop(lua);
            mlog::Debug("Lua State was created: ", _name);
            isowner = true;
            binder = new rf::wrapper::LuaBinder(lua);
            mlog::Debug("Opening standart libs");
            luaL_openlibs(lua);
            mlog::Debug("std libs were opened, now defining dispatcher");
            lua_pushlightuserdata(lua, dispatcher);
            mlog::Debug("dispatcher pushed, now setting name");
            lua_setglobal(lua, DISPATCHER_NAME);
            mlog::Debug("Dispatcher was initialized, Initializing events");
            luaopen_events(lua);
            mlog::Debug("Events were opened, initializing event data");
            refeventdata = InitEventData(lua);
            //refeventdata = luaL_ref(lua, LUA_REGISTRYINDEX);
            mlog::Debug("Event data was initialized, not registing Event to require");
            luaL_requiref(lua, "Event", luaopen_events, 1);
            mlog::Debug("Lua state was initialized");
            lua_settop(lua, top);
        }

        void LogErrors(const char* err)
        {
            mlog::Debug(err);
            printf("%s \n",err);
        }

        TLua::TLua(lua_State* lua_state, const char* _name, EventDispatcherBase* dispatcher)
        {
            mlog::Debug("Lua was created: ", _name);
            name = _name;
            lua = lua_state;

            binder = new rf::wrapper::LuaBinder(lua);
            isowner = false;
        }

        TLua::~TLua()
        {
            mlog::Debug("The state destroyed: ", name.c_str());
            delete binder;
            if (isowner == true)
            {
                if (lua != NULL)
                {
                    lua_close(lua);
                }
            }
        }
         char* TLua::DoStr(const char* str)
        {
            int res = luaL_dostring(lua, str);
            if (res != 0)
            {
                return (char*)lua_tostring(lua, -1);
            }
            return NULL;
        }
         void TLua::DoStr(const char* str, const char* name)
        {
            int top = lua_gettop(lua);
            char* result = NULL;
            int res = luaL_loadbuffer(lua, str, strlen(str), name);
            // mlog::Debug("Loading script");
            if (!res)
            {
                //mlog::Debug("Running script");
                res = lua_pcall(lua, 0, 0, 0);
                if (res)
                {
                    //mlog::Debug("Error when running script");
                    result = (char*)lua_tostring(lua, -1);

                }
            }
            else
            {
                //mlog::Debug("Error when loading script");
                result = (char*)lua_tostring(lua, -1);
            }
            lua_settop(lua, top);
            if (result)
            {
                LogErrors(result); 
            }
        }

         void TLua::DoFile(const char* str)
        {
            int res = luaL_dofile(lua, str);
            if (res != 0)
            {
                char* error = (char*)lua_tostring(lua, -1);
                LogS() << "[lua error]: " << error << std::endl;
                TextPrint(error);
            }
        }
         int TLua::RegFunction(const char* name, int(*poin)(lua_State* st))
        {
            lua_register(lua, name, poin);
            return 0;
        }
         void TLua::CallNoArgsNoRet(const char* name)
        {
            lua_getglobal(lua, name);
            lua_pcall(lua, 0, 0, 0);
        }
         int TLua::ToInteger(int index)
        {
            return (int)lua_tointeger(lua, index);
        }
         double TLua::ToNumber(int index)
        {
            return lua_tonumber(lua, index);
        }
         const char* TLua::ToString(int index)
        {
            return lua_tostring(lua, index);
        }
         void TLua::Push(int i)
        {
            lua_pushinteger(lua, i);
        }
         void TLua::Push(char* str)
        {
            lua_pushstring(lua, str);
        }
         void TLua::PushNil()
        {
            lua_pushnil(lua);
        }
         void TLua::PushNumber(double d)
        {
            lua_pushnumber(lua, d);
        }
        template<class... args>
         void TLua::call_func(const char* name, args... argv)
        {
            binder->call_function(name, argv);
        }
         void  TLua::Pop(int count)
        {
            lua_pop(lua, count);
        }
         int TLua::GetTop()
        {
            return lua_gettop(lua);
        }
         void TLua::SetTop(int top)
        {
            lua_settop(lua, top);
        }
         int TLua::GetType(int index)
        {
            return lua_type(lua, index);
        }
         const char* TLua::GetTypeName(int TypeCode)
        {
            return lua_typename(lua, TypeCode);
        }
         void TLua::SetIntConst(int data, const char* name)
        {
            lua_pushnumber(lua, data);
            lua_setglobal(lua, name);
        }
         void TLua::Error()
         {
             lua_error(lua);
         }
}