#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <vector>
#include <string>

class Character {
public:
    virtual string getName()const = 0;
    virtual double getHitChance()const =0;
    virtual int getHealth()const =0;
    virtual void setHealth(int newHealth)=0;
    //virtual ~Character();
};

#endif /*CHARACTER_H_*/
