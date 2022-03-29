#include <string>;
#include "DataNode Info Types.h"
#include <iostream>
export module DataNode;

import Object;
export using NODETYPE_FLOAT = double;



export class DataNode:public Object
{
public:
	int BaseId()
	{
		return 'dnod';
	}
	const char* Type()
	{
		return "DataNode";
	}
	virtual const char* ToCString()
	{
		return nullptr;
	}
	virtual std::string ToString()
	{
		return std::string(nullptr);
	}
	virtual NODETYPE_FLOAT ToFloat()
	{
		return 0.0;
	}
	virtual bool ToBool()
	{
		return false;
	}
	virtual int ToInt()
	{
		return 0;
	}
	virtual int InfoType()
	{
		return DATANODE_TYPE_NONE;
	}
	virtual bool Set(int data)
	{
		return false;
	}
	virtual bool Set(const char* data)
	{
		return false;
	}
	virtual bool Set(NODETYPE_FLOAT data)
	{
		return false;
	}
	virtual bool Set(std::string data)
	{
		return false;
	}
	virtual bool Set(bool data)
	{
		return false;
	}
};

export class DataNodeInt :public DataNode
{
private:
	int data;
public:
	DataNodeInt(int _data) :data(_data) {};
	int BaseId()
	{
		return 'dndi';
	}
	const char* Type()
	{
		return "DataNodeInt";
	}
	int ToInt()
	{
		return data;
	}
	NODETYPE_FLOAT ToFloat()
	{
		return data;
	}
	int InfoType()
	{
		return DATANODE_TYPE_INT;
	}
	bool Set(int _data)
	{
		data = _data;
		return true;
	}
};

export class DataNodeFloat :public DataNode
{
private:
	NODETYPE_FLOAT data;
public:
	DataNodeFloat(NODETYPE_FLOAT _data) :data(_data) {};
	int BaseId()
	{
		return 'dndf';
	}
	const char* Type()
	{
		return "DataNodeFloat";
	}
	NODETYPE_FLOAT ToFloat()
	{
		return data;
	}
	int ToInt()
	{
		return data;
	}
	int InfoType()
	{
		return DATANODE_TYPE_FLOAT;
	}

	bool Set(NODETYPE_FLOAT _data)
	{
		data = _data;
		return true;
	}
};

export class DataNodeCString :public DataNode
{
private:
	const char* data;
public:
	DataNodeCString(const char* _data) :data(_data) {};
	int BaseId()
	{
		return 'dndc';
	}
	const char* Type()
	{
		return "DataNodeCString";
	}
	int InfoType()
	{
		return DATANODE_TYPE_CSTR;
	}
	const char* ToCString()
	{
		return data;
	}
	std::string ToString()
	{
		return data;
	}
	bool Set(const char* _data)
	{
		data = _data;
		return true;
	}
};

export class DataNodeString :public DataNode
{
private:
	std::string data;
public:
	DataNodeString(std::string _data) :data(_data) {};
	int BaseId()
	{
		return 'dnds';
	}
	const char* Type()
	{
		return "DataNodeString";
	}
	int InfoType()
	{
		return DATANODE_TYPE_STRING;
	}
	std::string ToString()
	{
		return data;
	}
	bool Set(std::string _data)
	{
		data = _data;
		return true;
	}
	const char* ToCString()
	{
		return data.c_str();
	}
};



export class DataNodeBool :public DataNode
{
private:
	bool data;
public:
	DataNodeBool(bool _data) :data(_data) {};
	int BaseId()
	{
		return 'dndb';
	}
	const char* Type()
	{
		return "DataNodeBool";
	}
	int InfoType()
	{
		return DATANODE_TYPE_BOOL;
	}
	std::string ToString()
	{
		return data?"true":"false";
	}
	bool Set(bool _data)
	{
		data = _data;
		return true;
	}
	const char* ToCString()
	{
		return data ? "true" : "false";
	}
	bool ToBool()
	{
		return data;
	}
};