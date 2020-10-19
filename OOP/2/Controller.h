//
// Created by shakhinn on 19.10.2020.
//

#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H
#include "Field.h"
#include "Player.h"
#include "View.h"

class Controller {
public:
    void init();
    void draw();
    void event();
    void input();
    void checkObject();
    Field* field;
    View view;
    sf::Event events;
    Player* player;

};


#endif //OOP_CONTROLLER_H
