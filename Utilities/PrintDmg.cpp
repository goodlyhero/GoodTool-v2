#include <CNatives.h>
#include <string>
int printdmgmode = 0;
void PrintDmgMode(int mode)
{
	printdmgmode = mode;
}


void printdmg(DWORD hTarget, float amount)
{
	if (printdmgmode==0) return;
	
	if (fabs(amount) > 0.4 && IsVisibleToPlayer(GetUnitX(hTarget), GetUnitY(hTarget), GetLocalPlayer()))
	{
		DWORD tt = CreateTextTag();
		if (fabs(amount) < 3)
		{
			SetTextTagText(tt, std::to_string(amount).c_str(), 12 * .0023);
		}
		else
		{
			int a = amount;
			SetTextTagText(tt, std::to_string(a).c_str(), 12 * .0023);
		}
		SetTextTagPosUnit(tt, hTarget, 20.);
		SetTextTagVelocity(tt, 0.05325 * Cos(1.570795), 0.05325 * Sin(1.570795));
		SetTextTagPermanent(tt, false);
		SetTextTagLifespan(tt, 4.);
		SetTextTagColor(tt, 255, 0, 0, 200);
		SetTextTagFadepoint(tt, 4.);

	}
	
}