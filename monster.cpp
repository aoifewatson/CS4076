#include "Monster.h"

Monster::Monster(){
}

Monster::~Monster(){
}

Monster::Monster(string newName, int newHealth, double newHitChance)
    : Character(newName, newHealth, newHitChance)
{ }
