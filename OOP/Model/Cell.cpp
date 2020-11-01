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
Type Cell::showCELL() const{
    return type;
}
void Cell::makeEntrance() {
    type = ENTRANCE;
    EntranceFactory factory = EntranceFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeExit() {
    type = EXIT;
    ExitFactory factory = ExitFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeCoin() {
    type = COIN;
    CoinFactory factory = CoinFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeBomb() {
    type = BOMB;
    BombFactory factory = BombFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeTele() {
    type = TELE;
    TeleFactory factory = TeleFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeCoord(int x, int y) {
    coord.x = x;
    coord.y = y;
}