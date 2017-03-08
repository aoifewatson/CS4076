#include "Character.h"

Character::Character() {
}

Character::Character(string inDescription) { //constuctor with name - do we need this method??
    description = inDescription;
}

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
    //delete item;
}

void Character::setName(string newName) {
    name = "James";
}

string Character::getName() {
    return name;
}

vector <Item> Character::getItemsInCharacter()
{
    return itemsInCharacter;
}




