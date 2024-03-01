#include <iostream>
using namespace std;

#include "../header/fight.h"

// for when you want to test your functions the lazy way

int main()
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    Skeleton s("Wallace", "skeleton", 105, scythe);
    bool win = fight(w, s);
}
