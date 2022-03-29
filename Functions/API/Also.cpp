#include <BasicConstants.h>
#include <Windows.h>
#include <Additional Native Constants.h>

DWORD GetWidgetUnderCursor()
{
	return ReadRealMemory(pWidgetUnderCursor);
}

void MouseDownInstant(int id)
{
    if(GetForegroundWindow() != hwndwc) return;
	DWORD Engine = ReadRealMemory(pEventEngine);
	DWORD x = ReadRealMemory(pMouseScreenX);
	DWORD y = ReadRealMemory(pMouseScreenY);
	__asm
	{
		push 0
		push y
		push x
		push Engine
		mov EAX, id
		mov EDX, pClickMouseWC3down
		call EDX
	}
}

void MouseUpInstant(int id)
{
	if (GetForegroundWindow() != hwndwc) return;
	DWORD Engine = ReadRealMemory(pEventEngine);
	DWORD x = ReadRealMemory(pMouseScreenX);
	DWORD y = ReadRealMemory(pMouseScreenY);
	__asm
	{
		push 0
		push y
		push x
		push Engine
		mov EAX, id
		mov EDX, pClickMouseWC3up
		call EDX
	}
}


void MouseDownInstantXY(int id, DWORD x, DWORD y)
{
	if (GetForegroundWindow() != hwndwc) return;
	DWORD Engine = ReadRealMemory(pEventEngine);
	__asm
	{
		push 0
		push y
		push x
		push Engine
		mov EAX, id
		mov EDX, pClickMouseWC3down
		call EDX
	}
}

void MouseUpInstantXY(int id,DWORD x, DWORD y)
{
	if (GetForegroundWindow() != hwndwc) return;
	DWORD Engine = ReadRealMemory(pEventEngine);
	__asm
	{
		push 0
		push y
		push x
		push Engine
		mov EAX, id
		mov EDX, pClickMouseWC3up
		call EDX
	}
}

void MouseClickInstantXY(int id, DWORD x, DWORD y)
{
	MouseDownInstantXY(id, x, y);
	MouseUpInstantXY(id, x, y);
}

void MouseClickInstant(int id)
{
	MouseDownInstant(id);
	MouseUpInstant(id);
}