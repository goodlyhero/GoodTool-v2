#include "../EVENT_INFO.h"
#include "../../Observer/DataNode Info Types.h"
#include <Events.h>
export module EVENT_KEY_INPUT;

import EventData;
import Event;

export class EventKeyInput : public Event
{
public:
	EventKeyInput(int _id) :Event(_id) {};
	void OnAct()
	{
		HookKeyboard(true);
	};
	virtual void OnDeact()
	{
		HookKeyboard(false);
	};
};


export class EventDataKeyInput :public EventData
{
private:
	int key;
	int mode;
public:
	EventDataKeyInput(int _key, int _mode) :key(_key),mode(_mode) {};
	int DataAtToInt(int _id)
	{
		switch (_id)
		{
		case(EVENT_DATA_ID_INPUTED_KEY):
			return key;
		case(EVENT_DATA_ID_INPUTED_KEY_MODE):
			return mode;
		}
		return 0;
	}
	int InfoTypeAt(int _id)
	{
		switch (_id)
		{
		case(EVENT_DATA_ID_INPUTED_KEY):
			return DATANODE_TYPE_INT;
		case(EVENT_DATA_ID_INPUTED_KEY_MODE):
			return DATANODE_TYPE_INT;
		}
		return DATANODE_TYPE_NONE;
	}
};

