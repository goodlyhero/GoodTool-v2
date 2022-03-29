#include <iostream>
export module Object;

export class Object
{
private:
	int id;
public:
	Object():id(BaseId())
	{

	}
	Object(int _id) :id(_id)
	{

	}
	virtual void SetId(int _id)
	{
		id = _id;
	}
	virtual int BaseId()
	{
		return '+obj';
	}
	virtual const char* Type()
	{
		return "Object";
	}
	virtual int Id()
	{
		return id;
	}
	~Object()
	{

	}
};