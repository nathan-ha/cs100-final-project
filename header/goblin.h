#pragma once
#include "character.h"

class Goblin : public Character
{
public:
    void attack(Character &target);
};