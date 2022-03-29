#include <From MemHack.h>
#include <Windows.h>
export module CommandBarButton;

bool IsCommandBarShown(DWORD pCommandBar)
{
	if (!pCommandBar) return false;
	return (ReadRealMemory(pCommandBar + 0x90) != NULL);
}