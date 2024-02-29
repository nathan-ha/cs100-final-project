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
    cout << "Now adventurer, state your name and let your name be inscribbed to the records" << endl << endl;

    // Player's name input
    string playername, playerclass, FowardsOrRetreat;

    cout << "Enter your name: ";
    cin >> playername;
    if(playername == "q" || playername == "Q"){
        cout << "Farewell unknown Adventurer." << endl;
        return 0; // Exit the game loop
    }
    
    cout << endl << "Very well Adventurer " << playername << ", The guild under the king's authority has presented you with 3 classes" << endl;
    cout << "Please review each class and pick one of the 3 classes" << endl << endl;

    cout << "------------------------------------------" << endl;
    cout << "1.WARRIOR - High base HP" << endl << "Physical attack - sword swing" << endl << "Special attack - Flame Strike (fire elemental damage skill: does small damage per turn for x turns)" << endl;
    cout << "2.ARCHER - Normal base HP" << endl << "Physical attack - shoot arrow" << endl << "Special attack - Wind Arrow (wind elemental damage skill: damage multiplier towards base attack)" << endl;
    cout << "3.THIEF - Low base HP" << endl << "Physical attack - stab" << endl << "Special attack - Mirage Step (water elemental evasive skill: dodge skill for 1-2 turns)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "What is your class?" << endl << "(Choose from Warrior, Archer, or Thief)" << endl << endl;

    cin >> playerclass;
    if (playerclass == "q" || playerclass == "Q") {//repeat this chunck for player's options
        cout << "Farewell Adventurer" << endl;
        return 0; // Exit the game loop
    }
    bool failcheck = true;
    while(failcheck == true){
        if(playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W"){
            playerclass = "Warrior";
            Weapon playerweapon("Sword", 5, WARRIOR);
            Character player(playername, "Human", 200, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;//not sure if i should use break instead
            //maybe replace playerclass with player.get_class_type() later?
        }
        else if(playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A"){
            playerclass = "Archer";
            Weapon playerweapon("Bow", 5, ARCHER);
            Character player(playername, "Human", 100, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;

        }
        else if(playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T"){
            playerclass = "Thief";
            Weapon playerweapon("Dagger", 5, THIEF);
            Character player(playername, "Human", 75, playerweapon);
            cout << endl << endl;
            cout << "Welcome, " << player.get_race() << " " << playerclass << " " << player.get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player.get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl << endl;
            failcheck = false;
        }
        else{
            cout << "Wrong class!"<< endl << "Choose your class" << endl;
            cin >> playerclass;
        }
    }
    cout << "You set off on your adventure..." << endl;
    cout << "You exit the castle walls and enter the plains, it is known that goblins and skeletons freqently roam this area" << endl;
    cout << "Press onwards or turn back now? (y to press on, n/N or q/Q for retreat)" << endl;
    cin >> FowardsOrRetreat;
    if (FowardsOrRetreat == "n" || FowardsOrRetreat == "N" || FowardsOrRetreat == "q" || FowardsOrRetreat == "Q") {
        cout << "Farewell Adventurer." << endl;//placeholder for now
        return 0; // Exit the game loop
    }
    else{
        cout << "Knowing the dangers, you press on..." << endl;//placeholder
        /*
        first battle goes here
        */
    }
return 0;
}