#include <BasicConstants.h>
typedef int(__thiscall* TYPE_ChatCheckForSpecial) (DWORD*, char* msg);
TYPE_ChatCheckForSpecial ChatCheckForSpecial;
void InitNativeFunctions()
{
	ChatCheckForSpecial = (TYPE_ChatCheckForSpecial)(dwGameDll + 0x2F93B0);
}