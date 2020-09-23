#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell{
public:
    Cell():open(false),entrance(false),exit(false){}

    void makeOpen();

    void makeClose();

    void makeEntrance();

    bool checkEntrance() const;

    bool checkExit() const;

    void makeExit();

    bool show() const;

private:
    bool open;
    bool entrance;
    bool exit;
};


#endif //OOP_CELL_H
