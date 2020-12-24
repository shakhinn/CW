#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Point.h"
#include "Objects/Object.h"
#include "Loggers/logger.h"
#include <list>
#include <string>


class Object;



class Player {
public:
    Point tele;
    int health = 10;
    int score = 5;
    bool win = false;
    int armor = 0;
public:
    int x, y;
    Player& operator+=(Object* right);
    void move(int dX, int dY, bool isOpen);
    Player(int x, int y):x(x),y(y){
        tele.x = x;
        tele.y = y;
    };
    ~Player() = default;
    void addCoin();
    void setCords();
    void decreaseHealth(int a = 1);
    void incArmor();
    void decArmor();
    void kill();
    void decreaseCoins(int a);

    int getX()const ;
    int getY() const ;
    int getScore() const ;
    int getHealth() const;
    bool isWin()const;


    void registerLogger(logger* log);
    void removeLogger(logger* log);
    void notifyLogger();
    friend std::ostream &operator << (std::ostream &output, const Player &player) ;

    void save(std::ofstream& filestream);
    void load(std::ifstream& filestream);

private:
    std::list<logger *> loggers;

};


#endif //OOP_PLAYER_H
