#include <Commands\Base.h>
#include <LuaStates.h>
#include <BasicConstants.h>
#include <Functions.h>
#include <Mem_restorer.h>
#include <Additional Native Functions.h>
#include <Logs/Log.h>
#include <../main.h>
#include <Lua/Events.h>

import EVENTS;
import EVENT_CHAT_COMMAND;

int checkString(char* EnteredString)
{
	TextPrint(EnteredString, 30.0f);
	return 1;
}

std::string FindSub(char* mystr)
{
	std::string result;
	char* temp = mystr;
	int len = 0;
	while ((*temp != 0) && (*temp != ' '))
	{
		result += tolower(*temp);
		temp++;
	}
	return result;
}

bool StateRunChatCallback(lua::TLua* state, const char* msg)
{
	if (state == NULL) return true;
	lua_State* lua = state->lua;
	if (lua == NULL) return true;
	luabridge::LuaRef fun = luabridge::getGlobal(lua, "OnChatInput");
	if (!fun.isFunction()) return true;
	luabridge::LuaRef result = fun(msg);
	return result.cast<bool>();
}

int __fastcall CheckEnteredString(DWORD* it,char* useless, char* enteredString)
{
	if (enteredString[0] == '$')
	{
		TextPrintNoLog(enteredString);
		LogS() << "[command]: " << enteredString + 1 << std::endl;
		std::map<std::string, void*>::iterator mit = Commands.find(FindSub(enteredString + 1));
		if (mit != Commands.end())
		{
			Func_iChar toCall = (Func_iChar)(mit->second);
			if (toCall(enteredString))
			{
				TextPrint("Error");
				LogS() << "[warning]: Bad command" << std::endl;
			}
			return 1;
		}
		else
		{
			auto data = std::make_shared< EventDataChatcommand>(enteredString + 1);
			EVENT_CHAT_COMMAND.SendEvent(data);
			if (data->IsCanceled()) return 1;
		}

	}
	else if (!GoodToolSimple)
	{
		if (enteredString[0] == '#')
		{
			lua::TLua* lua = lua::GetGlobalState();
			if (NULL != lua)
			{
				LogS() << "[lua global]: Calling: " << enteredString + 1 << std::endl;
				char* error = lua->DoStr(enteredString + 1);
				if (NULL != error)
				{
					LogS() << "[lua global error] : " << error << std::endl;
					TextPrint(error);
				}
			}
			else
			{
				LogS() << "[error]: tryed to call string in global lua, but it can't be loaded, fuck" << std::endl;
				TextPrint("Cant Load Global Lua");
			}

			return 1;
		}
		else if (enteredString[0] == '%')
		{
			lua::TLua* lua = lua::GetLocalState();
			if (lua)
			{
				LogS() << "[lua local]: Calling: " << enteredString + 1 << std::endl;
				const char* error = lua->DoStr(enteredString + 1);
				if (NULL != error)
				{
					//mlog::Error("[local lua]: ",error);
					TextPrint(error);
				}
			}
			else
			{
				//mlog::Error("tryed to call string in local lua, but it can't be loaded, fuck");
				TextPrint("Can't Load Local Lua");
			}

			return 1;
		}
	}
	return ChatCheckForSpecial(it,enteredString);

}

void initChatHook() //creates hook
{
	DWORD toWrite = dwGameDll + 0x2FC77D;
	WriteDWORDSave(toWrite + 1, (DWORD)(CheckEnteredString)-(DWORD)(dwGameDll + 0x2FC77D + 5));
	InitMap();
	return;
}