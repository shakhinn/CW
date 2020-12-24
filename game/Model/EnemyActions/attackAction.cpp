#include "attackAction.h"

bool attackAction::interact(Player &player) {
    if(!player.armor) {
        player.decreaseHealth(1);
        return true;
    } else{
        player.decArmor();
        return false;
    }
}
