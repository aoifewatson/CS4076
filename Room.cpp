#include <sstream>
#include <QString>
#include <algorithm>
#include "Room.h"
#include "battle.h"
using namespace std;

Room::Room(string newName) : name(newName), monsterInRoom(NULL), last(false) { }

Room::Room(string newName, Item *item) {
    name = newName;
    itemsInRoom.push_back(item);
    last = false;
}

Room::~Room() {
}

void Room::setExits(Room *up, Room *left, Room *down, Room *right) {
    if (up != NULL)
        exits["up"] = up;
    if (left != NULL)
        exits["left"] = left;
    if (down != NULL)
        exits["down"] = down;
    if (right != NULL)
        exits["right"] = right;
}

string Room::getName() {
    return name;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL;
    return next->second;
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}

string Room::displayItem(){
    string items;
    int sizeItems = itemsInRoom.size();
    if (sizeItems < 1) {
        items = "There are no items in this room.\n";
    }
    else {
        items =  "Items in room:\n";
        for (int n = 0; n < sizeItems; n++) {
            items += " - " + itemsInRoom[n]->getName() + "\n";
        }
    }
    return items;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::getItemIndexByName(string itemName) { //used for getItemByName
    int index = 0;
    int size = itemsInRoom.size();
    for(int i = 0; i < size; i++) {
        //if (0 == itemName.compare(itemsInRoom[i]->getName())) {
        if ((*itemsInRoom[i]) == itemName) {
            index = i;
        }
    }
    return index;
}

Item* Room::getItemByName(string itemName) { //used
    int index = getItemIndexByName(itemName);
    return itemsInRoom[index];
}

void Room::addMonster(Monster *mon){
    this->monsterInRoom = mon;
}

Monster* Room::getMonsterInRoom() const{
    return monsterInRoom;
}

void Room::deleteMonsterInRoom(){
    delete this->monsterInRoom;
}

vector <Item*> Room::getItemsInRoom()const{
    return itemsInRoom;
}

void Room::removeItem(Item *item){
    itemsInRoom.erase( std::remove(itemsInRoom.begin(), itemsInRoom.end(), item), itemsInRoom.end());
}

void Room::setNullMonster(){
    this->monsterInRoom = NULL;
}

void Room::setLast(){
    this->last = true;
}

bool Room::getLast()const{
    return this->last;
}
