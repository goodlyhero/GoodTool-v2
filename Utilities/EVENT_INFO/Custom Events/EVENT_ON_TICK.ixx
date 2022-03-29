#include "../EVENT_INFO.h"
#include "../../Observer/DataNode Info Types.h"
export module EVENT_ON_TICK;

import EventData;

export class EventDataOnTick :public EventData
{
private:
	int pCNetData;
public:
	EventDataOnTick(int _pCNetData) :pCNetData(_pCNetData) {};
	int DataAtToInt(int id)
	{
		if (id != EVENT_DATA_ID_PNETDATA) return 0;
		return pCNetData;
	}
	int InfoTypeAt(int id)
	{
		if (id != EVENT_DATA_ID_PNETDATA) return DATANODE_TYPE_NONE;
		return DATANODE_TYPE_INT;
	}
};