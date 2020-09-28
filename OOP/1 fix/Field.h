#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <iostream>
#include "Cell.h"
#include <cstdlib>
#define WIDTH 50
#define HEIGHT 100



class Field {
public:
    static Field& instance();

    void showField();

    Point& getEntrance();

    Point& getExit();

    ~Field();

private:
    explicit Field(int width = 20, int height = 100);

    Field(Field const &a);

    Field& operator=(const Field & a);

    Field(Field && a)noexcept;

    Field& operator=(Field && a)noexcept;

    void initialiseMap();

    void doSimulationStep();

    int countOpenNeighbors(int x, int y);

    void generateMap();

    bool makeEntrance();

    bool makeExit();

    void checkSpace(int x, int y, int* count, int flag);

    int countNeighbors(int x, int y);

    Cell** getMap();

private:
    Cell** map;
    static Field* uniqueInstance;
    int width;
    int height;
    Point entrance;
    Point exit;
};


#endif //OOP_FIELD_H
