#include <sstream>

#include "Character.h"
#include "item.h"
#include "ZorkUL.h"
#include "battle.h"
#include "playwindow.h"

using namespace std;

ZorkUL::ZorkUL(string name, string food) {
    me = new Player(name, 10, .75, food);
	createRooms();
}

void ZorkUL::createRooms()  {
    //creating items and extra characters
    Item *knife = new Item("Knife", true);
    Item *sword = new Item("Sword", true);

    //creating rooms
    Room *one, *two, *three, *four, *five, *six, *seven;
    one = new Room("one");
    two = new Room("two");
    three = new Room("three");
    four = new Room("four");
    five = new Room("five");
    six = new Room("six");
    seven = new Room("seven");

    //adding rooms to vector of rooms
    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    roomList.push_back(four);
    roomList.push_back(five);
    roomList.push_back(six);
    roomList.push_back(seven);
    seven -> setLast();

    //adding items and extra characters to rooms
    three->addItem(sword);
    four->addItem(knife);
    five->addMonster(new Monster("Small Monster", 5, .55));
    six->addMonster(new Monster("Bigger Monster", 10, .75));

                //(up, left, down, right)
    one->setExits(NULL, five, NULL, two);
    two->setExits(three, one, four, NULL);
    three->setExits(NULL, NULL, two, NULL);
    four->setExits(two, NULL, NULL, NULL);
    five->setExits(NULL, NULL, six, one);
    six->setExits(five, NULL, seven, NULL);
    seven->setExits(six, NULL, NULL, NULL);
    currentRoom = one;
}

void ZorkUL::goRoom(string direction) {
    stringstream output;
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
        output << "You can't go this way!" << endl;
    }
    else {
        currentRoom = nextRoom;
    }
}

Room* ZorkUL::getCurrentRoom() const{
    return this->currentRoom;
}

Player* ZorkUL::getPlayer() const{
    return this->me;
}

ZorkUL::~ZorkUL(){
    delete me;
}
