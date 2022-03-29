#include <memory>
#include <map>
#include "DataNode Info Types.h"
#include <string>
#include <iostream>
export module EventDataEx;

import EventData;

export class EventDataEx:public EventData
{
private:
	std::map<int, std::shared_ptr<DataNode>> data;
public:
	EventDataEx() :EventData() {};
	int BaseId()
	{
		return 'edtx';
	}
	const char* Type()
	{
		return "EventDataEx";
	}
	const char* DataAtToCString(int dataid)
	{
		auto inode = data.find(dataid);
		if (inode == data.end())
		{
			return nullptr;
		}
		auto pnode = inode->second;
		return pnode->ToCString();
	}
	std::string DataAtToString(int dataid)
	{
		auto inode = data.find(dataid);
		if (inode == data.end()) return std::string(nullptr);
		auto pnode = inode->second;
		return pnode->ToString();
	}
	NODETYPE_FLOAT DataAtToFloat(int dataid)
	{
		auto inode = data.find(dataid);
		if (inode == data.end()) return 0;
		auto pnode = inode->second;
		return pnode->ToFloat();
	}
	int DataAtToInt(int dataid)
	{
		auto inode = data.find(dataid);
		if (inode == data.end())
		{
			return 0;
		}
		auto pnode = inode->second;
		return pnode->ToInt();
	}
	int InfoTypeAt(int dataid)
	{
		auto inode = data.find(dataid);
		if (inode == data.end()) return DATANODE_TYPE_NONE;
		auto pnode = inode->second;
		return pnode->InfoType();
	}
	bool SetDataAt(int dataid, int _data)
	{
		data[dataid] = std::make_shared<DataNodeInt>(_data);
		return true;
	}
	bool SetDataAt(int dataid, const char* _data)
	{
		data[dataid] = std::make_shared<DataNodeCString>(_data);
		return true;
	}
	bool SetDataAt(int dataid, std::string _data)
	{
		data[dataid] = std::make_shared<DataNodeString>(_data);
		return true;
	}
	bool SetDataAt(int dataid, NODETYPE_FLOAT _data)
	{
		data[dataid] = std::make_shared<DataNodeFloat>(_data);
		return true;
	}
	bool SetDataAt(int dataid, bool _data)
	{
		data[dataid] = std::make_shared<DataNodeBool>(_data);
		return true;
	}
};