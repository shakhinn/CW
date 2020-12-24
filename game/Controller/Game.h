//
// Created by shakhinn on 19.10.2020.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#define LOGPATHSTART "Logs/"
#define LOGPATHEND "-log-player.txt"
#define LOGOBJECT " -log-object.txt"
#include <ctime>
#include <list>
#include "../Model/Field.h"
#include "../Model/Player.h"
#include "../Model/Enemy.h"
#include "../Model/EnemyActions/attackAction.h"
#include "../Model//EnemyActions/killAction.h"
#include "../Model//EnemyActions/thiefAction.h"
#include "../View/GameWindow.h"
#include "../Model/Loggers/FileLogger.h"
#include "../Model/Loggers/ConsolLogger.h"
#include "../Model//Loggers/ObjectPublisher.h"
#include "Save.h"
#include "Load.h"

class Game {
public:
    void newGame();
    void openGame();
private:
    void draw();
    void event();
    void input();
    void checkObject();
    void check_End_of_Game();
    void checkEnemy();
    void deleteObj();
    void moveEnemies();
    void move(IEnemy& enemy);
    Field* field;
    GameWindow view;
    GameWindow view1;
    sf::Event events;
    Player* player;
    IEnemy* e1;
    IEnemy* e2;
    IEnemy* e3;
    ConsolLogger* consolLogger;
    FileLogger* fileLogger;
    ObjectPublisher* publisher;
    FileLogger* objectFileLogger;
    ConsolLogger* objectConsolLogger;
    Save* save;
    Load* load;
    bool flag;
    time_t movement;
    std::string timeToString();

};


#endif //OOP_GAME_H
