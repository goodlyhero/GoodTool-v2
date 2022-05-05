#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>

int GetAbilityBaseDataById(DWORD aid)
{
    if (aid > 0)
    {
        return this_call(pGetAbilityBaseData, aid);
    }

    return 0;
}

int GetAbilityBaseDataByIdCaching(DWORD aid)
{
    // DEF_ADR_ABILITY_DATA = 0
    DWORD pAbil = 0;

        //if HaveSavedInteger(htObjectDataPointers, 0, aid)
        //{
        //    return LoadInteger(htObjectDataPointers, 0, aid);
        //}

    pAbil = GetAbilityBaseDataById(aid);
    /*if (pAbil > 0)
    {
        SaveInteger(htObjectDataPointers, 0, aid, pAbil);
    }*/

    return pAbil;
}

int GetAbilityBaseUIById(DWORD aid)
{
    if (aid > 0)
    {
        return this_call(pGetAbilityBaseUI, aid);
    }

    return 0;
}

int GetAbilityBaseUICaching(DWORD aid)
{
    // DEF_ADR_ABILITY_UI = 1
    DWORD pAbil = 0;

        /*if HaveSavedInteger(htObjectDataPointers, 1, aid)
        {
            return LoadInteger(htObjectDataPointers, 1, aid);
        }*/

    pAbil = GetAbilityBaseUIById(aid);
    /*if (pAbil > 0)
    {
        SaveInteger(htObjectDataPointers, 1, aid, pAbil);
    }*/

    return pAbil;
}
//===========================================

void SetAbilityBaseHotkeyParam(DWORD aid, int off, int newVal)
{
    DWORD pAbil = GetAbilityBaseUICaching(aid);
        DWORD pData = 0;

        if (pAbil > 0)
        {
            pAbil = pAbil + off;
            pData = pAbil - 0x4;
            WriteRealMemory(pData, newVal);
            WriteRealMemory(pAbil, pData);
        }
}

int GetAbilityBaseHotkeyParam(DWORD aid, int off)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            pData = ReadRealMemory(pData + off);

            if (pData > 0)
            {
                return ReadRealMemory(pData);
            }
        }

    return 0;
}

void SetAbilityBaseIntegerParam(DWORD aid, int off, int newVal)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            WriteRealMemory(pData + off, newVal);
        }
}

int GetAbilityBaseIntegerParam(DWORD aid, int off)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + off);
        }

    return 0;
}

void SetAbilityBaseRealParam(DWORD aid, int off, float newVal)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            WriteRealMemory(pData + off, SetRealIntoMemory(newVal));
        }
}

float GetAbilityBaseRealParam(DWORD aid, int off)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            return GetRealFromMemory(ReadRealMemory(pData + off));
        }

    return 0.;
}

void SetAbilityBaseBoolParam(DWORD aid, int off, bool flag)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            WriteRealMemory(pData + off, flag);
        }
}

bool GetAbilityBaseBoolParam(DWORD aid, int off)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            return ReadRealMemory(pData + off) > 0;
        }

    return false;
}

const char* GetAbilityBaseStringParam(DWORD aid, int off)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            pData = ReadRealMemory(pData + off);

            if (pData > 0)
            {
                return (char*)pData;
            }
        }

    return NULL;
}

void SetAbilityBaseStringParam(DWORD aid, int off, const char* newVal)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if (pData > 0)
        {
            WriteRealMemory(pData + off, (DWORD)newVal);
        }
}

const char* GetAbilityBaseStringParam2(DWORD aid, int off, int lvl)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if ((pData > 0) && lvl >= 0)
        {
            pData = ReadRealMemory(pData + off);

            if (pData > 0)
            {
                if (lvl > 0)
                {
                    lvl = lvl - 1;
                }

                pData = ReadRealMemory(pData + lvl * 0x4);
                if (pData > 0)
                {
                    return (char*)pData;
                }
            }
        }

    return NULL;
}

void SetAbilityBaseStringParam2(DWORD aid, int off, const char* newVal, int lvl)
{
    DWORD pData = GetAbilityBaseUICaching(aid);

        if ((pData > 0) && lvl >= 0)
        {
            pData = ReadRealMemory(pData + off);

            if (ReadRealMemory(pData) > 0)
            {
                if (lvl > 0)
                {
                    lvl = lvl - 1;
                }

                pData = ReadRealMemory(pData + lvl * 0x4);
                if (pData>0)
                {
                    char* buffer = new char[strlen(newVal) + 1];
                    strcpy(buffer, newVal);
                    WriteRealMemory(pData, *(DWORD*)&buffer);
                }
            }
        }
}

int GetAbilityBaseMaxLevel(DWORD aid)
{
    DWORD pAbil;

        if (aid > 0)
        {
            pAbil = GetAbilityBaseDataByIdCaching(aid);

            if (pAbil > 0)
            {
                return ReadRealMemory(pAbil + 0x50);
            }
        }

    return 0;
}

int GetAbilityBaseManaCost(DWORD aid, int level)
{
    DWORD pAbil = GetAbilityBaseDataByIdCaching(aid);

        if (pAbil > 0)
        {
            pAbil = ReadRealMemory(pAbil + 0x54);

            if (pAbil > 0)
            {
                return ReadRealMemory(pAbil - 0x58 + level * 0x68);
            }
        }

    return 0;
}

void SetAbilityBaseManaCost(DWORD aid, int level, int cost)
{
    DWORD pAbil = GetAbilityBaseDataByIdCaching(aid);

        if (pAbil > 0)
        {
            pAbil = ReadRealMemory(pAbil + 0x54);

            if (pAbil > 0)
            {
                WriteRealMemory(pAbil - 0x58 + level * 0x68, cost);
            }
        }
}

float GetAbilityBaseCooldown(DWORD aid, int level)
{
    DWORD pAbil = GetAbilityBaseDataByIdCaching(aid);

        if (pAbil > 0)
        {
            pAbil = ReadRealMemory(pAbil + 0x54);

            if (pAbil > 0)
            {
                return GetRealFromMemory(ReadRealMemory(pAbil - 0x54 + level * 0x68));
            }
        }

    return 0.;
}

void SetAbilityBaseCooldown(DWORD aid, int level, float cool)
{
    DWORD pAbil = GetAbilityBaseDataByIdCaching(aid);

        if (pAbil > 0)
        {
            pAbil = ReadRealMemory(pAbil + 0x54);

            if (pAbil > 0)
            {
                WriteRealMemory(pAbil - 0x54 + level * 0x68, SetRealIntoMemory(cool));
            }
        }
}

const char* GetAbilityBaseEffectSound(DWORD aid)
{
    return GetAbilityBaseStringParam(aid, 0x30);
}

void SetAbilityBaseEffectSound(DWORD aid, const char* s)
{
    SetAbilityBaseStringParam(aid, 0x30, s);
}

const char* GetAbilityBaseGlobalMessage(DWORD aid)
{
    return GetAbilityBaseStringParam(aid, 0x48);
}

void SetAbilityBaseGlobalMessage(DWORD aid, const char* s)
{
    SetAbilityBaseStringParam(aid, 0x48, s);
}

const char* GetAbilityBaseGlobalSound(DWORD aid)
{
    return GetAbilityBaseStringParam(aid, 0x4C);
}

void SetAbilityBaseGlobalSound(DWORD aid, const char* s)
{
    SetAbilityBaseStringParam(aid, 0x4C, s);
}

int GetAbilityBaseButtonX(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x50);
}

void SetAbilityBaseButtonX(DWORD aid, int newX)
{
    SetAbilityBaseIntegerParam(aid, 0x50, newX);
}

int GetAbilityBaseButtonY(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x54);
}

void SetAbilityBaseButtonY(DWORD aid, int newY)
{
    SetAbilityBaseIntegerParam(aid, 0x54, newY);
}

int GetAbilityBaseUnButtonX(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x58);
}

void SetAbilityBaseUnButtonX(DWORD aid, int newX)
{
    SetAbilityBaseIntegerParam(aid, 0x58, newX);
}

int GetAbilityBaseUnButtonY(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x5C);
}

void SetAbilityBaseUnButtonY(DWORD aid, int newY)
{
    SetAbilityBaseIntegerParam(aid, 0x5C, newY);
}

int GetAbilityBaseResearchButtonX(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x60);
}

void SetAbilityBaseResearchButtonX(DWORD aid, int newX)
{
    SetAbilityBaseIntegerParam(aid, 0x60, newX);
}

int GetAbilityBaseResearchButtonY(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x64);
}

void SetAbilityBaseResearchButtonY(DWORD aid, int newY)
{
    SetAbilityBaseIntegerParam(aid, 0x64, newY);
}

float GetAbilityBaseMissileSpeed(DWORD aid)
{
    return GetAbilityBaseRealParam(aid, 0x68);
}

void SetAbilityBaseMissileSpeed(DWORD aid, float speed)
{
    SetAbilityBaseRealParam(aid, 0x68, speed);
}

float GetAbilityBaseMissileArc(DWORD aid)
{
    return GetAbilityBaseRealParam(aid, 0x6C);
}

void SetAbilityBaseMissileArc(DWORD aid, float arc)
{
    SetAbilityBaseRealParam(aid, 0x6C, arc);
}

bool IsAbilityMissileHoming(DWORD aid)
{
    return GetAbilityBaseBoolParam(aid, 0x70);
}

void SetAbilityBaseMissileHoming(DWORD aid, bool homing)
{
    SetAbilityBaseBoolParam(aid, 0x70, homing);
}

int GetAbilityBaseSpellDetails(DWORD aid)
{
    return GetAbilityBaseIntegerParam(aid, 0x74);
}

void SetAbilityBaseSpellDetails(DWORD aid, int det)
{
    SetAbilityBaseIntegerParam(aid, 0x74, det);
}

int GetAbilityBaseHotkeyId(DWORD aid)
{
    return GetAbilityBaseHotkeyParam(aid, 0x84);
}

void SetAbilityBaseHotkeyId(DWORD aid, int newVal)
{
    SetAbilityBaseHotkeyParam(aid, 0x84, newVal);
}

int GetAbilityBaseUnHotkeyId(DWORD aid)
{
    return GetAbilityBaseHotkeyParam(aid, 0x90);
}

void SetAbilityBaseUnHotkeyId(DWORD aid, int newVal)
{
    SetAbilityBaseHotkeyParam(aid, 0x90, newVal);
}

int GetAbilityBaseResearchHotkeyId(DWORD aid)
{
    return GetAbilityBaseHotkeyParam(aid, 0x9C);
}

void SetAbilityBaseResearchHotkeyId(DWORD aid, int newVal)
{
    SetAbilityBaseHotkeyParam(aid, 0x9C, newVal);
}

const char* GetAbilityBaseTip(DWORD aid, int lvl)
{
    return GetAbilityBaseStringParam2(aid, 0x138, lvl);
}

void SetAbilityBaseTip(DWORD aid, int lvl, const char* s)
{
    SetAbilityBaseStringParam2(aid, 0x138, s, lvl);
}

const char* GetAbilityBaseUbertip(DWORD aid, int lvl)
{
    return GetAbilityBaseStringParam2(aid, 0x15C, lvl);
}

void SetAbilityBaseUbertip(DWORD aid, int lvl, const char* s)
{
    SetAbilityBaseStringParam2(aid, 0x15C, s, lvl);
}

void SetAbilityBaseHotkeyCommon(DWORD aid, int newVal)
{
    SetAbilityBaseHotkeyId(aid, newVal);
    SetAbilityBaseUnHotkeyId(aid, newVal);
    SetAbilityBaseResearchHotkeyId(aid, newVal);
}