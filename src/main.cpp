#include <iostream>
using namespace std;

#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"
#include "../header/fight.h"
#include "../header/wolf.h"

void wait_for_user();

// TODO: hard code damage? or randomize
/*
    note: make sure to add new .cpp files to ~/src/CMakeLists.txt under add_library
    note: run tests with
     cmake . && make && ./bin/runAllTests
    note: run build with
     cmake . && make && ./bin/runBuild
    note: if want to see results but you're too lazy to write tests, use lazy main
     cmake . && make && ./bin/runLazyTests

*/

int main()
{
    /*since the player can choose when to quit, will we implement some sort of loop?
    or will we implement some sorta function that we pass in the input in for every action */
    Weapon playerweapon("", 0, WARRIOR);
    Character *player = nullptr;

    cout << " -------------------------------------------------------------------------------" << endl << endl;

    cout << endl
         << endl
         << "Welcome adventurer, to His majeasty's DragonSlayer's Quest" << endl;
    cout << "His majeasty's sacred treasure has been stolen by the mythical dragon king from the northern mountains" << endl;
    cout << "He beeseaches you to venture into his deen to kill the dragon king and reclaim his sacred treasure that has been lost" << endl;
    cout << "The King will reward you handsomely should you complete this quest!" << endl;
    cout << "Now adventurer, state your name and let your name be inscribbed to the records" << endl
         << endl;

    wait_for_user();

    // Player's name input
    string playername, playerclass, userchoice;

    cout << "Enter your name: ";
    cin >> playername;
    if (playername == "q" || playername == "Q")
    {
        cout << "Farewell unknown Adventurer." << endl;
        delete player;
        return 0; // Exit the game
    }

    cout << " -------------------------------------------------------------------------------" << endl << endl << endl;
    cout << endl
         << "Very well Adventurer " << playername << ", The guild under the king's authority has presented you with 3 classes" << endl;
    cout << "Please review each class and pick one of the 3 classes" << endl
         << endl;

    wait_for_user();
    cout << endl;

    cout << "------------------------------------------" << endl;
    cout << "1.WARRIOR - High base HP" << endl
         << "Physical attack - sword swing" << endl
         << "Special attack - Flame Strike (fire elemental damage skill: does small damage per turn for x turns)" << endl;
    cout << "2.ARCHER - Normal base HP" << endl
         << "Physical attack - shoot arrow" << endl
         << "Special attack - Wind Arrow (wind elemental damage skill: damage multiplier towards base attack)" << endl;
    cout << "3.THIEF - Low base HP" << endl
         << "Physical attack - stab" << endl
         << "Special attack - Mirage Step (water elemental evasive skill: dodge skill for 1-2 turns)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "What is your class?" << endl
         << "(Choose from Warrior, Archer, or Thief)" << endl
         << endl;

    cin >> playerclass;
    if (playerclass == "q" || playerclass == "Q")
    { // repeat this chunck for player's options
        cout << "Farewell Adventurer" << endl;
        delete player;
        return 0; // Exit the game
    }

    bool failcheck = true;
    while (failcheck == true)
    {
        if (playerclass == "Warrior" || playerclass == "warrior" || playerclass == "w" || playerclass == "W")
        {
            playerclass = "Warrior";
            playerweapon = Weapon("Sword", 5, WARRIOR);
            player = new Warrior(playername, "Human", 200, playerweapon);
            cout << endl
                 << endl;
            cout << "Welcome, " << player->get_race() << " " << playerclass << " " << player->get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player->get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl
                 << endl;

            failcheck = false;
        }
        else if (playerclass == "Archer" || playerclass == "archer" || playerclass == "a" || playerclass == "A")
        {
            playerclass = "Archer";
            playerweapon = Weapon("Bow", 5, ARCHER);
            player = new Archer(playername, "Human", 100, playerweapon);
            cout << endl
                 << endl;
            cout << "Welcome, " << player->get_race() << " " << playerclass << " " << player->get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player->get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl
                 << endl;
            failcheck = false; 
        }
        else if (playerclass == "Thief" || playerclass == "thief" || playerclass == "t" || playerclass == "T")
        {
            playerclass = "Thief";
            playerweapon = Weapon("Dagger", 5, THIEF);
            player = new Thief(playername, "Human", 75, playerweapon);
            cout << endl
                 << endl;
            cout << "Welcome, " << player->get_race() << " " << playerclass << " " << player->get_name() << " your name has been recorded" << endl;
            cout << "As a " << playerclass << ", Your base HP is " << player->get_health() << endl;
            cout << "The king's guild then presents you a " << playerweapon.name << ", it has " << playerweapon.damage << " attack value." << endl
                 << endl;
            failcheck = false;
        }
        else
        {
            cout << "Wrong class!" << endl
                 << "Choose your class" << endl;
            cin >> playerclass;
        }
    }

    wait_for_user();

    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

    cout << "You set off on your adventure..." << endl;
    cout << "You exit the castle walls and enter the plains, it is known that goblins and skeletons freqently roam this area" << endl;
    cout << "Press onwards or turn back now?" << endl
         << "> press anykey to press on" << endl
         << "> n/N or q/Q for retreat" << endl
         << endl;
    cin >> userchoice;
    if (userchoice == "n" || userchoice == "N" || userchoice == "q" || userchoice == "Q")
    {
        cout << "Farewell Adventurer." << endl; // placeholder for now
        delete player;
        return 0; // Exit the game
    }
    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
    userchoice = ""; // destructor for later push fowards or retreat
    cout << endl
         << "Knowing the dangers, you press on..." << endl; // placeholder
    cout << "Stepping into the field, you part the tall grass and plants to continue forth" << endl;
    cout << "You encounter a clearing where you encounter a goblin" << endl;

    wait_for_user();

    /*
    first battle goes here
    */

    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
    cout << "After a grueling battle, you emerge victorious" << endl;
    cout << "As you Catch your breath, you notice a fork in the road ahead..." << endl;
    cout << "Do you wish to continue through the fields or brave through the step cliffs towards the mountains?" << endl;
    cout << "> M for the mountain cliffs" << endl
         << "> F for fields" << endl
         << "> Q to retreat" << endl
         << endl;
    cin >> userchoice;
    if (userchoice == "f" || userchoice == "F")
    {
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        userchoice == "";
        cout << endl
             << "You decide to further venture into the fields" << endl;
        cout << "As you walk along the beaten path, the fields turn into a dark forest" << endl;
        cout << "The Next thing you know, night has befallen on you and you are feeling tired" << endl;
        cout << "you decide on whether to make camp for the night or push on in the dark" << endl;
        cout << "> press any key except W or Q to make camp and rest the night" << endl;
        cout << "> press W to continue your journey at night" << endl;
        cout << "> press Q to quit" << endl
             << endl;
        cin >> userchoice;
        if (userchoice == "W" || userchoice == "w")
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You decide to trek on in the middle of the night..." << endl;
            cout << "As you do, the forest is pitch black and you are unable to see anyfurther than whats directly infront of you or in your immediate surroundings." << endl;
            cout << "Suddenly you get amushed by a skeleton from the rear, and the next thing you know you fall to the ground bleeding out, paralyzed and unable to move a muscle" << endl;
            cout << "You turn around and you see a skeleton that is now looming over you, it's sword glowing dimmly in the dark as it kills you off" << endl;
            cout << "due to some magic imbedded in the sword, you now become a undead, cursed to wander the lands..." << endl;
            cout << "GAME OVER" << endl;
            delete player;
            return 0;
        }
        else if (userchoice == "Q" || userchoice == "q")
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;    
            userchoice = "";
            cout << "you have deserted the quest..." << endl
                 << "A bounty has been place on your head!" << endl;
            delete player;
            return 0;
        }
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        userchoice = "";
        cout << "You decide to rest the night..." << endl;
        cout << "You wake up the next morning feeling alert" << endl;
        cout << "feeling energetic you sense danger behind you as a skeleton approaches you from behind" << endl;
        cout << "> fight? (F)" << endl
             << "> flee(R)" << endl
             << "> Quit(Q)" << endl
             << endl;
        cin >> userchoice;
        if (userchoice == "F" || userchoice == "f")
        {
            userchoice = "";
            cout << " " << endl; // continue story
        }
        else if (userchoice == "R" || userchoice == "r")
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            cout << endl
                 << "Sparked by your fears of skeletons, you decide to flee" << endl;
            cout << "As you run through the thick forest, you fall into a boobytrap laid out by the hunters of a different party and become unable to move" << endl;
            cout << "You turn around and you see that same skeleton that approached you earlier is now looming over you, sword in hand as it kills you off" << endl;
            cout << "due to some magic imbedded in the sword, you now become a undead, cursed to wander the lands..." << endl;
            cout << "GAME OVER" << endl;
            userchoice = "";
            delete player;
            return 0; // game over
        }
        else if( userchoice == "Q" || userchoice == "q")
        {
            userchoice = "";
            cout << "Farewell Adventurer " << playername << endl;
            delete player;
            return 0;
        }
        else
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "Wrong input!" << endl;
            cout << "you have hesitated and was stabbed to death by skeleton" << endl;
            cout << "due to some magic imbedded in the sword, you now become a undead, cursed to wander the lands..." << endl;
            cout << "GAME OVER" << endl;
            delete player;
            return 0;
        }
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        /*
        skeleton fight goes here
        */
    
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        cout << "Traveling further deeper into the dark forest, You are exhausted after that battle" << endl;
        cout << "You turn the corner around the path and you spot a cave" << endl;
        cout << "caves are nice places to rest but they can also be hosts to dangerous animals too" << endl;
        cout << "knowing this, you decide to go into the cave to rest anyways" << endl;
        cout << "the inside of the cave looks like someone or something has been there, and theres a chest at the back wall" << endl;
        cout << "thinking that the chest isnt going to run off anywhere, you decide to rest first before you open the chest" << endl;
        wait_for_user();
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        cout << "While resting, you encounter a pack of wolves on their return trip from their hunt, and they look angry that" << endl;
        cout << "You have decided to make their home a resting spot" << endl;
        cout << "With your back against the cave wall, You have no choice but to engage in a fight head on" << endl;

        wait_for_user();

        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

        /*
        wolf fight goes here
        */
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        cout << "After a grueling battle, you emerge victorious as you finally get your rest" << endl;
        cout << "An hour later, you finally muster the strength to pull yourself together and decide on whether to open the chest or not" << endl;
        cout << "Open chest?" << endl
             << "> Yes (Y)" << endl
             << "> No (N)" << endl
             << "> Quit (Q)" << endl
             << endl;
        cin >> userchoice;
        if (userchoice == "Y" || userchoice == "y")
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You open the chest, and find a map inside." << endl;
            cout << "It leads to directions to the dragon's lair!" << endl;
            cout << "Proceed with the map's directions?" << endl;
            cout << "> Yes (Y)" << endl
                 << "> No (N)" << endl
                 << "> Quit (Q)" << endl
                 << endl;
            cin >> userchoice;
            if (userchoice == "Y" || userchoice == "y")
            {
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                userchoice = "";
                cout << "You continue down the cave's path, carefully following the directions." << endl;
                cout << "A strange smell permeates the area, so you rush ahead. Soon, you encounter a door. Open ?" << endl;
                cout << "> Yes (Y)" << endl
                     << "> No (N)" << endl
                     << endl;
                cin >> userchoice;
                if (userchoice == "n" || userchoice == "N")
                {
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "Leaving the door unopened, you succumb to the toxic fumes." << endl;
                    cout << "GAME OVER" << endl;
                    delete player;
                    return 0;
                }
                else if (userchoice == "Y" || userchoice == "y")
                {
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "you barge through the door and you are face to face with more monsters" << endl;
                    cout << "No where to go, you are quickly forced into battle" << endl;

                    wait_for_user();
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

                    /*
                    fight goes here
                    */

                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    cout << "Emerging victorious, a huge door now looms infront of you" << endl;
                    cout << "unsure whats behind the door, you take a peek through the tiny cracks in the door" << endl;
                    cout << "you quickly realize this door leads to the dragon king's deen as you spot the dragon king laying ontop of a mountian of gold." << endl;
                    cout << "Are you ready?" << endl;
                    cout << "> Yes(Y)" << endl
                         << "> No(N)" << endl
                         << "> Quit (Q)" << endl
                         << endl;
                    cin >> userchoice;
                    if (userchoice == "N" || userchoice == "n")
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        userchoice = "";
                        cout << "Faced with a almighty dragon, fear takes over you and you flee" << endl;
                        cout << "The dragon sensing that someone was at the door that wasnt his guards mocks you a you run away" << endl;
                        cout << "'HAHAHAHA COWARD!'" << endl;
                        cout << "GAME OVER" << endl;
                        delete player;
                        return 0;
                    }
                    else if (userchoice == "Y" || userchoice == "y")
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        cout << "you open the door, and suddenly a loud voice booms the room..." << endl;
                        cout << "'WHO DARES WAKE ME FROM MY SLUMBER'" << endl;
                    
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        /*
                        Dragon fight goes here
                        */
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        cout << "You have emerged victorious! With the defeat of the dragon king and the reclamation of His Majesty's sacred treasure from the depths of the northern mountains, the quest is fulfilled." << endl;
                        cout << "You return to the castle to a hero's welcome" << endl;
                        cout << "VICTORY" << endl;
                        delete player;
                        return 0;
                    }
                    else if( userchoice == "Q" || userchoice == "q")
                    {
                        userchoice = "";
                        cout << "Farewell Adventurer " << playername << endl;
                        delete player;
                        return 0;
                    }
                    else
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        cout << "Unsure what to do after seeing the dragon king, you dont flee nor fight" << endl;
                        cout << "However, with the dead dragon kings guard laying there, other guards have become alerted to your presense" << endl;
                        cout << "the next thing you know, you have become surrounded with both doors now locked" << endl;
                        cout << "you try your best to fight to stay alive, but their numbers are too much and you take a fatal blow" << endl;
                        cout << "Incapacitated, the dragon kings guards drag you to their king, and you become his lunch" << endl;
                        cout << "GAME OVER" << endl;
                        delete player;
                        return 0;
                    }
                }
                else if( userchoice == "Q" || userchoice == "q")
                {
                    userchoice = "";
                    cout << "Farewell Adventurer " << playername << endl;
                    delete player;
                    return 0;
                }
                else
                {
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "unsure what to do, you hesitate and succumb to the toxic fumes" << endl;
                    cout << "GAME OVER" << endl;
                    delete player;
                    return 0;
                }
            }
            else
            {
                // if(userchoice == "n" || userchoice == "N"){
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                userchoice = "";
                cout << "Dwelling too long on the contents of the map, you dont notice a dark shadowy figure sneaking up on you." << endl;
                cout << "the next thing you know, your on the floor bleeding out as you pass out" << endl;
                cout << "GAME OVER" << endl;
                delete player;
                return 0;
            }
        }
        else if (userchoice == "N" || userchoice == "n")
        { // chest prompt
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You decide against opening the chest, fearful of Mimics could posses unopened chests" << endl;
            cout << "You trek through the dark forest and soon there is a clearing." << endl;
            cout << "On the other side of the clearing, there is a small villave in the distanct" << endl;
            cout << "As you walk closer to the village, you see dark smoke rising from the village, it becomes apparent that the village is under attack" << endl;
            cout << "Go and assist the villagers? or turn the other way?" << endl;
            cout << "> Assist (A)" << endl
                 << "> Turn the other way(D)" << endl
                 << "> Quit (Q)" << endl
                 << endl;
            cin >> userchoice;
            if (userchoice == "D" || userchoice == "d")
            {
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                userchoice = "";
                cout << "Tring to turn the other way, a villager spots you fleeing and thinks you are the one behind the attack" << endl;
                cout << "The scout relays information to other villagers and be have been branded a traitor to the kingdom" << endl;
                cout << "Unbeingknownst to you, a hunting party has been set out to hunt you down" << endl;
                cout << "An hour later after you flee the burning village, you are ambushed by the vengeful villagers and die" << endl;
                cout << "GAME OVER" << endl;
                delete player;
                return 0;
            }
            else if (userchoice == "A" || userchoice == "a")
            {
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                userchoice = "";
                cout << "You decide on helping the villagers..." << endl
                     << "You draw your " << playerweapon.name << " and rush to the villagers aid" << endl;
                cout << "Upon entering the village limits, you are face to face with a skeleton knight" << endl;
                cout << "The villagers take note that you are not the one responsible for the attack on their home and have come to aid you in the ensuing battle." << endl;

                wait_for_user();
                
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                /*
                skeleton battle goes here (knight?)
                */

                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                cout << "Emerging victorious, the villagers welcome you with open arms" << endl;
                cout << "For your reward for helping the villagers, they offer you to rest before you continue on your quest" << endl;
                cout << "Thankful for the reward you decide to spend the night patching up your wounds" << endl
                     << endl;

                wait_for_user();

                // set player health to 100% OR +50% to current hp if makeing back to 100% is too OP

                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                cout << "While resting, you tell the villagers about your quest to slay the dragon king and return the king's sacred treasure" << endl;
                cout << "The name of the Dragon King brings hushes the second you say the name dragon king" << endl;
                cout << "it becomes apparent that this dragon king as been tormenting the local village for quite some time too" << endl;
                cout << "Eager to help you, the villagers present you a map to where the dragon king resides" << endl;
                cout << "shortly after the villagers knights return to their posts, and the others continue tending to the wounded as you make your way to your assigned cabin to rest the night" << endl
                     << endl;

                wait_for_user();

                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                cout << "The next morning, you set off to a hero's departure" << endl;
                cout << "While enroute, to find that the map has avioded all the traps the villagers have placed leading up to the draon's deen." << endl;
                cout << "Finally you come across a cave, where another skeleton knight stands guard" << endl;
                cout << "Fight the skeleton knight guarding the entrance?" << endl;
                cout << "> fight (F)" << endl
                     << "> Flee (R)" << endl
                     << "> Quit (Q)" << endl
                     << endl;
                cin >> userchoice;
                if (userchoice == "R" || userchoice == "r")
                {
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "decidng that the knight was well to guarded you decide to turn the other way and venture off the marked path on the map." << endl;
                    cout << "You fall into a unmarked trap and become immobilzied" << endl;
                    cout << "Hearing the noise you made when you activated the trap, the patrolling knights converge on your location to finish you off" << endl;
                    cout << "unable to move, you are surrounded by enemy knights on all sides as you are killed with no mercy" << endl;
                    cout << "GAME OVER" << endl;
                    delete player;
                    return 0;
                }
                else if (userchoice == "F" || userchoice == "f")
                {
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "You draw your " << playerweapon.name << " and prepare for battle" << endl;

                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    /*
                    fight goes here
                    */
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

                    cout << "Emerging victorious, a huge door now looms infront of you" << endl;
                    cout << "unsure whats behind the door, you take a peek through the tiny cracks in the door" << endl;
                    cout << "you quickly realize this door leads to the dragon king's deen as you spot the dragon king laying ontop of a mountian of gold." << endl;
                    cout << "Are you ready?" << endl;
                    cout << "> Yes(Y)" << endl
                         << "> No(N)" << endl
                         << endl;
                    cin >> userchoice;
                    if (userchoice == "N" || userchoice == "n")
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        userchoice = "";
                        cout << "Faced with a almighty dragon, fear takes over you and you flee" << endl;
                        cout << "The dragon sensing that someone was at the door that wasnt his guards mocks you a you run away" << endl;
                        cout << "'HAHAHAHA COWARD!'" << endl;
                        cout << "GAME OVER" << endl;
                        delete player;
                        return 0;
                    }
                    else if (userchoice == "Y" || userchoice == "y")
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        userchoice = "";
                        cout << "you open the door, and suddenly a loud voice booms the room..." << endl;
                        cout << "'WHO DARES WAKE ME FROM MY SLUMBER'" << endl;

                        
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

                        /*
                        Dragon fight goes here
                        */
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

                        cout << "You have emerged victorious! With the defeat of the dragon king and the reclamation of His Majesty's sacred treasure from the depths of the northern mountains, the quest is fulfilled." << endl;
                        cout << "You return to the castle to a hero's welcome" << endl;
                        cout << "VICTORY" << endl;
                        delete player;
                        return 0;
                    }
                    else if( userchoice == "Q" || userchoice == "q")
                    {
                        userchoice = "";
                        cout << "Farewell Adventurer " << playername << endl;
                        delete player;
                        return 0;
                    }
                    else
                    {
                        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                        userchoice = "";
                        cout << "Unsure what to do after seeing the dragon king, you dont flee nor fight" << endl;
                        cout << "However, with the dead dragon kings guard laying there, other guards have become alerted to your presense" << endl;
                        cout << "the next thing you know, you have become surrounded with both doors now locked" << endl;
                        cout << "you try your best to fight to stay alive, but their numbers are too much and you take a fatal blow" << endl;
                        cout << "Incapacitated, the dragon kings guards drag you to their king, and you become his lunch" << endl;
                        cout << "GAME OVER" << endl;
                        delete player;
                        return 0;
                    }
                }
                else if( userchoice == "Q" || userchoice == "q")
                {
                    userchoice = "";
                    cout << "Farewell Adventurer " << playername << endl;
                    delete player;
                    return 0;
                }
                else
                {//knight fight at dragon entrance
                    cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                    userchoice = "";
                    cout << "unsure what to do, you hesitate and other patroling skeleton guards ambush you from behind" << endl;
                    cout << "GAME OVER" << endl;
                    delete player;
                    return 0;
                }
            }
            else if( userchoice == "Q" || userchoice == "q")
            {
                userchoice = "";
                cout << "Farewell Adventurer " << playername << endl;
                delete player;
                return 0;
            }
            else
            { // wrong key for village scene
                cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
                userchoice = "";
                cout << "Hesitating for too long, you get ambushed by a hungry vengeful lone wolf" << endl;
                cout << "You try to fend it off as best as you can, but this lone wolf has nothing else left to lose and comes at you relentlessly." << endl;
                cout << "You get overpowered by the wolf and become it's dinner" << endl;
                cout << "GAME OVER" << endl;
                delete player;
                return 0;
            }
            delete player;
            return 0;
        }
        else if( userchoice == "Q" || userchoice == "q")//chest scene
        {
            userchoice = "";
            cout << "Farewell Adventurer " << playername << endl;
            delete player;
            return 0;
        }
        else{
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You carelessly reapproach the chest, tripping on a unseen wire and triggering a hidden boobytrap" << endl;
            cout << "Spikes fly in all directions as you fall on your face as you try to take cover" << endl;
            cout << "Because of the activated boobytrap, the cave you are in collapses, burying you alive with it" << endl;
            cout << "GAME OVER" << endl;

            delete player;
            return 0;
        }
    }
    else if (userchoice == "M" || userchoice == "m")
    { // path prompt
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        userchoice = "";
        cout << "You choose to brave the treacherous mountain pass, hoping for a faster route." << endl;
        cout << "However it is found to be a more treacherous as the entire right flank of the path is a bottomless fall" << endl;
        cout << "As you make your way up the mountain, the dragon king flies right by you creating hurrticane winds" << endl;
        cout << "> Grab onto something (S)" << endl
             << "> Stand your ground as best you can (W)" << endl
             << "> Quit (Q)" << endl;
        cin >> userchoice;
        if (userchoice == "W" || userchoice == "w")
        { // cliff side prompt
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You try to stand your ground, but the winds are too strong as you are thrown down the bottomless cliff" << endl;
            cout << "You fall for a agnozing 40 seconds before you hit the ground and die" << endl;
            cout << "GAME OVER" << endl;
            delete player;
            return 0;
        }
        else if (userchoice == "S" || userchoice == "s")
        { // cliffside stand
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            cout << "You stand your ground, however the dragon notices you, and you are forced to fight for your life" << endl;
            /*
            set player HP to 30% of current or base HP
            this fight is meant to be a impossible fight
            */
            cout << "Faced with no other choice, you draw your " << playerweapon.name << " and commence battle" << endl;

            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;

            /*
            impossible dragon fight goes here --> GAME OVER
            */

            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            cout << "Faced with impossible odds you fight your hardest but your efforts are in vain" << endl;
            cout << "The dragon king has too much free rein over you and your attacks do not even faze him" << endl;
            cout << "After your latest move, it reads yous like a book and prepares a devastating breath attack" << endl;
            wait_for_user();
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            cout << "With nowhere to run, nowhere to hide, you close your eyes as you brace for the inevitable" << endl;
            cout << "The dragon king unleashes it's devastating breath attack, and you feel nothing but warmth as you burn away to ashes..." << endl;
            cout << endl << "GAME OVER" << endl;
            delete player;
            return 0;
        }
        else if( userchoice == "Q" || userchoice == "q")
        {//dragon wind scene
            userchoice = "";
            cout << "Farewell Adventurer " << playername << endl;
            delete player;
            return 0;
        }
        else
        {
            cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
            userchoice = "";
            cout << "You hesistate, and the strong winds push you off the mountain" << endl;
            cout << "You fall for a agnozing 40 seconds before you hit the ground and die" << endl;
            cout << "GAME OVER" << endl;
            delete player;
            return 0;
        }
        delete player;
        return 0;
    }
    else if (userchoice == "Q" || userchoice == "q")
    {//path scene (mountain, forest)
        userchoice ="";
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        cout << "You decide your life is more important than the quest from the king, so you go AWOL..." << endl;
        cout << "Several years past, and you settle down on a lonely cabin. In hiding and living out your days as a hermit as you have been branded a traitor and a coward." << endl;
        cout << endl << "GAME OVER" << endl;
        delete player;
        return 0;
    }
    else{//path scene (mt or forest, wrong input)
        userchoice = "";
        cout << endl << " -------------------------------------------------------------------------------" << endl << endl << endl << endl;
        cout << "Unsure which path to take, you open a your map and study your surroundings" << endl;
        cout << "Unbeknownst to you, while you are trying to figure out your bearings, you are surrounded by an army of goblins, each of them angry that you have slain one of their brethren" << endl;
        cout << "it is a 200 vs 1 fight, a near impossible odds as a monster of this count is on par with a monster raid" << endl;
        cout << "You try to run away put there is a seemingly endless army in whichever direction you take" << endl;
        cout << "Faced with no other options you charge head long into battle, only to be squashed in a stampede of goblins" << endl;
        cout << endl << endl << "GAME OVER" << endl;
        delete player;
        return 0;
    }
    delete player;
    return 0;
}

void wait_for_user()
{
    cout << "\nPress any key to continue...\n";
    string s;
    system("read"); // only works on linux/mac
    // system("pause"); // only works on windows
}