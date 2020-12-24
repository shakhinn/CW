#ifndef OOP_STARTWINDOW_H
#define OOP_STARTWINDOW_H
#include "SFML/Graphics.hpp"

#define WHEIGHT 200
#define WWIDTH 200

class StartWindow {
private:
    sf::RenderWindow window;
public:
    StartWindow() = default;

    sf::RenderWindow* getWindow();

    sf::RenderWindow* create();

    void stop();

    void clear();

    void display();

    void drawInfo(int choice);
};


#endif //OOP_STARTWINDOW_H
