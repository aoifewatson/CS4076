#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"
#include "Room.h"

class Battle
{
private:
public:
    Battle();
    void engageBattle(Room *currentRoom);
    void pickWeapon(Character *me);
    void engageBattle(Character *me, Character *mon);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
