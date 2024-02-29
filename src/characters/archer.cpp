#include "../../header/archer.h"
#include <iostream>

using namespace std;

Archer::Archer(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon),
      arrow_count(5)
{
}

void Archer::shoot_arrow(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage;
    target.set_health(target_new_health);
}

void Archer::wind_arrow_strike(Character &target)
{
    if (arrow_count > 0)
    {
        int dmg_amount = 100; // placeholder
        int target_new_health = target.get_health() - dmg_amount;
        target.set_health(target_new_health);
    }
}