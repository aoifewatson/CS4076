#include "Character.h"

Character::Character() {
}


Character::Character(string newDescription, int startingHealth, double newHitChance) {
    this->description = newDescription;
    this->health = startingHealth;
    this->hitChance = newHitChance;
}

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
    //delete item;
}

void Character::setName(string newName) {
    name = "James";
}

string Character::getName() const {
    return name;
}

vector <Item> Character::getItemsInCharacter() {
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



