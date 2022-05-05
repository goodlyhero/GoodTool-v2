#include <rcmp.hpp>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Functions.h>
#include <String>
#include <CNatives.h>
import CIconCover;
export module UIHooks;
int saveeax;
char buffer[4000];
bool isspeedhooked = false;
bool isspeedhookenabled = false;
std::string tstr;
int __stdcall PrintMoveSpeed(int addr, float* movespeed, int AmovAddr)
{
	int retval = 0;
	__asm mov retval, eax;
	int owner = GetAddressAbilityOwner(AmovAddr);
	std::string s("|cFFFFFFFF");
	if (movespeed != 0)
	{

		s += "MS: ";
		s += std::to_string((int)*movespeed); 
	}
	if (owner != NULL)
	{
		DWORD hUnit = ObjectToUnit(owner);
		if (hUnit != NULL)
		{
			s += "|n";
			s += "Id: ";
			s += Int2Id(GetUnitTypeId(hUnit));
			s += "|n";
			s += "|cFF000088HP/s: ";
			s += std::to_string(GetUnitLifeRegen(hUnit));
			s += "|r|n";
			s += "|c0000FF40MP/s: ";
			s += std::to_string(GetUnitManaRegen(hUnit));
			s += "|r|cFFFFFFFF";
			float tlf = GetUnitTimedLife(hUnit);
			if (tlf > 0)
			{
				s += "|n";
				s += "TLF: ";
				s += std::to_string(GetUnitTimedLife(hUnit));
			}
			float BAT = GetUnitBAT1(hUnit);
			if (BAT > 0)
			{
				s += "|n";
				s += "BAT1: ";
				s += std::to_string(BAT);
			}
			BAT = GetUnitBAT2(hUnit);
			if (BAT > 0)
			{
				s += "|n";
				s += "BAT2: ";
				s += std::to_string(BAT);
			}
			float TS = GetUnitTurnSpeed(hUnit);
			if (TS > 0)
			{
				s += "|n";
				s += "TS: ";
				s += std::to_string(BAT);
			}
			DWORD cntr = GetUnitInvulnerableCounter(hUnit);
			if (cntr > 0)
			{
				s += "|n";
				s += "Invuls: ";
				s += std::to_string(cntr);
			}
			
		}

	}
	s += "|r";
	sprintf_s((char*)addr, 0x200,s.c_str());
	return retval;
}
	
void __declspec(naked)  PrintHook()
{
		__asm
	{
		mov saveeax, eax;
		mov eax, esp;
		add eax, 4;
		push ebx;
		push eax;
		push esi;
		call PrintMoveSpeed;
		mov eax, saveeax;
		ret 8;
	}
}

void __fastcall CustomDefTip(DWORD pIconCover, DWORD EDX, char* def, char* move, char* desc)
{
	DWORD fs = FirstLocalSelected();
	if (fs != 0)
	{
		tstr = "|n";
		tstr += "Id: ";
		tstr += Int2Id(GetUnitTypeId(fs));
		tstr += "|n";
		tstr += "|c0000FFFFHP/s: ";
		tstr += std::to_string(GetUnitLifeRegen(fs));
		tstr += "|r|n";
		tstr += "|cFF0000FFMP/s: ";
		tstr += std::to_string(GetUnitManaRegen(fs));
		tstr += "|r|cFFFFFFFF";
		tstr += "|n";
		tstr += "owner: ";
		tstr += std::to_string(GetPlayerId(GetOwningPlayer(fs)));
		float tlf = GetUnitTimedLife(fs);
		if (tlf > 0)
		{
			tstr += "|n";
			tstr += "TLF: ";
			tstr += std::to_string(GetUnitTimedLife(fs));
		}
		float BAT = GetUnitBAT1(fs);
		if (BAT > 0)
		{
			tstr += "|n";
			tstr += "BAT1: ";
			tstr += std::to_string(BAT);
			tstr += "     range:  ";
			tstr += std::to_string(GetUnitAttackRange1(fs));
		}
		BAT = GetUnitBAT2(fs);
		if (BAT > 0)
		{
			tstr += "|n";
			tstr += "BAT2: ";
			tstr += std::to_string(BAT);
			tstr += "     range:  ";
			tstr += std::to_string(GetUnitAttackRange2(fs));
		}
		float TS = GetUnitTurnSpeed(fs);
		if (TS > 0)
		{
			tstr += "|n";
			tstr += "TS: ";
			tstr += std::to_string(TS);
		}
		float MS = GetUnitMoveSpeed(fs);
		if (MS > 0)
		{
			tstr += "|n";
			tstr += "MS: ";
			tstr += std::to_string(MS);
		}
		DWORD cntr = GetUnitInvulnerableCounter(fs);
		if (cntr > 0)
		{
			tstr += "|n";
			tstr += "Invuls: ";
			tstr += std::to_string(cntr);
		}
		tstr += "|n";
		tstr += desc;
		SetCIconCoverTip(pIconCover, def, move, (char*)tstr.c_str());
		return;
	}
	SetCIconCoverTip(pIconCover, def, move, desc);
}

export void HookSpeedText(bool mode)
{
	if (isspeedhookenabled == mode) return;
	if (mode == true)
	{
		isspeedhookenabled = true;
		if (!isspeedhooked)
		{
			isspeedhooked = true;
			//PlantDetourJMP((BYTE*)(pDrawMoveSpeed), (BYTE*)PrintHook, 5);
			PlantDetourCall((BYTE*)pDrawDefTip, (BYTE*)&CustomDefTip, 5);
		}
	}
	else
	{
		isspeedhookenabled = false;
	}

}