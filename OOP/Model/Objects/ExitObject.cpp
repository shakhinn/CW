#include "ExitObject.h"

void Exit::action(Player& player) {
    if(player.score != 0) {
        player.win = true;
        player.notifyLogger();
    }
    notifyPublisher();
}

void Exit::setPublisher(Publisher *pub) {
    publisher = pub;
}

void Exit::notifyPublisher() {
    publisher->notifyLogger(this);
}
std::string Exit::print() {
    std::string str = "\n--------------EXiT------------\n";
    str += "EXIT at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}

Object* ExitFactory::factoryMethod(int x, int y) const {
    Exit* ex = new Exit(x, y);
    return ex;
}