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
    Item (string name, bool weaponCheck);
    Item (string name);
    string getName();
    string getLongDescription();
    bool getWeaponCheck(bool weaponCheck);
	void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
