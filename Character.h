#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <vector>
#include <string>

using namespace std;
using std::vector;

class Character {
private:
	string description;
    vector < Item* > itemsInCharacter;
    double hitChance;

public:
    void addItem(Item *Item);
    Character(string description, int health, double hitChance);
    Character();
	string shortDescription();
    vector <Item*> getItemsInCharacter();
    void setName(string newName);
    string getName() const;
    double getHitChance() const;
    int getHealth() const;
    void setHealth(int newHealth);

private:
    string name;
    int health;
};

#endif /*CHARACTER_H_*/
