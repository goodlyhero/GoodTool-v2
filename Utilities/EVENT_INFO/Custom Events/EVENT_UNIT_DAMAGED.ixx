#include "../EVENT_INFO.h"
#include "../../Observer/DataNode Info Types.h"

export module EVENT_UNIT_DAMAGED;

import EventData;

export class EventDataUnitDamaged :public EventData
{
private:
	int source;
	int target;
	int flags;
	int damagetype;
	int attacktype;
	float damage;
public:
	EventDataUnitDamaged(int& _source, int& _target,int& _flags, int& _damagetype, int& _attacktype, float& _damage) :source(_source), target(_target),flags(_flags),damagetype(_damagetype),attacktype(_attacktype),damage(_damage) {};
	int DataAtToInt(int id)
	{
		switch (id)
		{
		case(EVENT_DATA_ID_DAMAGE_SOURCE):
			return source;
		case(EVENT_DATA_ID_DAMAGE_TARGET):
			return target;
		case(EVENT_DATA_ID_DAMAGE_TYPE):
			return damagetype;
		case(EVENT_DATA_ID_ATTACK_TYPE):
			return attacktype;
		case(EVENT_DATA_ID_DAMAGE_FLAGS):
			return flags;
		}
		return 0;
	}
	NODETYPE_FLOAT DataAtToFloat(int id)
	{
		if (id == EVENT_DATA_ID_EVENT_DAMAGE)
		{
			return damage;
		}
		return 0.0;
	}
	bool SetDataAt(int id,int data)
	{
		switch (id)
		{
		case(EVENT_DATA_ID_DAMAGE_SOURCE):
			source = data;
			return true;
		case(EVENT_DATA_ID_DAMAGE_TARGET):
			target = data;
			return true;
		case(EVENT_DATA_ID_DAMAGE_TYPE):
			damagetype = data;
			return true;
		case(EVENT_DATA_ID_ATTACK_TYPE):
			attacktype = data;
			return true;
		case(EVENT_DATA_ID_DAMAGE_FLAGS):
			flags = data;
			return true;
		}
		return false;
	}
	bool SetDataAt(int id, NODETYPE_FLOAT data)
	{
		if (id == EVENT_DATA_ID_EVENT_DAMAGE)
		{
			damage = data;
			return true;
		}
		return false;
	}
	int InfoTypeAt(int id)
	{
		switch (id)
		{
		case(EVENT_DATA_ID_DAMAGE_SOURCE):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_DAMAGE_TARGET):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_DAMAGE_TYPE):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_ATTACK_TYPE):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_DAMAGE_FLAGS):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_EVENT_DAMAGE):
			return DATANODE_TYPE_FLOAT;
		}
		return DATANODE_TYPE_NONE;
	}
};