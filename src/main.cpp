#include <iostream>
using namespace std;

#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"

// TODO: hard code damage? or randomize
/* 
    note: make sure to add new .cpp files to ~/src/CMakeLists.txt under add_library
    note: run tests with 
     cmake . && make && ./bin/runAllTests
    note: run build with 
     cmake . && make && ./bin/runBuild
    
*/

int main() {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::Thief));
    cout << "hell\n";

    /*since the player can choose when to quit, will we implement some sort of loop?
    or will we implement some sorta function that we pass in the input in for every action */ 
    
    return 0;
}