#pragma once
#include "character.h"

class Wolf : public Character
{
public:
    Wolf(const string& name, const string& race, int health, const Weapon& current_weapon);
    void attack(Character &target);
};