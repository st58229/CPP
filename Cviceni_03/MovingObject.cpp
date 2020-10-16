#include "MovingObject.h"

void MovingObject::SetAngle(double angle){ this->angle = angle; }
double MovingObject::GetAngle(){ return this->angle; }
MovingObject::MovingObject(int id, double angle):Object(id)
{ 
	Object* object = new Object(id);
	this->angle = angle; 
}
