#ifndef OOP_CELL_H
#define OOP_CELL_H
#include "Objects/CoinObject.h"
#include "Objects/ExitObject.h"
#include "Objects/EntranceObject.h"
#include "Objects/BombObject.h"
#include "Objects/TeleportObject.h"
#include "Point.h"


enum Type{OPEN, CLOSE, ENTRANCE, EXIT, COIN, BOMB, TELE};

class Cell{
public:
    Cell():open(false),type(CLOSE),coord({0,0}){}

    void makeOpen();

    void makeClose();

    void makeEntrance();

    void makeExit();

    void makeCoin();

    void makeBomb();

    void makeTele();

    bool show() const;

    Type showCELL() const;

    void makeCoord(int x, int y);

    ~Cell(){
        if(object != nullptr){
            delete object;
        }
    }
    Point coord;
public:

    Object* object = nullptr;
    bool open;
    Type type;
};


#endif //OOP_CELL_H
