#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"

class Battle
{
private:
public:
    Battle();
    void engageBattle();
    void pickWeapon();
    void engageBattle(Character *me, Character *mon);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
