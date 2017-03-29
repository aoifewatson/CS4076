#ifndef Monster_H
#define Monster_H
#include "Character.h"

class Monster : public Character
{
public:
    Monster();
    Monster(std::string newName, int newHealth, double newHitChance);
    ~Monster();

};

#endif // Monster_H
