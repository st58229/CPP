#include "Game.h"
#include "StaticObject.h"
#include <iostream>

Game::Game(int numberOfMaxEntites) 
{
	objects = new Object*[numberOfMaxEntites];
	this->counter = 0;
	this->maxSize = numberOfMaxEntites;
}

void Game::InsertObject(Object* o) 
{
	if (this->counter < this->maxSize)
	{
		objects[this->counter] = o;
		this->counter++;
	}
}
int* Game::FindStaticObjectsIDs(double xMin, double xMax, double yMin, double yMax) 
{	
	int* IDs = new int[counter];
	int counterID = 0;

	for (size_t i = 0; i < this->counter; i++)
	{
		Object* o = objects[i];
		double x = o->GetX();
		double y = o->GetY();

		if (dynamic_cast<StaticObject*>(objects[i]) != nullptr && x >= xMin && x <= xMax && y >= yMin && y <= yMax)
		{
			IDs[counterID] = o->GetID();
			counterID++;
		}	
	}

	int* retID = new int[counterID];
	for (size_t i = 0; i < counterID; i++)
	{
		retID[i] = IDs[i];
	}
	delete[] IDs;

	return retID;
}
MovingObject** Game::FindMovingObjects(double X, double Y, double r)
{
	MovingObject** fObjects = new MovingObject*[this->counter];
	int counterMO = 0;

	for (size_t i = 0; i < counter; i++)
	{

		if (dynamic_cast<MovingObject*>(objects[i]) != nullptr && pow(objects[i]->GetX() - X, 2) + pow(objects[i]->GetY() - Y, 2) <= pow(r, 2))
		{
			fObjects[counterMO] = dynamic_cast<MovingObject*>(objects[i]);
			counterMO++;
		}
	}

	MovingObject** retObjects = new MovingObject * [counterMO];
	for (size_t i = 0; i < counterMO; i++)
	{
		retObjects[i] = fObjects[i];
	}

	delete[] fObjects;

	return retObjects;
}

MovingObject** Game::FindMovingObjects(double X, double Y, double r, double angleMin, double angleMax)
{
	MovingObject** fObjects = new MovingObject * [this->counter];
	int counterMO = 0;

	for (size_t i = 0; i < counter; i++)
	{
		MovingObject* o = dynamic_cast<MovingObject*>(objects[i]);
		if (o != nullptr && pow(objects[i]->GetX() - X, 2) + pow(objects[i]->GetY() - Y, 2) <= pow(r, 2) && o->GetAngle() <= angleMax && o->GetAngle() >= angleMin)
		{
			fObjects[counterMO] = dynamic_cast<MovingObject*>(objects[i]);
			counterMO++;
		}
	}

	MovingObject** retObjects = new MovingObject * [counterMO];
	for (size_t i = 0; i < counterMO; i++)
	{
		retObjects[i] = fObjects[i];
	}

	delete[] fObjects;

	return retObjects;

}
