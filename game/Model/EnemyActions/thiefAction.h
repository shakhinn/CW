#ifndef OOP_THIEFACTION_H
#define OOP_THIEFACTION_H
#include "enemyAction.h"

class thiefAction: public enemyAction {
public:
    thiefAction() = default;
    bool interact(Player &player) override;
    ~thiefAction() = default;

};


#endif //OOP_THIEFACTION_H
