#include "Monster.h"
#include "Character.h"

Monster::Monster(){
}

Monster::~Monster(){
}

Monster::Monster(string newName, int newHealth, double newHitChance){
    this->name = newName;
    this->health = newHealth;
    this->hitChance = newHitChance;
}

