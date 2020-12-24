#include "TeleportObject.h"

void Tele::action(Player& player) {
    player.setCords();
    notifyPublisher();
}
void Tele::notifyPublisher() {
    if(publisher) {
        publisher->notifyLogger(this);
    }
}

void Tele::setPublisher(Publisher *pub) {
    if(publisher) {
        publisher = pub;
    }
}

std::string Tele::print() {
    std::string str = "\n--------------TELEPORT------------\n";
    str += "Player picked teleport at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}

Object* TeleFactory::factoryMethod(int x, int y) const {
    Tele* t = new Tele(x, y);
    return t;
}
