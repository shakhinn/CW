#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include "iostream"
#include "fstream"


class Player;
class Publisher;
class logger {
public:
    virtual ~logger(){}

    virtual void update() = 0;

    virtual void unsubscribe() = 0;

protected:
    Player* player_ = nullptr;
    Publisher* publisher_ = nullptr;
};


#endif //OOP_LOGGER_H
