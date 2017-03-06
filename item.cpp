#include "item.h"

Item::Item(string newName, bool newWeaponCheck) {
    name = newName;
    weaponCheck = newWeaponCheck;
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

