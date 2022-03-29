export module EVENTS;
#include "EVENT_INFO.h"
export import Event;
export import EventData;
import Dispatcher;
import GeneralDispatcher;
export import EVENT_KEY_INPUT;

//Dispatcher GeneralDispatcher;

#define NewEvent(id,name) export Event name(id); // GeneralDispatcher.AddEvent(id,&(name));

export EventKeyInput EVENT_KEY_INPUT(EVENT_ID_KEY_INPUT);
NewEvent(EVENT_ID_CHAT_COMMAND, EVENT_CHAT_COMMAND)
NewEvent(EVENT_ID_SCREEN_UPDATE, EVENT_SCREEN_UPDATE)
NewEvent(EVENT_ID_SCRIPT_LOADED, EVENT_SCRIPT_LOADED)
NewEvent(EVENT_ID_UNIT_DAMAGED, EVENT_UNIT_DAMAGED)
NewEvent(EVENT_ID_GAME_ENDED, EVENT_GAME_ENDED)
NewEvent(EVENT_ID_ON_TICK, EVENT_ON_TICK)
#undef NewEvent
#define NewEvent(id,name) (name).SetEventId(id); GeneralDispatcher.AddEvent((id),&(name));
export void InitEvents()
{
	NewEvent(EVENT_ID_CHAT_COMMAND, EVENT_CHAT_COMMAND)
	NewEvent(EVENT_ID_SCREEN_UPDATE, EVENT_SCREEN_UPDATE)
	NewEvent(EVENT_ID_KEY_INPUT, EVENT_KEY_INPUT)
	NewEvent(EVENT_ID_SCRIPT_LOADED, EVENT_SCRIPT_LOADED)
	NewEvent(EVENT_ID_UNIT_DAMAGED, EVENT_UNIT_DAMAGED)
	NewEvent(EVENT_ID_GAME_ENDED, EVENT_GAME_ENDED)
	NewEvent(EVENT_ID_ON_TICK, EVENT_ON_TICK)
}
#undef NewEvent
