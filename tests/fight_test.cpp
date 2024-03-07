#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../header/fight.h"
#include "../header/archer.h"
#include "../header/warrior.h"
#include "../header/wolf.h"

TEST(FightTest, ArcherDefeatsWolf) {
    std::ostringstream oss;
    std::istringstream iss("a\n"); // Simulating 'a' as input
    std::streambuf* cinBackup = std::cin.rdbuf(iss.rdbuf());
    std::streambuf* coutBackup = std::cout.rdbuf(oss.rdbuf());

    Archer player("Alice", "Human", 100, Weapon("Bow", 10, ARCHER));
    Wolf enemy("Wolf", "Animal", 50, Weapon("Claws", 5, ENEMY));
    bool result = fight(player, enemy, iss, oss);

    std::cin.rdbuf(cinBackup); // Restore cin
    std::cout.rdbuf(coutBackup); // Restore cout

    EXPECT_TRUE(result);

    // Consume any remaining input from std::cin
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
