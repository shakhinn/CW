#ifndef OOP_ATTACKACTION_H
#define OOP_ATTACKACTION_H
#include "enemyAction.h"


class attackAction: public enemyAction {
public:
    attackAction() = default;
    bool interact(Player &player) override;
    ~attackAction() = default;
};


#endif //OOP_ATTACKACTION_H
