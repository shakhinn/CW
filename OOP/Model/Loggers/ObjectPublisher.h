//
// Created by shakhinn on 01.11.2020.
//

#ifndef OOP_OBJECTPUBLISHER_H
#define OOP_OBJECTPUBLISHER_H
#include "Publisher.h"


class ObjectPublisher: public Publisher {
public:
    void registerLogger(logger* log) override;
    void removeLogger(logger* log) override;
    void notifyLogger(Object* obj) override;

private:
    std::list<logger *> loggers;
};


#endif //OOP_OBJECTPUBLISHER_H
