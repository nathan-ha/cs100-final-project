#pragma once
#include "character.h"

class Skeleton : public Character {
public:
    void attack(Character& target);
}