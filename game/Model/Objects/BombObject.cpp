#include "BombObject.h"

void Bomb::action(Player& player) {
    player.decreaseHealth();
    notifyPublisher();
}
void Bomb::notifyPublisher() {
    if(publisher) {
        publisher->notifyLogger(this);
    }
}

void Bomb::setPublisher(Publisher *pub) {
    if(publisher) {
        publisher = pub;
    }
}

std::string Bomb::print() {
    std::string str = "\n--------------BOMB------------\n";
    str += "Player picked bomb at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}

Object* BombFactory::factoryMethod(int x, int y) const {
    Bomb* b = new Bomb(x, y);
    return b;
}