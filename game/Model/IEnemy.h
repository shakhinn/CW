#ifndef OOP_IENEMY_H
#define OOP_IENEMY_H
#include "EnemyActions/enemyAction.h"

enum BType{KILL, THIEF, ATTACK };

class IEnemy{
public:
    virtual void interact(Player& player)=0;
    virtual void operator+=(Player& player)=0;
    virtual void kill()=0;
    virtual int getX()=0;
    virtual int getY()=0;
    virtual void move(int dX, int dY)=0;
    virtual const std::type_info& getType() = 0;
    virtual BType getBehaviorType() = 0;
    ~IEnemy() = default;
    bool isalive = true;
};

#endif //OOP_IENEMY_H
