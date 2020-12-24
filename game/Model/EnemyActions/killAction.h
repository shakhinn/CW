#ifndef OOP_KILLACTION_H
#define OOP_KILLACTION_H
#include "enemyAction.h"

class killAction: public enemyAction {
public:
    killAction() = default;
    bool interact(Player &player) override;
    ~killAction() = default;

};


#endif //OOP_KILLACTION_H
