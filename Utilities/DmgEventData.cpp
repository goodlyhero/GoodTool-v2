#include <From MemHack.h>

struct dmgeventdata
{
	DWORD source;
	DWORD target;
	DWORD dmgtype;
	DWORD atktype;
	float dmg;
	DWORD flags;
};

dmgeventdata DmgData;

void SetSource(DWORD _source)
{
	DmgData.source = _source;
}
DWORD GetSource()
{
	return DmgData.source;
}
void SetTarget(DWORD _target)
{
	DmgData.target = _target;
}
DWORD GetTarget()
{
	return DmgData.target;
}
void SetSourceHandle(DWORD _source)
{
	DmgData.source = ConvertHandle(_source);
}
DWORD GetSourceHandle()
{
	return ObjectToHandleId(DmgData.source);
}
void SetTargetHandle(DWORD _target)
{
	DmgData.target = ConvertHandle(_target);
}
DWORD GetTargetHandle()
{
	return ObjectToHandleId(DmgData.target);
}
void SetDmgType(DWORD _dmgtype)
{
	DmgData.dmgtype = _dmgtype;
}
DWORD GetDmgType()
{
	return DmgData.dmgtype;
}
void SetAtkType(DWORD _atktype)
{
	DmgData.atktype = _atktype;
}
DWORD GetAtkType()
{
	return DmgData.atktype;
}
void SetDmg(float _dmg)
{
	DmgData.dmg = _dmg;
}
float GetDmg()
{
	return DmgData.dmg;
}
void SetFlags(DWORD _flags)
{
	DmgData.flags = _flags;
}
DWORD GetFlags()
{
	return DmgData.flags;
}