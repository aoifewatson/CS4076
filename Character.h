#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include "item.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
     vector < Item* > itemsInCharacter;
public:
    //void addItems(string Item);
    //void addItem(Item &Item);
    void addItem(Item *Item);
	Character(string description);
	string shortDescription();
	string longDescription();
    vector <Item*> getItemsInCharacter();
    void setName(string newName);
    string getName();

private:
    string name;

};

#endif /*CHARACTER_H_*/
