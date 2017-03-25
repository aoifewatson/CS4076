#include <sstream>

#include "Character.h"
#include "item.h"
#include "ZorkUL.h"
#include "battle.h"
#include "playwindow.h"

using namespace std;

ZorkUL::ZorkUL(string name, string food) {
    me = new Player(name, food, 10, .75);
	createRooms();
}

void ZorkUL::createRooms()  {
    //creating items and extra characters

    Item *key = new Item("Key", false);
    Item *knife = new Item("Knife", true);
    Item *torch = new Item("Torch", false);
    Item *water = new Item("Water", false);
    Item *sword = new Item("Sword", true);

    //creating rooms
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

    //adding items and extra characters to rooms
    three->addItem(key);
    four->addItem(knife);
    five->addItem(torch);
    seven->addItem(sword);
    fifteen->addItem(water);
    six->addMonster(new Monster("Small Monster", 5, .55));
    fifteen->addMonster(new Monster("Bigger Monster", 10, .75));

//    (N, E, S, W)(up, left, down, right)
    one->setExits(NULL, five, NULL, two);
    two->setExits(three, one, four, NULL);
    three->setExits(NULL, NULL, two, NULL);
    four->setExits(two, NULL, NULL, NULL);
    five->setExits(NULL, NULL, six, one);
    six->setExits(five, NULL, seven, NULL);
    seven->setExits(six, NULL, eight, NULL);
    eight->setExits(seven, NULL, NULL, nine);
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
    /*playWin = new PlayWindow;
    playWin->setFixedSize(800,500);
    playWin->show();
    playWin->setName(me->getName());
    playWin->setHealth(me->getHealth());
    playWin->setRoom(currentRoom->shortDescription()); */

    bool finished = false;
    while(!finished) {
        //Command* cmd = parser.getCommand();
        //finished = processCommand(*cmd);
        //delete cmd;
    }


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
        cout << "Invalid input."<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
    {
        cout << "                [3]" << endl;
        cout << "                 | " << endl;
        cout << "                 | " << endl;
        cout << "[5] --- [1] --- [2]" << endl;
        cout << " |               | " << endl;
        cout << " |               | " << endl;
        cout << "[6]             [4]" << endl;
        cout << " |"                  << endl;
        cout << " |"                  << endl;
        cout << "[7]"                 << endl;
        cout << " |"                  << endl;
        cout << " |"                  << endl;
        cout << "[8] --- [9] --- [10]"<< endl;
        cout << "         | "         << endl;
        cout << "         | "         << endl;
        cout << "        [11]"        << endl;
        cout << "         | "         << endl;
        cout << "         | "         << endl;
        cout << "        [12] --- [13] -- [14]" << endl;
        cout << "         |                |"   << endl;
        cout << "         |                |"   << endl;
        cout << "        [15]             [16]" << endl;
    }

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("inventory") == 0) {
        displayItems();
    }
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord()) {
			cout << "overdefined input"<< endl;
        }
        else {
			return true; /**signal to quit*/
        }
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "Valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    stringstream output;

	if (!command.hasSecondWord()) {
        output << "Incomplete input."<< endl;
		return;
	}
	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
        output << "You can't go this way!" << endl;
    }
    else {
        currentRoom = nextRoom;
    }
}

string ZorkUL::go(string direction) { // is this method needed????
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("There's no exit this way.");
	else
	{
		currentRoom = nextRoom;
        return currentRoom->longDescription();
	}
}

void ZorkUL::displayItems(){
   cout << "Items in your inventory:" << endl;
   vector <Item*> itemsList = me->getItemsInCharacter(); //call get method for vector that stores all item picked up
   //vector<Item*>::iterator itemIterator;
   int size = itemsList.size();
   for (int i = 0; i < size; i++){
     cout << " -" << itemsList[i]->getName() << endl;
   }
   cout << endl;
   cout << currentRoom->longDescription() << endl;
}

/*void ZorkUL::teleport() {
    //currentRoom = a;
    cout << "attempting to teleport" << endl;
    int i = (rand()%9)+1;
    currentRoom = roomList[i];
    cout <<"You are now in room" << currentRoom->shortDescription() << endl;
    cout << currentRoom->longDescription() << endl;
}*/

Room* ZorkUL::getCurrentRoom() const{
    return this->currentRoom;
}

Player* ZorkUL::getPlayer() const{
    return this->me;
}
