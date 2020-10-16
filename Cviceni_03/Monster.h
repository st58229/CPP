#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include "MovingObject.h"

class Monster:public MovingObject
{
private:
	int hp;
	int maxHP;
public:
	void SetHP(int hp);
	void SetMaxHP(int maxHP);
	int GetHP();
	int getMaxHP() const;
};
#endif