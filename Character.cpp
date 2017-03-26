#include "Character.h"

//Character::~Character(){
//}

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
