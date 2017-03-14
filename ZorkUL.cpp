#include "Character.h"
#include "item.h"
#include "ZorkUL.h"
#include "battle.h"
#include "playwindow.h"

/*ZorkUL::ZorkUL(){ //default constructor
 *
 * }
 */

ZorkUL::ZorkUL(string name, string food) {
    me = new Character(name, food, 10, .75);
	createRooms();
}

void ZorkUL::createRooms()  {
    //creating items and extra characters

    Item *key = new Item("Key", false);
    Item *knife = new Item("Knife", true);
    Item *torch = new Item("Torch", true);
    Item *envelope = new Item("Envelope", true);
    Item *water = new Item("Water", false);
    Character *monsterOne = new Character("Monster One", 5, .55);
    Character *monsterTwo = new Character("Monster Two", 10, .75);


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

    three->addItem(key);
    four->addItem(knife);
    five->addItem(torch);
    seven->addItem(envelope);
    fifteen->addItem(water);
    six->addCharacter(monsterOne);
    fifteen->addCharacter(monsterTwo);

    //added character monster to room 15 here

//    (N, E, S, W)(up, left, down, right)
    one->setExits(NULL, five, NULL, two);
    two->setExits(three, one, four, NULL);
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
    playWin = new PlayWindow();
    playWin->setFixedSize(800,500);
    playWin->show();

	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
    while (!finished) {
        playWin->sendUpdate(me->getHealth(), currentRoom->shortDescription());
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
        cout << "Invalid input."<< endl;
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

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else {
            ZorkUL::takeItem(command);
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
                cout << "You're adding " + command.getSecondWord() << endl;
                //currentRoom->itemsInRoom.push_back;
            }
        }
    }

    else if (commandWord.compare("teleport") == 0) {
        //teleport();
        cout << currentRoom->longDescription() << endl;
    }

    else if (commandWord.compare("take") == 0) {
        takeItem(command);
    }
    else if (commandWord.compare("pick") == 0){
        //do something here;
    }
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
	if (!command.hasSecondWord()) {
        cout << "Incomplete input."<< endl;
		return;
	}
	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL){
		cout << "underdefined input"<< endl;
    }
    //else if statement for battle sequence
    else if(nextRoom->shortDescription()==("six")){
        currentRoom = nextRoom;
        vector <Character*> temp = currentRoom->getOthersInRoom();
        Battle *battle1 = new Battle();
        battle1->engageBattle(me, temp[0]);
    }
    else if(nextRoom->shortDescription()==("fifteen")){
        currentRoom = nextRoom;
        vector <Character*> temp = currentRoom->getOthersInRoom();
        Battle *battle2 = new Battle();
        battle2->engageBattle(me, temp[0]);
    }
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
        return("There's no exit this way.");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

void ZorkUL::takeItem(Command command){
    string itemName = command.getSecondWord();
    int location = currentRoom->isItemInRoom(itemName);
    if (0 != location) {
        cout << "Item '" << itemName << "' is not in the room." << endl;
    }
    else {
        cout << "Item '" << itemName << "' is in the room." << endl;
        me->addItem(currentRoom->getItemByName(itemName));
        cout << me->getName() << " took the " + command.getSecondWord() << endl;
    }
    cout << endl;
    cout << currentRoom->longDescription() << endl;
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

