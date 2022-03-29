#include "../EVENT_INFO.h"
#include "../../Observer/DataNode Info Types.h"
export module EVENT_CHAT_COMMAND;

import EventData;

export class EventDataChatcommand :public EventData
{
private:
	const char* EnteredMessage;
public:
	EventDataChatcommand(const char* _EnteredMessage) :EnteredMessage(_EnteredMessage) {};
	const char* DataAtToCString(int id)
	{
		if (id != EVENT_DATA_ID_INPUTED_STRING) return nullptr;
		return EnteredMessage;
	}
	int InfoTypeAt(int id)
	{
		if (id != EVENT_DATA_ID_INPUTED_STRING) return DATANODE_TYPE_NONE;
		return DATANODE_TYPE_CSTR;
	}
};