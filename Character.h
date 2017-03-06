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
    vector <Item> itemsInCharacter;

public:
    void addItem(Item item);
    Character(string description);
    Character();
	string shortDescription();
    vector <Item> getItemsInCharacter();
    void setName(string newName);
    string getName();

private:
    string name;
};

#endif /*CHARACTER_H_*/
