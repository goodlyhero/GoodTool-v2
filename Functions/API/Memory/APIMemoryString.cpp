#include <BasicConstants.h>
#include <Calls.h>
#include <Additional Native Constants.h>
#include <Functions.h>
#include "MemoryGameData.h"

const char* ConvertJString(DWORD string)
{
    return (const char*)this_call(pGetString, string);
}

pString ConvertString(integer pNullTerminatedString)
{
    return (this_call(pConvertString, pNullTerminatedString));
}

pString ConvertString(const char* pNullTerminatedString)
{
    return (this_call(pConvertString, (int)pNullTerminatedString));
}

DWORD LConvertString(const char* pNullTerminatedString)
{
    return (this_call(pConvertString, (int)pNullTerminatedString));
}

DWORD ToRCString(const char* pNullTerminatedString)
{
    return (this_call(pConvertString, (int)pNullTerminatedString));
}


void WriteNullTerminatedString(pString s, integer pAddr)
{
    WriteRealMemory(pAddr, GetStringAddress(s));
}

int SearchStringValueAddress(pString str)
{
    integer retaddr = this_call(pSearchStringValue, pSearchStringAddr1, GetStringAddress(str));

        if ((retaddr == 0) || (ReadRealMemory(retaddr + 0x1C) == 0)) {
             retaddr = this_call(pSearchStringValue, pSearchStringAddr2, GetStringAddress(str));
        }

    if (retaddr == 0 || ReadRealMemory(retaddr + 0x1C) == 0) {
        return 0;
    }

    return ReadRealMemory(retaddr + 0x1C);
}

pString SearchStringValue(pString str)
{
    return ConvertString(SearchStringValueAddress(str));
}

void ReplaceStringValue(pString str, integer newstraddress, integer str_len)
{
    
        integer retaddr = SearchStringValueAddress(str);

        CopyMemory((void*)retaddr, (void*)newstraddress, str_len);
}

pString RegStr(const char* NullTermStr)
{
    return GetString(ConvertString(NullTermStr));
}

DWORD RegisterStr(const char* NullTermStr)
{
    return GetString(ConvertString(NullTermStr));
}

void WriteNullTerminatedString(const char* s, int pAddr)
{
    WriteRealMemory(pAddr, (DWORD)s);
}

const char* GetRCstringValue(DWORD pRCString)
{
    if(pRCString==0) return NULL;
    return (char*)ReadRealMemory(pRCString+0x1c);
}
const char* SetRCstringValue(DWORD pRCString)
{
    if(pRCString==0) return NULL;
    return (char*)ReadRealMemory(pRCString+0x1c);
}