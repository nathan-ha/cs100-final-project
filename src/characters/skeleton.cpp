#include "../../header/skeleton.h"

Skeleton::Skeleton(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon)
{
}

void Skeleton::attack(Character &target)
{
    int dmg_amount = 10;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}