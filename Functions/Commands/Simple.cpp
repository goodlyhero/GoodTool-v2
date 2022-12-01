#include <../main.h>
#include <string>
#include <map>
#include <Functions.h>
#include <Warcraft Functions.h>
#include <PrintDmg.h>
#include <iostream>

extern int GetIntFromString(char* enterefString);
extern std::map<std::string, void*> Commands;

int EnableDmgPrint(char* enteredString)
{
	int value;
	try
	{
		value = GetIntFromString(enteredString);
	}
	catch (int i)
	{
		return 1;
	}
	PrintDmgMode(value);
	TextPrint(value == 0?"Dmg Printing was disabled":"Dmg Printing was enabled");
	return 0;
}

void InitSimpleCommands()
{
	Commands["dmgmode"] = EnableDmgPrint;
}