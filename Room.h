#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QString>
#include <string>
#include <vector>
#include <QPushButton>
#include "item.h"
#include "Monster.h"

class Room {

private:
    string name;
    map<string, Room*> exits;
    string exitString();
    vector <Item*> itemsInRoom;
    Monster *monsterInRoom;
    ~Room();
    bool last;

public:
    int numberOfItems();
    Room(string description, Item *item);
    Room(string description);
    void setExits(Room *up, Room *left, Room *down, Room *right);
    string getName();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    string getItems();
    int getItemIndexByName(string itemName);
    Item* getItemByName(string itemName);
    //void eraseItemFromRoom(int index);
    vector <QPushButton> getItemButtons();
    void removeItemFromRoom(int index);
    string getItems() const;
    void addMonster(Monster *Monster);
    Monster* getMonsterInRoom() const;
    Room* getCurrentRoom() const;
    void deleteMonsterInRoom();
    vector <Item*> getItemsInRoom()const;
    void removeItem(Item *item);
    void setNullMonster();
    void setLast();
    bool getLast()const;


};

#endif
