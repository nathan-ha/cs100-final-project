#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"

TEST(swordTest, constructorTest)
{
    Weapon w("sword", 20, character_class::THIEF);
    EXPECT_EQ(w.name, "sword");
    EXPECT_EQ(w.damage, 20);
    EXPECT_EQ(w.class_type, character_class::THIEF);
    EXPECT_EQ(w.name, "sword");
}

TEST(skeletonTest, nameTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Bob", "monster", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(skeletonTest, setNameTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_name("Bob");
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(skeletonTest, raceTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_race(), "monster");
}

TEST(skeletonTest, setRaceTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_race("Big Skeleton");
    EXPECT_EQ(c.get_race(), "Big Skeleton");
}

TEST(skeletonTest, healthTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_health(), 100);
}

TEST(skeletonTest, getHealthTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_health(80);
    EXPECT_EQ(c.get_health(), 80);
}

TEST(skeletonTest, classTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_class_type(), character_class::ENEMY);
}

TEST(skeletonTest, attackTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton s("Jim", "monster", 100, sword);
    Character c("Jim", "monster", 100, sword);
    s.attack(c);
    EXPECT_EQ(c.get_health(), 80);
}

TEST(thiefTest, nameTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Bob", "monster", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(thiefTest, setNameTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    c.set_name("Bob");
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(thiefTest, raceTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_race(), "monster");
}

TEST(thiefTest, setRaceTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    c.set_race("Big Thief");
    EXPECT_EQ(c.get_race(), "Big Thief");
}

TEST(thiefTest, healthTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_health(), 100);
}

TEST(thiefTest, setHealthTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    c.set_health(80);
    EXPECT_EQ(c.get_health(), 80);
}

TEST(thiefTest, classTest)
{
    Weapon sword("Sword", 20, character_class::THIEF);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_class_type(), character_class::THIEF);
}

TEST(thiefTest, stabTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton s("Jim", "monster", 100, sword);
    Thief t("Jim", "human", 100, sword);
    t.stab(s);
    EXPECT_EQ(s.get_health(), 80);
}

TEST(thiefTest, throwKnifeTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton s("Jim", "monster", 100, sword);
    Thief t("Jim", "human", 100, sword);
    t.throw_knife(s);
    EXPECT_EQ(s.get_health(), 90);
}

TEST(thiefTest, mirageStepTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Thief t("Jim", "human", 100, sword);
    t.mirage_step();
    EXPECT_EQ(t.get_is_invulnerable(), true);
    
    t.disable_mirage_step();
    EXPECT_EQ(t.get_is_invulnerable(), false);
}


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

TEST(Goblin, enemyraceTest) { 
    Weapon club("club", 1, character_class::ENEMY);
    Goblin c("Nameless goblin", "Monster", 5, club);
    c.set_race("Goblin");
    EXPECT_EQ(c.get_race(), "Goblin");
}