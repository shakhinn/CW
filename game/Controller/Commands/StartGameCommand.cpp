#include "StartGameCommand.h"

void StartGameCommand::Execute() {
    game->newGame();
}