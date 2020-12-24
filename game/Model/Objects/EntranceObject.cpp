//
// Created by shakhinn on 31.10.2020.
//
#include "EntranceObject.h"

void Entrance::action(Player& player) {
    notifyPublisher();
}

void Entrance::setPublisher(Publisher *pub) {
    publisher = pub;
}

void Entrance::notifyPublisher() {
    if(publisher) {
        publisher->notifyLogger(this);
    }
}

std::string Entrance::print() {
    std::string str = "\n--------------ENTRANCE------------\n";
    str += "Entrance at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}


Object* EntranceFactory::factoryMethod(int x, int y) const {
    auto* ent = new Entrance(x, y);
    return ent;
}
