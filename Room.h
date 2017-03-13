#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Character.h"
using namespace std;
using std::vector;

class Room {

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector <Item*> itemsInRoom;
    vector <Character*> othersInRoom;
    ~Room();



public:
    int numberOfItems();
    Room(string description, Item *item);
    Room(string description);
    void setExits(Room *up, Room *left, Room *down, Room *right);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    string getItems();
    int getItemIndexByName(string itemName);
    int getItemIndex(Item *item);
    int getItemLocation(Item item);
    Item* getItemByIndex(int index);
    Item* getItemByName(string itemName);

    void removeItemFromRoom(int index);
    string getItems() const;
    int getItemByName(string itemName) const;
    int getItemIndex(Item item);
    int getItemLocation(Item item) const;
    void addCharacter(Character *monster);
    string displayCharacters() const;
    vector <Character*> getOthersInRoom() const;

};

#endif
