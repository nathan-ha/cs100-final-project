#pragma once
#include "character.h"

class Warrior : public Character
{
protected:
    int bomb_count;

public:
    Warrior(const string &name, const string &race, int health, const Weapon &current_weapon);
    void swing_sword(Character &target);
    void flame_strike(Character &target);
    void throw_bomb();
};
