//
// Created by shakhinn on 31.10.2020.
//

#ifndef OOP_CONSOLLOGGER_H
#define OOP_CONSOLLOGGER_H
#include "logger.h"
#include "../Player.h"
#include "../Object.h"

class ConsolLogger: public logger {

public:
    explicit ConsolLogger(Player* player);
    explicit ConsolLogger(Publisher* publisher);

    void update() override;

    void unsubscribe() override;

};


#endif //OOP_CONSOLLOGGER_H
