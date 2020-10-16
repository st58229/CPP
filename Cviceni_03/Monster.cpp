#include "Monster.h"

void Monster::SetHP(int hp) { this->hp = hp; }
void Monster::SetMaxHP(int maxHP) {	this->maxHP = maxHP; }
int Monster::GetHP() { return this->hp; }
int Monster::getMaxHP() const { return this->maxHP; }
