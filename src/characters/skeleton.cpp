#include "../../header/skeleton.h"

Skeleton::Skeleton(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon)
{
}

void Skeleton::attack(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage;
    target.set_health(target_new_health);
}