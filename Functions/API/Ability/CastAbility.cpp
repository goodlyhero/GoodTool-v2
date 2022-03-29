#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <CNatives.h>

void CastAbilityPosition(int aid, jHANDLE source, float targX, float targY)
{
    // Fits for non-target spells, i.e. Was Stomp && such...
    DWORD pData = ConvertHandle(source);

    if (pData > 0)
    {
        pData = GetUnitAbility(source, aid);

        if (pData > 0)
        {
            WriteRealMemory(pData + 0xF8, SetRealIntoMemory(targX));
            WriteRealMemory(pData + 0x100, SetRealIntoMemory(targY));
            WriteRealMemory(pData + 0x20, 0x9800);
            pData = this_call(pCastAbility, pData);
        }
    }
}

void CastAbilityTarget(DWORD aid, jHANDLE source, jHANDLE target)
{

    DWORD pData = 0;
    DWORD unitHashA = 0;
    DWORD unitHashB = 0;
    DWORD flags = 0;

    if (GetUnitAbilityLevel(source, aid) > 0 && target != NULL)
    {
        pData = ConvertHandle(target);

        if (pData > 0)
        {
            unitHashA = ReadRealMemory(pData + 0x0C);
            unitHashB = ReadRealMemory(pData + 0x10);

            if (unitHashA > 0 && unitHashB > 0)
            {
                pData = ConvertHandle(source);

                if (pData > 0)
                {
                    pData = GetUnitAbility(source, aid);

                    if (pData > 0)
                    {
                        // Widget is saved via HashGroup, hence we grab our units HashA && HashB && save them to TargetHashGroup
                        WriteRealMemory(pData + 0xE4, unitHashA);
                        WriteRealMemory(pData + 0xE8, unitHashB);
                        flags = ReadRealMemory(pData + 0x20);

                        if (not IsFlagBitSet(flags, 0x10000))
                        {
                            // 0x19804 stands for "target", 0x1F020 stands for "target item", 0x9800 stands for point target
                            WriteRealMemory(pData + 0x20, flags + 0x10000);
                            flags = flags + 0x10000;
                            if (not IsFlagBitSet(flags, 0x1))
                            {
                                WriteRealMemory(pData + 0x20, flags + 0x1);
                            }
                        }

                        pData = this_call(pCastAbility, pData);

                    }
                }
            }
        }
    }
}

void CastAbilityTargetGround(int aid, jHANDLE source, int lvl, float targX, float targY, bool remove)
{
    UnitAddAbility(source, aid);

    if (lvl > 1)
    {
        SetUnitAbilityLevel(source, aid, lvl);
    }

    CastAbilityPosition(aid, source, targX, targY);
    if (remove)
    {
        // Note: channeled abilities stop as soon as ability is removed!
        // This Applies to Chain Lightning && such.
UnitRemoveAbility(source, aid);
    }
}

void CastAbilityTargetWidget(int aid, jHANDLE source, jHANDLE target, int lvl, bool remove)
{
    UnitAddAbility(source, aid);

    if (lvl > 1)
    {
        SetUnitAbilityLevel(source, aid, lvl);
    }

    CastAbilityTarget(aid, source, target);
    if (remove)
    {
        // Note: channeled abilities stop as soon as ability is removed!
        // This Applies to Chain Lightning && such.
UnitRemoveAbility(source, aid);
    }
}

void CastAbilityTargetSelf(int aid, jHANDLE source, int lvl)
{
    CastAbilityTargetWidget(aid, source, source, lvl, true);
}
