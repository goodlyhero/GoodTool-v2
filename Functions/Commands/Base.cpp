#include <map>
#include "Powerful.h"
#include "Test.h"
#include <LuaStates.h>
#include <Logs/Log.h>
#include <States.h>
#include <../main.h>
#include "Simple.h"

extern std::map<std::string, void*> Commands;

int isIWantOut = 0;
int isNoEndgame = 0;

extern void DetachPreparations();



int HelloWorld(char* enteredString)
{
	TextPrint("Hello World");
	return 0;
}
int PrintGameType(char* enteredString)
{
	char* temp = new char[30];
	itoa(*(int*)GameType(), temp, 10);
	TextPrint(temp, 5.0f);
	//cTextPrintEx(3, "GameType: \"", temp, "\"");
	delete[] temp;
	return 0;
}

int detachBegin(char* enteredString)
{
	TextPrint("|cFF5BDDFDWill be freed after some time|r");
	mlog::State("GoodTool Will Be Detached");
	DetachPreparations();
	return 0;
}

void RestoreSpecial()
{
	PowerfulCommands::RestoreResHook();
	//TestCommands::OnDetach();
	return;
}

void InitMap()
{
	Commands["hello"] = HelloWorld;
	Commands["detach"] = detachBegin;
	Commands["gtype"] = PrintGameType;
	InitSimpleCommands();
	if (!GoodToolSimple)
	{
		PowerfulCommands::Init();
		TestCommands::Init();
	}
	return;
};


