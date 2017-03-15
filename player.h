#ifndef Player_H
#define Player_H
#include "Character.h"

class Player : public Character
{
public:
    void addItem(Item *item);
    Player(string name, string food, int health, double hitChance);
    Player();
    string getName()const;
    double getHitChance()const;
    int getHealth()const;
    void setHealth(int newHealth);
    vector <Item*> getItemsInCharacter()const;
    ~Player();

private:
    string name;
    int health;
    double hitChance;
    string food;
    vector <Item*> itemsInCharacter;

};

#endif // Player_H
