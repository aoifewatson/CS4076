#include "Character.h"

Character::Character(){ //no args construtor
}

Character::Character(string description) { //constuctor with name - do we need this method??
    this->description = description;
}

void Character::addItem(Item *item) {
    itemsInCharacter.push_back(item);
    //delete item;
}

vector <Item*> Character::getItemsInCharacter()
{
    return itemsInCharacter;
}



