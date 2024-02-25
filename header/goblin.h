#pragma once
#include "character.h"

class goblin : public Character
{
public:
    void attack(Character &target);
};