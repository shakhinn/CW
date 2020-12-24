#ifndef OOP_COMMAND_H
#define OOP_COMMAND_H
#include "../Game.h"

class Command {
public:
    virtual ~Command()= default;
    virtual void Execute() =0;
};


#endif //OOP_COMMAND_H
