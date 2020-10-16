#pragma once
#ifndef OBJECT_H
#define OBJECT_H
class Object
{
private:
	int id;
	double x;
	double y;

public:
	Object(int id);
	virtual ~Object() {};
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);
	int GetID() const;
};

#endif

