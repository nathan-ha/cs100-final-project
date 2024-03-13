#include "../../header/archer.h"
#include <iostream>

using namespace std;

Archer::Archer(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon),
      arrow_count(75)
{
}

void Archer::shoot_arrow(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage;
    target.set_health(target_new_health);
    arrow_count--;
}

void Archer::wind_arrow_strike(Character &target)
{
    int dmg_amount = current_weapon.damage * 5; 
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
    arrow_count -= 5;
}

void Archer::bow_smack(Character &target)
{
    int dmg_amount = current_weapon.damage / 4; 
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}

int Archer::get_arrow_count()
{
    return arrow_count;
}
void Archer::set_arrow_count(int c)
{
    arrow_count = c;
}