#pragma once
#include "character.h"

class Skeleton : public Character
{
public:
    Skeleton(const string &name, const string &race, int health, const Weapon &current_weapon);
    void attack(Character &target);
};