#include <gtest/gtest.h>
#include "../header/character.h"
#include "../header/skeleton.h"
#include "../header/thief.h"
#include "../header/goblin.h"
#include "../header/archer.h"
#include "../header/warrior.h"
#include "../header/dragon.h"
#include "../header/wolf.h"

TEST(CharacterTest, GetName) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    EXPECT_EQ(character.get_name(), "Alice");
}

TEST(CharacterTest, SetName) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    character.set_name("Bob");
    EXPECT_EQ(character.get_name(), "Bob");
}

TEST(CharacterTest, GetRace) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    EXPECT_EQ(character.get_race(), "Human");
}

TEST(CharacterTest, SetRace) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    character.set_race("Elf");
    EXPECT_EQ(character.get_race(), "Elf");
}

TEST(CharacterTest, GetHealth) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    EXPECT_EQ(character.get_health(), 100);
}

TEST(CharacterTest, SetHealth) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    character.set_health(80);
    EXPECT_EQ(character.get_health(), 80);
}

TEST(CharacterTest, GetClassType) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    EXPECT_EQ(character.get_class_type(), WARRIOR);
}

TEST(CharacterTest, GetWeapon) {
    Weapon weapon("Sword", 10, WARRIOR);
    Character character("Alice", "Human", 100, weapon);
    EXPECT_EQ(character.get_weapon().name, "Sword");
    EXPECT_EQ(character.get_weapon().damage, 10);
    EXPECT_EQ(character.get_weapon().class_type, WARRIOR);
}

TEST(CharacterTest, SetWeapon) {
    Weapon weapon1("Sword", 10, WARRIOR);
    Weapon weapon2("Axe", 15, WARRIOR);
    Character character("Alice", "Human", 100, weapon1);
    character.set_weapon(weapon2);
    EXPECT_EQ(character.get_weapon().name, "Axe");
    EXPECT_EQ(character.get_weapon().damage, 15);
    EXPECT_EQ(character.get_weapon().class_type, WARRIOR);
}

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
    EXPECT_EQ(s.get_health(), 60);
}

TEST(thiefTest, throwKnifeTest)
{
    Weapon sword("Sword", 20, character_class::ENEMY);
    Skeleton s("Jim", "monster", 100, sword);
    Thief t("Jim", "human", 100, sword);
    t.throw_knife(s);
    EXPECT_EQ(s.get_health(), 40);
}

TEST(ThiefTest, Stab) {
    Weapon dagger("Dagger", 15, THIEF);
    Thief thief("Rogue", "Human", 100, dagger);
    Character target("Enemy", "Orc", 50, Weapon("Sword", 20, WARRIOR));
    thief.stab(target);
    EXPECT_EQ(target.get_health(), 20);
}

TEST(ThiefTest, ThrowKnife) {
    Weapon dagger("Dagger", 15, THIEF);
    Thief thief("Rogue", "Human", 100, dagger);
    Character target("Enemy", "Orc", 50, Weapon("Sword", 20, WARRIOR));
    thief.throw_knife(target);
    EXPECT_EQ(target.get_health(), 5);
}

TEST(ThiefTest, GetSetThrowingKnifeCount) {
    Weapon dagger("Dagger", 15, THIEF);
    Thief thief("Rogue", "Human", 100, dagger);
    thief.set_throwing_knife_count(10);
    EXPECT_EQ(thief.get_throwing_knife_count(), 10);
}


// tests for archer class

TEST(archerTest, getNameTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    EXPECT_EQ(a.get_name(), "Alice");
}

TEST(archerTest, setNameTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    a.set_name("Alice");
    EXPECT_EQ(a.get_name(), "Alice");
}

TEST(archerTest, getRaceTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    EXPECT_EQ(a.get_race(), "human");
}

TEST(archerTest, setRaceTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    a.set_race("Ranged Human");
    EXPECT_EQ(a.get_race(), "Ranged Human");
}

TEST(archerTest, getHealthTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    EXPECT_EQ(a.get_health(), 101);
}

TEST(archerTest, setHealthTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    a.set_health(0);
    EXPECT_EQ(a.get_health(), 0);
}

TEST(archerTest, getClassTest)
{
    Weapon bow("Bow", 35, character_class::ARCHER);
    Archer a("Alice", "human", 101, bow);
    EXPECT_EQ(a.get_class_type(), character_class::ARCHER);
}

TEST(archerTest, shootArrowTest)
{
    Weapon bow("Bow", 35, character_class::ENEMY);
    Archer a("Alice", "human", 101, bow);
    Skeleton s("Jim", "monster", 70, bow);

    a.shoot_arrow(s);
    EXPECT_EQ(s.get_health(), 35);
}

TEST(archerTest, windArrowTest)
{
    Weapon bow("Bow", 35, character_class::ENEMY);
    Archer a("Alice", "human", 101, bow);
    Skeleton s("Jim", "monster", 70, bow);

    a.wind_arrow_strike(s);
    EXPECT_TRUE(s.get_health() < 0);
}

TEST(ArcherTest, ShootArrow) {
    Weapon bow("Longbow", 10, ARCHER);
    Archer archer("Bob", "Elf", 100, bow);
    Character target("Bob", "Goblin", 50, Weapon("Club", 5, ENEMY));
    archer.shoot_arrow(target);
    EXPECT_EQ(target.get_health(), 40);
    EXPECT_EQ(archer.get_arrow_count(), 49);
}

TEST(ArcherTest, WindArrowStrike) {
    Weapon bow("Longbow", 10, ARCHER);
    Archer archer("Bob", "Elf", 100, bow);
    Character target("Bob", "Goblin", 50, Weapon("Club", 5, ENEMY));
    archer.wind_arrow_strike(target);
    EXPECT_EQ(target.get_health(), 0);
    EXPECT_EQ(archer.get_arrow_count(), 45);
}

TEST(ArcherTest, BowSmack) {
    Weapon bow("Longbow", 10, ARCHER);
    Archer archer("Bob", "Elf", 100, bow);
    Character target("Bob", "Goblin", 50, Weapon("Club", 5, ENEMY));
    archer.bow_smack(target);
    EXPECT_EQ(target.get_health(), 48);
}

TEST(ArcherTest, SetAndGetArrowCount) {
    Weapon bow("Longbow", 10, ARCHER);
    Archer archer("Bob", "Elf", 100, bow);
    archer.set_arrow_count(30);
    EXPECT_EQ(archer.get_arrow_count(), 30);
}

//warrior tests

TEST(warriorTest, getNameTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    EXPECT_EQ(w.get_name(), "Wallace");
}

TEST(warriorTest, setNameTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    w.set_name("Wallace");
    EXPECT_EQ(w.get_name(), "Wallace");
}

TEST(warriorTest, getRaceTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    EXPECT_EQ(w.get_race(), "human");
}

TEST(warriorTest, setRaceTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    w.set_race("Melee Human");
    EXPECT_EQ(w.get_race(), "Melee Human");
}

TEST(warriorTest, getHealthTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    EXPECT_EQ(w.get_health(), 105);
}

TEST(warriorTest, setHealthTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    w.set_health(0);
    EXPECT_EQ(w.get_health(), 0);
}

TEST(warriorTest, getClassTest)
{
    Weapon scythe("Scythe", 25, character_class::WARRIOR);
    Warrior w("Wallace", "human", 105, scythe);
    EXPECT_EQ(w.get_class_type(), character_class::WARRIOR);
}

TEST(warriorTest, swingSwordTest)
{
    Weapon scythe("Scythe", 25, character_class::ENEMY);
    Warrior w("Wallace", "human", 105, scythe);
    Skeleton s("Jim", "monster", 50, scythe);

    w.swing_sword(s);
    EXPECT_EQ(s.get_health(), 25);
}

TEST(warriorTest, flameStrikeTest)
{
    Weapon scythe("Scythe", 25, character_class::ENEMY);
    Warrior w("Wallace", "human", 105, scythe);
    Skeleton s("Jim", "monster", 50, scythe);

    w.flame_strike(s);
    EXPECT_LT(s.get_health(), 0);
}

TEST(warriorTest, throwBombTest)
{
    Weapon scythe("Scythe", 25, character_class::ENEMY);
    Warrior w("Wallace", "human", 105, scythe);
    Skeleton s("Jim", "monster", 50, scythe);

    w.throw_bomb(s);
    EXPECT_TRUE(s.get_health() < 0);
}

TEST(WarriorTest, SwingSword) {
    Weapon sword("Greatsword", 25, WARRIOR);
    Warrior warrior("Conan", "Human", 150, sword);
    Character target("Enemy", "Orc", 100, Weapon("Axe", 20, WARRIOR));
    warrior.swing_sword(target);
    EXPECT_EQ(target.get_health(), 75);
}

TEST(WarriorTest, FlameStrike) {
    Weapon sword("Greatsword", 25, WARRIOR);
    Warrior warrior("Conan", "Human", 150, sword);
    Character target("Enemy", "Orc", 100, Weapon("Axe", 20, WARRIOR));
    warrior.flame_strike(target);
    EXPECT_EQ(target.get_health(), 25);
}

TEST(WarriorTest, ThrowBomb) {
    Weapon sword("Greatsword", 25, WARRIOR);
    Warrior warrior("Conan", "Human", 150, sword);
    Character target("Enemy", "Orc", 100, Weapon("Axe", 20, WARRIOR));
    warrior.throw_bomb(target);
    EXPECT_TRUE(target.get_health() < 0);
}

TEST(WarriorTest, GetBombCount) {
    Weapon sword("Greatsword", 25, WARRIOR);
    Warrior warrior("Conan", "Human", 150, sword);
    EXPECT_EQ(warrior.get_bomb_count(), 5);
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

// #include "../header/fight.h"
// TEST(polymorphism, referenceTest) {
//     Warrior w("name", "race", 0, Weapon("weapon", 10, character_class::WARRIOR));
//     Goblin c("Nameless goblin", "Monster", 5, Weapon("club", 1, character_class::ENEMY));
//     EXPECT_EQ(fight(w, c), true);

// }

TEST(DragonTest, DragonAttacksTarget) {
    Dragon dragon("Smore", "Fire Dragon", 100, Weapon("Fire Breath", 30, ENEMY));
    Warrior target("Bob", "Human", 100, Weapon("Sword", 20, WARRIOR));
    int initial_health = target.get_health();
    dragon.attack(target);
    EXPECT_LT(target.get_health(), initial_health);
}

TEST(DragonTest, DragonAttacksTargetLowHealth) {
    Dragon dragon("Smore", "Fire Dragon", 100, Weapon("Fire Breath", 30, ENEMY));
    Warrior target("Bob", "Human", 10, Weapon("Sword", 20, WARRIOR));
    int initial_health = target.get_health();
    dragon.attack(target);
    EXPECT_LT(target.get_health(), initial_health);
}
