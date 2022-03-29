#include <BasicConstants.h>
#include <Functions.h>
export module UnlimitMapSize;

export void UnlockMapSize()
{
	DWORD buffer = 0xFFFFFFFF;
	Patch(dwGameDll + 0x6577e4, (char*)&buffer,4);
	Patch(dwGameDll + 0x66ED7F, (char*)&buffer,4);
	Patch(dwGameDll + 0x67EC61, (char*)&buffer,4);
}