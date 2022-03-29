#include "Common Includes.h"
#include <Functions.h>
#include <BasicConstants.h>
#include <Functions.h>
#include <fstream>
#include <Warcraft Functions.h>
#include <Hook Text Messages.h>
#include <ShowSkillsForAllies.h>


extern int isIWantOut;
extern int isNoEndgame;
extern void InitMapErrorHook();
extern void DetachMapErrorHook();
extern void InitInterestingTextHook();
extern void DetachInterestingTextHook();
extern int MapErrInit;
extern int Storm578HookInit;
std::ofstream DebugOut;

namespace PowerfulCommands
{
	int resHookActivated = 0;
	int wood2AddFromClick = 100;
	int gold2AddFromClick = 100;
	int WoodAct = 0;
	int GoldAct = 0;
	char ToWrite[1000];
	int isDebugTestHook = 0;
	int msghookstate = 0;

	DWORD ResRetAdress;

	int globalRemoveAsLimit(char* enteredString)
	{
		char* temp = enteredString;
		DWORD limit = dwGameDll + 0xC6F52;
		while ((*temp != 0) && (*temp != ' '))
		{
			temp++;
		}
		if (*temp == 0)
		{
			return 1;
		}
		else
		{
			temp++;
			switch (*temp)
			{
			case '1':
				Patch(limit, "\x05", 1);
				TextPrint("As limit was Restored");
				break;
			case '0':
				Patch(limit, "\x06", 1);
				TextPrint("As limit was Removed");
				break;
			default:
				return 1;
			}
		}
		return 0;

	}

#define IWantOutNativesToDisableCount 22
	int IWantOut(char* enteredString)
	{
		DWORD NativesToDisable[IWantOutNativesToDisableCount];
		NativesToDisable[0] = dwGameDll + 0x3b3880;  //EnableUserControl
		NativesToDisable[1] = dwGameDll + 0x3b3810;  //ShowInterface
		NativesToDisable[2] = dwGameDll + 0x3b4820;  //SetCinematicCamera
		NativesToDisable[3] = dwGameDll + 0x3b45d0;  //SetCameraPosition
		NativesToDisable[4] = dwGameDll + 0x3b4610;  //SetCameraQuickPosition
		NativesToDisable[5] = dwGameDll + 0x3b4700;  //PanCameraTo
		NativesToDisable[6] = dwGameDll + 0x3b4740;  //PanCameraToTimed
		NativesToDisable[7] = dwGameDll + 0x3b4790;  //PanCameraToWithZ
		NativesToDisable[8] = dwGameDll + 0x3b47d0;  //PanCameraToTimedWithZ
		NativesToDisable[9] = dwGameDll + 0x3b4820;  //SetCinematicCamera
		NativesToDisable[10] = dwGameDll + 0x3b4850; //SetCameraRotateMode
		NativesToDisable[11] = dwGameDll + 0x3cd900; //CameraSetupApply
		NativesToDisable[12] = dwGameDll + 0x3cd930; //CameraSetupApplyWithZ
		NativesToDisable[13] = dwGameDll + 0x3cd960; //CameraSetupApplyForceDuration
		NativesToDisable[14] = dwGameDll + 0x3cd990; //CameraSetupApplyForceDurationWithZ
		NativesToDisable[15] = dwGameDll + 0x3b4930; //CameraSetTargetNoise
		NativesToDisable[16] = dwGameDll + 0x3b49e0; //CameraSetSourceNoise
		NativesToDisable[17] = dwGameDll + 0x3b4a70; //CameraSetTargetNoiseEx
		NativesToDisable[18] = dwGameDll + 0x3b4b20; //CameraSetSourceNoiseEx
		NativesToDisable[19] = dwGameDll + 0x3b4bb0; //CameraSetSmoothingFactor
		NativesToDisable[20] = dwGameDll + 0x3b48b0; //SetCameraField
		NativesToDisable[21] = dwGameDll + 0x3b48f0; //AdjustCameraField
		switch (isIWantOut)
		{
		case 0:
			isIWantOut = 1;
			for (int i = 0; i < IWantOutNativesToDisableCount; i++)
			{
				Patch(NativesToDisable[i], "\xC3", 1);
			}
			TextPrint("I Want Out");
			break;
		case 1:
			isIWantOut = 0;
			Patch(NativesToDisable[0], "\x33", 1);
			Patch(NativesToDisable[1], "\x33", 1);
			Patch(NativesToDisable[2], "\x33", 1);
			Patch(NativesToDisable[3], "\x33", 1);
			Patch(NativesToDisable[4], "\x33", 1);
			Patch(NativesToDisable[5], "\x33", 1);
			Patch(NativesToDisable[6], "\x33", 1);
			Patch(NativesToDisable[7], "\x33", 1);
			Patch(NativesToDisable[8], "\x33", 1);
			Patch(NativesToDisable[9], "\x33", 1);
			Patch(NativesToDisable[10], "\x83", 1);
			Patch(NativesToDisable[11], "\x8B", 1);
			Patch(NativesToDisable[12], "\x8B", 1);
			Patch(NativesToDisable[13], "\x8B", 1);
			Patch(NativesToDisable[14], "\x8B", 1);
			Patch(NativesToDisable[15], "\x51", 1);
			Patch(NativesToDisable[16], "\x33", 1);
			Patch(NativesToDisable[17], "\x51", 1);
			Patch(NativesToDisable[18], "\x33", 1);
			Patch(NativesToDisable[19], "\x33", 1);
			Patch(NativesToDisable[20], "\x33", 1);
			Patch(NativesToDisable[21], "\x33", 1);
			TextPrint("I dont Want Out");
		}
		return 0;
	}

	int NoEndgame(char* enteredString)
	{
		DWORD NativesToDisable[3];
		NativesToDisable[0] = dwGameDll + 0x3bbbb0;  //Endgame
		NativesToDisable[1] = dwGameDll + 0x3bbc00;  //RestartGame
		//NativesToDisable[2] = (unsigned char*)dwGameDll + 0x3c9fe0;  //DialogAddQuitButton
		switch (isNoEndgame)
		{
		case 0:
			isNoEndgame = 1;
			Patch(NativesToDisable[0], "\xC3", 1);
			Patch(NativesToDisable[1], "\xC3", 1);
			TextPrint("With no Endgame");
			break;
		case 1:
			isNoEndgame = 0;
			Patch(NativesToDisable[0], "\x8B", 1);
			Patch(NativesToDisable[1], "\xE8", 1);
			TextPrint("With Endgame");
			break;
		}
		return 0;
	}

	int GameSpeed(char* enteredString)
	{
		char* temp = enteredString;
		while ((*temp != 0) && (*temp != ' '))
		{
			temp++;
		}
		if (*temp == 0)
		{
			return 1;
		}
		else
		{
			temp++;
			int len = 0;
			char* ttemp = temp;
			while ((*ttemp >= '0') && (*ttemp <= '9'))
			{
				len++;
				ttemp++;
			}
			if (len == 0)
			{
				return 1;
			}
			else
			{
				char* buffer = new char[len + 1];
				for (int i = 0; i < len; i++)
				{
					buffer[i] = *(temp + i);
				}
				buffer[len] = 0;
				int value = atoi(buffer);
				DWORD iGSpeed = (dwGameDll + 0x553738);
				WriteInt(iGSpeed, value);
				delete[] buffer;
			}
		}
		return 0;
	}

	int BrokeControlDisabling(char* enteredString)
	{
		char* temp = enteredString;
		DWORD disablecontrol = dwGameDll + 0x2FC1C3;
		while ((*temp != 0) && (*temp != ' '))
		{
			temp++;
		}
		if (*temp == 0)
		{
			return 1;
		}
		else
		{
			float ftemp[1];
			*ftemp = 0;
			temp++;
			switch (*temp)
			{
			case '1':
				Patch(disablecontrol, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10);
				break;
			case '0':
				Patch(disablecontrol, "\xC7\x86\xAC\x01\x00\x00\x00\x00\x00\x00", 10);
				TextPrint("Control disabling was restored");
				break;
			default:
				return 1;
			}
		}
		return 0;
	}

	void __declspec(naked) setRecource2Give()
	{
		__asm
		{
			mov eax, [edi + 0x00000168]
			cmp esi, 1
			je WOOD
			cmp GoldAct, 0
			je ToReturn
			mov eax, gold2AddFromClick
			jmp ToReturn
		}
	WOOD:
		__asm
		{
			cmp WoodAct, 0
			je ToReturn
			mov eax, wood2AddFromClick
		}
	ToReturn:
		__asm
		{
			jmp ResRetAdress
		}
	}

	void RestoreResHook()
	{
		if (1 == resHookActivated)
		{
			DWORD jmp = dwGameDll + 0x34DDAA;
			Patch(jmp, "\x8B\x87\x68\x01\x00\x00", 6);
		}
		return;
	}

	void ActivateGetResHook()
	{
		if (resHookActivated == 0)
		{
			DWORD jmp = dwGameDll + 0x34DDAA;
			Patch(jmp, "\xE9", 1);
			Patch(jmp + 5, "\x90", 1);
			WriteDWORD(jmp + 1, (DWORD)(setRecource2Give)-(dwGameDll + 0x34DDAF));
			resHookActivated = 1;
		}
		return;
	}

	int SetGold2Give(char* enteredString)
	{
		ResRetAdress = dwGameDll + 0x34DDB0;
		int value;
		try
		{
			value = GetIntFromString(enteredString);
		}
		catch (int i)
		{
			return 1;
		}
		ActivateGetResHook();
		gold2AddFromClick = value;
		GoldAct = 1;
		TextPrint("Gold to send setted");
		return 0;
	}

	int SetWood2Give(char* enteredString)
	{
		ResRetAdress = dwGameDll + 0x34DDB0;
		int value;
		try
		{
			value = GetIntFromString(enteredString);
		}
		catch (int i)
		{
			return 1;
		}
		ActivateGetResHook();
		wood2AddFromClick = value;
		WoodAct = 1;
		TextPrint("Lumber to send setted");
		return 0;
	}

	int AttachMapErrorHook(char* enteredString)
	{
		if (MapErrInit == 0)
		{
			InitMapErrorHook();
			TextPrint("Recording");
		}
		else
		{ 
			DetachMapErrorHook();
			TextPrint("Not Recording");
		}
		return 0;
	}

	int AttachInterestingTextHook(char* enteredString)
	{
		if (Storm578HookInit == 0)
		{
			InitInterestingTextHook();
			TextPrint("Recording");
		}
		else
		{
			DetachInterestingTextHook();
			TextPrint("Not Recording");
		}
		return 0;
	}

	void masterofpve(char* enteredString)
	{
		pvemaster = !pvemaster;
	}
	int CallConsoleConstruct(char* enteredString)
	{
		typedef int(ConsoleFunc)();
		ConsoleFunc* Interesting = (ConsoleFunc*)(dwGameDll + 0x864490);
		TextPrint("Called");
		Interesting();
		return 0;
	}


	int AttachNetMsgHook(char* enteredString)
	{
		if (Storm578HookInit == 0)
		{
			NetMsgInitHook();
			TextPrint("Recording");
		}
		else
		{
			detachNetMsgInitHook();
			TextPrint("Not Recording");
		}
		return 0;
	}

	void DebugWrite()
	{
		static int initialized = 0;
		if (initialized == 0)
		{	
			DebugOut.open("DebugOut.txt");
		}
		initialized = 1;
		DebugOut << ToWrite << std::endl;
		return;
	}

	void SimpleOut(char* s, va_list k)
	{
		vsprintf_s(ToWrite, s, k);
		DebugWrite();
		return;
	}

	void MsgHookInit()
	{
		//WriteJmp(dwGameDll + 0x20BC60, (DWORD)SimpleOut);
		//WriteJmp(dwGameDll + 0x39E970, (DWORD)SimpleOut);
		//WriteJmp(dwGameDll + 0x41F5E0, (DWORD)SimpleOut);
		return;
	}

	void DetachMsgHook()
	{
		DebugOut.close();
		Patch(dwGameDll + 0x20BC60, "\xC3\xCC\xCC\xCC\xCC", 5);
		Patch(dwGameDll + 0x39E970, "\xC3\xCC\xCC\xCC\xCC", 5);
		Patch(dwGameDll + 0x41F5E0, "\xC3\xCC\xCC\xCC\xCC", 5);
		return;
	}

	int MsgHook()
	{
		if (msghookstate == 0)
		{
			msghookstate = 1;
			MsgHookInit();
			TextPrint("Recording");
		}
		else
		{
			msghookstate = 0;
			DetachMsgHook();
			TextPrint("Not Recording");
		}
		return 0;
	}

	void Init()
	{
		Commands["iwantout"] = IWantOut;
		Commands["gspeed"] = GameSpeed;
		Commands["noendgame"] = NoEndgame; //dont works correctly
		Commands["aslimit"] = globalRemoveAsLimit;
		Commands["sg2g"] = SetGold2Give;
		Commands["sw2g"] = SetWood2Give;
		Commands["stextrec"] = AttachInterestingTextHook;
		Commands["smaperec"] = AttachMapErrorHook;
		Commands["msghook"] = MsgHook;
		Commands["pvemaster"] = masterofpve;
		//Commands["ntextrec"] = AttachNetMsgHook;
		//Commands["console"] = CallConsoleConstruct;
	}
}