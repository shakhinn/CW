//
// Created by shakhinn on 31.10.2020.
//

#ifndef OOP_EXITOBJECT_H
#define OOP_EXITOBJECT_H
#include "../Object.h"

class Exit : public Object{
public:
    Exit(int x, int y): x(x), y(y){}
    void action(Player& player) override;
    void notifyPublisher() override;
    void setPublisher(Publisher* pub) override;
    std::string print() override;
    int x, y;
private:
    Publisher* publisher = nullptr;

};

class ExitFactory : public Factory{
public:
    Object* factoryMethod(int x, int y) const override;
};
#endif //OOP_EXITOBJECT_H
