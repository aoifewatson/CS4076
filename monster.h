#ifndef Monster_H
#define Monster_H
#include "Character.h"

class Monster : public Character
{
public:
    Monster();
    Monster(string newName, int newHealth, double newHitChance);
    ~Monster();

};

#endif // Monster_H
