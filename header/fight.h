#pragma once

#include <vector>
#include <iostream>
#include "character.h"
#include "archer.h"
#include "warrior.h"
#include "thief.h"
#include "goblin.h"
#include "skeleton.h"
#include "wolf.h"



// yeah just #include this file into main

// return true when enemy was defeated, false for flee (and die)
bool fight(Character& player, Character& enemy, std::istream& input = std::cin, std::ostream& output = std::cout)
// bool fight(Character& player, Character &enemy)
{
    output << enemy.get_name() + ", the " + enemy.get_race() + " has appeared!\n"
         << "The enemy has " << enemy.get_health() << " health\n";

    while (enemy.get_health() > 0)
    {
        // player attacks first
        char choice = 0;
        bool is_invulnerable = false; // only used by thief
        output << "Attack (a)\n"
             << "Special Attack (s)\n"
             << "Use item (i)\n"
             << "Flee (f)\n";

        input >> choice;
        choice = tolower(choice);


        // Player turn
        if (choice == 'f') // flee
        {
            output << "You choose to flee! As you turn around in a panic, you trip on a rock.\n";
            output << "Your enemy takes advantage of this, and deals a fatal blow!\n";
            output << "You Died.\n";
            return false;
        }

        // different classes have different movesets
        if (player.get_class_type() == WARRIOR)
        {
            Warrior& hero = dynamic_cast<Warrior&>(player);
            if (choice == 'a')
            {
                output << "You swing your sword!\n";
                hero.swing_sword(enemy);
            }
            else if (choice == 's')
            {
                output << "You use Flame Strike!\n";
                hero.flame_strike(enemy);
            }
            else if (choice == 'i')
            {
                if (hero.get_bomb_count() <= 0)
                {
                    output << "You ran out of bombs!\n";
                }
                else
                {
                    output << "You throw your bomb!\n";
                    hero.throw_bomb(enemy);
                    output << "You have " << hero.get_bomb_count() << " bombs left.\n";
                }
            }
            else
            {
                output << "Invalid input. As punishment, you lose your turn!\n"; // lazy cop out because i'm too lazy to jump back up to the start
            }
        }
        else if (player.get_class_type() == THIEF)
        {
            Thief& hero = dynamic_cast<Thief&>(player);
            if (choice == 'a')
            {
                output << "You stab the enemy!\n";
                hero.stab(enemy);
            }
            else if (choice == 's')
            {
                output << "You use Mirage Step!\n";
                is_invulnerable = true;
            }
            else if (choice == 'i')
            {
                if (hero.get_throwing_knife_count() <= 0)
                {
                    output << "You're out of knives!\n";
                }
                else
                {
                    output << "You throw your knife!\n";
                    hero.throw_knife(enemy);
                    output << "You have " << hero.get_throwing_knife_count() << " throwing knives left.\n";
                }
            }
            else
            {
                output << "Invalid input. As punishment, you lose your turn!\n";
            }

        }
        else if (player.get_class_type() == ARCHER)
        {
            // TODO: revamp archer class if have time
            Archer& hero = dynamic_cast<Archer&>(player);
            if (choice == 'a')
            {
                output << "You smack the enemy with your bow!\n";
                hero.bow_smack(enemy);
            }
            else if (choice == 's')
            {
                if (hero.get_arrow_count() <= 5)
                {
                    output << "You don't have enough arrows!\n";
                }
                else{
                    output << "You use wind arrow strike!\n";
                    hero.wind_arrow_strike(enemy);
                }
            }
            else if (choice == 'i')
            {
                if (hero.get_arrow_count() <= 0)
                {
                    output << "You're out of arrows!\n";
                }
                else
                {
                    output << "You shoot an arrow at the enemy!\n";
                    hero.shoot_arrow(enemy);
                    output << "You have " << hero.get_arrow_count() << " arrows left.\n";
                }
            }
            else
            {
                output << "Invalid input. As punishment, you lose your turn!\n";
            }
        }
        else
        {
            throw "fight.h: invalid player class";
        }

        if (player.get_health() <= 0) 
        {
            output << "After a hard fought battle, You died!P\n";
            return false;
        }
        
        if (enemy.get_health() <= 0)
        {
            output << "Congratulations! You defeated the " << enemy.get_race() << '\n';
            return true;
        }


        output << "The enemy is now at " << enemy.get_health() << " health\n";

        // Enemy turn

        if (is_invulnerable)
        {
            output << "You manage to dodge the " << enemy.get_race() << "'s attack.\n";
        }
        else
        {
            output << "The " << enemy.get_race() << " attacks you!\n";
            enemy.attack(player);

            if (enemy.get_race() == "Wolf") {
                output<< "The " << enemy.get_race() << " attacks you again!\n";
                enemy.attack(player);
            }

            output << "You are now at " << player.get_health() << " health!\n";
        }

    }

    return false;
}