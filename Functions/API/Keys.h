#pragma once
#include <string>


const char* ToUpper(std::string s);
int _StrToVKey(const std::string& skey);
std::string _VKeyToStr(int vkey);
std::string CovertKeyCodeToString(unsigned int val);
unsigned int CovertStringToKeyCode(std::string code);
int ConvertKeyStringToKeyCode(const char* str);
const char* ConvertKeyCodeToKeyString(unsigned int code);
bool IsKeyPressed(int key);