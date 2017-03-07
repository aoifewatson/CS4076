#include "battle.h"
#include "Character.h"
#include <random>

Battle::Battle(){

}

void Battle::EngageBattle(Character *me, Character *mon){
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
    }
    else if(me->getHealth() == 0){
        cout << "You have no health left - game over!" << endl;
    }
}

void Battle::ContinueGame(){
    cout << "continue game" << endl;
}

void Battle::EndGame(){
    cout << "end game" << endl;
}
