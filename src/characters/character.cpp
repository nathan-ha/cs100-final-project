#include "../../header/character.h"

Character::Character(const string& name, const string& race, int health, const Weapon& current_weapon)
    : name(name), race(race), health(health), current_weapon(current_weapon)
{
}