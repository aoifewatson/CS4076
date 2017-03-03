#include <iostream>
#include <QApplication>
#include "Character.h"
#include "item.h"
#include "mainwindow.h"
#include "characterinfo.h"
#include "ZorkUL.h"

using namespace std;

vector <Room*> roomList;

int main(int argc, char **argv) {
   /*QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.setFixedSize(400,400);
    mainWin.show();

    return app.exec();*/

    ZorkUL temp;
    //close();
    temp.play();
    return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *one, *two, *three, *four, *five, *six, *seven, *eight, *nine, *ten, *eleven, *twelve, *thirteen, *fourteen, *fifteen, *sixteen;
    one = new Room("one");
    two = new Room("two");
    three = new Room("three");
    four = new Room("four");
    five = new Room("five");
    six = new Room("six");
    seven = new Room("seven");
    eight = new Room("eight");
    nine = new Room("nine");
    ten = new Room("ten");
    eleven = new Room("eleven");
    twelve = new Room("tweleve");
    thirteen = new Room("thirteen");
    fourteen = new Room("fourteen");
    fifteen = new Room("fifteen");
    sixteen = new Room("sixteen");

    //adding rooms to vector of rooms
    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    roomList.push_back(four);
    roomList.push_back(five);
    roomList.push_back(six);
    roomList.push_back(seven);
    roomList.push_back(eight);
    roomList.push_back(nine);
    roomList.push_back(ten);
    roomList.push_back(eleven);
    roomList.push_back(twelve);
    roomList.push_back(thirteen);
    roomList.push_back(fourteen);
    roomList.push_back(fifteen);
    roomList.push_back(sixteen);

    //creating items
    //adding items to rooms
    three->addItem(new Item("Key", false));
    four->addItem(new Item("Knife", true));
    five->addItem(new Item("Torch", true));
    seven->addItem(new Item("Envelope", true));
    eleven->addItem(new Item("Trap", false));
    fifteen->addItem(new Item("Water", false));


//    (N, E, S, W)(up, left, down, right)
    one->setExits(NULL, five, NULL, two);
    two->setExits(three, NULL, four, NULL);
    three->setExits(NULL, NULL, two, NULL);
    four->setExits(two, NULL, NULL, NULL);
    five->setExits(NULL, NULL, six, one);
    six->setExits(five, NULL, seven, NULL);
    seven->setExits(six, NULL, eight, NULL);
    eight->setExits(seven, nine, NULL, NULL);
    nine->setExits(NULL, eight, eleven, ten);
    ten->setExits(NULL, nine, NULL, NULL);
    eleven->setExits(nine, NULL, twelve, NULL);
    twelve->setExits(eleven, NULL, NULL, thirteen);
    thirteen->setExits(NULL, twelve, NULL, fourteen);
    fourteen->setExits(NULL, thirteen, sixteen, NULL);
    fifteen->setExits(twelve, NULL, NULL, NULL);
    sixteen->setExits(fourteen, NULL, NULL, NULL);
    currentRoom = one;
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
        //only print out rooms on map if they have been visited.
    {
        cout << "                [3]" << endl;
        cout << "                 | " << endl;
        cout << "                 | " << endl;
        cout << "[5] --- [1] --- [2]" << endl;
        cout << " |               | " << endl;
        cout << " |               | " << endl;
        cout << "[6]             [4]" << endl;
        cout << " | "                 << endl;
        cout << " | "                 << endl;
        cout << "[7]"                 << endl;
        cout << " | "                 << endl;
        cout << " | | "               << endl;
        cout << "[8] --- [9] --- [10]"<< endl;
        cout << "         | "         << endl;
        cout << "         | "         << endl;
        cout << "[5] --- [11] --- [2]"<< endl;
        cout << "          | " << endl;
        cout << "          | " << endl;
        cout << "        [12] --- [13] --- [14]" << endl;
        cout << "          |                 |"  << endl;
        cout << "                            | " << endl;
        cout << "         [15]              [16]"<< endl;

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

string ZorkUL::go(string direction) { // is this method needed????
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

