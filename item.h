#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string name;
	string longDescription;
	bool weaponCheck;

public:
    bool operator==(const Item& item);

    Item (string newName, bool newWeaponCheck);
    Item (string name);
    Item ();
    string getName() const;
    string getLongDescription();
    bool getWeaponCheck() const;
};

#endif /*ITEM_H_*/
