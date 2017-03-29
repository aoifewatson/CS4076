#include <vector>
#include "Player.h"
#include "item.h"
using namespace std;

Player::Player(){
}

Player::Player(string newName, int newHealth, double newHitChance, string favFood) : Character(newName, newHealth, newHitChance), food(favFood)
{ }

Player::~Player(){

}

vector <Item*> Player::getItemsInCharacter()const{
    return itemsInCharacter;
}

void Player::addItem(Item *item){
    itemsInCharacter.push_back(item);
}

void Player::setCurrentItem(Item item) {
    currentItem = item;
}

Item Player::getCurrentItem() {
    return currentItem;
}

