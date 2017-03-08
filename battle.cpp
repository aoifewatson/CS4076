#include "battle.h"
#include "Character.h"
#include "Room.h"
#include "ZorkUL.h"
#include <random>

Battle::Battle(){

}

void Battle::engageBattle(){
    cout << "No one to fight here!" << endl;
    //cout << currentRoom->longDescription() << endl;
}

void Battle::pickWeapon(){
    /*cout << "Pick a weapon to fight with" << endl;
    vector <Item*> temp = me->getItemsInCharacter();
    for(int i=0; i < temp.size(); i++){
        cout << temp[i] << endl;
    }*/
    cout << "Hint: a weapon might be a good choice" << endl;
}

void Battle::engageBattle(Character *me, Character *mon){
    //while both characters have health above zero
    while (me->getHealth() > 0 && mon->getHealth() > 0){
        double hit = ((double) rand() / (RAND_MAX));
        int myHealth = me->getHealth();
        int monHealth = mon->getHealth();
        //decrementing health for monster and my character
        if(hit < me->getHitChance())
            mon->setHealth(monHealth - 1);
        else if(hit < mon->getHitChance())
            me->setHealth(myHealth - 1);
    }
    if(mon->getHealth() == 0){
        //continue on in game - continue game method
        continueGame();
    }
    else if(me->getHealth() == 0){
        cout << "You have no health left - game over!" << endl;
        endGame();
    }
}

void Battle::continueGame(){
    cout << "continue game" << endl;
}

void Battle::endGame(){
    cout << "end game" << endl;
}
