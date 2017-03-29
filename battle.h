#ifndef BATTLE_H
#define BATTLE_H
#include "ZorkUL.h"

class Battle
{
private:
public:
    Battle();
    void engageBattle(ZorkUL *playGame);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
