#include "Room.h"
#include "Command.h"

Room::Room(string description){
   this->description = description;
}

/*Room::Room(string description, Item item) {
    this->description = description;
    this->itemsInRoom.push_back(item);
}*/

void Room::setExits(Room *up, Room *left, Room *down, Room *right) {
    if (up != NULL)
        exits["up"] = up;
    if (left != NULL)
        exits["left"] = left;
    if (down != NULL)
        exits["down"] = down;
    if (right != NULL)
        exits["right"] = right;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}


Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}

string Room::displayItem() {
    string tempString = "";
    int sizeItems = itemsInRoom.size();
    if (itemsInRoom.size() < 1)
        tempString = "no items in room";
    else {
        for(int n =0; n < sizeItems; n++) {
            Item *temp = itemsInRoom[n];
            tempString = temp->getName();
        }
    }
    return tempString;
    }

/*string Room::displayItem() {
    string tempString = "Item is room is ";
    if (itemInRoom==NULL)
        tempString = "no items in room";
    else
        tempString = tempString + itemInRoom.getName();
    return tempString;
    }*/

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    /*int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getName());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }*/
    return -1;
}

/*string Room:: getItems(){
    string items;
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1)
        items = "No items in room";
    else{
        for(int i=0; i < sizeItems; i++){
            items = items + itemsInRoom[i].getName();
        }
    }
    return items;
}*/

void Room::addCharacter(Character *monster){
    othersInRoom.push_back(monster);
    cout << "monster created in " << this->shortDescription() << endl;
}
