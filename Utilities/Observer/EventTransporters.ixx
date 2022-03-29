#include <memory>
#include <Logs\Log.h>
#include <vector>
export module EventTransporters;


export import EventData;
class ObserverBase;
class EventSender;
export class EventSender
{
protected:
	ObserverBase* target;
	int eventid;
	bool active;
	bool enabled;
public:
	void SetEventId(int _id)
	{
		eventid = _id;
	}

	int EventId()
	{
		return eventid;
	}
	bool IsEnabled()
	{
		return enabled;
	}
	bool IsActive()
	{
		return active;
	}
	void Enable(bool mode)
	{
		enabled = mode;
	}
	virtual void OnAct()
	{

	}
	virtual void OnDeact()
	{

	}
	virtual void Activate(bool mode)
	{
		if (active == mode)return;
		active = mode;
		if (mode)
		{
			OnAct();
		}
		else
		{
			OnDeact();
		}
	}
	virtual void RawConnect(ObserverBase* _target)
	{
		if (target)
		{
			Disconnect();
		}
		target = _target;
		Activate(true);
	}
	virtual void Connect(ObserverBase* _target);
	virtual void RawDisconnect()
	{
		target = nullptr;
		Activate(false);
	}
	virtual void Disconnect();
	virtual void SendEvent(std::shared_ptr<EventData> data);
	EventSender() :  active(false),enabled(true),eventid(0),target(nullptr) {};
	EventSender(int _id) : active(false),enabled(true),target(nullptr) {};
	virtual bool IsConnected()
	{
		return target;
	}
	virtual ~EventSender()
	{
		Disconnect();
	}

};

export class ObserverBase
{
protected:
	EventSender* source;
public:
	ObserverBase() :source(nullptr) {};
	virtual void AcceptMessage(std::shared_ptr<EventData> data) {};
	virtual void RawConnect(EventSender* _source)
	{
		if (source)
		{
			Disconnect();
		}
		source = _source;
	}
	virtual bool Connect(EventSender* _source) 
	{
		if (!_source) return false;
		_source->RawConnect(this);
		RawConnect(_source);
		return true;
	}
	virtual void RawDisconnect()
	{
		source = nullptr;
	}
	virtual void Disconnect()
	{
		if (!source)

		{
			return;
		}
		source->RawDisconnect();
		RawDisconnect();
	}
	virtual bool IsConnected()
	{
		return source;
	}
	virtual ~ObserverBase()
	{
		Disconnect();
	}
};


void EventSender::Connect(ObserverBase* _target)
{
	if (!_target) return;
	_target->RawConnect(this);
	RawConnect(_target);
}

void EventSender::Disconnect()
{
	if (!target) return;
	target->RawDisconnect();
	RawDisconnect();
}

void EventSender::SendEvent(std::shared_ptr<EventData> data)
{
	if (enabled && target)
	{
		if (data.get())
		{
			data->SetEventId(eventid);
		}
		target->AcceptMessage(data);
	}
}
