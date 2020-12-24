#ifndef OOP_INVOKER_H
#define OOP_INVOKER_H
#include "StartGameCommand.h"
#include "NewGameCommand.h"


class Invoker {
private:
    Game game;
    Command* command;
public:
    void startGame();
    void openGame();

};


#endif //OOP_INVOKER_H
