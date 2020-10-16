#include "Object.h"

Object::Object(int id) 
{
	this->id = id;
}
double Object::GetX() const { return this->x; }
double Object::GetY() const { return this->y; }
void Object::SetX(double x)  { this->x = x; }
void Object::SetY(double y)  { this->y = y; }
int Object::GetID() const { return this->id; }
