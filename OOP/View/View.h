//
// Created by shakhinn on 19.10.2020.
//

#ifndef OOP_VIEW_H
#define OOP_VIEW_H
#include "SFML/Graphics.hpp"
#include "../Model/Cell.h"
#include <sstream>

#define WINDOWHEIGHT 850
#define WINDOWWIDTH 1250
#define RECTSIZE 25


class View {
private:
    sf::RenderWindow window;
public:
    View() = default;

    sf::RenderWindow* getWindow();

    sf::RenderWindow* create();

    void stop();

    void clear();

    void display();

    void drawCell(Cell* c);

    void drawPlayer(Player player);

    void drawInfo(Player player);


};


#endif //OOP_VIEW_H
