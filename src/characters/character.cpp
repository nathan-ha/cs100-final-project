#include "../../header/character.h"

Character::Character(const string& name, const string& race, int health, const Weapon& current_weapon)
    : name(name), race(race), health(health), current_weapon(current_weapon)
{
}

string Character::get_name(){
    return name;
}

void Character::set_name(const string& new_name) {
    name = new_name;
}

string Character::get_race() {
    return race;
}

void Character::set_race(const string& new_race) {
    race = new_race;
}


int Character::get_health() {
    return health;
}

void Character::set_health(int new_health) {
    health = new_health;
}

character_class Character::get_class_type() {
    return current_weapon.class_type;
}

