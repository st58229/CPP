#include "StaticObject.h"

StaticObject::StaticObject(int id, BarrierType type):Object(id)
{
	Object* object = new Object(id);
	this->type = type;
}
StaticObject::~StaticObject() {}

BarrierType StaticObject::GetBarrier() 
{
	return this->type;
}
