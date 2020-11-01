//
// Created by shakhinn on 01.11.2020.
//

#ifndef OOP_PUBLISHER_H
#define OOP_PUBLISHER_H
#include <list>
#include "logger.h"

class Object;
class Publisher {
public:
    virtual void registerLogger(logger* log) = 0;
    virtual void removeLogger(logger* log) = 0;
    virtual void notifyLogger(Object* obj) = 0;
    Object * object = nullptr;
};


#endif //OOP_PUBLISHER_H
