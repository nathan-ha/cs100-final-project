#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"


// tests for get_name function
TEST(NameSuite, correctName) { // tests set_name(string) function too
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    c.set_name("Hello25!");

    EXPECT_EQ(c.get_name(), "Hello25!");
}

TEST(NameSuite, falseName) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_FALSE(c.get_name() == "NOT A NAME");
}

TEST(NameSuite, defaultName) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_EQ(c.get_name(), "name");
}

// test for get_race()
TEST(RaceSuite, defaultRace) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_EQ(c.get_race(), "race");
}

TEST(RaceSuite, correctRace) { // tests set_race(string)
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    c.set_race("elf");
    EXPECT_EQ(c.get_race(), "elf");
}

TEST(RaceSuite, falseRace) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_EQ(c.get_race(), "Not a race");
}

// test for get_health()

TEST(HealthSuite, defaultHealth) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_EQ(c.get_health(), 0);
}

TEST(HealthSuite, correctHealth) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    c.set_health(1050);
    EXPECT_EQ(c.get_health(), 1050);
}

TEST(HealthSuite, falseHealth) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_FALSE(c.get_health() == -20);
}

// test for get_class_type()

TEST(ClassSuite, thief_default) {
    Character c("name", "race", 0, Weapon("weapon", 10, character_class::THIEF));
    EXPECT_TRUE(c.get_class_type() == character_class::THIEF);
}

TEST(GolbinTest, enemyraceTest) { 
    Weapon club("club", 1, character_class::ENEMY);
    Goblin c("Nameless goblin", "Monster", 5, club);
    c.set_race("Goblin");
    EXPECT_EQ(c.get_race(), "Goblin");
}