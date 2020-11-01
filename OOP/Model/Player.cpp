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
    notifyLogger();
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

int Player::getHealth() const {
    return health;
}

int Player::getScore() const{
    return score;
}

int Player::getX() const {
    return x;
}
int Player::getY() const {
    return y;
}
bool Player::isWin() const {
    return win;
}

void Player::registerLogger(logger *log) {
    loggers.push_back(log);
}

void Player::removeLogger(logger *log) {
    loggers.remove(log);
}

void Player::notifyLogger() {
    for(auto log : loggers){
        (*log).update();
    }
}

std::ostream &operator << (std::ostream &output, const Player &player){
    output << "\n----------- Player---------\n";
    output << "Coords: x - " + std::to_string(player.getY()) + ", y - " + std::to_string(player.getX()) + "\n"
              + "Score: " + std::to_string(player.getScore()) + "\n" + "Health:" + std::to_string(player.getHealth()) + "\n" +
              "End: " + (player.isWin() ? "true" : "false");
    output << "\n----------------------------\n";
    return output;

}






