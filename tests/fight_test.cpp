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

TEST(FightTest, ArcherDefeatsGoblin) {
    Archer player("Alice", "Elf", 100, Weapon("Bow", 10, ARCHER));
    player.set_arrow_count(8);
    Goblin enemy("Gobta", "Goblin", 1000, Weapon("Sword", 0, ENEMY));
    std::string input;
    for (int i = 0; i < 500; i++) {
        input += "a\n"; // Attack
        input += "s\n"; // Special Attack
        input += "i\n"; // Use item
    }
    std::istringstream iss(input);
    std::ostringstream oss;
    bool result = fight(player, enemy, iss, oss);
    EXPECT_TRUE(result);
    std::string fight_log = oss.str();
    EXPECT_TRUE(fight_log.find("You smack the enemy with your bow!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You use wind arrow strike!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You're out of arrows!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You don't have enough arrows!") != std::string::npos);
    EXPECT_LT(player.get_arrow_count(), 1);
    EXPECT_TRUE(fight_log.find("You shoot an arrow at the enemy!") != std::string::npos);
    EXPECT_GT(player.get_health(), 0);
}

TEST(FightTest, ThiefDefeatsWolf) {
    Thief player("Eve", "Human", 80, Weapon("Dagger", 5, THIEF));
    Wolf enemy("Wolf", "Animal", 1000, Weapon("Claws", 0, ENEMY));
    std::string input;
    for (int i = 0; i < 500; ++i) {
        input += "a\n"; // Attack
        input += "s\n"; // Special Attack
        input += "i\n"; // Use item
    }
    std::istringstream iss(input); 
    std::ostringstream oss; 
    bool result = fight(player, enemy, iss, oss);
    EXPECT_TRUE(result); // Thief should defeat the wolf
    EXPECT_GT(player.get_health(), 0); // Player should survive the fight
    std::string fight_log = oss.str();
    EXPECT_TRUE(fight_log.find("You stab the enemy!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You use Mirage Step!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You throw your knife!") != std::string::npos);
    EXPECT_TRUE(fight_log.find("You're out of knives!") != std::string::npos);
    EXPECT_LT(player.get_throwing_knife_count(), 1);
}

TEST(FightTest, PlayerDiesInFight) {
    Warrior player("John", "Human", 30, Weapon("Sword", 0, WARRIOR)); // Low health
    Goblin enemy("Goblin", "Monster", 50, Weapon("Club", 8, ENEMY));
    // Simulate player input for multiple rounds
    std::string input;
    for (int i = 0; i < 100; ++i) {
        input += "a\n"; // Attack
    }
    std::istringstream iss(input); // Simulate user input
    std::ostringstream oss; // Capture fight output
    bool result = fight(player, enemy, iss, oss); 
    EXPECT_FALSE(result); // Player should not defeat the enemy
    EXPECT_TRUE(player.get_health() <= 0); // Player should be defeated
    std::string fight_log = oss.str();
    EXPECT_TRUE(fight_log.find("You died!") != std::string::npos);
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