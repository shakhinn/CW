#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <iostream>
#include "Cell.h"
//#include "Object.h"
#include "Point.h"
#include <cstdlib>
#include <experimental/random>
#define WIDTH 30
#define HEIGHT 50



class Field {
public:
    static Field* instance();

    Point& getEntrance();

    ~Field();

private:
    explicit Field(int width = 20, int height = 100);

    Field(Field const &a);

    Field& operator=(const Field & a);

    Field(Field && a)noexcept;

    Field& operator=(Field && a)noexcept;

    void initialiseMap() const;

    void doSimulationStep();

    int countOpenNeighbors(int x, int y) const;

    void generateMap();

    bool makeEntrance();

    bool makeExit();

    void checkSpace(int x, int y, int* count, int flag);

    int countNeighbors(int x, int y) const;

    void makeCoins() const;

    void makeBombs() const;

    void makeTele() const;

    void makeCords() const;

public:
    Cell** map;
    static Field* uniqueInstance;
    int width;
    int height;
    Point entrance;
    Point exit;
};


#endif //OOP_FIELD_H
