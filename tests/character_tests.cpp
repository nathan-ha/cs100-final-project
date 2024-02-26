#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"

//weapon name(itemname, atk value, class_type)
//character c(character name, race, hp value, eqed weapon)

TEST(characterTest, nameTest) {
    Weapon sword("Sword", 20, character_class::WARRIOR);
    Character c("Bob", "Human", 100, sword);
    EXPECT_EQ(c.get_name(), "Bob");
}
TEST(characterTest, healthTest) {
    Weapon sword("Sword", 20, character_class::WARRIOR);
    Character c("Bob", "Human", 100, sword);
    EXPECT_EQ(c.get_health(), 100);
}
TEST(characterTest, classTest) {
    Weapon sword("Sword", 20, character_class::WARRIOR);
    Character c("Bob", "Human", 100, sword);
    EXPECT_EQ(c.get_class_type(), WARRIOR);

}
TEST(GolbinTest, enemyraceTest){ 
    Weapon club("club", 1, character_class::ENEMY);
    Goblin c("Nameless goblin", "Monster", 5, club);
    c.set_race("Goblin");
    EXPECT_EQ(c.get_race(), "Goblin");
}