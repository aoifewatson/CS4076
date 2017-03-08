#include "item.h"

//pass by const reference because it is NOT a cheap copy - slightly improves performance
bool Item::operator==(const Item& item) {
    return((name == item.getName()) && (weaponCheck == item.getWeaponCheck()));
}

Item::Item() {
}

Item::Item(string newName, bool newWeaponCheck) {
    name = newName;
    weaponCheck = newWeaponCheck;
}

bool Item::getWeaponCheck() const {
    return weaponCheck;
}

string Item::getName() const {
    return name;
}

string Item::getLongDescription()
{
    return " item(s), " + name + ".\n";
}


