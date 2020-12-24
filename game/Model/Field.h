#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <iostream>
#include "Cell.h"
//#include "Object.h"
#include "Point.h"
#include <cstdlib>
#include <experimental/random>
#include "../Controller/ReadExeption.h"
#define WIDTH 30
#define HEIGHT 50

class Field;
class SingletonDestroyer{
private:
    Field* uniqueInstance;
public:
    ~SingletonDestroyer();
    void initialize(Field* p);
};

class Field {
public:
    static Field& instance();

    Point& getEntrance();

    ~Field();

    void save(std::ofstream & filestream);

    void load(std::ifstream & filestream);

private:
    friend class SingletonDestroyer;

    static Field* uniqueInstance;

    static SingletonDestroyer destroyer;

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

    void makeArmor() const;

    void makeEnemySpawn();

    void makeCords() const;

    void setSize(int w, int h);


public:
    void returnSpawn(Point& e1, Point& e2, Point& e3) const;
    Cell** map;
    int width;
    int height;
    Point entrance;
    Point exit;
    Point en1, en2, en3;
};


#endif //OOP_FIELD_H
