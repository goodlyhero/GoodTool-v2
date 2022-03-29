#pragma once
#include <BasicConstants.h>

pString ConvertNullTerminatedStringToString(integer pNullTerminatedString);
pString ConvertNullTerminatedStringToString(const char* pNullTerminatedString);
pString RegStr(const char* NullTermStr);
void WriteNullTerminatedString(pString s, integer pAddr);
int SearchStringValueAddress(pString str);
pString SearchStringValue(pString str);
void ReplaceStringValue(pString str, integer newstraddress, integer str_len);
DWORD ToRCString(const char* pNullTerminatedString);
DWORD RegisterStr(const char* NullTermStr);
const char* ConvertJString(DWORD string);