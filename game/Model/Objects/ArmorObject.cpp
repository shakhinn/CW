#include "ArmorObject.h"

void Armor::action(Player& player) {
    player.incArmor();
    notifyPublisher();
}
void Armor::setPublisher(Publisher *pub) {
    publisher = pub;
}
void Armor::notifyPublisher() {
    if(publisher) {
        publisher->notifyLogger(this);
    }
}

std::string Armor::print() {
    std::string str = "\n--------------Armor------------\n";
    str += "Player picked armor at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}

Object* ArmorFactory::factoryMethod(int x, int y) const {
    Armor* c = new Armor(x, y);
    return c;
}