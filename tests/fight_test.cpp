#include <gtest/gtest.h>
#include <sstream>
#include "../header/fight.h"
#include "../header/archer.h"
#include "../header/warrior.h"
#include "../header/thief.h"
#include "../header/goblin.h"
#include "../header/skeleton.h"
#include "../header/wolf.h"

// Test when player defeats the enemy
TEST(FightTest, WarriorDefeatsEnemy) {
    Warrior player("Alice", "Human", 100, Weapon("Sword", 15, WARRIOR));
    Goblin enemy("Goblin", "Monster", 1000, Weapon("Club", 0, ENEMY));
    string input;
    for (int i = 0; i < 100; i++) {
        input += "a\n";
        input += "s\n";
        input += "i\n";
    }
    std::istringstream iss(input); // spam attacks
    std::ostringstream oss;
    bool result = fight(player, enemy, iss, oss);
    EXPECT_TRUE(result);
    std::string fight_log = oss.str();
    EXPECT_TRUE(fight_log.find("You swing your sword!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You use Flame Strike!\n") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You throw your bomb!\n") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You ran out of bombs!\n") != std::string::npos && player.get_bomb_count() <= 0);
    EXPECT_GT(player.get_health(), 0);
}

// Test when player flees from the fight
TEST(FightTest, PlayerFlees) {
    Archer player("Bob", "Elf", 80, Weapon("Bow", 20, ARCHER));
    Skeleton enemy("Skeleton", "Undead", 60, Weapon("Sword", 12, ENEMY));
    std::istringstream iss("f\n"); // Simulating 'f' as input
    std::ostringstream oss;
    bool result = fight(player, enemy, iss, oss);
    EXPECT_FALSE(result);
    EXPECT_GT(player.get_health(), 0); // Player should not die even if they flee
    std::string fight_log = oss.str();
    EXPECT_TRUE(fight_log.find("You choose to flee! Im disappointed") != std::string::npos);
}