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
}
void Cell::makeExit() {
    type = EXIT;
}
void Cell::makeCoord(int x, int y) {
    coord.x = x;
    coord.y = y;
}