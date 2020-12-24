#ifndef OOP_NEWGAMECOMMAND_H
#define OOP_NEWGAMECOMMAND_H
#include "Command.h"

class NewGameCommand: public Command {
private:
    Game* game;
public:
    explicit NewGameCommand(Game* game_):game(game_){};
    void Execute() override;

};


#endif //OOP_NEWGAMECOMMAND_H
