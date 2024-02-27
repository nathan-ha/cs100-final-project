#pragma once
#include "character.h"

class Goblin : public Character
{
public:
    Goblin(const string& name, const string& race, int health, const Weapon& current_weapon);
    void attack(Character &target);
};