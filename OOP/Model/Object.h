#ifndef OOP_OBJECT_H
#define OOP_OBJECT_H

#include "Player.h"
#include <string>
#include "Loggers/Publisher.h"

class Player;
class Publisher;

class Object {
public:
    virtual void action(Player& player) = 0;
    virtual ~Object() = default;
    virtual void notifyPublisher() = 0;
    virtual void setPublisher(Publisher* pub) = 0;
    virtual std::string print() = 0;
    friend std::ostream &operator<<(std::ostream &output, Object& object);
};

class Factory{
public:
    virtual ~Factory() {};
    virtual Object* factoryMethod(int x, int y) const = 0;
};
#endif //OOP_OBJECT_H
