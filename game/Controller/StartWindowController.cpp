#include "StartWindowController.h"

void StartWindowController::play() {
    view.create();
    invoker = new Invoker;
    while (view.getWindow()->isOpen()){
        event();
        draw();
    }
}
void StartWindowController::event() {
    while (view.getWindow()->pollEvent(events)) {
        if (events.type == sf::Event::Closed) {
            view.stop();
        }
        if(events.type == sf::Event::KeyPressed){
            input();
        }

    }
}
void StartWindowController::doCommand() {
    switch (choice) {
        case 0:
            view.stop();
            invoker->startGame();
            view.create();
            break;
        case 1:
            view.stop();
            invoker->openGame();
            view.create();
            break;
        case 2:
            view.stop();
    }
}

void StartWindowController::input() {
    switch (events.key.code) {
        case sf::Keyboard::Up:
            changeChoice(-1);
            break;
        case sf::Keyboard::Down:
            changeChoice(1);
            break;
        case sf::Keyboard::Enter:
            doCommand();
            break;
    }
}
void StartWindowController::draw() {
    view.clear();
    view.drawInfo(choice);
    view.display();
}

void StartWindowController::changeChoice(int a) {
    choice+=a;
    if(choice > 2){
        choice = 0;
    }
    if(choice < 0){
        choice = 2;
    }
}