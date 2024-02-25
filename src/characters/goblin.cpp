#include "../../header/goblin.h"

void goblin::attack(Character &target)
{
    int dmg_amount = 5;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}