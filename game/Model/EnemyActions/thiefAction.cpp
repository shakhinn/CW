#include "thiefAction.h"
bool thiefAction::interact(Player &player) {
    if(!player.armor) {
        player.decreaseCoins(2);
        return true;
    } else{
        player.decArmor();
        return false;
    }
}