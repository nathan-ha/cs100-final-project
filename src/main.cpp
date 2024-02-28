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

    cout << endl << endl << "Welcome adventurer, to His majeasty's DragonSlayer's Quest" << endl;
    cout << "His majeasty's sacred treasure has been stolen by the mythical dragon king from the northern mountains" << endl;
    cout << "He beeseaches you to venture into his deen to kill the dragon king and reclaim his sacred treasure that has been lost" << endl;
    cout << "The King will reward you handsomely should you complete this quest!" << endl;
    cout << "Now adventurer, state your name and let your name be inscribbed to the records" << endl;

    // Player's name input
    string playername, playerclass, FowardsOrRetreat;

    while (true) {
        cout << "Enter your name: ";
        cin >> playername;
        if(playername == "q" || playername == "Q"){
            cout << "Farewell Adventurer." << endl;
            break; // Exit the game loop
        }
        cout << "What is your class?" << endl << "(Choose from Warrior, Archer, or Thief)" << endl;
        cin >> playerclass;
        if (playerclass == "q" || playerclass == "Q") {//repeat this chunck for player's options
            cout << "Farewell Adventurer." << endl;
            break; // Exit the game loop
        }
        bool failcheck = true;
        while(failcheck == true){
            if(playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W"){
                playerclass = "Warrior";
                Weapon playerweapon("Sword", 5, WARRIOR);
                Character player(playername, "Human", 100, playerweapon);
                cout << endl << endl;
                cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
                cout << "You are given a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value " << endl << endl;
                failcheck = false;//not sure if i should use break instead
                //maybe replace playerclass with player.get_class_type() later?
            }
            else if(playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A"){
                playerclass = "Archer";
                Weapon playerweapon("Bow", 5, ARCHER);
                Character player(playername, "Human", 100, playerweapon);
                cout << endl << endl;
                cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
                cout << "You are given a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value " << endl << endl;                
                failcheck = false;

            }
            else if(playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T"){
                playerclass = "Thief";
                Weapon playerweapon("Dagger", 5, THIEF);
                Character player(playername, "Human", 100, playerweapon);
                cout << endl << endl;
                cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
                cout << "You are given a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value " << endl << endl;                
                failcheck = false;
            }
            else{
                cout << "Wrong class!"<< endl << "Choose your class" << endl;
                cin >> playerclass;
            }
        }
        cout << "You set off on your adventure..." << endl;
        cout << "You exit the castle walls and enter the plains, it is known that goblins and skeletons freqently roam this area" << endl;
        cout << "Press onwards or turn back now? (y to press on, n for retreat)" << endl;
        cin >> FowardsOrRetreat;
        if (FowardsOrRetreat == "n" || FowardsOrRetreat == "N") {//is not optimal but will do for now.. need to make it so it takes y/n only and loops question if wrong input
            cout << "Farewell Adventurer." << endl;//placeholder for now
            break; // Exit the game loop
        }
        else{
            cout << "Knowing the dangers, you press on..." << endl;
        }
    }
    return 0;
}