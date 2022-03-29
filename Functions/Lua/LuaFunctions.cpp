#include <iostream>
#include <memory>
#include <string>
#include <Functions.h>
#include "LuaFunctions.h"
#include "LuaStates.h"
#include <Calls.h>
#include <CNatives.h>
#include <From MemHack.h>
#include <Jass Natives.h>
#include <Extern Natives.h>
#include <luabinder.hpp>
#include <Hook Text Messages.h>
#include <map>
#include <LuaBridge.h>
#include <Properties.h>
#include <Widescreen.h>
#include <ShowSkillsForAllies.h>
#include <Windows.h>

import JassLuaThreadInteraction;
#define FastBind(x) binder->def(#x,x)
namespace lua
{
	extern TLua Lua;

}

int LId2Int(lua_State* io_luaState)
{
	if (lua_isstring(io_luaState, 1))
	{
		const char* c = lua_tostring(io_luaState, 1);
		lua_pushnumber(io_luaState, Id2Int(c));
	}
	else
	{
		return luaL_error(io_luaState, "Argument#1 should be of int type");
	}

	return 1;
}


int LSetGameTickSpeed(lua_State* io_luaState)
{
	DWORD iGSpeed = (dwGameDll + 0x553738);
	_geti(1, i_1)
		WriteInt(iGSpeed, i_1);
	return 0;
}

int LGetGameTickSpeed(lua_State* io_luaState)
{
	DWORD iGSpeed = (dwGameDll + 0x553738);
	lua_pushnumber(io_luaState, *(int*)iGSpeed);
	return 1;
}
int LGetGameDll(lua_State* io_luaState)
{
	lua_pushnumber(io_luaState, pGameDLL);
	return 1;
}

int LSetGameTickLen(lua_State* io_luaState)
{
	float* duration = (float*)(pTickDuration);
	_getf(1, f_1);
	*duration = f_1;
	return 0;
}

int LGetGameTickLen(lua_State* io_luaState)
{
	float* duration = (float*)(pTickDuration);
	lua_pushnumber(io_luaState, *duration);
	return 1;
}


	int LWriteRealMemory(lua_State* io_luaState)
	{
		int i;
		if (lua_isnumber(io_luaState, 1))
		{
			i = lua_tointeger(io_luaState, 1);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#1 should be of int type");
		}
		int i2;
		if (lua_isnumber(io_luaState, 2))
		{
			i2 = lua_tointeger(io_luaState, 2);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#2 should be of int type");
		}
		WriteRealMemory(i, i2);
		return 0;
	}


	int LWriteRealFloat (lua_State* io_luaState)
	{
		int i;
		if (lua_isnumber(io_luaState, 1))
		{
			i = lua_tointeger(io_luaState, 1);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#1 should be of int type");
		}
		float i2;
		if (lua_isnumber(io_luaState, 2))
		{
			i2 = lua_tonumber(io_luaState, 2);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#2 should be of float type");
		}
		WriteRealMemory(i, *(DWORD*)&i2);
		return 0;
	}

	int LReadRealMemory(lua_State* io_luaState)
	{
		int i;
		if (lua_isnumber(io_luaState, 1))
		{
			i = lua_tointeger(io_luaState, 1);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#1 should be of int type");
		}
		lua_pushnumber(io_luaState, ReadRealMemory(i));
		return 1;
	}

	int LReadRealFloat(lua_State* io_luaState)
	{
		int i;
		if (lua_isnumber(io_luaState, 1))
		{
			i = lua_tointeger(io_luaState, 1);
		}
		else
		{
			return luaL_error(io_luaState, "Argument#1 should be of int type");
		}
		DWORD d = ReadRealMemory(i);
		lua_pushnumber(io_luaState, *(float*)&d);
		return 1;
	}


	int LThiscall_1(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		lua_pushnumber(io_luaState, this_call(i1, i2));
		return 1;
	}
	int LThiscall_2(lua_State* io_luaState)
	{

		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3));
		return 1;
	}
	int LThiscall_3(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4));
		return 1;
	}
	int LThiscall_4(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5));
		return 1;
	}
	int LThiscall_5(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6));
		return 1;
	}
	int LDostring(lua_State* io_luaState)
	{
		const char* c;
		if (lua_isstring(io_luaState, 1))
		{
			c = lua_tostring(io_luaState, 1);
		}
		else
		{
			lua_pushboolean(io_luaState, false);
			lua_pushstring(io_luaState, "Error, cannot convert input to string Dostring, (stack[1])");
			return 2;
		}
		mlog::Debug("running script: ",c);
		int res = luaL_dostring(io_luaState, c);
		if (res != 0)
		{
			const char* result = lua_tostring(io_luaState, -1);
			mlog::Debug("Errors when run: ", result);
			lua_pushboolean(io_luaState, false);
			lua_pushstring(io_luaState, result);
			return 2;
		}
		lua_pushboolean(io_luaState, true);
		return 1;
	}
	int LThiscall_6(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7));
		return 1;
	}
	int LThiscall_7(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7, i8));
		return 1;
	}
	int LThiscall_8(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		_getDwEx(9, i9);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7, i8,i9));
		return 1;
	}
	int LThiscall_9(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		_getDwEx(9, i9);
		_getDwEx(10, i10);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7, i8,i9,i10));
		return 1;
	}
	int LThiscall_10(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		_getDwEx(9, i9);
		_getDwEx(10, i10);
		_getDwEx(11, i11);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7, i8,i9,i10,i11));
		return 1;
	}
	int LThiscall_11(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		_getDwEx(9, i9);
		_getDwEx(10, i10);
		_getDwEx(11, i11);
		_getDwEx(12, i12);
		lua_pushnumber(io_luaState, this_call(i1, i2, i3, i4, i5, i6, i7, i8,i9,i10,i11,i12));
		return 1;
	}

	int LFastcall_1(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		lua_pushnumber(io_luaState, fast_call(i1, i2));
		return 1;
	}
	int LFastcall_2(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3));
		return 1;
	}
	int LFastcall_3(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3, i4));
		return 1;
	}
	int LFastcall_4(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3, i4, i5));
		return 1;
	}
	int LFastcall_5(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3, i4, i5, i6));
		return 1;
	}
	int LFastcall_6(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3, i4, i5, i6, i7));
		return 1;
	}
	int LFastcall_7(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		lua_pushnumber(io_luaState, fast_call(i1, i2, i3, i4, i5, i6, i7, i8));
		return 1;
	}

	int LCdeclcall_1(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2));
		return 1;
	}
	int LCdeclcall_2(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3));
		return 1;
	}
	int LCdeclcall_3(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3, i4));
		return 1;
	}
	int LCdeclcall_4(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3, i4, i5));
		return 1;
	}
	int LCdeclcall_5(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3, i4, i5, i6));
		return 1;
	}
	int LCdeclcall_6(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3, i4, i5, i6, i7));
		return 1;
	}
	int LCdeclcall_7(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		lua_pushnumber(io_luaState, cdecl_call(i1, i2, i3, i4, i5, i6, i7, i8));
		return 1;
	}

	int LStdcall_1(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		lua_pushnumber(io_luaState, std_call(i1, i2));
		return 1;
	}
	int LStdcall_2(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3));
		return 1;
	}
	int LStdcall_3(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3, i4));
		return 1;
	}
	int LStdcall_4(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3, i4, i5));
		return 1;
	}
	int LStdcall_5(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3, i4, i5, i6));
		return 1;
	}
	int LStdcall_6(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3, i4, i5, i6, i7));
		return 1;
	}
	int LStdcall_7(lua_State* io_luaState)
	{
		_getDwEx(1, i1);
		_getDwEx(2, i2);
		_getDwEx(3, i3);
		_getDwEx(4, i4);
		_getDwEx(5, i5);
		_getDwEx(6, i6);
		_getDwEx(7, i7);
		_getDwEx(8, i8);
		lua_pushnumber(io_luaState, std_call(i1, i2, i3, i4, i5, i6, i7, i8));
		return 1;
	}

	int Cstring2LuaString(lua_State* io_luaState)
	{
		_geti(1, i);
		lua_pushstring(io_luaState, (char*)i);
		return 1;
	}

	int LGetJassVM(lua_State* io_luaState)
	{
		_geti(1, i);
		lua_pushnumber(io_luaState, GetJassVM(i));
		return 1;
	}
	int LGetJassTable(lua_State* io_luaState)
	{
		lua_pushnumber(io_luaState, GetJassTable());
		return 1;
	}

	bool __cdecl nativecondition(int i)
	{
		lua::TLua* lua = lua::GetLocalState();
		bool result = false;
		if (NULL != lua)
		{
			lua_getglobal(lua->lua, "run_condition");
			lua_pushnumber(lua->lua, i);
			lua_call(lua->lua, 1, 1);
			if (lua_isboolean(lua->lua, -1))
			{
				result = lua_toboolean(lua->lua, -1);
				lua_pop(lua->lua, 1);
			}
		}
		return result;
	}

	void __cdecl nativetest(int i)
	{
		char buffer[20];
		TextPrint(itoa(i, buffer, 10));
	}
	int RegisterTestFunc(lua_State* io_luaState)
	{
		_geti(1, i);
		RegisterNative((DWORD)nativetest, "test", "(I)V");
		DWORD nid = GetNativesCnt();
		RegisterFunction(CreateJassNcallFunction1arg(i, nid));
		lua_pushinteger(io_luaState, nid);
		return 0;
	}

	int TestRegisterFunc(lua_State* io_luaState)
	{
		_geti(1, i);
		RegisterNative((DWORD)nativetest, "test", "(I)V");
		DWORD nid = GetNativesCnt();
		RegisterFunction(CreateJassNcallFunction1arg(i, nid));
		lua_pushinteger(io_luaState, nid);
		return 0;
	}

	void __cdecl nativecallback(int i)
	{
		lua::TLua * lua = lua::GetLocalState();
		if (NULL != lua)
		{
			lua_getglobal(lua->lua, "run_callback");
			lua_pushnumber(lua->lua, i);
			lua_call(lua->lua, 1, 0);
		}
	}
	int RegisterActionNative(lua_State* io_luaState)
	{
		_gets(1, s);
		RegisterNative((DWORD)nativecallback, s, "(I)V");
		return 0;
	}

	
	int RegisterConditionNative(lua_State* io_luaState)
	{
		_gets(1, s);
		RegisterNative((DWORD)nativecondition, s, "(I)B");
		return 0;
	}

	int TestRegisterNative(lua_State* io_luaState)
	{
		_gets(1, s);
		lua_pushnumber(io_luaState, RegisterNative((DWORD)nativetest, s, "(I)V"));
		return 1;
	}

	int SetMetatableAdv(lua_State* io_luaState)
	{
		lua_State* L = io_luaState;
		int t = lua_type(L, 2);
		luaL_argexpected(L, t == LUA_TNIL || t == LUA_TTABLE, 2, "nil or table");
		lua_settop(L, 2);
		lua_setmetatable(L, 1);
		return 1;
	}

	int LAllocateMemInLTable(lua_State* io_luaState)
	{
		DWORD jVM = GetJassVM(1);
		DWORD pAllocator = jVM + 0x2890;
		DWORD pfunclist = jVM + 10376;
		lua_pushinteger(io_luaState, AllocatePlaceInJTable(pfunclist));
		return 1;
	}


	int RegisterFunctionNumberCallback(lua_State* io_luaState)
	{
		_geti(1, native);
		_geti(2, number);
		DWORD* t = CreateJassNcallFunction1arg(number, native);
		lua_pushinteger(io_luaState, RegisterFunction(t));
		lua_pushinteger(io_luaState, (unsigned int)t);
		return 2;
	}

	int TestLuaToBoolean(lua_State* io_luaState)
	{
		_getb(1, bool1);
		char buffer[20];
		TextPrint(itoa(bool1, buffer, 10));
		return 0;
	}
	int LRegisterFunction(lua_State* io_luaState)
	{
		_geti(1, i);
		lua_pushinteger(io_luaState, RegisterFunction((DWORD*)i));
		return 1;
	}

	int RegisterPureFunc(lua_State* io_luaState)
	{
		DWORD* t = CreatePureFunc();
		lua_pushinteger(io_luaState, RegisterFunction(t));
		return 1;
	}
	int RegisterFcallFunc(lua_State* io_luaState)
	{
		_geti(1, fid);
		_geti(2, number);
		DWORD* t = CreateJassFcallFunction1arg(number, fid);
		lua_pushinteger(io_luaState, RegisterFunction(t));
		return 1;
	}
	int LMalloc(lua_State* io_luaState)
	{
		_geti(1, i);
		lua_pushinteger(io_luaState, (int)malloc(i));
		return 1;
	}

	int LFree(lua_State* io_luaState)
	{
		_geti(1, i);
		free((void*)i);
		return 0;
	}

	int CType(lua_State* io_luaState)
	{
		lua_pushnumber(io_luaState, lua_type(io_luaState, 1));

		return 1;
	}


	int LuaGetWorkingDir(lua_State* io_luaState)
	{
		char* p = new char[MAX_PATH + 1];
		GetCurrentDirectoryA(MAX_PATH, p);
		p[MAX_PATH] = 0;
		if (p != NULL)
		{
			lua_pushfstring(io_luaState, p);
			delete[] p;
			return 1;

		}
		delete[] p;
		return 0;
	}

	int LuaGetTempPath(lua_State* io_luaState)
	{
		char* p = new char[MAX_PATH + 1];
		GetTempPathA(MAX_PATH, p);
		p[MAX_PATH] = 0;
		if (p != NULL)
		{
			lua_pushfstring(io_luaState, p);
			delete[] p;
			return 1;

		}
		delete[] p;
		return 0;
	}

	int LGetGameUI(lua_State* io_luaState)
	{
		lua_pushinteger(io_luaState, GetGameUI(0, 0));
		return 1;
	}

	int GetTestFunc(lua_State* io_luaState)
	{
		lua_pushnumber(io_luaState, (unsigned int)GetTestFunc);
		return 1;
	}


	int LGetJassNameById(lua_State* io_luaState)
	{
		_geti(1, i);
		lua_pushstring(io_luaState, GetJassNameById(ReadRealMemory(GetJassVM(1) + 10328), i));
		return 1;
	}

	int LRegStr(lua_State* io_luaState)
	{
		_gets(1, s);
		lua_pushinteger(io_luaState, RegStr(s));

		return 1;
	}

	int LGetJassEnvAddress(lua_State* io_luaState)
	{
		lua_pushinteger(io_luaState, (pGameDLL + 0xADA848));
		return 1;
	}

	int LTextPrint(lua_State* L)
	{
		std::string str = "";
		int n = lua_gettop(L);  /* number of arguments */
		int i;
		for (i = 1; i <= n; i++) {  /* for each argument */
			size_t l;
			const char* s = luaL_tolstring(L, i, &l);  /* convert it to string */
			if (i > 1)  /* not the first element? */
				str =str + " ";
			str = str + s;
			lua_pop(L, 1);  /* pop result */
		}
		TextPrint(str.c_str());
		return 0;
	}

	int LLog(lua_State* L)
	{
		std::string str = "";
		int n = lua_gettop(L);  /* number of arguments */
		int i;
		for (i = 1; i <= n; i++) {  /* for each argument */
			size_t l;
			const char* s = luaL_tolstring(L, i, &l);  /* convert it to string */
			if (i > 1)  /* not the first element? */
				str = str + " ";
			str = str + s;
			lua_pop(L, 1);  /* pop result */
		}
		mlog::Log(str.c_str());
		return 0;
	}

	int LReadString(lua_State* io_luaState)
	{
		int addr;
		if (lua_isnumber(io_luaState, 1))
		{
			addr = lua_tointeger(io_luaState, 1);
		}
		else
		{
			return luaL_error(io_luaState, "Address should be of int type");
		}
		if (addr < 500)
		{
			return luaL_error(io_luaState, "Address must be higher than 500!!!");
		}
		lua_pushstring(io_luaState, (char*)addr);
		return 1;
	}


	int LUnitAddAbility2(lua_State* L)
	{
		luaL_checkinteger(L, 1);
		luaL_checkinteger(L, 2);
		UnitAddAbility2(lua_tointeger(L, 1), lua_tointeger(L, 2));
		return 0;
	}

	int LCreateCallbackTable(lua_State* l)
	{
		jcallbackcode::LCheckTable(l);
		return 0;
	}

	int LGetTickCount(lua_State* l)
	{
		lua_pushnumber(l, GetTickCount());
		return 1;
	}

	int LGetTickCount64(lua_State* l)
	{
		lua_pushnumber(l, GetTickCount64());
		return 1;
	}
	namespace lua
	{
		void LuaInitCustomFunctions(lua::TLua& Lua)
		{
			auto binder = Lua.binder;
			FastBind(FirstLocalSelected);
			binder->def("FS", FirstLocalSelected);
			FastBind(GetMouseWorldX);
			FastBind(GetMouseWorldY);
			binder->def("MX", GetMouseWorldX);
			binder->def("MY", GetMouseWorldY);
			Lua.RegFunction("id2i", LId2Int);
			Lua.RegFunction("setgametickspeed", LSetGameTickSpeed);
			Lua.RegFunction("getgametickspeed", LGetGameTickSpeed);
			Lua.RegFunction("setgameticklen", LSetGameTickLen);
			Lua.RegFunction("getgameticklen", LGetGameTickLen);
			Lua.RegFunction("getgamedll", LGetGameDll);
			Lua.RegFunction("WriteRealMemory", LWriteRealMemory);
			Lua.RegFunction("ReadRealMemory", LReadRealMemory);
			Lua.RegFunction("WriteInt", LWriteRealMemory);
			Lua.RegFunction("ReadInt", LReadRealMemory);
			/*Lua.RegFunction("TestWindow", TestWindow);*/
			FastBind(TextToClipboard);
			Lua.RegFunction("fastcall1", LFastcall_1);
			Lua.RegFunction("fastcall2", LFastcall_2);
			Lua.RegFunction("fastcall3", LFastcall_3);
			Lua.RegFunction("fastcall4", LFastcall_4);
			Lua.RegFunction("fastcall5", LFastcall_5);
			Lua.RegFunction("fastcall6", LFastcall_6);
			Lua.RegFunction("fastcall7", LFastcall_7);
			Lua.RegFunction("thiscall1", LThiscall_1);
			Lua.RegFunction("thiscall2", LThiscall_2);
			Lua.RegFunction("thiscall3", LThiscall_3);
			Lua.RegFunction("thiscall4", LThiscall_4);
			Lua.RegFunction("thiscall5", LThiscall_5);
			Lua.RegFunction("thiscall6", LThiscall_6);
			Lua.RegFunction("thiscall7", LThiscall_7);
			Lua.RegFunction("thiscall8", LThiscall_8);
			Lua.RegFunction("thiscall9", LThiscall_9);
			Lua.RegFunction("thiscall10", LThiscall_10);
			Lua.RegFunction("thiscall11", LThiscall_11);
			Lua.RegFunction("ccall1", LCdeclcall_1);
			Lua.RegFunction("ccall2", LCdeclcall_2);
			Lua.RegFunction("ccall3", LCdeclcall_3);
			Lua.RegFunction("ccall4", LCdeclcall_4);
			Lua.RegFunction("ccall5", LCdeclcall_5);
			Lua.RegFunction("ccall6", LCdeclcall_6);
			Lua.RegFunction("ccall7", LCdeclcall_7);
			Lua.RegFunction("stdcall1", LStdcall_1);
			Lua.RegFunction("stdcall2", LStdcall_2);
			Lua.RegFunction("stdcall3", LStdcall_3);
			Lua.RegFunction("stdcall4", LStdcall_4);
			Lua.RegFunction("stdcall5", LStdcall_5);
			Lua.RegFunction("stdcall6", LStdcall_6);
			Lua.RegFunction("stdcall7", LStdcall_7);
			FastBind(HandleIdToObject);
			FastBind(ConvertHandle);
			FastBind(ObjectToHandleId);
			Lua.RegFunction("Cstring2LuaString", Cstring2LuaString);
			Lua.RegFunction("GetJassVM", LGetJassVM);
			Lua.RegFunction("GetJassTable", LGetJassTable);
			Lua.RegFunction("TestRegisterNative", TestRegisterNative);
			Lua.RegFunction("TestRegisterFunc", TestRegisterFunc);
			Lua.RegFunction("AllocateMemInLTable", LAllocateMemInLTable);
			Lua.RegFunction("RegisterActionNative", RegisterActionNative);
			Lua.RegFunction("RegisterConditionNative", RegisterConditionNative);
			Lua.RegFunction("RegisterFunctionNumberCallback", RegisterFunctionNumberCallback);
			Lua.RegFunction("TestLuaToBoolean", TestLuaToBoolean);
			Lua.RegFunction("RegisterPureFunc", RegisterPureFunc);
			Lua.RegFunction("RegisterFcallFunc", RegisterFcallFunc);
			//Lua.RegFunction("RegisterConditionNativeTEST", RegisterConditionNativeTEST);
			//Lua.RegFunction("GetJassFuncIdByName", LGetJassFuncIdByName);
			Lua.RegFunction("GetJassNameById", LGetJassNameById);
			Lua.RegFunction("GetJassEnvAddress", LGetJassEnvAddress);
			Lua.RegFunction("RegStr", LRegStr);
			Lua.RegFunction("TestRegisterFunc", TestRegisterFunc);
			Lua.RegFunction("malloc", LMalloc);
			Lua.RegFunction("free", LFree);
			Lua.RegFunction("RegisterFunction", LRegisterFunction);
			Lua.RegFunction("GetGameUI", LGetGameUI);
			Lua.RegFunction("TextPrint", LTextPrint);
			Lua.RegFunction("gprint", LTextPrint);
			Lua.RegFunction("GetTestFunc", GetTestFunc);
			Lua.RegFunction("WriteFloat", LWriteRealFloat);
			Lua.RegFunction("ReadFloat", LReadRealFloat);
			Lua.RegFunction("ReadString", LReadString);
			Lua.RegFunction("UnitAddAbility2s", LUnitAddAbility2);
			Lua.RegFunction("GetTickCount", LGetTickCount);
			Lua.RegFunction("GetTickCount64", LGetTickCount64);

			binder->def("HookNetEvents", HookNetEvents);
			FastBind(ptoclip);
			Lua.RegFunction("GetWorkingDir", LuaGetWorkingDir);
			Lua.RegFunction("GetTempPath", LuaGetTempPath);
			Lua.RegFunction("CType", CType);
			Lua.RegFunction("Dostring", LDostring);
			Lua.RegFunction("Log", LLog);
			Lua.RegFunction("CreateCallbackTable", LCreateCallbackTable);
			//Lua.RegFunction("CreateThread", LuaCreateThread);
			Lua.RegFunction("SetMetatableAdv", SetMetatableAdv);
			binder->def("Int2Id", Int2Id);
			binder->def("i2id", Int2Id);
			binder->def("IntToHex", IntToHex);
			binder->def("LoadMod", LoadMod);
			FastBind(EnableWidescreen);
			FastBind(SetCustomFovFix);
			FastBind(ShowAllyPanel);
		}
	}
