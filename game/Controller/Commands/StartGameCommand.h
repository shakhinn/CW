#ifndef OOP_STARTGAMECOMMAND_H
#define OOP_STARTGAMECOMMAND_H
#include "Command.h"


class StartGameCommand: public Command {
private:
    Game* game;
public:
    explicit StartGameCommand(Game* game_):game(game_){};
    void Execute() override;
};


#endif //OOP_STARTGAMECOMMAND_H
