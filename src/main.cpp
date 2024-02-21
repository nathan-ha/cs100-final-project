#include <iostream>
using namespace std;

#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"

// TODO: hard code damage? or randomize
/* note: run tests with 
    cmake . && make && ./bin/runAllTests
   note: run build with 
    cmake . && make && ./bin/runBuild
*/

int main() {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::Thief));
    cout << "hell\n";
    return 0;
}