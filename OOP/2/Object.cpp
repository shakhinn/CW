//
// Created by shakhinn on 18.10.2020.
//

#include "Object.h"

bool Coin::action(Player& player) {
    player.addCoin();
    return true;
}
bool Exit::action(Player& player) {
    if(player.score != 0)
        player.win = true;
    return true;
}
bool Entrance::action(Player& player) {
    return false;
}
bool Bomb::action(Player& player) {
    player.decreaseHealth();
    return true;
}
bool Tele::action(Player& player){
    player.setCords();
    return true;
}

Coin * CoinFactory::factoryMethod() const {
    Coin* c = new Coin;
    return c;
}

Exit * ExitFactory::factoryMethod() const {
    Exit* ex = new Exit;
    return ex;
}
Entrance * EntranceFactory::factoryMethod() const {
    Entrance* ent = new Entrance;
    return ent;
}

Bomb * BombFactory::factoryMethod() const {
    Bomb* b = new Bomb;
    return b;
}

Tele * TeleFactory::factoryMethod() const {
    Tele* t = new Tele;
    return t;
}