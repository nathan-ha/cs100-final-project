#include "../../header/skeleton.h"

void Skeleton::attack(Character &target)
{
    int dmg_amount = 10;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}