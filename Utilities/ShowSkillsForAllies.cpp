#include <ShowSkillsForAllies.h>
#include <CNatives.h>
#include <rcmp.hpp>
#include <Calls.h>
#include <Additional Native Constants.h>
#include <Functions.h>

bool ispanelshown = false;
bool ispanelhooked = false;
bool pvemaster = false;

void DrawSkillPanel(DWORD punit,int oid)
{
	this_call(pDrawSkillPanel, punit,oid);
}

bool IsNeedToDrawPanel(DWORD punit)
{
	return this_call(pDisplayCommandBar, punit);
}

void ShowAllyPanel(bool flag)
{
	if (flag == true && !ispanelhooked)
	{
		ispanelhooked = true;
		rcmp::hook_function<int(__fastcall*)(DWORD punit, DWORD addr1)>(pDisplayCommandBarIfNeeded, [](auto original, DWORD punit, DWORD addr1)
			{
				int oid = 0;
				int result = 0;
				if (addr1 != NULL)
				{
					int oid2 = ReadRealMemory(addr1 + 0x1B8);
					oid = ReadRealMemory(addr1 + 0x1BC);
					if ((oid2!=NULL)&&(ReadRealMemory(oid2+0x4)!=oid))
					{
						oid = ReadRealMemory(oid + 0x8);
					}
					else
					{
						oid = 852290;
					}
					result = 1;
					DWORD hunit = ObjectToHandleId(punit);
					DWORD howner = GetOwningPlayer(hunit);
					DWORD hlocal = GetLocalPlayer();
					if (IsNeedToDrawPanel(punit))
					{
						DrawSkillPanel(punit, oid);
					}
					else if(ispanelshown&&(pvemaster||IsPlayerAlly(howner, hlocal)))
					{
						DrawSkillPanel(punit, oid);
					}
				}
				else
				{
					result = 0;
				}
				return result;

			}
		);
	}
	ispanelshown = flag;
}