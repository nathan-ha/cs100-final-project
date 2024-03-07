// rand generate based on char class, if archer gen bow weapons,
#pragma once

#include <vector>
#include <iostream>
#include "character.h"
#include "archer.h"
#include "warrior.h"
#include "thief.h"

using namespace std;

// #include me uwu !

void weapon_drop_rate(Character &player)
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
{//addd dialogue and weapon choice y/n
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

    if (weapon_rate() < 30)
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            hero.set_weapon(axe);
            hero.get_weapon();
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            hero.set_weapon(power_bow);
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            hero.set_weapon(big_tack);
        }
    }
    else if (weapon_rate() < 50)
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            hero.set_weapon(slashy_sword);
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            hero.set_weapon(punch_bow);
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            hero.set_weapon(stealey_sword);
        }
    }
    else if (weapon_rate() < 85)
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            hero.set_weapon(lance);
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            hero.set_weapon(shootey_bow);
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            hero.set_weapon(bandit_dagger);
        }
    }
    else
    {
        if (player.get_class_type() == WARRIOR)
        {
            Warrior &hero = dynamic_cast<Warrior &>(player);
            hero.set_weapon(mace);
        }
        if (player.get_class_type() == ARCHER)
        {
            Archer &hero = dynamic_cast<Archer &>(player);
            hero.set_weapon(flame_bow);
        }
        if (player.get_class_type() == THIEF)
        {
            Thief &hero = dynamic_cast<Thief &>(player);
            hero.set_weapon(caltrops);
        }
    }
}
