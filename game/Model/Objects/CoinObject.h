#ifndef OOP_COINOBJECT_H
#define OOP_COINOBJECT_H
#include "Object.h"

class Coin : public Object{
public:
    Coin(int x, int y): x(x),y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x, y;
private:
    Publisher* publisher = nullptr;
};

class CoinFactory : public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};

#endif //OOP_COINOBJECT_H
