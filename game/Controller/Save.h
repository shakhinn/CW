#ifndef OOP_SAVE_H
#define OOP_SAVE_H
#include "../Model/Field.h"
#include "../Model/Player.h"
#include "../Model/IEnemy.h"
#include <ostream>
#include "ReadExeption.h"

class Save {
private:
    std::ofstream fileStreamO;
public:
    explicit Save(std::string filename);
    void save(Field& field, Player* player, IEnemy* e1, IEnemy* e2, IEnemy* e3);
    ~Save();

};


#endif //OOP_SAVE_H
