#ifndef OOP_ENTRANCEOBJECT_H
#define OOP_ENTRANCEOBJECT_H
#include "Object.h"

class Entrance : public Object {
public:
    Entrance(int x, int y): x(x), y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x, y;
private:
    Publisher* publisher = nullptr;
};

class EntranceFactory : public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};
#endif //OOP_ENTRANCEOBJECT_H
