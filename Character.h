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

public:
    void addItem(Item *Item);

public:
    Character(string description);
    Character();
	string shortDescription();
    vector <Item*> getItemsInCharacter();
};

#endif /*CHARACTER_H_*/
