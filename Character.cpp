#include "Character.h"

Character::Character() {
    this->name = "Flan Costello";
    this->health = 1;
    this->hitChance = 1;
}


Character::Character(string newName, string favFood, int startingHealth, double newHitChance) {
    this->name = newName;
    this->food = favFood;
    this->health = startingHealth;
    this->hitChance = newHitChance;
}


void Character::addItem(Item *item) {
    itemsInCharacter.push_back(item);
    //delete item;
}

string Character::getName() const {
    return name;
}

vector <Item*> Character::getItemsInCharacter() {
    return itemsInCharacter;
}

double Character::getHitChance() const {
    return this->hitChance;
}

int Character::getHealth() const {
    return this->health;
}

void Character::setHealth(int newHealth){
    this->health = newHealth;
}



