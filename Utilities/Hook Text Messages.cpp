#include <BasicConstants.h>
#include <fstream>
#include <Functions.h>
#include <Logs/Log.h>
#include <Extern Natives.h>
#include <rcmp.hpp>

DWORD Ret2ChatEroor;
DWORD Ret2Loading;
char* errmsgAddress;
char* interestingtext;
char* loadingcommands;
std::ofstream MapErrorOut;
std::ofstream Storm578Text;
std::ofstream CommandsLoading;
std::ofstream NetMsg;
int MapErrInit = 0;
int Storm578HookInit = 0;
int NetMsgHookInit = 0;
int isCommandsLoadinghook = 0;
int playernumber;
int oldesp;
char* msg;
int retaddr;
char oldchatmsg[6];
DWORD tESP;




void  sendChatError2File()
{
	static int initialized = 0;
	if (initialized == 0)
	{
		initialized = 1;
		MapErrorOut.open("OnMapLoadErrors.txt");
	}
	MapErrorOut << errmsgAddress << std::endl;
	return;
}

void _declspec(naked) CatchChatError()
{
	__asm
	{
		push edi
		push eax
		push ecx
		push edx
		push ebx
		push esi
		push ebp
		mov ebp,[esp+28]
		mov errmsgAddress,ebp
	}
	sendChatError2File();
	__asm
	{
		pop ebp
		pop esi
		pop ebx
		pop edx
		pop ecx
		pop eax
		pop edi
		add esp, 20
		pop edi
		pop esi
		jmp Ret2ChatEroor
	}
}


void InitMapErrorHook()
{
	MapErrInit = 1;
	WriteJmp(dwGameDll+0x3B195A, (DWORD)CatchChatError);
	Ret2ChatEroor = dwGameDll + 0x3B195A + 5;
}

void DetachMapErrorHook()
{
	if (MapErrInit == 1)
	{
		MapErrorOut.close();
		Patch(dwGameDll + 0x3B195A, "\x83\xC4\x14\x5F\x5E", 5);
		MapErrInit = 0;
	}
	return;
}

void  SendInterestingText()
{
	static int initialized = 0;
	if (initialized == 0)
	{
		initialized = 1;
		Storm578Text.open("InterestingText.txt");
	}
	Storm578Text << interestingtext << std::endl;
	return;
}

void _declspec(naked) CatchInterestiongText()
{
	__asm
	{
		push edi
		push eax
		push ecx
		push edx
		push ebx
		push esi
		push ebp
		mov interestingtext, edi
	}
	SendInterestingText();
	__asm
	{
		pop ebp
		pop esi
		pop ebx
		pop edx
		pop ecx
		pop eax
		pop edi
		POP ESI
		POP EDI
		RETN
	}
}

void InitInterestingTextHook()
{	
	DWORD dwStorm = (DWORD)GetModuleHandle("Storm.dll");
	if (Storm578HookInit == 0)
	{
		Storm578HookInit = 1;
		WriteJmp(dwStorm + 0x34182, (DWORD)CatchInterestiongText);
		Ret2ChatEroor = dwGameDll + 0x3B195A + 5;
	}
}

void DetachInterestingTextHook()
{
	if (Storm578HookInit == 1)
	{
		Storm578Text.close();
		DWORD dwStorm = (DWORD)GetModuleHandle("Storm.dll");
		Patch(dwStorm + 0x34182, "\x5E\x5F\xC3\xCC\xCC", 5);
		Storm578HookInit = 0;
	}
}

void  __fastcall SendLoadingcommands()
{
	static int initialized = 0;
	if (initialized == 0)
	{
		initialized = 1;
		CommandsLoading.open("LoadingCommands.txt");
	}
	CommandsLoading << loadingcommands << std::endl;
	return;
}

void _declspec(naked) CatchLoadingCommands()
{
	__asm
	{

		push esp
		push edi
		push eax
		push ecx
		push edx
		push ebx
		push esi
		push ebp
		mov loadingcommands, ecx
		call SendLoadingcommands
		pop ebp
		pop esi
		pop ebx
		pop edx
		pop ecx
		pop eax
		pop edi
		pop esp
		mov eax, [esp + 0x14]
		push esi
		jmp Ret2Loading

	}
}

void CommandsInitHook()
{
	if (isCommandsLoadinghook == 0)
	{
		isCommandsLoadinghook = 1;
		WriteJmp(dwGameDll + 0x7B2D30, (DWORD)CatchLoadingCommands);

		Ret2Loading = dwGameDll + 0x7B2D30 + 5;
	}
}

void detachCommandsInitHook()
{
	if (isCommandsLoadinghook == 1)
	{
		CommandsLoading.close();
		Patch(dwGameDll + 0x7B2D30, "\x8B\x44\x24\x14\x56", 5);
		isCommandsLoadinghook = 0;
	}
}

void  NetMsgCatchSave(char* format, ...)
{
	char buffer[1000];
	va_list params;
	va_start(params, format);
	vsprintf(buffer, format, params);
	va_end(params);
	static int initialized = 0;
	if (initialized == 0)
	{
		initialized = 1;
		NetMsg.open("NetText.txt");
	}

	NetMsg << buffer;
	return;
}

void _declspec(naked) NetMsgCatch()
{
	__asm
	{
		jmp NetMsgCatchSave
	}
}

void NetMsgInitHook()
{
	if (NetMsgHookInit == 0)
	{
		NetMsgHookInit = 1;
		WriteJmp(dwGameDll + 0x20BC60, (DWORD)NetMsgCatchSave);
	}
}

void detachNetMsgInitHook()
{
	if (NetMsgHookInit == 1)
	{
		NetMsg.close();
		Patch(dwGameDll + 0x7B2D30, "\xC3\xCC\xCC\xCC\xCC", 5);
		NetMsgHookInit = 0;
	}
}

void printchatmsg()
{
	LogS() << "[Chat]: " << jGetPlayerName(jPlayer(playernumber)) << ": " << msg << std::endl;
}

void __declspec(naked) realchathook()
{
	__asm
	{
		mov playernumber, ESP - 8
		mov msg, ESP - 12
	}
	retaddr = dwGameDll + 0x2FB480;
	printchatmsg();
	__asm
	{
		sub ESP, 4
		jmp retaddr;
	}

}

void HookNetEvents()
{
	static FILE* f = fopen("GoodTool/netevents.txt","w");
	rcmp::hook_function<void(__cdecl*)(char* format,int a, char* b)>(dwGameDll + 0x20bc60, [](auto original, char* format, int a, char* b) {
		fprintf(f,format, a, b);
		fflush(f);
		original(format,a,b);
	});
}

void initrealchathook()
{
	memcpy(oldchatmsg, (void*)((long)dwGameDll + 0x2FB480), 6);
}