#include "battle.h"
#include "Character.h"
#include "ZorkUL.h"
#include <random>
#include <QApplication>

Battle::Battle(){

}

void Battle::engageBattle(ZorkUL *playGame){

    cout << "engage battle method" << endl;

    Player *me = playGame->getPlayer();
    Room *room = playGame->getCurrentRoom();
    Monster *mon = room->getMonsterInRoom();

    //while both characters have health above zero
    //while (me->getHealth() > 0 && mon->getHealth() > 0){
    double hit = ((double) rand() / (RAND_MAX));

    int myHealth = me->getHealth();
    int monHealth = mon->getHealth();

    if(hit <= me->getHitChance()){
        mon->setHealth(monHealth - 1);
    }
    else if(hit >= mon->getHitChance()){
        me->setHealth(myHealth - 1);
    }
    //}
    if(me->getHealth() == 0){
        cout << "You have no health left - game over!" << endl;
        endGame();
    }
    else if(mon->getHealth() == 0){
        delete mon;
    }
}

void Battle::endGame(){
    cout << "end game" << endl;
    QApplication::quit(); //slightly more graceful method of exiting game?
}
