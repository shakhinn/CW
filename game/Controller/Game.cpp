#include "Game.h"

void Game::newGame() {
    this->view.create();
    field = &Field::instance();
    Point start = field->getEntrance();
    player = new Player(start.x, start.y);
    Point E1 = {0,0};
    Point E2 = {0,0};
    Point E3 = {0,0};
    field->returnSpawn(E1, E2, E3);
    e1 = new Enemy<attackAction>(E1.x, E1.y);
    e2 = new Enemy<thiefAction>(E2.x, E2.y);
    e3 = new Enemy<killAction>(E3.x, E3.y);
    fileLogger = new FileLogger(player, LOGPATHSTART + timeToString() + LOGPATHEND);
    consolLogger = new ConsolLogger(player);
    publisher = new ObjectPublisher();
    objectConsolLogger = new ConsolLogger(publisher);
    objectFileLogger = new FileLogger(publisher, LOGPATHSTART + timeToString() + LOGOBJECT);
    for(int x = 0; x < field->width; x++){
        for(int y = 0; y < field->height; y++){
            if(field->map[x][y].showCELL() != OPEN && field->map[x][y].showCELL() != CLOSE){
                if(field->map[x][y].object)
                field->map[x][y].object->setPublisher(publisher);
            }
        }
    }
    movement = time(nullptr);
    while (view.getWindow()->isOpen()){
        event();
        draw();
    }
}

void Game::openGame() {
    this->view.create();
    load = new Load("save.txt");
    field = &Field::instance();
    player = new Player(0, 0);
    load->load(*field, *player, &e1, &e2, &e3);
    delete load;
    //fileLogger = new FileLogger(player, LOGPATHSTART + timeToString() + LOGPATHEND);
    //consolLogger = new ConsolLogger(player);
    publisher = new ObjectPublisher();
    objectConsolLogger = new ConsolLogger(publisher);
    objectFileLogger = new FileLogger(publisher, LOGPATHSTART + timeToString() + LOGOBJECT);
    for(int x = 0; x < field->width; x++){
        for(int y = 0; y < field->height; y++){
            if(field->map[x][y].showCELL() != OPEN && field->map[x][y].showCELL() != CLOSE){
                if(field->map[x][y].object)
                    field->map[x][y].object->setPublisher(publisher);
            }
        }
    }
    movement = time(nullptr);
    while (view.getWindow()->isOpen()){
        event();
        draw();
    }
    view.stop();
}

void Game::event() {
    while (view.getWindow()->pollEvent(events)) {
        if (events.type == sf::Event::Closed) {
            deleteObj();
            view.stop();
        }
        if(events.type == sf::Event::KeyPressed){
            input();
            flag = true;
        }
    }
    moveEnemies();
    checkObject();
    checkEnemy();
}

void Game::input() {
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
        case sf::Keyboard::P:
            save = new Save("save.txt");
            save->save(*field, player, e1, e2, e3);
            delete save;
    }
}
void Game::move(IEnemy &enemy) {
    bool f = false;
    int x = enemy.getX();
    int y = enemy.getY();
    while (!f) {
        int i = std::experimental::randint(0, 4);
        switch (i) {
            case 0:
                if (!field->map[x - 1][y].show()) {
                    enemy.move(-1, 0);
                    f = true;
                }
                break;
            case 1:
                if (!field->map[x + 1][y].show()) {
                    enemy.move(+1, 0);
                    f = true;
                }
                break;
            case 2:
                if (!field->map[x][y + 1].show()) {
                    enemy.move(0, +1);
                    f = true;
                }
                break;
            case 3:
                if (!field->map[x][y - 1].show()) {
                    enemy.move(0, -1);
                    f = true;
                }
                break;
        }
    }
}

void Game::moveEnemies(){
    if(difftime(time(nullptr), movement) > 0.5){
        if(e1) {
            move(*e1);
        }
        if(e2) {
            move(*e2);
        }
        if(e3) {
            move(*e3);
        }
        movement = time(nullptr);
        flag = true;
    }

}

void Game::check_End_of_Game() {
    if(player->isWin() && player->getScore() != 0){
        deleteObj();
        std::cout << "You WIN";
        view.stop();
        return;
    }
    if(player->getHealth() <= 0){
        deleteObj();
        std::cout << "You Lose";
        view.stop();
        return;
    }
}

void Game::checkObject() {
    int x = player->x;
    int y = player->y;
    if (field->map[x][y].object != nullptr) {
        if (!field->map[x][y].show()) {
            if ((field->map[x][y].showCELL() == EXIT && player->getScore() == 0) ||
                field->map[x][y].showCELL() == OPEN) { return; }
            *player += field->map[x][y].object;
            if(field->map[x][y].showCELL() != EXIT) {
                delete field->map[x][y].object;
                field->map[x][y].object = nullptr;
            }
            if (field->map[x][y].type != EXIT && field->map[x][y].type != ENTRANCE)
                field->map[x][y].type = OPEN;
            check_End_of_Game();
            }
        }

}
void Game::checkEnemy() {
    if(flag) {
        int x = player->x;
        int y = player->y;
        if(e1) {
            if (x == e1->getX() && y == e1->getY()) {
                *e1 += *player;
                if (!e1->isalive) {
                    delete e1;
                    e1 = nullptr;
                }
                flag = false;
            }
        }
        if(e2) {
            if (x == e2->getX() && y == e2->getY()) {
                *e2 += *player;
                if (!e2->isalive) {
                    delete e2;
                    e2 = nullptr;
                }
                flag = false;
            }
        }
        if(e3) {
            if (x == e3->getX() && y == e3->getY()) {
                *e3 += *player;
                if (!e3->isalive) {
                    delete e3;
                    e3 = nullptr;
                }
                flag = false;
            }
        }
        if(player->getHealth() <= 0){
            deleteObj();
            std::cout << "You Lose";
            view.stop();
            return;
        }
    }
}

void Game::draw() {
    view.clear();
    if(field) {
        for (int i = 0; i < field->width; i++) {
            for (int j = 0; j < field->height; j++) {
                field->map[i][j].makeCoord(i, j);
                view.drawMap(&field->map[i][j]);
                view.drawCell(&field->map[i][j]);
            }
        }
    }
    if(player) {
        view.drawPlayer(*player);
    }
    if(e1) {
        view.drawEnemy(*e1);
    }
    if(e2) {
        view.drawEnemy(*e2);
    }
    if(e3) {
        view.drawEnemy(*e3);
    }
    if(player) {
        view.drawInfo(*player);
    }
    view.display();
}

std::string Game::timeToString() {
    time_t now = time(nullptr);
    tm* tstruct ;
    char buf[80];
    tstruct = localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", tstruct);
    return buf;
}

void Game::deleteObj(){
    delete objectFileLogger;
    delete objectConsolLogger;
    //delete fileLogger;
    //delete consolLogger;
}