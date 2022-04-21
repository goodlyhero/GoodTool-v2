#pragma once
#include <lua.hpp>
#include "../Logs/Log.h"
//import log;
#include <luabinder.hpp>
#include <Logs/Log.h>
#include "../Warcraft Functions.h"
#include <string>
#include <LuaBridge.h>

extern class EventDispatcherBase;

#define RLUA_IMPLEMENTATION

namespace lua
{

    class TLua
    {
    public:
        lua_State* lua;
        rf::wrapper::LuaBinder* binder;
        std::string name;
        bool isowner;
        TLua(const char* _name, EventDispatcherBase* dispatcher);
        TLua(lua_State* lua_state, const char* _name, EventDispatcherBase* dispatcher);
        int refeventdata;

        ~TLua();
        char* DoStr(const char* str);
        void DoStr(const char* str, const char* name);
        void DoFile(const char* str);
        int RegFunction(const char* name, int(*poin)(lua_State* st));
        void CallNoArgsNoRet(const char* name);
        int ToInteger(int index);
        double ToNumber(int index);
        const char* ToString(int index);
        void Push(int i);
        void Push(char* str);
        void PushNil();
        void PushNumber(double d);
        template<class... args>
        void call_func(const char* name, args... argv);
        void  Pop(int count);
        int GetTop();
        void SetTop(int top);
        int GetType(int index);
        const char* GetTypeName(int TypeCode);
        void SetIntConst(int data, const char* name);
        void Error();
        
    };
    void LogErrors(const char* err);

}

#define lua_setglobalfunction(L,f,name) \
lua_pushcclosure(L, f,0);\
lua_setglobal(L, name);