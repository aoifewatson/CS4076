#include "Player.h"

Player::Player(){
}

Player::Player(string newName, string favFood, int newHealth, double newHitChance){
    this->name = newName;
    this->food = favFood;
    this->health = newHealth;
    this->hitChance = newHitChance;
}

Player::~Player(){

}

vector <Item*> Player::getItemsInCharacter()const{
    return itemsInCharacter;
}

void Player::addItem(Item *item){
    itemsInCharacter.push_back(item);
    //delete item;
}

