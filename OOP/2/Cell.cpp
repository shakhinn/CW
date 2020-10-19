#include "Cell.h"

void Cell::makeOpen() {
    open = false;
    type = OPEN;
}
void Cell::makeClose() {
    open = true;
    type = CLOSE;
}
bool Cell::show() const {
    return open;
}
Type Cell::showCELL(){
    return type;
}
void Cell::makeEntrance() {
    type = ENTRANCE;
    EntranceFactory factory = EntranceFactory();
    object = factory.factoryMethod();
}
void Cell::makeExit() {
    type = EXIT;
    ExitFactory factory = ExitFactory();
    object = factory.factoryMethod();
}
void Cell::makeCoin() {
    type = COIN;
    CoinFactory factory = CoinFactory();
    object = factory.factoryMethod();
}
void Cell::makeBomb() {
    type = BOMB;
    BombFactory factory = BombFactory();
    object = factory.factoryMethod();
}
void Cell::makeTele() {
    type = TELE;
    TeleFactory factory = TeleFactory();
    object = factory.factoryMethod();
}
void Cell::makeCoord(int x, int y) {
    coord.x = x;
    coord.y = y;
}