#include <iostream>
using namespace std;

#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"

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


    // Character(const string& name, const string& race, int health, const Weapon& current_weapon);

    // string get_name();
    // void set_name(const string& new_name);

    // string get_race();
    // void set_race(const string& new_race);

    // int get_health();
    // void set_health(int new_health);

    // void run_away();
    // character_class get_class_type();

    cout << "Welcome adventurer, to His majeasty's DragonSlayer's Quest" << endl;
    cout << "His majeasty's sacred treasure has been stolen by the mythical dragon king from the northern mountains" << endl;
    cout << "He beeseaches you to venture into his deen to kill the dragon king and reclaim his sacred treasure that has been lost" << endl;
    cout << "The King will reward you handsomely should you complete this quest!" << endl;
    cout << "Now adventurer, state your name and let your name be inscribbed to the records" << endl;

    // Player's name input
    string playername, playerclass;
    cout << "Enter your name: ";
    cin >> playername;
    cout << "What is your class?" << endl << "(Choose from Warrior, Archer, or Thief" << endl;
    cin >> playerclass;
    bool passfail = true;
    while(passfail){
        if(playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W"){
            Weapon playerweapon("Sword", 5, Warrior);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << "your name has been recorded" << endl;
            passfail = false;//not sure if i should use break instead
        }
        else if(playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A"){
            Weapon playerweapon("Bow", 5, Archer);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << "your name has been recorded" << endl;
            passfail = false;

        }
        else if(playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T"){
            Weapon playerweapon("Dagger", 5, Thief);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << "your name has been recorded" << endl;
            passfail = false;
        }
        else{
            cout << "Wrong class!"<< endl << "Choose your class" << endl;
            cin >> playerclass;
        }
    }




    return 0;
}