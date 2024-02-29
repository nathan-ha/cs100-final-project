
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
    int dmg_amount = 50; // might need balancing
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}

void Warrior::throw_bomb()
{
    if (bomb_count > 0)
    {
        cout << "bomb has been planted" << endl;
    }
}
