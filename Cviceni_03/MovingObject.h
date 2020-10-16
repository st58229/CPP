#pragma once
#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#include "Object.h"

class MovingObject:public Object
{
private:
	double angle;
public:
	MovingObject(int id, double angle);
	void SetAngle(double angle);
	double GetAngle();
};
#endif

