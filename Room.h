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
    std::string name;
    std::map<std::string, Room*> exits;
    std::string exitString();
    std::vector <Item*> itemsInRoom;
    Monster *monsterInRoom;
    bool last;

public:
    ~Room();
    int numberOfItems();
    Room(std::string description, Item *item);
    Room(std::string description);
    void setExits(Room *up, Room *left, Room *down, Room *right);
    std::string getName();
    Room* nextRoom(std::string direction);
    void addItem(Item *inItem);
    std::string displayItem();
    std::string getItems();
    int getItemIndexByName(std::string itemName);
    Item* getItemByName(std::string itemName);
    void addMonster(Monster *Monster);
    Monster* getMonsterInRoom() const;
    void deleteMonsterInRoom();
    std::vector <Item*> getItemsInRoom()const;
    void removeItem(Item *item);
    void setNullMonster();
    void setLast();
    bool getLast()const;

};

#endif
