#pragma once
#include "character.h"

class Warrior : public Character
{
protected:
    int bomb_count;
    int skillcount;

public:
    Warrior(const string &name, const string &race, int health, const Weapon &current_weapon);
    void swing_sword(Character &target);
    void flame_strike(Character &target);
    void throw_bomb(Character &target);
    int get_bomb_count();
    void set_bomb_count(int count);
    void set_skill_count(int s);
    int get_skill_count();
};
