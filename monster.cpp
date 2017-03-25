#include "Monster.h"
#include "Character.h"

Monster::Monster(){
}

Monster::~Monster(){
    cout << "deleting monster" << endl;

}

Monster::Monster(string newName, int newHealth, double newHitChance){
    this->name = newName;
    this->health = newHealth;
    this->hitChance = newHitChance;
}

string Monster::getName()const{
    return this->name;
}

double Monster::getHitChance()const{
    return this->hitChance;
}

int Monster::getHealth()const{
   return this->health;
}

void Monster::setHealth(int newHealth){
    this->health = newHealth;
}
