#include "item.h"

//Item::Item (string inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/) {
Item::Item (string description, bool weaponCheck) {
    description = description;
    weaponCheck = weaponCheck;
}

Item::Item(string description) {
    description = description;
}

/*void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}*/

bool Item::getWeaponCheck(bool w)
{
    if(w == false)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
    return w;
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

