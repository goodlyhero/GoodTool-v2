#include <memory>
export module EventDispatcherBase;

import Object;
import EventTransporters;

class EventDispatcherBase;
class DispatcherObserverBase;
class DispatcherSenderBase;

export class DispatcherObserverBase : public ObserverBase
{
private:
public:
	DispatcherObserverBase() {};
	virtual void SetOwner(EventDispatcherBase* dispatcher) {};
	virtual bool IsConnectedWithObserver(ObserverBase* obs) { return false; };
	virtual bool AddObserver(ObserverBase* obs) { return false; };
	virtual void RemoveObserver(ObserverBase* obs) {};
	virtual void ObserveAnotherDispatcher(int eventid, EventDispatcherBase* dispatcher) {};
	virtual int CountListeners() { return 0; };
	virtual ~DispatcherObserverBase() {};
};

export class DispatcherSenderBase : public EventSender
{
private:
public:
	DispatcherSenderBase() {};
	virtual void SetOwner(DispatcherObserverBase* _dispatcher) {};
	virtual ~DispatcherSenderBase() {};
};

export class EventDispatcherBase :public Object
{
private:
public:
	int BaseId()
	{
		return 'odsb';
	}
	const char* Type()
	{
		return "EventDispatcherBase";
	}
	virtual bool AddEvent(int id, EventSender* s) { return false; };
	virtual void RemoveEvent(int id) {};
	virtual bool AddObserver(int eventid, ObserverBase* obs) { return false; };
	virtual void RemoveObserver(ObserverBase* obs) {};
	virtual DispatcherObserverBase* GetEventWithId(int id) { return nullptr; };
	virtual bool HasEventWithId(int id) { return false; };
	virtual int CountListeners(int id) { return 0; };
};