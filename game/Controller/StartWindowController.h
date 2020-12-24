#ifndef OOP_STARTWINDOWCONTROLLER_H
#define OOP_STARTWINDOWCONTROLLER_H
#include "../View/StartWindow.h"
#include "Commands/Invoker.h"


class StartWindowController {
private:
    int choice=0;
    StartWindow view;
    sf::Event events;
    Invoker* invoker;
    void changeChoice(int);
    void draw();
    void event();
    void input();
    void doCommand();
public:
    void play();
};


#endif //OOP_STARTWINDOWCONTROLLER_H
