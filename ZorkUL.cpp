#include <iostream>
#include <QApplication>
#include "Character.h"
#include "item.h"
#include "mainwindow.h"
#include "characterinfo.h"

//Initializer list??
//Friends

using namespace std;
#include "ZorkUL.h"

Character * me;
vector <Room*> roomList;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.setFixedSize(400,400);
    mainWin.show();

    return app.exec();
}

ZorkUL::ZorkUL() {
    //me = new Character("default");
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

	a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
        roomList.push_back(a);
	b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
        roomList.push_back(b);
	c = new Room("c");
    roomList.push_back(c);
    d = new Room("d");
    roomList.push_back(d);
	e = new Room("e");
    roomList.push_back(e);
	f = new Room("f");
    roomList.push_back(f);
	g = new Room("g");
    roomList.push_back(g);
	h = new Room("h");
    roomList.push_back(h);
	i = new Room("i");
    roomList.push_back(i);
    j = new Room("j");
        j->addItem(new Item("xyz", 5, 55));
        roomList.push_back(j);

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, j, NULL);
    j->setExits(i, NULL, NULL, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {

	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << "[j]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {
    cout << "You are trying to put an item in this room" << endl;
    //cout << currentRoom->longDescription() << endl;
        {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
            }
            else
                if (command.hasSecondWord()) {
                cout << "you're adding " + command.getSecondWord() << endl;
                //currentRoom->itemsInRoom.push_Back;
            }
        }
    }

    else if (commandWord.compare("teleport") == 0)
        teleport();

    else if (commandWord.compare("take") == 0)
        takeItem(command);

    else if (commandWord.compare("inventory") == 0)
        displayItems();

    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

void ZorkUL::takeItem(Command command){
    cout << "You are taking " + command.getSecondWord() << endl;
    string name = command.getSecondWord();
    Item *itemTaken = new Item(name);
    //*me->addItem(itemTaken);
    int location = currentRoom->isItemInRoom(command.getSecondWord());
    if (location  < 0 )
        cout << "item is not in room" << endl;
    else
        cout << "item is in room" << endl;
        //cout << "index number " << + location << endl;
        cout << endl;
        cout << currentRoom->longDescription() << endl;
}

void ZorkUL::displayItems(){
   cout << "Display inventory" << endl;
   /*vector <Item*> items = *me->getItemsInCharacter(); //call get method for vector that stores all item picked up
   vector<Item*>::iterator itemIterator;
   for (itemIterator = items.begin(); itemIterator != items.end(); itemIterator++){
     //cout <<*itemIterator->getShortDescription() <<endl;
     //cout << *itemIterator << endl;
   }*/
   cout << endl;
   cout << currentRoom->longDescription() << endl;
}

void ZorkUL::teleport() {
    //currentRoom = a;
    cout << "attempting to teleport" << endl;
    int i = (rand()%9)+1;
    currentRoom = roomList[i];
    cout <<"You are now in room" << currentRoom->shortDescription() << endl;
    cout << currentRoom->longDescription() << endl;
}

