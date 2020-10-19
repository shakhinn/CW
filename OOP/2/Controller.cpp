//
// Created by shakhinn on 19.10.2020.
//

#include "Controller.h"

void Controller::init() {
    this->view.create();
    field = Field::instance();
    Point start = field->getEntrance();
    player = new Player(start.x, start.y);
    while (view.getWindow()->isOpen()){
        event();
        draw();
    }
}

void Controller::event() {
    while (view.getWindow()->pollEvent(events)) {
        if (events.type == sf::Event::Closed) {
            view.stop();
        }
        if(events.type == sf::Event::KeyPressed){
            input();
        }

    }
    checkObject();
}

void Controller::input() {
    switch (events.key.code) {
        case sf::Keyboard::W:
            player->move(-1, 0, !field->map[player->x-1][player->y].show());
            break;
        case sf::Keyboard::S:
            player->move(+1, 0, !field->map[player->x+1][player->y].show());
            break;
        case sf::Keyboard::D:
            player->move(0, +1, !field->map[player->x][player->y+1].show());
            break;
        case sf::Keyboard::A:
            player->move(0, -1, !field->map[player->x][player->y-1].show());
            break;
    }

}

void Controller::checkObject() {
    int x = player->x;
    int y = player->y;
    if(field->map[x][y].object != nullptr){
        if(!field->map[x][y].show()){
            if((field->map[x][y].showCELL() == EXIT && player->score == 0) || field->map[x][y].showCELL() == OPEN){return;}
            *player+=field->map[x][y].object;
            delete field->map[x][y].object;
            field->map[x][y].object = nullptr;
            if(field->map[x][y].type != EXIT && field->map[x][y].type != ENTRANCE)
                field->map[x][y].type = OPEN;
            if(player->win && player->score != 0){
                view.stop();
                std::cout << "You WIN";
            }
            if(player->health <= 0){
                view.stop();
                std::cout << "You Lose";
            }
        }
    }
}
void Controller::draw() {
    view.clear();
    for(int i = 0; i < field->width; i++){
        for(int j = 0; j < field->height; j++){
            field->map[i][j].makeCoord(i, j);
            view.drawCell(&field->map[i][j]);
        }
    }
    view.drawPlayer(*player);
    view.drawInfo(*player);
    view.display();
}