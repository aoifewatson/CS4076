#include "item.h"

Item::Item(string name, bool weaponCheck) {
    name = name;
    weaponCheck = weaponCheck;
}

bool Item::getWeaponCheck(bool w)
{
    if(w == false)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
    return w;
}

string Item::getName(){
    return name;
}

string Item::getLongDescription()
{
    return " item(s), " + name + ".\n";
}

