#include "killAction.h"
bool killAction::interact(Player &player) {
    if(!player.armor) {
        player.kill();
        return true;
    } else{
        player.decArmor();
        return false;
    }
}