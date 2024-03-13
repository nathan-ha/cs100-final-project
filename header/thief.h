#pragma once
#include "character.h"

class Thief : public Character
{
protected:
    int throwing_knife_count;
    bool is_invulnerable;
    int skillcount;

public:
    Thief(const string &name, const string &race, int health, const Weapon &current_weapon);
    void stab(Character &target);
    void throw_knife(Character &target);
    int get_throwing_knife_count();
    void set_throwing_knife_count(int x);
    // mirage step is implemented in fight.h now
    void set_skill_count(int t);
    int get_skill_count();
};