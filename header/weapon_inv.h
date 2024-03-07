#pragma once

#include <vector>
#include <iostream>
#include "character.h"
#include "archer.h"
#include "warrior.h"
#include "thief.h"

using namespace std;

// #include me uwu !

void weapon_drop_rate(Character &player) //use
{ //40% chance of weapon dropped
    if(weapon_rate() < 40){

        weapon_drop(player);
    }
}

int weapon_rate()
{

    int choice = rand() % 100;
    return choice;
}

void weapon_drop(Character &player)
{
    string input;

    Weapon axe("Big Axe", 15, WARRIOR);
    Weapon slashy_sword("Slashy Sword", 20, WARRIOR);
    Weapon lance("Lance", 30, WARRIOR);
    Weapon mace("Mace", 31, WARRIOR);

    Weapon power_bow("Power Bow", 15, ARCHER);
    Weapon punch_bow("Punch Bow", 20, ARCHER);
    Weapon shootey_bow("Shootey Bow", 30, ARCHER);
    Weapon flame_bow("Flame Bow", 35, ARCHER);

    Weapon big_tack("Big Thumbtack", 20, THIEF);
    Weapon stealey_sword("Stealey Sword", 25, THIEF);
    Weapon bandit_dagger("Bandit's Dagger", 30, THIEF);
    Weapon caltrops("Caltrops", 35, THIEF);

    cout << "Replace " << player.get_weapon().name << "(" << player.get_weapon().damage << " damage)? Press Y to confirm." << endl;

        if (weapon_rate() < 30)
        {
            if (player.get_class_type() == WARRIOR)
            {
                Warrior &hero = dynamic_cast<Warrior &>(player);
                cout << "New weapon: BIG AXE (15 dmg)"<<endl;
                cin>>input;

                if (input == "Y" || input == "y"){
                    hero.set_weapon(axe);
                    cout << "Weapon switched to " << hero.get_weapon().name;
                }
                else{
                    cout << "Weapon remains "<<hero.get_weapon().name;
                }
            
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            cout << "New weapon: POWER BOW (15 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(power_bow);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }

        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            cout << "New weapon: BIG THUMBTACK (20 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(big_tack);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
    }
    else if (weapon_rate() < 50)
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            cout << "New weapon: SLASHY SWORD (20 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(slashy_sword);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            cout << "New weapon: PUNCH BOW (20 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(punch_bow);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            cout << "New weapon: STEALEY SWORD (20 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(stealey_sword);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
    }
    else if (weapon_rate() < 85)
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            cout << "New weapon: LANCE (30 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(lance);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
         
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            cout << "New weapon: SHOOTEY BOW (30 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(shootey_bow);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }

        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            cout << "New weapon: BANDIT's DAGGER (30 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(bandit_dagger);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
           
        }
    }
    else
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            cout << "New weapon: MACE (31 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(mace);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            cout << "New weapon: FLAME BOW (35 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(flame_bow);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            cout << "New weapon: CALTROPS (35 dmg)" << endl;
            cin >> input;

            if (input == "Y" || input == "y")
            {
                hero.set_weapon(caltrops);
                cout << "Weapon switched to " << hero.get_weapon().name;
            }
            else
            {
                cout << "Weapon remains " << hero.get_weapon().name;
            }
        }
    }
    }
