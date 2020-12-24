#include "Invoker.h"

void Invoker::startGame() {
    command = new StartGameCommand(&game);
    command->Execute();
    delete command;
}

void Invoker::openGame(){
    command = new NewGameCommand(&game);
    command->Execute();
    delete command;
}
