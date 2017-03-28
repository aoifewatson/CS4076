#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <string>
#include <iostream>
#include "Room.h"
#include "item.h"
#include "Character.h"
#include "Player.h"

using namespace std;

class ZorkUL {
    friend class PlayWindow;
private:
	Room *currentRoom;
    vector <Room*> roomList;
	void createRooms();
    void goRoom(string direction);
    Player *me;

public:
    ZorkUL(string name, string food);
    ~ZorkUL();
	void play();
    Room* getCurrentRoom() const;
    Player* getPlayer() const;
};

#endif /*ZORKUL_H_*/
