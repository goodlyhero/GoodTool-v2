#pragma once
#include <Windows.h>
void SetSource(DWORD _source);
DWORD GetSource();
void SetTarget(DWORD _target);
DWORD GetTarget();
void SetSourceHandle(DWORD _source);
DWORD GetSourceHandle();
void SetTargetHandle(DWORD _target);
DWORD GetTargetHandle();
void SetDmgType(DWORD _dmgtype);
DWORD GetDmgType();
void SetAtkType(DWORD _atktype);
DWORD GetAtkType();
void SetDmg(float _dmg);
float GetDmg();
void SetFlags(DWORD _flags);
DWORD GetFlags();
struct dmgeventdata
{
	DWORD source;
	DWORD target;
	DWORD dmgtype;
	DWORD atktype;
	float dmg;
	DWORD flags;
};
extern dmgeventdata DmgData;


