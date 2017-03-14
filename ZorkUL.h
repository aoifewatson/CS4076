#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <string>
#include <iostream>

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include "playwindow.h"

using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
    PlayWindow *playWin;
    vector <Room*> roomList;
	void createRooms();
    void printWelcome();
    void printHelp();
    // all these methods should be moved to other classes?
    bool processCommand(Command command); //command.cpp?
    void goRoom(Command command); //room.cpp?
    void displayItems(); //item.cpp? or character.cpp?
    //void teleport();
    Character *me;// = new Character();
    void takeItem(Command command); //item.cpp? or character.cpp?

public:
    ZorkUL(string name, string food);
	void play();
    // method should be moved?
	string go(string direction);

};

#endif /*ZORKUL_H_*/
