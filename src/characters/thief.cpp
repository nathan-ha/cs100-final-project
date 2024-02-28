#include "../../header/thief.h"
#include <iostream>

Thief::Thief(const string &name, const string &race, int health, const Weapon &current_weapon)
    : Character(name, race, health, current_weapon),
      throwing_knife_count(5),
      is_invulnerable(false)
{
}

void Thief::stab(Character &target)
{
    int target_new_health = target.get_health() - current_weapon.damage;
    target.set_health(target_new_health);
}

void Thief::throw_knife(Character &target)
{
    if (throwing_knife_count <= 0)
    {
        std::cout << "TODO: handle running out of throwing knives\n";
        return;
    }
    int dmg_amount = 10;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}

void Thief::disable_mirage_step()
{
    is_invulnerable = false;
}

bool Thief::get_is_invulnerable()
{
    return is_invulnerable;
}

void Thief::mirage_step()
{
    // TODO: disable mirage step after some turns
    is_invulnerable = true;
}