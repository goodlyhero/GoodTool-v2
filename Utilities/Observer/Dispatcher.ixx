#include <vector>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <iostream>
#include <Logs\Log.h>
export module Dispatcher;

export import EventDispatcherBase;
export import EventTransporters;
export class DispatcherSender : public DispatcherSenderBase
{
private:
	DispatcherObserverBase* owner;
public:
	DispatcherSender() {};
	DispatcherSender(DispatcherObserverBase* _owner) :owner(_owner) {};
	DispatcherSender(DispatcherObserverBase* _owner, ObserverBase* obs) :owner(_owner) { if (obs) Connect(obs); };
	void SetOwner(DispatcherObserverBase* obs)
	{
		if (!obs || owner) return;
		owner = obs;
	}
	void RawDisconnect()
	{
		auto oldtarget = target;
		//mlog::Debug("Raw disconnect dispatcher");
		target = nullptr;
		owner->RemoveObserver(oldtarget);
	}
	void Disconnect()
	{
		if (!target) return;
		target->RawDisconnect();
		RawDisconnect();
	}
	~DispatcherSender()
	{
		Disconnect();
	}
};

export class DispatcherObserver :public DispatcherObserverBase
{
private:
	EventDispatcherBase* owner;
	EventSender* source;
	std::map<ObserverBase*, DispatcherSenderBase*> senders;
	int id;
public:
	DispatcherObserver() :id(0), owner(nullptr), source(nullptr), senders() {};
	DispatcherObserver(int _id) :id(_id), owner(nullptr), source(nullptr), senders() {};
	DispatcherObserver(EventSender* _source) :DispatcherObserver()
	{
		source = _source;
	};
	DispatcherObserver(int _id, EventSender* _source) :DispatcherObserver(_id)
	{
		source = _source;
	};
	DispatcherObserver(int _id, EventSender* _source, EventDispatcherBase* _owner) :DispatcherObserver(_id)
	{
		source = _source;
		owner = _owner;
	};
	void AcceptMessage(std::shared_ptr<EventData> data)
	{
		auto sender = senders.begin();
		while (sender != senders.end())
		{
			auto target = sender->second;
			sender++;
			if (target)
			{
				target->SendEvent(data);
			}
		}
	}
	void SetOwner(EventDispatcherBase* dispatcher)
	{
		if (!dispatcher || owner) return;
		owner = dispatcher;
	}
	bool IsConnectedWithObserver(ObserverBase* obs)
	{
		return (senders.find(obs) != senders.end());
	}
	bool AddObserver(ObserverBase* obs)
	{
		if (!obs)return false;
		if (IsConnectedWithObserver(obs)) return false;
		auto* sender = new DispatcherSender(this);
		sender->Connect(obs);
		if (!sender->IsConnected())
		{
			delete sender;
			return false;
		}
		senders[obs] = sender;
		if (senders.size() == 1) Connect(source);
		return true;
	}
	void RemoveObserver(ObserverBase* obs)
	{
		auto s = senders.find(obs);
		//mlog::Debug("Removing observer");
		if (s == senders.end())
		{
			//mlog::Debug("Observer not found");
			return;
		}
		//mlog::Debug("Observer found, removing");
		delete s->second;
		senders.erase(obs);
		if (senders.size() == 0) Disconnect();
	}
	int CountListeners()
	{
		return senders.size();
	}
	~DispatcherObserver()
	{
		Disconnect();
		for (auto a = senders.begin(); a != senders.end(); a = senders.begin())
		{
			auto ptr = a->second;
			senders.erase(a);
			delete ptr;
		}
		if (owner)
		{
			owner->RemoveEvent(id);
		}
	}
};

export class Dispatcher :public EventDispatcherBase
{
protected:
	std::map< int,DispatcherObserver*> events;
public:
	Dispatcher() :EventDispatcherBase()
	{

	};
	int BaseId()
	{
		return 'odsd';
	}
	const char* Type()
	{
		return "Dispatcher";
	}
	bool AddEvent(int id, EventSender* s)
	{
		if (id < (int)0 || !s) return false;
		auto obs = new DispatcherObserver(id, s, this);
		events[id] = obs;
		return true;
	}
	DispatcherObserverBase* GetEventWithId(int id)
	{
		auto a = events.find(id);
		if (a == events.end()) return nullptr;
		return a->second;
	}
	void RemoveEvent(int id)
	{
		auto event = GetEventWithId(id);
		if (!event) return;
		if (event == nullptr) return;
		events[id] = nullptr;
		delete event;
	}
	bool AddObserver(int eventid, ObserverBase* obs)
	{
		auto event = GetEventWithId(eventid);
		if (!event)
		{
			return false;
		}
		return event->AddObserver(obs);
	}
	void RemoveObserver(int id, ObserverBase* obs)
	{
		auto event = GetEventWithId(id);
		if (!event)
		{
			//mlog::Debug("Unable to find event with id: ", id);
			return;
		}
		//mlog::Debug("Removing observer");
		event->RemoveObserver(obs);
	}
	void ObserveAnotherDispatcher(int eventid, EventDispatcherBase* dispatcher)
	{
		if (!dispatcher) return;
		DispatcherObserver* obs = new DispatcherObserver(eventid,nullptr,this);

	}
	int CountListeners(int id)
	{
		auto event = GetEventWithId(id);
		if (!event)
		{
			return 0;
		}
		return event->CountListeners();
	}
	~Dispatcher()
	{
		auto a = events.begin();
		while (a != events.end())

		{
			auto ptr = a->second;
			events.erase(a);
			delete ptr;
			a = events.begin();
		}
	}
};