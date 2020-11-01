//
// Created by shakhinn on 19.10.2020.
//

#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H
#define LOGPATHSTART "Logs/"
#define LOGPATHEND " - log - player.txt"
#define LOGOBJECT " - log - object.txt"
#include <ctime>
#include "../Model/Field.h"
#include "../Model/Player.h"
#include "../View/View.h"
#include "../Model/Loggers/FileLogger.h"
#include "../Model/Loggers/ConsolLogger.h"
#include "../Model//Loggers/ObjectPublisher.h"

class Controller {
public:
    void init();
    void draw();
    void event();
    void input();
    void checkObject();
    void check_End_of_Game();
    void deleteLoggers() const;
    Field* field;
    View view;
    sf::Event events;
    Player* player;
    ConsolLogger* consolLogger;
    FileLogger* fileLogger;
    ObjectPublisher* publisher;
    FileLogger* objectFileLogger;
    ConsolLogger* objectConsolLogger;
private:
    std::string timeToString();

};


#endif //OOP_CONTROLLER_H
