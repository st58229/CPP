#pragma once
#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "Object.h"
enum class BarrierType { Rock, Plant, Tree };

class StaticObject:public Object
{
private:
	BarrierType type;

public:
	StaticObject(int id, BarrierType type);
	~StaticObject();
	BarrierType GetBarrier();
};
#endif

