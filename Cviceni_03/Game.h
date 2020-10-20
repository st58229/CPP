#pragma once
#ifndef GAME_H
#define GAME_H
#include "MovingObject.h"

class Game
{
private:
	Object** objects;
	int counter;
	int maxSize;
public:
	Game(int nuberOfMaxEntites);
	~Game();
	void InsertObject(Object* o);
	int* FindStaticObjectsIDs(double xMin, double xMax, double yMin, double yMax);
	MovingObject** FindMovingObjects(double X, double Y, double r, double angleMin, double angleMax);
	MovingObject** FindMovingObjects(double X, double Y, double r);
};
#endif