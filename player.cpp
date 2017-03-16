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

string Player::getName()const{
    return this->name;
}

double Player::getHitChance()const{
    return this->hitChance;
}

int Player::getHealth()const{
   return this->health;
}

void Player::setHealth(int newHealth){
    this->health = newHealth;
}


vector <Item*> Player::getItemsInCharacter()const{
    return itemsInCharacter;
}

void Player::addItem(Item *item){
    itemsInCharacter.push_back(item);
    //delete item;
}
