#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(string description, Item item);
    Room(string description);
    void setExits(Room *up, Room *left, Room *down, Room *right);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item item);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    string getItems();


};

#endif
