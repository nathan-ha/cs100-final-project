
#include "../../header/warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon),
      bomb_count(5)
{
}

void Warrior::swing_sword(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage;
    target.set_health(target_new_health);
}

void Warrior::flame_strike(Character &target)
{
    int dmg_amount = current_weapon.damage * 2; // might need balancing
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}

void Warrior::throw_bomb(Character &target)
{

    int dmg_amount = current_weapon.damage * 6;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
    bomb_count--;
}

int Warrior::get_bomb_count()
{
    return bomb_count;
}