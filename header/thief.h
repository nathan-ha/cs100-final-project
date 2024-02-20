#pragma once
#include "character.h"

class Thief : public Character {
protected:
    int throwing_knife_count;
    bool is_invulnerable;
public:
    void stab(Character& target);
    void throw_knife();
    void mirage_step();

}