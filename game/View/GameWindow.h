#ifndef OOP_GAMEWINDOW_H
#define OOP_GAMEWINDOW_H
#include "SFML/Graphics.hpp"
#include "../Model/Cell.h"
#include "../Model/IEnemy.h"
#include <sstream>

#define WINDOWHEIGHT 900
#define WINDOWWIDTH 1250
#define RECTSIZE 25


class GameWindow {
private:
    sf::RenderWindow window;
    sf::Texture openTexture;
    sf::Texture closeTexture;
    sf::Texture coinTexture;
    sf::Texture bombTexture;
    sf::Texture teleportTexture;
    sf::Texture exitTexture;
    sf::Texture entranceTexture;
    sf::Texture playerTexture;
    sf::Texture armorTexture;
    sf::Texture enemy1;
    sf::Texture enemy2;
    sf::Texture enemy3;
public:
    GameWindow(){
        openTexture.loadFromFile("Textures/mapTile_022.png");
        closeTexture.loadFromFile("Textures/mapTile_027.png");
        coinTexture.loadFromFile("Textures/platformPack_item008.png");
        bombTexture.loadFromFile("Textures/bomb.png");
        teleportTexture.loadFromFile("Textures/platformPack_tile054.png");
        exitTexture.loadFromFile("Textures/platformPack_tile049.png");
        entranceTexture.loadFromFile("Textures/platformPack_tile052.png");
        playerTexture.loadFromFile("Textures/platformChar_jump.png");
        armorTexture.loadFromFile("Textures/platformPack_item004.png");
        enemy1.loadFromFile("Textures/mapTile_137.png");
        enemy2.loadFromFile("Textures/mapTile_154.png");
        enemy3.loadFromFile("Textures/mapTile_153.png");
    }

    sf::RenderWindow* getWindow();

    sf::RenderWindow* create();

    void stop();

    void clear();

    void display();

    void drawMap(Cell* c);

    void drawCell(Cell* c);

    void drawPlayer(Player& player);

    void drawInfo(Player& player);

    void drawEnemy(IEnemy& enemy);


};


#endif //OOP_GAMEWINDOW_H
