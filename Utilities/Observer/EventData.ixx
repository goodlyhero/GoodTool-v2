#include <map>
#include <memory>
#include <string>
#include "DataNode Info Types.h"
export module EventData;

export import DataNode;
import Object;
export class EventData:public Object
{
private:
	int eventid;
	bool canceled;
public:
	EventData() :eventid(0), canceled(false) {};
	EventData(int _id) :eventid(_id),canceled(false) {};
	int BaseId()
	{
		return 'edat';
	}
	const char* Type()
	{
		return "EventData";
	}
	virtual int EventId()
	{
		return eventid;
	}
	virtual void SetEventId(int _id)
	{
		eventid = _id;
	}
	virtual bool IsCanceled()
	{
		return canceled;
	}
	virtual void Cancel()
	{
		canceled = true;
	}
	virtual const char* DataAtToCString(int dataid)
	{
		return nullptr;
	}
	virtual std::string DataAtToString(int dataid)
	{
		return std::string(nullptr);
	}
	virtual NODETYPE_FLOAT DataAtToFloat(int dataid)
	{
		return 0.0;
	}
	virtual int DataAtToInt(int dataid)
	{
		return 0;
	}
	virtual bool DataAtToBool(int dataid)
	{
		return false;
	}
	virtual int InfoTypeAt(int dataid)
	{
		return DATANODE_TYPE_NONE;
	}
	virtual bool SetDataAt(int dataid, int data)
	{
		return false;
	}
	virtual bool SetDataAt(int dataid,const char* data)
	{
		return false;
	}
	virtual bool SetDataAt(int dataid,std::string data)
	{
		return false;
	}
	virtual bool SetDataAt(int dataid, NODETYPE_FLOAT data)
	{
		return false;
	}
	virtual bool SetDataAt(int dataid, bool data)
	{
		return false;
	}
	
};