#include "Character.h"

Character::Character() {
}

Character::Character(string description) { //constuctor with name - do we need this method??
    this->description = description;
}

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
    //delete item;
}

void Character::setName(string newName) {
    name = newName;
}

string Character::getName() {
    return name;
}

vector <Item> Character::getItemsInCharacter()
{
    return itemsInCharacter;
}



