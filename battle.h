#ifndef BATTLE_H
#define BATTLE_H
#include "Room.h"
#include "Player.h"
#include "Monster.h"

class Battle
{
private:
public:
    Battle();
    void engageBattle(Room *currentRoom);
    void pickWeapon(Player *me);
    void engageBattle(Player *me, Monster *mon);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
