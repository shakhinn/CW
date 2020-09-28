#ifndef OOP_CELL_H
#define OOP_CELL_H

struct Point{
    int x;
    int y;
};

enum Type{OPEN, CLOSE, ENTRANCE, EXIT};

class Cell{
public:
    Cell():open(false),type(CLOSE),coord({0,0}){}

    void makeOpen();

    void makeClose();

    void makeEntrance();

    void makeExit();

    bool show() const;

    Type showCELL();

    void makeCoord(int x, int y);

private:
    Point coord;
    bool open;
    Type type;
};


#endif //OOP_CELL_H
