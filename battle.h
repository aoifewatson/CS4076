#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"

class Battle
{
private:
public:
    Battle();
    void EngageBattle(Character *me, Character *mon);
    void ContinueGame();
    void EndGame();
};

#endif // BATTLE_H
