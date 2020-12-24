#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H
#include "IEnemy.h"
#include "EnemyActions/attackAction.h"
#include "EnemyActions/killAction.h"
#include "EnemyActions/thiefAction.h"

template<class enemyAction>
class Enemy: public IEnemy {
private:
    enemyAction* action = nullptr;
    int x,y;
    void interact(Player& player) override{
        if(!action->interact(player))
            kill();
    }

public:
    Enemy(int x, int y):x(x), y(y){
        action = new enemyAction();
    }
    void operator+=(Player& player)override{
        if(isalive)
            interact(player);
    }
    int getX()override{
        return x;
    }
    int getY()override{
        return y;
    }
    void kill()override{
        isalive = false;
    }
    ~Enemy(){
        delete action;
    }
    void move(int dX, int dY)override{
        x+=dX;
        y+=dY;
    }
    const std::type_info& getType()override{
        return typeid(Enemy<enemyAction>);
    }

    BType getBehaviorType()override{
        if(getType() == typeid(Enemy<attackAction>)){
            return ATTACK;
        }else if(getType() == typeid(Enemy<killAction>)){
            return KILL;
        }else if(getType() == typeid(Enemy<thiefAction>)){
            return THIEF;
        }
    }
};


#endif //OOP_ENEMY_H
