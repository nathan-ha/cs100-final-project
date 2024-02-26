#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"

TEST(characterTest, nameTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Character c("Bob", "Human", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(swordTest, constructorTest) {
    Weapon w("sword", 20, character_class::Thief);
    EXPECT_EQ(w.name, "sword");
    EXPECT_EQ(w.damage, 20);
    EXPECT_EQ(w.class_type, character_class::Thief);
    EXPECT_EQ(w.name, "sword");
}

TEST(skeletonTest, nameTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Bob", "monster", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(skeletonTest, setNameTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_name("Bob");
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(skeletonTest, raceTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_race(), "monster");
}

TEST(skeletonTest, setRaceTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_race("Big Skeleton");
    EXPECT_EQ(c.get_race(), "Big Skeleton");
}

TEST(skeletonTest, healthTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_health(), 100);
}

TEST(skeletonTest, getHealthTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    c.set_health(80);
    EXPECT_EQ(c.get_health(), 80);
}

TEST(skeletonTest, classTest) {
    Weapon sword("Sword", 20, character_class::Enemy);
    Skeleton c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_class_type(), character_class::Enemy);
}


TEST(thiefTest, nameTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Bob", "monster", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(thiefTest, setNameTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    c.set_name("Bob");
    EXPECT_EQ(c.get_name(), "Bob");
}

TEST(thiefTest, raceTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_race(), "monster");
}

TEST(thiefTest, setRaceTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    c.set_race("Big Thief");
    EXPECT_EQ(c.get_race(), "Big Thief");
}

TEST(thiefTest, healthTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_health(), 100);
}

TEST(thiefTest, setHealthTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    c.set_health(80);
    EXPECT_EQ(c.get_health(), 80);
}

TEST(thiefTest, classTest) {
    Weapon sword("Sword", 20, character_class::Thief);
    Thief c("Jim", "monster", 100, sword);
    EXPECT_EQ(c.get_class_type(), character_class::Thief);
}