export module Event;
import Object;
import EventData;
import EventTransporters;
export class Event : public EventSender, public Object
{
public:
	Event() :EventSender() {};
	Event(int _eventid)
	{
		SetEventId(_eventid);
	}
	int BaseId()
	{
		return 'evnt';
	}
	const char* Type()
	{
		return "EventBase";
	}
};