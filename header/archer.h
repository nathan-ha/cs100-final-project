#pragma once
#include "character.h"

class Archer : public Character
{
protected:
    int arrow_count;

public:
    Archer(const string &name, const string &race, int health, const Weapon &current_weapon);
    void shoot_arrow(Character &target);
    void wind_arrow_strike(Character &target);
};