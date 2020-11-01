#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Point.h"
#include "Object.h"
#include "Loggers/logger.h"
#include <list>
#include <string>


class Object;



class Player {
public:
    int x, y;
    Point tele;
    int health = 5;
    int score = 0;
    bool win = false;
    Player& operator+=(Object* right);
    void move(int dX, int dY, bool isOpen);
    Player(int x, int y):x(x),y(y){
        tele.x = x;
        tele.y = y;
    };
    ~Player() = default;
    void addCoin();
    void setCords();
    void decreaseHealth();

    int getX()const ;
    int getY() const ;
    int getScore() const ;
    int getHealth() const;
    bool isWin()const;


    void registerLogger(logger* log);
    void removeLogger(logger* log);
    void notifyLogger();
    friend std::ostream &operator << (std::ostream &output, const Player &player) ;

private:
    std::list<logger *> loggers;

};


#endif //OOP_PLAYER_H
