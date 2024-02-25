#pragma once
#include <string>
using std::string;

enum character_class
{
    Thief,
    Warrior,
    Archer,
    Enemy
};

struct Weapon
{
    string name;
    int damage;
    character_class class_type;
    Weapon(const string& name, int damage, character_class class_type) : name(name), damage(damage), class_type(class_type) {}
};

class Character
{
protected:
    string name;
    string race;
    int health;
    Weapon current_weapon;

public:
    Character(const string& name, const string& race, int health, const Weapon& current_weapon);

    string get_name();
    void set_name(const string& new_name);

    string get_race();
    void set_race(const string& new_race);

    int get_health();
    void set_health(int new_health);

    void run_away();
    character_class get_class_type();

};