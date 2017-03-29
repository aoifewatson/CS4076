#include "Character.h"

Character::Character(){ }

Character::~Character(){
}

Character::Character(string name, int health, double hitChance) : name(name), health(health), hitChance(hitChance)
{
//    this->name = name;
//    this->health = health;
//    this->hitChance = hitChance;
}

string Character::getName()const{
    return this->name;
}

double Character::getHitChance()const{
    return this->hitChance;
}

int Character::getHealth()const{
   return this->health;
}

void Character::setHealth(int newHealth){
    this->health = newHealth;
}
