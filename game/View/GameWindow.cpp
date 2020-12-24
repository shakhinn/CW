#include "GameWindow.h"

sf::RenderWindow * GameWindow::getWindow() {
    return &window;
}
void GameWindow::stop() {
    this->window.close();
}

void GameWindow::clear() {
    this->window.clear();
}

void GameWindow::display() {
    this->window.display();
}

sf::RenderWindow * GameWindow::create() {
    this->window.create(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "game" );
    return &window;
}

void GameWindow::drawMap(Cell *c) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    if(c->show()){
        rec.setTexture(&closeTexture);
    } else{
        rec.setTexture(&openTexture);
    }
    rec.setPosition( c->coord.y * RECTSIZE,  c->coord.x * RECTSIZE);
    window.draw(rec);
}

void GameWindow::drawCell(Cell* c) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    Type type = c->showCELL();
    if(type != OPEN && type!= CLOSE) {
        switch (type) {
            /*case OPEN:{
                rec.setTexture(&openTexture);
                //rec.setFillColor(sf::Color::White);
                //rec.setOutlineColor(sf::Color::Black);
                break;
            }
            case CLOSE:
                rec.setTexture(&closeTexture);
                //rec.setFillColor(sf::Color::Magenta);
                //rec.setOutlineColor(sf::Color::Magenta);
                break;*/
            case COIN:
                rec.setTexture(&coinTexture);
                //rec.setFillColor(sf::Color::Yellow);
                //rec.setOutlineColor(sf::Color::Yellow);
                break;
            case ENTRANCE:
                rec.setTexture(&entranceTexture);
                //rec.setFillColor(sf::Color::Red);
                //rec.setOutlineColor(sf::Color::Black);
                break;
            case EXIT:
                rec.setTexture(&exitTexture);
                //rec.setFillColor(sf::Color::Green);
                //rec.setOutlineColor(sf::Color::Black);
                break;
            case BOMB:
                rec.setTexture(&bombTexture);
                //rec.setFillColor(sf::Color::Black);
                //rec.setOutlineColor(sf::Color::Black);
                break;
            case TELE:
                rec.setTexture(&teleportTexture);
                //rec.setFillColor(sf::Color::Cyan);
                //rec.setOutlineColor(sf::Color::Cyan);
                break;
            case ARMOR:
                rec.setTexture(&armorTexture);
                break;
        }
        rec.setPosition(c->coord.y * RECTSIZE, c->coord.x * RECTSIZE);
        window.draw(rec);
    }
}

void GameWindow::drawPlayer(Player& player) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    rec.setTexture(&playerTexture);
    //rec.setFillColor(sf::Color::Blue);
    //rec.setOutlineColor(sf::Color::Black);
    //rec.setOutlineThickness(1);
    rec.setPosition( player.y * RECTSIZE,  player.x * RECTSIZE);
    window.draw(rec);
}

void GameWindow::drawInfo(Player& player) {
    sf::Font font;
    if(!font.loadFromFile("ArialRegular.ttf")){
        return;
    }
    sf::Text score;
    score.setFont(font);
    score.setString("Coins: " + std::to_string(player.getScore())+"\n"+"Heals: " + std::to_string(player.getHealth()) + "\n"+"Armor: "+std::to_string(player.armor));
    score.setFillColor(sf::Color::Red);
    score.setPosition(5, 755);
    window.draw(score);

}
void GameWindow::drawEnemy(IEnemy &enemy) {
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(RECTSIZE, RECTSIZE));
    switch (enemy.getBehaviorType()) {
        case ATTACK:rec.setTexture(&enemy1); break;
        case THIEF:rec.setTexture(&enemy2); break;
        case KILL: rec.setTexture(&enemy3); break;
        default: break;
    }
    rec.setPosition( enemy.getY() * RECTSIZE,  enemy.getX() * RECTSIZE);
    window.draw(rec);
}