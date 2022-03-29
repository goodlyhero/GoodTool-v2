#pragma once
#include <map>
#include <string>
#include <BasicConstants.h>
std::map<std::string, void*> Commands;

void InitMap();
void RestoreSpecial();