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
    /*since the player can choose when to quit, will we implement some sort of loop?
    or will we implement some sorta function that we pass in the input in for every action */ 

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
    bool failcheck = true;
    while(failcheck == true){
        if(playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W"){
            Weapon playerweapon("Sword", 5, WARRIOR);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << "your name has been recorded" << endl;
            failcheck = false;//not sure if i should use break instead
        }
        else if(playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A"){
            Weapon playerweapon("Bow", 5, ARCHER);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << "your name has been recorded" << endl;
            failcheck = false;

        }
        else if(playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T"){
            Weapon playerweapon("Dagger", 5, THEIF);
            Character player(playername, "Human", 100, playerweapon);
            cout << "Welcome, " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            failcheck = false;
        }
        else{
            cout << "Wrong class!"<< endl << "Choose your class" << endl;
            cin >> playerclass;
        }
    }
    return 0;
}