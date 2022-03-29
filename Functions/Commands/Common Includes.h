#pragma once
#include <Windows.h>
#include <map>
#include <string>

extern int GetIntFromString(char* enterefString);
extern HMODULE ThisLib;
extern std::map<std::string, void*> Commands;
extern char* sstrcat(char* a, char* b);
extern int GameType();