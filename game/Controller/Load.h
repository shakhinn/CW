#ifndef OOP_LOAD_H
#define OOP_LOAD_H
#include "../Model/Field.h"
#include "../Model/Player.h"
#include "../Model/IEnemy.h"
#include "../Model/Enemy.h"
#include "../Model/EnemyActions/attackAction.h"
#include "../Model//EnemyActions/killAction.h"
#include "../Model//EnemyActions/thiefAction.h"
#include "ReadExeption.h"
#include <istream>

class Load {
    std::ifstream fileStreamI;
public:
    explicit Load(std::string filename);
    void load(Field& field, Player& player, IEnemy** e1, IEnemy** e2, IEnemy** e3);
    ~Load();
};


#endif //OOP_LOAD_H
