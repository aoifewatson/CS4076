#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <vector>
#include <string>

class Character {
public:
    virtual string getName()const;
    virtual double getHitChance()const;
    virtual int getHealth()const;
    virtual void setHealth(int newHealth);
    //virtual ~Character();

private:
    string name;
    int health;
    double hitChance;
};

#endif /*CHARACTER_H_*/
