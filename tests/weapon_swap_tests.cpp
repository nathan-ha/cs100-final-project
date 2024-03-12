#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/archer.h"
#include "../header/warrior.h"
#include "../header/thief.h"
#include "../header/weapon_inv.h"
#include <sstream>

TEST(WeaponDropTest, WarriorWeaponDrop) {
    Warrior player("Alice", "Human", 100, Weapon("Sword", 15, WARRIOR));
    std::istringstream iss("Y\n"); // Simulating 'Y' as user input to confirm weapon switch
    std::ostringstream oss;
    for (int i = 0; i < 500; i++)
    {
        weapon_drop(player, iss, oss);
        EXPECT_TRUE(player.get_weapon().name == "Big Axe" || player.get_weapon().name == "Slashy Sword" || player.get_weapon().name == "Lance" || player.get_weapon().name == "Mace");
    }
}

TEST(WeaponDropTest, ArcherWeaponDrop) {
    Archer player("Bob", "Elf", 100, Weapon("Bow", 20, ARCHER));
    std::istringstream iss("Y\n"); // Simulating 'Y' as user input to confirm weapon switch
    std::ostringstream oss;
    for (int i = 0; i < 500; i++)
    {
        weapon_drop(player, iss, oss);
        EXPECT_TRUE(player.get_weapon().name == "Power Bow" || player.get_weapon().name == "Punch Bow" || player.get_weapon().name == "Shootey Bow" || player.get_weapon().name == "Flame Bow");
    }
}

TEST(WeaponDropTest, ThiefWeaponDrop) {
    Thief player("Charlie", "Human", 100, Weapon("Dagger", 25, THIEF));
    std::istringstream iss("Y\n"); // Simulating 'Y' as user input to confirm weapon switch
    std::ostringstream oss;
    for (int i = 0; i < 500; i++)
    {
        weapon_drop(player, iss, oss);
        EXPECT_TRUE(player.get_weapon().name == "Big Thumbtack" || player.get_weapon().name == "Stealey Sword" || player.get_weapon().name == "Bandit's Dagger" || player.get_weapon().name == "Caltrops");
    }
}