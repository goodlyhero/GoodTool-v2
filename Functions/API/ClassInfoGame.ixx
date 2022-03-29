#include <map>
#include <BasicConstants.h>
#include <String>
#include <memory>
export module ClassInfoGame;
import ClassInfoGameBase;


export bool CheckGameClass(DWORD ptr)
{
	return ClassesFromVFTable.find(ptr) != ClassesFromVFTable.end();
}

export bool CheckGameClass(const char* name)
{
	return ClassesFromNames.find(name) != ClassesFromNames.end();
}

export DWORD GetFlagsFromVTable(DWORD VTable)
{
	auto a = ClassesFromVFTable.find(VTable);
	if (a == ClassesFromVFTable.end()) return CLASS_FLAG_INVALID;
	return a->second->flags;
}

export DWORD GetVTableFromName(const char* name)
{
	auto a = ClassesFromNames.find(name);
	if (a == ClassesFromNames.end()) return 0;
	return a->second->vtable;
}

export DWORD GetIdFromVtable(DWORD VTable)
{
	auto a = ClassesFromVFTable.find(VTable);
	if (a == ClassesFromVFTable.end()) return 0;
	return a->second->localid;
}

export DWORD GetIdFromName(const char* name)
{
	auto a = ClassesFromNames.find(name);
	if (a == ClassesFromNames.end()) return 0;
	return a->second->localid;
}

export const char* GetNameFromVTable(DWORD VTable)
{
	auto a = ClassesFromVFTable.find(VTable);
	if (a == ClassesFromVFTable.end()) return 0;
	auto targ = a->second;
	if (!targ.get()) return 0;
	return targ->classname;
}

export DWORD GetVTableFromId(DWORD id)
{
	auto a = ClassesFromIds.find(id);
	if (a == ClassesFromIds.end()) return 0;
	return a->second->vtable;
}

export const char* GetNameFromId(DWORD id)
{
	auto a = ClassesFromIds.find(id);
	if (a == ClassesFromIds.end()) return 0;
	auto targ = a->second;
	if (!targ.get()) return 0;
	return targ->classname;
}

export DWORD GetFlagsFromId(DWORD id)
{
	auto a = ClassesFromIds.find(id);
	if (a == ClassesFromIds.end()) return 0;
	return a->second->flags;
}	

export void InitClassInfoGame()
{
	InitClassInfoGameBase();
}