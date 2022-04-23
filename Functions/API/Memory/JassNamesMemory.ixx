#include <Functions.h>
#include <BasicConstants.h>
#include "MemoryGameData.h"
#include <Additional Native Constants.h>
#include <Calls.h>
export module JassNamesMemory;


export DWORD FindJFuncByName(const char* name)
{
	DWORD pData = ReadRealMemory(pJassEnvAddress);
	if (pData == NULL) return NULL;
	pData = ReadRealMemory(pData + 0x14);
	if (pData == NULL) return NULL;
	pData = ReadRealMemory(pData + 0x20);
	if (pData <500) return NULL;
	DWORD FirstAddress = pData;

	while (true) {
		DWORD pName = ReadRealMemory(pData + 0x8);
		if (pData < 500) return NULL;
		if (!strcmp((char*)pName, name)) {
			return pData;
		}
		pData = ReadRealMemory(pData);
		if (pData == FirstAddress || pData == 0) return 0;
	}
	return 0;
}

export DWORD GetJassNamePlace()
{
	DWORD p = GetJassVM(1);
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x2858);
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x8);
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x8);
	return p;
}

export DWORD GetJassNamesCnt()
{
	DWORD p = GetJassVM(1);
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x2858);
	if (p <= 0) return NULL;
	p = ReadRealMemory(p + 0x8);
	return ReadRealMemory(p + 0x4);
}

export DWORD GetJassNameById(DWORD id)
{
	if ((GetJassNamesCnt() <= id) || (id <= 0)) return NULL;
	DWORD p = GetJassNamePlace();
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x4 * id);
	if (p == NULL) return NULL;
	p = ReadRealMemory(p + 0x14);
	return p;
}

export DWORD FindJassNameHandle(const char* name)
{
	int id = this_call(pGetJassNameHandle,ReadRealMemory(pGameState), (DWORD)name);
	return id;
}

export DWORD FindJassNameHandleStupid(const char* name)
{
	int cnt = GetJassNamesCnt();
	DWORD p = GetJassNamePlace();
	if (p == NULL) return NULL;
	for (int i = 1; i < cnt; i++)
	{
		char* c = (char*)ReadRealMemory(ReadRealMemory(p + 0x4 * i)+0x14);
		//printf(c);
		if (c != NULL && strcmp(name, c)==0)
			return i;

	}
	return NULL;
}