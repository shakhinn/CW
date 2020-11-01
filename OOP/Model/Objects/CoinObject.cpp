#include "CoinObject.h"

void Coin::action(Player& player) {
    player.addCoin();
    notifyPublisher();
}
void Coin::setPublisher(Publisher *pub) {
    publisher = pub;
}
void Coin::notifyPublisher() {
    publisher->notifyLogger(this);
}

std::string Coin::print() {
    std::string str = "\n--------------Coin------------\n";
    str += "Player picked coin at x = " + std::to_string(y) + " y = " + std::to_string(x) + "\n--------------------------------\n";
    return str;
}

Object* CoinFactory::factoryMethod(int x, int y) const {
    Coin* c = new Coin(x, y);
    return c;
}