//
// Created by shakhinn on 18.10.2020.
//

#include "Player.h"
Player& Player::operator+=(Object* right){
    right->action(*this);
    return *this;
}
void Player::move(int dX, int dY, bool isOpen) {
    if(isOpen){
        x+=dX;
        y+=dY;
    }
}

void Player::addCoin() {
    score++;
}

void Player::decreaseHealth() {
        health--;

}

void Player::setCords() {
    x = tele.x;
    y = tele.y;
}