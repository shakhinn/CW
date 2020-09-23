#include "Cell.h"


void Cell::makeOpen() {
    open = false;
}
void Cell::makeClose() {
    open = true;
}
bool Cell::show() const {
    return open;
}
void Cell::makeEntrance() {
    entrance = true;
}
bool Cell::checkEntrance() const {
    return entrance ;
}
void Cell::makeExit() {
    exit = true;
}

bool Cell::checkExit() const {
    return exit;
}