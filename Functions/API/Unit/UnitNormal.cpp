#include <From MemHack.h>
#include <CNatives.h>
#include <cmath>
import JassCommonConsts;

int GetUnitTypeIdReal(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x30);
    }
    return 0;
}
void SetUnitTypeId(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0x30, i);
    }
}
int MorphUnitToTypeId(DWORD u, int id)
{
    DWORD pUnit = ConvertHandle(u);
    if (pUnit != NULL)
    {
        if (ReadRealMemory(pUnit + 0x30) != id)
        {
            if (pMorphUnitToTypeId != 0 && pUpdateHeroBar != 0 && pRefreshPortraitIfSelected != 0 && pRefreshInfoBarIfSelected != 0)
            {
                this_call(pMorphUnitToTypeId, pUnit, id, 1282, 0, 0, 2, 2, 1, 0, 0, 0);
                this_call(pUpdateHeroBar, pUnit, 0);
                this_call(pRefreshPortraitIfSelected, pUnit, 1);
                return this_call(pRefreshInfoBarIfSelected, pUnit);
            }
        }
    }
    return 0;
}
int GetHeroNeededXPForLevel(DWORD u, int level)
{
    DWORD pUnit = ConvertHandle(u);
    if (pUnit != NULL)
    {
        if (IsUnitType(u, UNIT_TYPE_HERO))
        {
            if (pGetHeroNeededXP > 0)
            {
                return this_call(pGetHeroNeededXP, pUnit, level);
            }
        }
    }
    return 0;
}
int GetHeroNeededXP(DWORD u)
{
    return GetHeroNeededXPForLevel(u, GetHeroLevel(u));
}
int GetUnitVertexColour(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x2D4);
    }
    return 0;
}
int GetUnitVertexColourA(DWORD u)
{
    return GetByteFromInteger(GetUnitVertexColour(u), 1);
}
int GetUnitVertexColourR(DWORD u)
{
    return GetByteFromInteger(GetUnitVertexColour(u), 2);
}
int GetUnitVertexColourG(DWORD u)
{
    return GetByteFromInteger(GetUnitVertexColour(u), 3);
}
int GetUnitVertexColourB(DWORD u)
{
    return GetByteFromInteger(GetUnitVertexColour(u), 4);
}
void SetUnitModel(DWORD u, const char* model)
{
    SetObjectModel(ConvertHandle(u), model);
}
int SetUnitTexture(DWORD u, const char* texturepath, int textureId)
{
    DWORD pUnit = ConvertHandle(u);
    DWORD pTexture = 0;
    if (pUnit != NULL)
    {
        if (texturepath != NULL)
        {
            pTexture = LoadCBackDropFrameTexture(texturepath, false);
            if (pTexture > 0 && textureId > 0)
            {
                return fast_call(pSetUnitTexture, ReadRealMemory(pUnit + 0x28), pTexture, textureId);
            }
        }
    }
    return 0;
}
float GetUnitImpactZ(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return GetRealFromMemory(ReadRealMemory(pData + 0x228));
    }
    return 0.;
}
void SetUnitImpactZ(DWORD u, float impactZ)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0x228, SetRealIntoMemory(impactZ));
    }
}
void RedrawUnit(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        this_call(pRedrawUnit, pData);
    }
}
bool IsAttackDisabled(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E8);
        if (pData != NULL)
        {
            return ReadRealMemory(pData + 0x40) > 0;
        }
    }
    return false;
}
void UnitDisableAttack(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E8);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x40, 0);
        }
    }
}
void UnitEnableAttack(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E8);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x40, 1);
        }
    }
}
int GetUnitCritterFlag(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x60);
    }
    return -1;
}
void SetUnitCritterFlag(DWORD u, int id)
{

    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        if (id >= 0 && id <= 1)
        {
            WriteRealMemory(pData + 0x60, id);
        }
    }
}
float GetUnitTimedLife(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAbility(u, 0x42544c46);
        if (pData != NULL)
        {
            pData = ReadRealMemory(pData + 0x90);
            if (pData != NULL)
            {
                return GetRealFromMemory(ReadRealMemory(pData + 0x4));
            }
        }
    }
    return 0.;
}
void SetUnitTimedLife(DWORD u, float dur)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAbility(u, 0x42544c46);
        if (pData != NULL)
        {
            pData = ReadRealMemory(pData + 0x90);
            if (pData != NULL)
            {
                WriteRealMemory(pData + 0x4, SetRealIntoMemory(dur));
            }
        }
    }
}
void SetUnitPhased(DWORD u)
{
    DWORD data = GetUnitBaseDataById(GetUnitTypeId(u)) + 0x1AC;
    DWORD p1 = ReadRealMemory(data);
    DWORD p2 = ReadRealMemory(data + 0x4);
    WriteRealMemory(data, 0x8);
    WriteRealMemory(data + 0x4, 0x10);
    SetUnitPathing(u, true);
    WriteRealMemory(data, p1);
    WriteRealMemory(data + 0x4, p2);
}
void UnitApplySilence(DWORD u, bool flag)
{
    DWORD pUnit = ConvertHandle(u);
    if (pUnit != NULL)
    {
        this_call(pCommonSilence, pUnit, flag);
    }
}
void UnitDisableAbilities(DWORD u, bool flag)
{
    DWORD pUnit = ConvertHandle(u);
    if (pUnit != NULL)
    {
        this_call(pPauseUnitDisabler, pUnit, 1, flag, 0, 0);
    }
}
void UnitSetStunFlag(DWORD u, bool add)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        if (add)
        {
            this_call(pSetStunToUnit, ConvertHandle(u), ConvertHandle(u));
        }
        else
        {
            this_call(pUnsetStunToUnit, ConvertHandle(u));
        }
    }
}
bool IsUnitStunned(DWORD u)
{
    DWORD pHandle = ConvertHandle(u);
    if (pHandle != 0)
    {
        return ReadRealMemory(pHandle + 0x198) > 0;
    }
    return false;
}
void UnitApplyStun(DWORD u)
{
    DWORD pHandle = ConvertHandle(u);
    if (pHandle != 0)
    {
        WriteRealMemory(pHandle + 0x198, 0);
    }
}
bool IsUnitMovementDisabled(DWORD u)
{
    int pdata = GetHandleId(u);
    if (pdata > 0)
    {
        pdata = ConvertHandle(u);
        if (pdata > 0)
        {
            pdata = ReadRealMemory(pdata + 0x1EC);
            if (pdata > 0)
            {
                return ReadRealMemory(pdata + 0x7C) > 0;
            }
        }
    }
    return false;
}
void SetUnitControl(DWORD u, int flagval, int moveval, int atackval, int invval)
{
    int pUnit = ConvertHandle(u);
    int flags;
    int Amov;
    int Aatk;
    DWORD AInv;
    if (pUnit != NULL)
    {
        flags = ReadRealMemory(pUnit + 0x248);
        Aatk = ReadRealMemory(pUnit + 0x1E8);
        Amov = ReadRealMemory(pUnit + 0x1EC);
        AInv = ReadRealMemory(pUnit + 0x1F8);
        if (not IsFlagBitSet(flags, 512))
        {
            WriteRealMemory(pUnit + 0x248, flags + flagval);
        }
        if (Amov != 0)
        {
            WriteRealMemory(Amov + 0x40, ReadRealMemory(Amov + 0x40) + moveval);
        }
        if (Aatk != 0)
        {
            WriteRealMemory(Aatk + 0x40, ReadRealMemory(Aatk + 0x40) + atackval);
        }
        if (AInv != 0)
        {
            WriteRealMemory(AInv + 0x3C, ReadRealMemory(AInv + 0x3C) + invval);
        }
    }
}
void UnitDisableControl(DWORD u)
{

    SetUnitControl(u, 512, 1, 1, 1);
}
void UnitEnableControl(DWORD u)
{
    SetUnitControl(u, -512, -1, -1, -1);
}
void UnitRemoveMovementDisables(DWORD u)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            WriteRealMemory(ReadRealMemory(pData + 0x1EC) + 0x7C, 0);
        }
    }
}
void SetUnitMovement(int pData, bool flag)
{
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x7C, !flag);
        }
    }
}
void UnitEnableMovement(DWORD u)
{
    if (u == NULL)
    {
        return;
    }
    SetUnitMovement(ConvertHandle(u), false);
}
void UnitDisableMovement(DWORD u)
{
    if (u == NULL)
    {
        return;
    }
    SetUnitMovement(ConvertHandle(u), true);
}
void UnitDisableMovementEx(DWORD u, bool disable)
{
    int i = 2;
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        if (not disable)
        {
            i = 1;
        }
        PauseUnit(u, true);
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            SetAddressAbilityDisabled(pData, i);
        }
        PauseUnit(u, false);
    }
}
bool IsUnitInventoryDisabled(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1F8);
        if (pData != NULL)
        {
            return ReadRealMemory(pData + 0x3C);
        }
    }
    return false;
}
void UnitEnableInventory(DWORD u, bool flag)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1F8);
        if (pData != NULL)
        {
            pData = pData + 0x3C;
            WriteRealMemory(pData, !flag);
        }
    }
}
int GetAddressLocustFlags(int pAddr1, int pAddr2)
{
    int i = GetSomeAddress(pAddr1, pAddr2);
    return ReadRealMemory(i + 0x94);
}
void SetLocustFlags(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = pData + 0x16C;
        pData = GetAddressLocustFlags(ReadRealMemory(pData), ReadRealMemory(pData + 4));
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x34, i);
        }
    }
}
void UnitEnableTruesightImmunity(DWORD u)
{
    SetLocustFlags(u, 0x08000000);
}
void UnitDisableTruesightImmunity(DWORD u)
{
    SetLocustFlags(u, 0);
}
int GetUnitFlags(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x20);
    }
    return 0;
}
void SetUnitFlags(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0x20, i);
    }
}
void AddUnitFlags(DWORD u, int i)
{
    SetUnitFlags(u, GetUnitFlags(u) + i);
}
int GetUnitFlags_2(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x5C);
    }
    return 0;
}
void SetUnitFlags_2(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0x5C, i);
    }
}
void AddUnitFlags_2(DWORD u, int i)
{
    SetUnitFlags_2(u, GetUnitFlags_2(u) + i);
}
int GetUnitVisibilityClass(DWORD u)
{
    int a = ConvertHandle(u);
    int res = 0;
    if (a != 0)
    {
        res = ReadRealMemory(a + 0x130);
        if (res != 0)
        {
            res = GetSomeAddressForAbility(res, ReadRealMemory(a + 0x134));
        }
    }
    return res;
}
void SetUnitVisibleByPlayer(DWORD u, int p, int c)
{
    int a = GetUnitVisibilityClass(u);
    if (a != 0)
    {
        WriteRealMemory(a + 0x2C + 4 * GetPlayerId(p), c);
        if (c != 0 && !IsFlagBitSet(ReadRealMemory(a + 0x24), (1 >> p)))
        {
            WriteRealMemory(a + 0x24, ReadRealMemory(a + 0x24) | (1 >> p));
        }
        else
        {
            if (c == 0 && IsFlagBitSet(ReadRealMemory(a + 0x24), (DWORD)(1 >> p)))
            {
                WriteRealMemory(a + 0x24, ReadRealMemory(a + 0x24) &&(~(DWORD)(1 >> p)));
            }
        }
    }
}
bool IsUnitInvulnerable(DWORD u)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return IsFlagBitSet(ReadRealMemory(pData + 0x20), 8);
    }
    return false;
}
int GetUnitInvulnerableCounter(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0xE8);
    }
    return 0;
}
void SetUnitInvulnerableCounter(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0xE8, i);
    }
}
void ModifyInvulnerableCounter(DWORD u, int diff)
{
    if (u != NULL)
    {
        SetUnitInvulnerableCounter(u, GetUnitInvulnerableCounter(u) + diff);
    }
}
bool IsUnitInvulnerable2(DWORD u)
{
    return GetUnitInvulnerableCounter(u) > 0;
}
void SetUnitFacingInstant(DWORD u, float a)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0xA0);
        if (pData != NULL)
        {
            pData = ReadRealMemory(pData + 0x28);
            if (pData != NULL)
            {
                SetUnitFacing(u, a);
                WriteRealMemory(pData + 0xA4, SetRealIntoMemory(CDeg2Rad(a)));
            }
        }
    }
}
int GetUnitMoveType(DWORD u)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0x16C);
        if (pData != NULL)
        {
            pData = ReadRealMemory(pData + 0xA8);
            if (pData != NULL)
            {
                return ReadRealMemory(pData + 0x9C);
            }
        }
    }
    return 0;
}
void SetUnitMoveType(DWORD u, int m_type)
{

    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0x16C);
        if (pData != NULL)
        {
            pData = ReadRealMemory(pData + 0xA8);
            if (pData != NULL)
            {
                WriteRealMemory(pData + 0x9C, m_type);
            }
        }
    }
}
int GetHeroPrimaryAttribute(DWORD u)
{
    int a = ConvertHandle(u);
    if (a != 0)
    {
        a = ReadRealMemory(a + 0x1F0);
        if (a != 0)
        {
            return ReadRealMemory(a + 0xCC);
        }
    }
    return 0;
}
void SetHeroPrimaryAttribute(DWORD u, int i)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        if (IsUnitIdType(GetUnitTypeId(u), UNIT_TYPE_HERO))
        {
            pData = ReadRealMemory(pData + 0x1F0);
            if (pData != NULL)
            {
                WriteRealMemory(pData + 0xCC, i);
            }
        }
    }
}
int GetUnitAttackAbility(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0x1E8);
    }
    return 0;
}
void SetUnitAttackAbility(DWORD u, int pAddr)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0x1E8, pAddr);
    }
}
int GetUnitAttackOffsetValue(DWORD u, int pOff)
{
    DWORD pData = GetUnitAttackAbility(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + pOff);
    }
    return 0;
}
float GetUnitNextAttackTimestamp(DWORD u)
{
    DWORD pData = GetUnitAttackAbility(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E4);
        if (pData != NULL)
        {
            return GetRealFromMemory(ReadRealMemory(pData + 0x4));
        }
    }
    return -1.;
}
bool UnitResetAttackCooldown(DWORD u)
{
    DWORD pData = GetUnitAttackAbility(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E4);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x1E4, 0);
            return true;
        }
    }
    return false;
}
DWORD UnitNullifyCurrentAttack(DWORD u)
{
    DWORD pData = GetUnitAttackAbility(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1F4);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x1F4, 0);
            return NULLIFY_RESULT_NULLED;
        }
        else
        {
            return NULLIFY_RESULT_EMPTY;
        }
    }
    else
    {
        return NULLIFY_RESULT_ATKDISABLED;
    }
    return NULLIFY_RESULT_NOATTACK;
}
bool AddUnitExtraAttack(DWORD u)
{
    int pData = GetUnitAttackAbility(u);
    float attackdelay;
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1E4);
        if (pData != NULL)
        {
            attackdelay = ReadFloat(pData + 0x8);
            if (attackdelay != 0)
            {
                WriteRealMemory(pData + 0x4, GetUnitNextAttackTimestamp(u) - attackdelay);
                return true;
            }
        }
    }
    return false;
}
int GetUnitAttackTypeByIndex(DWORD u, int index)
{
    if (index == 0 || index == 1)
    {
        return GetUnitAttackOffsetValue(u, 0xF4 + 4 * index);
    }
    return -1;
}
int GetUnitAttackType1(DWORD u)
{
    return GetUnitAttackTypeByIndex(u, 0);
}
int GetUnitAttackType2(DWORD u)
{
    return GetUnitAttackTypeByIndex(u, 1);
}
void SetUnitAttackOffsetValue(DWORD u, int offset, int val)
{
    DWORD pData = GetUnitAttackAbility(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + offset, val);
    }
}
void SetUnitAttackTypeByIndex(DWORD u, int i, int attacknum)
{

    SetUnitAttackOffsetValue(u, 0xF4 + 4 * attacknum, i);
}
void SetUnitAttackType1(DWORD u, int i)
{
    SetUnitAttackTypeByIndex(u, i, 0);
}
void SetUnitAttackType2(DWORD u, int i)
{
    SetUnitAttackTypeByIndex(u, i, 1);
}
int GetUnitWeaponSound(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0xE8);
}
void SetUnitWeaponSound(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0xE8, i);
}
int GetUnitWeaponType(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0xDC);
}
void SetUnitWeaponType(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0xDC, i);
}
int GetUnitBaseDamage(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0xA0);
}
void SetUnitBaseDamage(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0xA0, i);
}
void AddUnitBaseDamage(DWORD u, int bonus)
{
    SetUnitBaseDamage(u, GetUnitBaseDamage(u) + bonus);
}
int GetUnitBonusDamage(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0xAC);
}
void SetUnitBonusDamage(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0xAC, i);
}
void AddUnitBonusDamage(DWORD u, int i)
{
    SetUnitBonusDamage(u, GetUnitBonusDamage(u) + i);
}
int GetUnitTotalDamage(DWORD u)
{
    return GetUnitBaseDamage(u) + GetUnitBonusDamage(u);
}
int GetUnitBaseAttributeDamage(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0xA4);
}
void SetUnitBaseAttributeDamage(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0xA4, i);
}
int GetUnitDamageDicesSideCount(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0x94);
}
void SetUnitDamageDicesSideCount(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0x94, i);
}
int GetUnitDamageDicesCount(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0x88);
}
void SetUnitDamageDicesCount(DWORD u, int i)
{
    SetUnitAttackOffsetValue(u, 0x88, i);
}
float GetUnitAttackRangeByIndex(DWORD u, int index)
{
    if (index == 0 || index == 1)
    {
        return GetRealFromMemory(GetUnitAttackOffsetValue(u, 0x258 + 0x24 * index));
    }
    return 0.;
}
void SetUnitAttackRangeByIndex(DWORD u, int index, float r)
{
    if (index == 0 || index == 1)
    {
        SetUnitAttackOffsetValue(u, 0x258 + 0x24 * index, SetRealIntoMemory(r));
    }
}
float GetUnitAttackRange1(DWORD u)
{
    return GetUnitAttackRangeByIndex(u, 0);
}
void SetUnitAttackRange1(DWORD u, float r)
{
    SetUnitAttackRangeByIndex(u, 0, r);
}
float GetUnitAttackRange2(DWORD u)
{
    return GetUnitAttackRangeByIndex(u, 1);
}
void SetUnitAttackRange2(DWORD u, float r)
{
    SetUnitAttackRangeByIndex(u, 1, r);
}
float GetUnitBATByIndex(DWORD u, int index)
{
    if (index == 0 || index == 1)
    {
        return GetRealFromMemory(GetUnitAttackOffsetValue(u, 0x158 + 0x8 * index));
    }
    return 0.;
}
void SetUnitBATByIndex(DWORD u, int index, float r)
{
    if (index == 0 || index == 1)
    {
        SetUnitAttackOffsetValue(u, 0x158 + 0x8 * index, SetRealIntoMemory(r));
    }
}
float GetUnitBAT1(DWORD u)
{
    return GetUnitBATByIndex(u, 0);
}
void SetUnitBAT1(DWORD u, float r)
{
    SetUnitBATByIndex(u, 0, r);
}
float GetUnitBAT2(DWORD u)
{
    return GetUnitBATByIndex(u, 1);
}
void SetUnitBAT2(DWORD u, float r)
{
    SetUnitBATByIndex(u, 1, r);
}
float GetUnitAttackPointByIndex(DWORD u, int index)
{
    if (index == 0 || index == 1)
    {
        return GetRealFromMemory(GetUnitAttackOffsetValue(u, 0x16C + 0x10 * index));
    }
    return 0.;
}
void SetUnitAttackPointByIndex(DWORD u, int index, float r)
{
    if (index == 0 || index == 1)
    {
        SetUnitAttackOffsetValue(u, 0x16C + 0x10 * index, SetRealIntoMemory(r));
    }
}
float GetUnitAttackPoint1(DWORD u)
{
    return GetUnitAttackPointByIndex(u, 0);
}
void SetUnitAttackPoint1(DWORD u, float r)
{
    SetUnitAttackPointByIndex(u, 0, r);
}
float GetUnitAttackPoint2(DWORD u)
{
    return GetUnitAttackPointByIndex(u, 1);
}
void SetUnitAttackPoint2(DWORD u, float r)
{
    SetUnitAttackPointByIndex(u, 1, r);
}
int GetUnitAttackEnabledIndex(DWORD u)
{
    return GetUnitAttackOffsetValue(u, 0x104);
}
float GetUnitAttackBackswing(DWORD u)
{
    return GetRealFromMemory(GetUnitAttackOffsetValue(u, 0x190));
}
void SetUnitAttackBackswing(DWORD u, float r)
{
    SetUnitAttackOffsetValue(u, 0x190, SetRealIntoMemory(r));
}
float GetUnitAttackSpeed(DWORD u)
{
    return GetRealFromMemory(GetUnitAttackOffsetValue(u, 0x1B0));
}
void SetUnitAttackSpeed(DWORD u, float r)
{
    SetUnitAttackOffsetValue(u, 0x1B0, SetRealIntoMemory(r));
}
void AddUnitAttackSpeed(DWORD u, float r)
{
    SetUnitAttackSpeed(u, GetUnitAttackSpeed(u) + r);
}
float GetUnitAttackDamage(DWORD u)
{
    DWORD dmg = GetUnitDamageDicesCount(u);
    DWORD spread = GetRandomInt(dmg, dmg * GetUnitDamageDicesSideCount(u));
    return I2R(GetUnitBaseDamage(u) + GetUnitBonusDamage(u) + spread);
}
int GetUnitArmourType(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return ReadRealMemory(pData + 0xE4);
    }
    return 0;
}
void SetUnitArmourType(DWORD u, int id)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0xE4, id);
    }
}
float GetUnitArmour(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return GetRealFromMemory(ReadRealMemory(pData + 0xE0));
    }
    return 0.;
}
void SetUnitArmour(DWORD u, float r)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        WriteRealMemory(pData + 0xE0, SetRealIntoMemory(r));
    }
}
void AddUnitArmour(DWORD u, float value)
{
    SetUnitArmour(u, GetUnitArmour(u) + value);
}
float GetUnitTimeScale(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        return GetRealFromMemory(ReadRealMemory(pData + 0x300));
    }
    return 0.;
}
float GetUnitBaseMoveSpeed(DWORD u)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            return GetRealFromMemory(ReadRealMemory(pData + 0x70));
        }
    }
    return 0.;
}
float GetUnitBonusMoveSpeed(DWORD u)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            return GetRealFromMemory(ReadRealMemory(pData + 0x78));
        }
    }
    return -1000.;
}
bool SetUnitBonusMoveSpeed(DWORD u, float r)
{
    int pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = ReadRealMemory(pData + 0x1EC);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x78, SetRealIntoMemory(r));
            SetUnitMoveSpeed(u, GetRealFromMemory(ReadRealMemory(pData + 0x70)));
            return true;
        }
    }
    return false;
}
void AddUnitBonusMovespeed(DWORD u, float r)
{
    SetUnitBonusMoveSpeed(u, GetUnitBonusMoveSpeed(u) + r);
}
void SetUnitMaxLife(DWORD u, float newhp)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0xA0);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x84, SetRealIntoMemory(newhp));
        }
    }
}
void AddUnitMaxLife(DWORD u, float value)
{
    SetUnitMaxLife(u, GetUnitState(u, UNIT_STATE_MAX_LIFE) + value);
}
void SetUnitMaxMana(DWORD u, float newmp)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0xC0);
        if (pData != NULL)
        {
            WriteRealMemory(pData + 0x84, SetRealIntoMemory(newmp));
        }
    }
}
void AddUnitMaxMana(DWORD u, float value)
{
    SetUnitMaxMana(u, GetUnitState(u, UNIT_STATE_MAX_MANA) + value);
}
float GetWidgetLifeRegen(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0xA0);
        if (pData != NULL)
        {
            return GetRealFromMemory(ReadRealMemory(pData + 0x7C));
        }
    }
    return 0.;
}
float GetUnitLifeRegen(DWORD u)
{
    return GetWidgetLifeRegen(u);
}
void SetUnitLifeRegen(DWORD u, float r)
{
    DWORD pData = ConvertHandle(u);
    float curhp = GetWidgetLife(u);
    if (pData != NULL)
    {
        if (curhp > 0)
        {
            pData = GetUnitAddressFloatsRelated(pData, 0xA0);
            if (pData != NULL)
            {
                WriteFloat(pData + 0x7C, r);
                SetWidgetLife(u, curhp);
            }
        }
    }
}
void AddUnitLifeRegen(DWORD u, float r)
{
    SetUnitLifeRegen(u, GetUnitLifeRegen(u) + r);
}
float GetUnitManaRegen(DWORD u)
{
    DWORD pData = ConvertHandle(u);
    if (pData != NULL)
    {
        pData = GetUnitAddressFloatsRelated(pData, 0xC0);
        if (pData != NULL)
        {
            return GetRealFromMemory(ReadRealMemory(pData + 0x7C));
        }
    }
    return 0.;
}
void SetUnitManaRegen(DWORD u, float r)
{
    DWORD pData = ConvertHandle(u);
    float curmp = GetUnitState(u, UNIT_STATE_MANA);
    if (pData != NULL)
    {
        if (curmp > 0)
        {
            pData = GetUnitAddressFloatsRelated(pData, 0xC0);
            if (pData != NULL)
            {
                WriteRealMemory(pData + 0x7C, SetRealIntoMemory(r));
                SetUnitState(u, UNIT_STATE_MANA, curmp);
            }
        }
    }
}
void AddUnitManaRegen(DWORD u, float r)
{
    SetUnitManaRegen(u, GetUnitManaRegen(u) + r);
}