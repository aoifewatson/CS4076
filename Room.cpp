#include <sstream>
#include "Room.h"
#include "Command.h"

Room::Room(string newDescription){
   description = newDescription;
}

Room::Room(string newDescription, Item item) {
    description = newDescription;
    itemsInRoom.push_back(item);
}

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
    return "Room = " + description + "\n" + displayItem() + exitString();
    //return "room = " + this->description + ".\n" + getItems() + exitString();

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
    itemsInRoom.push_back(*inItem);
}

void Room::removeItemFromRoom(int index) {
    itemsInRoom.erase(itemsInRoom.begin() + index);
}

string Room::displayItem() {
    stringstream ss;
    ss << "Items in room:" << endl;
    int sizeItems = itemsInRoom.size();
    if (itemsInRoom.size() < 1) {
        ss << "There are no items in this room." << endl;
    }
    else {
        for (int n = 0; n < sizeItems; n++) {
            ss << "- " << itemsInRoom[n].getName() << endl;
        }
    }
    return ss.str();
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare(itemsInRoom[x].getName());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
        }
    }
    return -1;
}

string Room::getItems(){
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
}

Item Room::getItemByName(string itemName) {
    Item item;
    int size = itemsInRoom.size();
    for(int i = 0; i < size; i++) {
        if (itemName.compare(itemsInRoom[i].getName())) {
            item = itemsInRoom[i];
        }
    }

    return item;
}

int Room::getItemIndex(Item item){
    int itemIndex = 0;
    int size = itemsInRoom.size();
    for(int i = 0; i < size; i++) {
        if (item == itemsInRoom[i]) {
            itemIndex = i;
        }
    }

    return itemIndex;
}

int Room::getItemLocation(Item item) {
    int index = 0;
    int size = itemsInRoom.size();
    for(int i = 0; i < size; i++) {
        if(item == itemsInRoom[i]) {
            index = i;
        }

    }

    return index;
}

