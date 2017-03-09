#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <vector>
#include <string>

using namespace std;
using std::vector;

class Character {
private:
    string name;
    vector <Item*> itemsInCharacter;
    double hitChance;
    int health;

public:
    void addItem(Item *item);
    Character(string description, int health, double hitChance);
    Character();
	string shortDescription();
    vector <Item*> getItemsInCharacter();
    string getName() const;
    double getHitChance() const;
    int getHealth() const;
    void setHealth(int newHealth);
};

#endif /*CHARACTER_H_*/
