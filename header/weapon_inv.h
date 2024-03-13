#pragma once

#include <vector>
#include <iostream>
#include "character.h"
#include "archer.h"
#include "warrior.h"
#include "thief.h"

using namespace std;

int weapon_rate();
void weapon_drop_rate(Character &player);
void weapon_drop(Character &player, std::istream &in = std::cin, std::ostream &out = std::cout);

// #include me uwu !
//             ^^^ who let this bro comment
