#include <BasicConstants.h>
bool IsChatBoxOpen()
{
	return *(bool *)(dwGameDll + 0xAD15F0);
}


bool IsInGame()
{
	return *(DWORD*)(dwGameDll + 0xab65f4) != 0;
}

int GameType()
{
	return **(int**)(dwGameDll + 0xAB65F4);
}