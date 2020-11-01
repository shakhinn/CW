#include "View.h"

sf::RenderWindow * View::getWindow() {
    return &window;
}
void View::stop() {
    this->window.close();
}

void View::clear() {
    this->window.clear();
}

void View::display() {
    this->window.display();
}

sf::RenderWindow * View::create() {
    this->window.create(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "game" );
    return &window;
}

void View::drawCell(Cell* c) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    Type type = c->showCELL();
    switch (type) {
        case OPEN:{
            rec.setFillColor(sf::Color::White);
            rec.setOutlineColor(sf::Color::Black);
            break;
        }
        case CLOSE:
            rec.setFillColor(sf::Color::Magenta);
            rec.setOutlineColor(sf::Color::Magenta);
            break;
        case COIN:
            rec.setFillColor(sf::Color::Yellow);
            rec.setOutlineColor(sf::Color::Yellow);
            break;
        case ENTRANCE:
            rec.setFillColor(sf::Color::Red);
            rec.setOutlineColor(sf::Color::Black);
            break;
        case EXIT:
            rec.setFillColor(sf::Color::Green);
            rec.setOutlineColor(sf::Color::Black);
            break;
        case BOMB:
            rec.setFillColor(sf::Color::Black);
            rec.setOutlineColor(sf::Color::Black);
            break;
        case TELE:
            rec.setFillColor(sf::Color::Cyan);
            rec.setOutlineColor(sf::Color::Cyan);
            break;
    }
    rec.setOutlineThickness(1);
    rec.setPosition( c->coord.y * RECTSIZE,  c->coord.x * RECTSIZE);
    window.draw(rec);
}

void View::drawPlayer(Player player) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    rec.setFillColor(sf::Color::Blue);
    rec.setOutlineColor(sf::Color::Black);
    rec.setOutlineThickness(1);
    rec.setPosition( player.y * RECTSIZE,  player.x * RECTSIZE);
    window.draw(rec);
}

void View::drawInfo(Player player) {
    sf::Font font;
    if(!font.loadFromFile("ArialRegular.ttf")){
        return;
    }
    sf::Text score;
    score.setFont(font);
    score.setString("Coins: " + std::to_string(player.score)+"\n"+"Heals: " + std::to_string(player.health));
    score.setFillColor(sf::Color::Red);
    score.setPosition(5, 775);
    window.draw(score);

}