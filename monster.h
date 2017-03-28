#ifndef Monster_H
#define Monster_H
#include "Character.h"

class Monster : public Character
{
public:
    Monster();
    Monster(string name, int health, double hitChance);
    ~Monster();

private:
    string name;
    int health;
    double hitChance;
};

#endif // Monster_H
