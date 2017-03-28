#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <vector>
#include <string>
using std::string;

class Character {
public:
    Character();
    Character(string name, int health, double hitChance);
    virtual string getName()const;
    virtual double getHitChance()const;
    virtual int getHealth()const;
    virtual void setHealth(int newHealth);
    virtual ~Character();

protected:
    string name;
    int health;
    double hitChance;
};

#endif /*CHARACTER_H_*/
