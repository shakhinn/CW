//
// Created by shakhinn on 31.10.2020.
//

#ifndef OOP_BOMBOBJECT_H
#define OOP_BOMBOBJECT_H
#include "Object.h"

class Bomb : public Object {
public:
    Bomb(int x, int y): x(x), y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x,y;
private:
    Publisher* publisher = nullptr;
};

class BombFactory : public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};

#endif //OOP_BOMBOBJECT_H
