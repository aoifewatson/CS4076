#ifndef Monster_H
#define Monster_H
#include "Character.h"

class Monster : public Character
{
public:
    Monster();
    Monster(string name, int health, double hitChance);
    string getName()const;
    double getHitChance()const;
    int getHealth()const;
    void setHealth(int newHealth);
    ~Monster();

private:
    string name;
    int health;
    double hitChance;
};

#endif // Monster_H
