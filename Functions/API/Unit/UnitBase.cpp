#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <CNatives.h>

DWORD GetUnitBaseDataById(int uid)
{
	if (uid > 0)
	{
		return GetAgentBaseDataById(pUnitDataNode, uid);
	}

	return 0;
}

DWORD GetUnitBaseData(jHANDLE u)
{
	return GetUnitBaseDataById(GetUnitTypeId(u));
}

DWORD GetUnitBaseDataByIdCaching(DWORD uid)
{
	// DEF_ADR_UNIT_DATA = 2
	DWORD pUnit = 0;

	if (uid > 0)
	{
		/* if HaveSavedInteger(htObjectDataPointers, 2, uid)
		 {
			 return LoadInteger(htObjectDataPointers, 2, uid);
		 }*/

		pUnit = GetUnitBaseDataById(uid);
		/*if pUnit > 0
		{
			SaveInteger(htObjectDataPointers, 2, uid, pUnit);
		}*/

		return pUnit;
	}

	return 0;
}

DWORD GetUnitBaseDataCaching(jHANDLE u)
{
	return GetUnitBaseDataByIdCaching(GetUnitTypeId(u));
}

DWORD GetUnitBaseUIDataById(DWORD uid)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		return this_call(pGetUnitUIData, uid);
	}

	return 0;
}

DWORD GetUnitBaseUIData(jHANDLE u)
{
	return GetUnitBaseUIDataById(GetUnitTypeId(u));
}

DWORD GetUnitBaseUIDataByIdCaching(DWORD uid)
{
	// DEF_ADR_UNIT_UI = 3
	DWORD pUnit = 0;

	if (uid > 0)
	{
		/*if HaveSavedInteger(htObjectDataPointers, 3, uid)
		{
			return LoadInteger(htObjectDataPointers, 3, uid);
		}*/

		pUnit = GetUnitBaseUIDataById(uid);
		/*if pUnit > 0
		{
			SaveInteger(htObjectDataPointers, 3, uid, pUnit);
		}*/

		return pUnit;
	}

	return 0;
}

DWORD GetUnitBaseUIDataCaching(jHANDLE u)
{
	return GetUnitBaseUIDataByIdCaching(GetUnitTypeId(u));
}
//===========================================

// Unit Base UI Data Engine
DWORD GetUnitBaseUIIntegerParam(DWORD uid, int includedLevel, int offset)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			pData = ReadRealMemory(pData + offset);

			if (pData > 0)
			{
				if (includedLevel == 0)
				{
					return pData;
				}
				else
				{
					if (includedLevel == 1)
					{
						return ReadRealMemory(pData);
					}
				}
			}
		}
	}
	return 0;
}

void SetUnitBaseUIIntegerParam(DWORD uid, int includedLevel, int offset, int val)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			pData = pData + offset;

			if (offset == 0x274)
			{
				WriteRealMemory(pData, pData - 0x4);
			}
			else
			{
				if (includedLevel == 0)
				{
					WriteRealMemory(pData, val);
				}
				/*else
				{
					if (includedLevel == 1)
					{
						if (ReadRealMemory(pData) == 0)
						{
							WriteRealMemory(pData, val);
						}
						WriteRealMemory(ReadRealMemory(pData), val);
					}
				}*/
			}
		}
	}
}

const char* GetUnitBaseUIStringParam(DWORD uid, int includedLevel, int offset)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			pData = ReadRealMemory(pData + offset);

			if (pData > 0)
			{
				if (includedLevel == 1)
				{
					pData = ReadRealMemory(pData);
				}

				if (pData > 0)
				{
					return (char*)pData;
				}
			}
		}
	}

	return NULL;
}

void SetUnitBaseUIStringParam(DWORD uid, int includedLevel, int offset, const char* val)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			pData = pData + offset;

			if (includedLevel == 0)
			{
				WriteRealMemory(pData, (DWORD)val);
			}
			else
			{
				if (includedLevel == 1)
				{
					if (ReadRealMemory(pData) == 0)
					{
						WriteRealMemory(pData, (DWORD)val);
					}
					WriteRealMemory(ReadRealMemory(pData), (DWORD)val);
				}
			}
		}
	}
}
//===========================================

// Unit Base UI Data API by Id
const char* GetUnitBasePortraitById(DWORD uid)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			pData = ReadRealMemory(pData + 0x38);

			if (pData > 0)
			{
				return (char*)pData;
			}
		}
	}

	return NULL;
}

void SetUnitBasePortraitById(DWORD uid, const char* model)
{
	DWORD pData = 0;

	if (uid > 0)
	{
		pData = GetUnitBaseUIDataByIdCaching(uid);

		if (pData > 0)
		{
			WriteRealMemory(pData + 0x38, (DWORD)model);
		}
	}
}

const char* GetUnitBaseMissileArtById(DWORD uid, const char* path)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			pData = GetUnitBaseUIDataByIdCaching(uid);

			if (pData > 0)
			{
				pData = ReadRealMemory(pData + 0x44);

				if (pData > 0)
				{
					return (char*)(ReadRealMemory(pData));
				}
			}
		}

	return NULL;
}

void SetUnitBaseMissileArtById(DWORD uid, const char* model)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			pData = GetUnitBaseUIDataByIdCaching(uid);

			if (pData > 0)
			{
				pData = ReadRealMemory(pData + 0x44);

				if (pData > 0)
				{
					WriteRealMemory(pData, (DWORD)model);
				}
			}
		}
}

float GetUnitBaseMissileSpeedById(DWORD uid, int index)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			if (index == 0 || index == 1)
			{
				pData = GetUnitBaseUIDataByIdCaching(uid);

				if (pData > 0)
				{
					pData = ReadRealMemory(pData + 0x64);

					if (pData > 0)
					{
						return GetRealFromMemory(ReadRealMemory(pData + index));
					}
				}
			}
		}

	return -1.;
}

void SetUnitBaseMissileSpeedById(DWORD uid, DWORD index, float speed)
{
	DWORD pData = 0;

		if( uid > 0)
		{
			if (index == 0 || index == 1)
			{
				pData = GetUnitBaseUIDataByIdCaching(uid);

				if (pData > 0)
				{
					pData = ReadRealMemory(pData + 0x64);

					if (pData > 0)
					{
						WriteRealMemory(pData + index, SetRealIntoMemory(speed));
					}
				}
			}
		}
}

int GetUnitBaseColorById(int uid)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			pData = GetUnitBaseUIDataByIdCaching(uid);

			if (pData > 0)
			{
				return ReadRealMemory(pData + 0xAC);
			}
		}

	return 0;
}

const char* GetUnitBaseModelById(int uid)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			pData = GetUnitBaseUIDataByIdCaching(uid);

			if (pData > 0)
			{
				pData = ReadRealMemory(pData + 0x34);

				if (pData > 0)
				{
					return (char*)(pData);
				}
			}
		}

	return NULL;
}

void SetUnitBaseModelById(DWORD uid, const char* model)
{
	DWORD pData = 0;

		if (uid > 0)
		{
			pData = GetUnitBaseUIDataByIdCaching(uid);

			if (pData > 0)
			{
				WriteRealMemory(pData + 0x34,(DWORD)model);
			}
		}
}

const char* GetUnitBaseTipById(DWORD uid)
{
	return GetUnitBaseUIStringParam(uid, 1, 0x260);
}

void SetUnitBaseTipById(DWORD uid, const char* text)
{
	SetUnitBaseUIStringParam(uid, 1, 0x260, text);
}

const char* GetUnitBaseUbertipById(DWORD uid)
{
	return GetUnitBaseUIStringParam(uid, 1, 0x26C);
}

void SetUnitBaseUbertipById(DWORD uid, const char* text)
{
	SetUnitBaseUIStringParam(uid, 1, 0x26C, text);
}

int GetUnitBaseHotkeyById(DWORD uid)
{
	if (uid > 0)
	{
		if (GetUnitBaseUIIntegerParam(uid, 0, 0x270) > 0 || GetUnitBaseUIIntegerParam(uid, 0, 0x274) > 0)
		{
			return GetUnitBaseUIIntegerParam(uid, 1, 0x278);
		}
	}

	return 0;
}

void SetUnitBaseHotkeyById(DWORD uid, DWORD key)
{
	if (uid > 0)
	{
		SetUnitBaseUIIntegerParam(uid, 0, 0x270, 1);
		SetUnitBaseUIIntegerParam(uid, 0, 0x274, key);
		SetUnitBaseUIIntegerParam(uid, 1, 0x278, key);
	}
}
//===========================================

// Unit Base UI Data API by Unit
const char* GetUnitBaseModel(jHANDLE u)
{
	return GetUnitBaseModelById(GetUnitTypeId(u));
}

void SetUnitBaseModel(jHANDLE u, const char* model)
{
	SetUnitBaseModelById(GetUnitTypeId(u), model);
}

const char* GetUnitBasePortrait(jHANDLE u)
{
	return GetUnitBasePortraitById(GetUnitTypeId(u));
}

void SetUnitBasePortrait(jHANDLE u, const char* model)
{
	SetUnitBasePortraitById(GetUnitTypeId(u), model);
}

const char* GetUnitBaseMissileArt(jHANDLE u, const char* model)
{
	return GetUnitBaseMissileArtById(GetUnitTypeId(u), model);
}

void SetUnitBaseMissileArt(jHANDLE u, const char* model)
{
	SetUnitBaseMissileArtById(GetUnitTypeId(u), model);
}

float GetUnitBaseMissileSpeed(jHANDLE u, int index)
{
	return GetUnitBaseMissileSpeedById(GetUnitTypeId(u), index);
}

void SetUnitBaseMissileSpeed(jHANDLE u, int index, float speed)
{
	SetUnitBaseMissileSpeedById(GetUnitTypeId(u), index, speed);
}

int GetUnitBaseColor(jHANDLE u)
{
	return GetUnitBaseColorById(GetUnitTypeId(u));
}

const char* GetUnitBaseTip(jHANDLE u)
{
	return GetUnitBaseTipById(GetUnitTypeId(u));
}

void SetUnitBaseTip(jHANDLE u, const char* text)
{
	SetUnitBaseTipById(GetUnitTypeId(u), text);
}

const char* GetUnitBaseUbertip(jHANDLE u)
{
	return GetUnitBaseUbertipById(GetUnitTypeId(u));
}

void SetUnitBaseUbertip(jHANDLE u, const char* text)
{
	SetUnitBaseUbertipById(GetUnitTypeId(u), text);
}

DWORD GetUnitBaseHotkey(jHANDLE u)
{
	return GetUnitBaseHotkeyById(GetUnitTypeId(u));
}

void SetUnitBaseHotkey(jHANDLE u, DWORD key)
{
	SetUnitBaseHotkeyById(GetUnitTypeId(u), key);
}
//===========================================

// Unit Base Data API by Id
DWORD GetHeroBasePrimaryAttributeById(DWORD uid)
{
	DWORD pData = GetUnitBaseDataById(uid);

		if (pData > 0)
		{
			return ReadRealMemory(pData + 0x17C);
		}

	return -1;
}

void SetHeroBasePrimaryAttributeById(int uid, int index)
{
	DWORD pData = GetUnitBaseDataById(uid);

		if (pData > 0)
		{
			if (index >= 0 && index <= 2)
			{
				WriteRealMemory(pData + 0x17C, index);
			}
		}
}

// Unit Base Data API by unit
int GetHeroBasePrimaryAttribute(jHANDLE u)
{
	return GetHeroBasePrimaryAttributeById(GetUnitTypeId(u));
}

void SetHeroBasePrimaryAttribute(jHANDLE u, int index)
{
	SetHeroBasePrimaryAttributeById(GetUnitTypeId(u), index);
}
