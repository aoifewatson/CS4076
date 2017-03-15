#include "battle.h"
#include "Character.h"
#include "Room.h"
#include "ZorkUL.h"
#include <random>

Battle::Battle(){

}

void Battle::engageBattle(Room *currentRoom){
    cout << "No one to fight here!" << endl;
    cout << currentRoom->longDescription() << endl;
}

void Battle::pickWeapon(Player *me){
    cout << "Pick a weapon to fight with" << endl;
    //iterate through vector here and pick item to fight with
    //possible not able to fight with something with weaponCheck of false???
    //vector <Item*> temp = me->getItemsInCharacter();
    //for(vector<Item*>::iterator it = temp.begin(); it != temp.end(); ++it){
        //cout << (*it)->getName() << endl;

    cout << "Hint: a weapon might be a good choice" << endl;
}

void Battle::engageBattle(Player *me, Monster *mon){
    cout << "THERE'S A Monster" << endl;
    pickWeapon(me);
    //while both characters have health above zero
    while (me->getHealth() > 0 && mon->getHealth() > 0){
        cout <<"my health " << me->getHealth() << endl;
        cout << "Monster health " << mon->getHealth() << endl;
        double hit = ((double) rand() / (RAND_MAX));
        //cout << "value of hit " << hit << endl;
        int myHealth = me->getHealth();
        int monHealth = mon->getHealth();
        //decrementing health for Monster and my character
        if(hit <= me->getHitChance())
            mon->setHealth(monHealth - 1);
        else if(hit >= mon->getHitChance())
            me->setHealth(myHealth - 1);
    }
    if(mon->getHealth() == 0){
        //continue on in game - continue game method
        delete mon; //WANT TO DELETE Monster AND POINTER TO Monster IS THIS ENOUGH ???
        cout << endl;
    }
    else if(me->getHealth() == 0){
        cout << "You have no health left - game over!" << endl;
        endGame();
    }
}

void Battle::endGame(){
    cout << "end game" << endl;
    exit(EXIT_SUCCESS);
}
