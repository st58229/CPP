#include "Game.h"
#include "Monster.h"
#include "MovingObject.h"
#include "Object.h"
#include "StaticObject.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Game* game = new Game(50);

	Object* o1 = new StaticObject(1, BarrierType::Rock);
	o1->SetX(0);
	o1->SetY(0);
	game->InsertObject(o1);
	Object* o2 = new StaticObject(2, BarrierType::Plant);
	o2->SetX(5);
	o2->SetY(8);
	game->InsertObject(o2);
	Object* o3 = new MovingObject(3, 90.0);
	o3->SetX(1);
	o3->SetY(9);
	game->InsertObject(o3);
	Object* o4 = new MovingObject(4, 100.0);
	o4->SetX(1);
	o4->SetY(9);
	game->InsertObject(o4);
	Object* o5 = new MovingObject(5, 10.0);
	o5->SetX(1);
	o5->SetY(1);
	game->InsertObject(o5);

	cout << "(1) Id hledaneho je:" << game->FindStaticObjectsIDs(0, 10, 0, 10)[0] << "\n";
	cout << "(2) Id hledaneho je:" << game->FindStaticObjectsIDs(0, 10, 0, 10)[1] << "\n";
	cout << "(-) Id hledaneho je:" << game->FindStaticObjectsIDs(0, 10, 0, 10)[2] << "\n";
	cout << "*******\n";
	cout << "(5) Id hledaneho je:" << game->FindMovingObjects(0, 0, 5)[0]->GetID() << "\n";
	cout << "*******\n";
	cout << "(5) Id hledaneho je:" << game->FindMovingObjects(0, 0, 10, 0, 30)[0]->GetID() << "\n";
	cout << "*******\n";
	cout << "(3) Id hledaneho je:" << game->FindMovingObjects(0, 0, 10, 0, 110)[0]->GetID() << "\n";
	cout << "(4) Id hledaneho je:" << game->FindMovingObjects(0, 0, 10, 0, 110)[1]->GetID() << "\n";
	cout << "(5) Id hledaneho je:" << game->FindMovingObjects(0, 0, 10, 0, 110)[2]->GetID() << "\n";


	return 0;
}