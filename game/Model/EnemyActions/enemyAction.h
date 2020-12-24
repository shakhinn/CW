#ifndef OOP_ENEMYACTION_H
#define OOP_ENEMYACTION_H
#include "../Player.h"

class Player;

class enemyAction {
    virtual bool interact(Player& player)=0;
};


#endif //OOP_ENEMYACTION_H
