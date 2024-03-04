#pragma once

#include <vector>
#include <iostream>
#include "character.h"
#include "archer.h"
#include "warrior.h"
#include "thief.h"
#include "goblin.h"
#include "skeleton.h"

using std::vector;
using std::cout;
using std::cin;

// yeah just #include this file into main

// return true when enemy was defeated, false for flee
bool fight(Character& player, Character &enemy)
{
    cout << "A wild " + enemy.get_race() + " appeared!\n"
         << "The enemy has " << enemy.get_health() << " health\n";

    while (enemy.get_health() > 0)
    {
        // player attacks first
        char choice = 0;
        bool is_invulnerable = false; // only used by thief
        cout << "Attack (a)\n"
             << "Special Attack (s)\n"
             << "Use item (i)\n"
             << "Flee (f)\n";

        cin >> choice;
        choice = tolower(choice);


        // Player turn
        if (choice == 'f')
        {
            cout << "You choose to flee! Im disappointed\n";
            return false;
        }

        // different classes have different movesets
        if (player.get_class_type() == WARRIOR)
        {
            Warrior& hero = dynamic_cast<Warrior&>(player);
            if (choice == 'a')
            {
                cout << "You swing your sword!\n";
                hero.swing_sword(enemy);
            }
            else if (choice == 's')
            {
                cout << "You use Flame Strike!\n";
                hero.flame_strike(enemy);
            }
            else if (choice == 'i')
            {
                if (hero.get_bomb_count() <= 0)
                {
                    cout << "You ran out of bombs!\n";
                }
                else
                {
                    cout << "You throw your bomb!\n";
                    hero.throw_bomb(enemy);
                    cout << "You have " << hero.get_bomb_count() << " bombs left.\n";
                }
            }
            else
            {
                cout << "Invalid input. As punishment, you lose your turn!\n"; // lazy cop out because i'm too lazy to jump back up to the start
            }
        }
        else if (player.get_class_type() == THIEF)
        {
            Thief& hero = dynamic_cast<Thief&>(player);
            if (choice == 'a')
            {
                cout << "You stab the enemy!\n";
                hero.stab(enemy);
            }
            else if (choice == 's')
            {
                cout << "You use Mirage Step!\n";
                is_invulnerable = true;
            }
            else if (choice == 'i')
            {
                if (hero.get_throwing_knife_count() <= 0)
                {
                    cout << "You're out of knives!\n";
                }
                else
                {
                    cout << "You throw your knife!\n";
                    hero.throw_knife(enemy);
                    cout << "You have " << hero.get_throwing_knife_count() << " throwing knives left.\n";
                }
            }
            else
            {
                cout << "Invalid input. As punishment, you lose your turn!\n";
            }

        }
        else if (player.get_class_type() == ARCHER)
        {
            // TODO: revamp archer class if have time
            Archer& hero = dynamic_cast<Archer&>(player);
            if (choice == 'a')
            {
                cout << "You smack the enemy with your bow!\n";
                hero.bow_smack(enemy);
            }
            else if (choice == 's')
            {
                if (hero.get_arrow_count() <= 5)
                {
                    cout << "You don't have enough arrows!\n";
                }
                else{
                    cout << "You use wind arrow strike!\n";
                    hero.wind_arrow_strike(enemy);
                }
            }
            else if (choice == 'i')
            {
                if (hero.get_arrow_count() <= 0)
                {
                    cout << "You're out of arrows!\n";
                }
                else
                {
                    cout << "You shoot an arrow at the enemy!\n";
                    hero.shoot_arrow(enemy);
                    cout << "You have " << hero.get_arrow_count() << " arrows left.\n";
                }
            }
            else
            {
                cout << "Invalid input. As punishment, you lose your turn!\n";
            }
        }
        else
        {
            throw "fight.h: invalid player class";
        }

        if (enemy.get_health() <= 0)
        {
            cout << "Congratulations! You defeated the " << enemy.get_race() << '\n';
            return true;
        }

        cout << "The enemy is now at " << enemy.get_health() << " health\n";

        // Enemy turn

        if (is_invulnerable)
        {
            cout << "You manage to dodge the " << enemy.get_race() << "'s attack.\n";
        }
        else
        {
            cout << "The " << enemy.get_race() << " attacks you!\n";
            enemy.attack(player);
            cout << "You are now at " << player.get_health() << " health!\n";
        }

    }

    return false;
}