#include "../../header/thief.h"
#include <iostream>

Thief::Thief(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon),
      throwing_knife_count(5),
      is_invulnerable(false),
      skillcount(10)
{
}

void Thief::stab(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage - current_weapon.damage;
    target.set_health(target_new_health);
}

void Thief::throw_knife(Character &target)
{
    int dmg_amount = current_weapon.damage * 3;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
    throwing_knife_count--;
}

int Thief::get_throwing_knife_count()
{
    return throwing_knife_count;   
}
void Thief::set_throwing_knife_count(int x)
{
    throwing_knife_count = x;
}


int Thief::get_skill_count()
{
    return skillcount;
}
void Thief::set_skill_count(int t)
{
    skillcount = t;
}