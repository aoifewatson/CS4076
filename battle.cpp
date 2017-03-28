#include "battle.h"
#include "Character.h"
#include "ZorkUL.h"
#include <random>
#include <QApplication>

Battle::Battle(){

}

void Battle::engageBattle(ZorkUL *playGame){

    Player *me = playGame->getPlayer();
    Room *room = playGame->getCurrentRoom();
    Monster *mon = room->getMonsterInRoom();

    //while both characters have health above zero
    double hit = ((double) rand() / (RAND_MAX));

    int myHealth = me->getHealth();
    int monHealth = mon->getHealth();

    if(hit <= me->getHitChance()){
        mon->setHealth(monHealth - 1);
    }
    if(hit >= mon->getHitChance()){
        me->setHealth(myHealth - 1);
    }
    if(me->getHealth() == 0){
        endGame();
    }
    else if(mon->getHealth() == 0){
        delete mon;
        room->setNullMonster();
    }
    cout << "Me: " << me->getHealth() << endl;
    cout << "Monster: " << mon->getHealth() << endl;
}

void Battle::endGame(){
    QApplication::quit(); //exit game
}
