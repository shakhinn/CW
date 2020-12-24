#ifndef OOP_TELEPORTOBJECT_H
#define OOP_TELEPORTOBJECT_H

#include "Object.h"
class Tele : public Object{
public:
    Tele(int x, int y): x(x), y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x, y;
private:
    Publisher* publisher = nullptr;
};

class TeleFactory : public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};



#endif //OOP_TELEPORTOBJECT_H
