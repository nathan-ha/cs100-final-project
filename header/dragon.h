#pragma once
#include "character.h"

class Dragon : public Character
{
public:
    Dragon(const string& name, const string& race, int health, const Weapon& current_weapon);
    void attack(Character &target);
};