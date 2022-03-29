#include "Common Includes.h"
#include <BasicConstants.h>
#include <Functions.h>
#include <fstream>
#include <Warcraft Functions.h>
#include <From MemHack.h>


namespace TestCommands
{


	int Handles(char* enteredString)
	{
		DWORD handles = dwGameDll + 0xAAF324;
		DWORD decorations = dwGameDll + 0xAB41F8;
		DWORD groups = dwGameDll + 0xAB6838;
		DWORD points = dwGameDll + 0xAB7174;
		DWORD items = dwGameDll + 0xAB4BC0;
		DWORD units = dwGameDll + 0xAB4288;
		DWORD triggers = dwGameDll + 0xAB7234;
		DWORD forces = dwGameDll + 0xAB67D8;
		DWORD Rects = dwGameDll + 0xAB6944;
		DWORD Timers = dwGameDll + 0xAB69D8;
		DWORD Effects = dwGameDll + 0xAB4B08;
		char buffer[20];
		_itoa_s(*(int*)handles, buffer, 10);
		cTextPrint(2, "All handles:", buffer);
		_itoa_s(*(int*)units, buffer, 10);
		cTextPrint(2, "Units:", buffer);
		_itoa_s(*(int*)decorations, buffer, 10);
		cTextPrint(2, "Decorations:", buffer);
		_itoa_s(*(int*)groups, buffer, 10);
		cTextPrint(2, "Groups:", buffer);
		_itoa_s(*(int*)points, buffer, 10);
		cTextPrint(2, "Locations:", buffer);
		_itoa_s(*(int*)Rects, buffer, 10);
		cTextPrint(2, "Rects:", buffer);
		_itoa_s(*(int*)items, buffer, 10);
		cTextPrint(2, "Items:", buffer);
		_itoa_s(*(int*)triggers, buffer, 10);
		cTextPrint(2, "Triggers:", buffer);
		_itoa_s(*(int*)forces, buffer, 10);
		cTextPrint(2, "Forces:", buffer);
		_itoa_s(*(int*)Timers, buffer, 10);
		cTextPrint(2, "Timers:", buffer);
		_itoa_s(*(int*)Effects, buffer, 10);
		cTextPrint(2, "Effects:", buffer);
		return 0;
	}

	int ClipboardSelectedUnitAddress(char* enteredString)
	{
		
		char temp[50];
		int t_int = FirstLocalSelected();
		t_int = GetUnitAddress(t_int);
		itoa(t_int, temp, 16);
		TextPrint(temp);
		TextToClipboard(temp);
		TextPrint("Copied To Clipboard");
		return 0;
	}

	std::ofstream GetFrameByNameData;

	int tnumber;
	int teax, tebx;
	char* tname;
	DWORD ret2GetFrameByName;

	void  __fastcall SendGetFrameByNameData()
	{
		static int initialized = 0;
		if (initialized == 0)
		{
			initialized = 1;
			GetFrameByNameData.open("GetFrameByNameData.txt");
		}
		GetFrameByNameData << tnumber << ": "<< tebx  << ": "<< teax << ": " << tname <<std::endl;
		return;
	}

	void _declspec(naked) CatchGetFrameByName()
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
			mov tnumber, edx
			mov tname, ecx
			mov tebx, ebx
			mov teax, eax
		}
		SendGetFrameByNameData();
		__asm
		{
			pop ebp
			pop esi
			pop ebx
			pop edx
			pop ecx
			pop eax
			pop edi
			push ecx
			lea eax,[esp]
			push eax
			jmp ret2GetFrameByName
		}
	}

	void InitGetFrameByNameHook()
	{
		WriteJmp(dwGameDll + 0x5FA970, (DWORD)CatchGetFrameByName);
		ret2GetFrameByName = dwGameDll + 0x5FA970 + 5;
	}

	void DetachGetFrameByNameHook()
	{
			GetFrameByNameData.close();
			Patch(dwGameDll + 0x5FA970, "\x5E\x5F\xC3\xCC\xCC", 5);
	}

	int GetFrameByNameHookChange(char* c)
	{
		static int init = 0;
		if (init == 0)
		{
			InitGetFrameByNameHook();
			TextPrint("inited");
			init = 1;
		}
		else
		{
			DetachGetFrameByNameHook();
			TextPrint("DETACHED");
			init = 0;
		}
		return 0;
	}

	void OnDetach()
	{
		DetachGetFrameByNameHook();
	}

	void Init()
	{
		Commands["handles"] = Handles;
		Commands["csua"] = ClipboardSelectedUnitAddress;
		Commands["cgfbn"] = GetFrameByNameHookChange;
	}
}