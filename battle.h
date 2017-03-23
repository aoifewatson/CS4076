#ifndef BATTLE_H
#define BATTLE_H
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "ZorkUL.h"

class Battle
{
private:
public:
    Battle();
    void pickWeapon(Player *me);
    void engageBattle(ZorkUL *playGame);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
