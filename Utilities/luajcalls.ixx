export module luajcalls;

export void MyFunc();


#include <States.h>
#include <Warcraft Functions.h>
#include <Functions.h>
#include <Jass Natives.h>
#include <Lua/LuaStates.h>
bool initialized = false;
int callback(int _state, int func)
{
	lua_State* state = (lua_State*)_state;
	
	if (state == lua::GetGlobalState()->lua || state == lua::GetLocalState()->lua)
	{
	}
}


void initialize()
{
	if (IsInGame())
	{

	}
}

void unitialize()
{
	initialized = false;
}