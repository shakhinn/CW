#include "StartWindow.h"
sf::RenderWindow * StartWindow::getWindow() {
    return &window;
}
void StartWindow::stop() {
    this->window.close();
}

void StartWindow::clear() {
    this->window.clear();
}

void StartWindow::display() {
    this->window.display();
}

sf::RenderWindow * StartWindow::create() {
    this->window.create(sf::VideoMode(WWIDTH, WHEIGHT), "game" );
    return &window;
}

void StartWindow::drawInfo(int choice) {
    sf::Font font;
    if(!font.loadFromFile("ArialRegular.ttf")){
        return;
    }
    sf::Text line1;
    line1.setFont(font);
    line1.setString("NEW GAME\n");
    line1.setFillColor(sf::Color::Red);
    line1.setPosition(5, 10);
    sf::Text line2;
    line2.setFont(font);
    line2.setString("OPEN GAME");
    line2.setFillColor(sf::Color::Red);
    line2.setPosition(5, 40);
    sf::Text line3;
    line3.setFont(font);
    line3.setString("EXIT");
    line3.setFillColor(sf::Color::Red);
    line3.setPosition(5, 70);
    switch (choice) {
        case 0:
            line1.setFillColor(sf::Color::White);
            break;
        case 1:
            line2.setFillColor(sf::Color::White);
            break;
        case 2:
            line3.setFillColor(sf::Color::White);
            break;
    }
    window.draw(line1);
    window.draw(line2);
    window.draw(line3);
}