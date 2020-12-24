#ifndef OOP_ARMOROBJECT_H
#define OOP_ARMOROBJECT_H
#include "Object.h"

class Armor: public Object{
public:
    Armor(int x, int y): x(x),y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x, y;
private:
    Publisher* publisher = nullptr;
};

class ArmorFactory: public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};


#endif //OOP_ARMOROBJECT_H
