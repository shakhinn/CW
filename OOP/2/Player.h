//
// Created by shakhinn on 18.10.2020.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Point.h"
#include "Object.h"

class Object;

class Player {
public:
    int x, y;
    Point tele;
    int health = 5;
    int score = 0;
    bool win = false;
    Player& operator+=(Object* right);
    void move(int dX, int dY, bool isOpen);
    Player(int x, int y):x(x),y(y){
        tele.x = x;
        tele.y = y;
    };
    ~Player() = default;
    void addCoin();
    void setCords();
    void decreaseHealth();

};


#endif //OOP_PLAYER_H
