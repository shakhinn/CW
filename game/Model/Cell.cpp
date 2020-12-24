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
    open = false;
    type = ENTRANCE;
    EntranceFactory factory = EntranceFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeExit() {
    open = false;
    type = EXIT;
    ExitFactory factory = ExitFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeCoin() {
    open = false;
    type = COIN;
    CoinFactory factory = CoinFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeBomb() {
    open = false;
    type = BOMB;
    BombFactory factory = BombFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeTele() {
    open = false;
    type = TELE;
    TeleFactory factory = TeleFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeArmor() {
    open = false;
    type = ARMOR;
    ArmorFactory factory = ArmorFactory();
    object = factory.factoryMethod(coord.x, coord.y);
}
void Cell::makeCoord(int x, int y) {
    coord.x = x;
    coord.y = y;
}