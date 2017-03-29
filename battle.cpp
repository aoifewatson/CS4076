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
    double hit = ((double) rand() / (RAND_MAX));

    int monsterStrength = 1;
    int playerStrength = 1;

    if(me->getCurrentItem() == "Knife") {
        playerStrength = 2;
        monsterStrength = 2;
    }
    else if (me->getCurrentItem() == "Sword") {
        playerStrength = 3;
    }

    int myHealth = me->getHealth();
    int monHealth = mon->getHealth();
    if(hit <= me->getHitChance()){
        mon->setHealth(monHealth - playerStrength);
    }
    if(hit >= mon->getHitChance()){
        me->setHealth(myHealth - monsterStrength);
    }
    if(me->getHealth() <= 0){
        endGame();
    }
}

void Battle::endGame(){
    QApplication::quit();
}

Battle::~Battle() {}

