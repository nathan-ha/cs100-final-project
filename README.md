# Dragonslayer's Quest

  Authors: [Claire Lu](https://github.com/claire-lu-113),
           [Kent Liang](https://github.com/kliang193),
           [Nathan Ha](https://github.com/nathan-ha),
           [Natalie Shin](https://github.com/nats26) 
 
## Project Description
  * Why is it important or interesting to you?
       - This project is interesting because it combines the essentials of team collaboration, such as
           Scrum patterns, with the practical application of game design. In particular, since 
           class-based RPGs require intricate knowledge of necessary coding features like classes 
           and inheritance, this project will be a fun challenge of both teamwork and good coding
           Practice.
 
  * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
       - We plan to implement this project in C++. We will be using VSCode as our main IDE and use 
           gitHub to collaborate. By utilizing the GitHub Project board, we can effectively 
           contribute code and reviews. We will also be utilizing slack and/or discord as our
           main communications hub.
 
  * What will be the input/output of your project?
       - The input will be based on the player’s situation while ingame. It could be a variation
           of simple yes(y)/no(n) inputs or action based inputs such as movements (w,a,s,d) or 
           interactions(e,x,c, etc…).
       - The output will be a series of brief descriptions based on where/what the player is doing.
            With a end condition output should the player reach the end or if player dies with a
            prompt to restart game from the beginning. 
 
  * What are the features that the project provides?
       - This is a turn-based text RPG that will feature character classes, all with unique weapons, 
           armor, and abilities. 
       - Features a level system where player can choose to grind for better or higher rarity gear or 
           higher levels before progressing forward (subject to change).
       - Will also feature a win/lose condition should the player reach the end of the game or if the
           player dies in battle with the option to restart game or forfeit game.
 
  * In short our project will be:  
       - Text-based RPG where the player will battle enemies in turn-based combat, have a level system 
           (subject to change), loot pool for different rarity items as drops or chest opens, a win or 
           lose system, different combat styles based on class/weapon, text based description for 
           each scenario the player is in, and a variety of text based actions.
 
   
   ## Phase II
   ## User Interface Specification

### Navigation Diagram
![nav diagram](https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/130444120/31d1a4e1-5b16-48f3-9462-c29ebab99bc6)

The diagram starts where the user will chooose their IGN (in game name). They will choose a game difficulty, choose, their class (archer, thief, or warrior), then play the game. Whether they win, lose, or quit, they will be redirected to the restart page. If they choose to restart, they will be prompted to the game difficulty once more. If not, the program will end. At all points and choices in the game given, the user will be given the choice to quit.


### Screen Layouts
As a text-based RPG, the screen layout of the game will generally follow the same formula: the player is presented with a text prompt to select one of multiple options. Differences in this formula include in the beginning of the game, when the user is prompted for a string input for their name. 

**Name prompt screen (requires user input):**
```
CHOOSE YOUR NAME: (user input)
```
The end of the game, whether it results in a loss or win, will have only the options to restart or exit the game. 

**Loss screen:**
```
GAME OVER
> Restart
> Exit
```
The middle portion of the game past inputting an username will have the following text prompts and options based on their type of scenario:

**Choosing Character Class:** At the start of the game, the player is presented with three unique character classes, Warrior, Archer, and Thief, along with their descriptions. 
```
CHOOSE YOUR CLASS:
1.WARRIOR
Physical attack - sword swing
Special attack - Flame Strike (fire elemental damage skill: does small damage per turn for x turns)
2.ARCHER
Physical attack - shoot arrow
Special attack - Wind Arrow (wind elemental damage skill: damage multiplier towards base attack)
3.THIEF
Physical attack - stab
Special attack - Mirage Step (water elemental evasive skill: dodge skill for 1-2 turns)

> Warrior
> Archer
> Thief
```
**Combat:** The player is presented with a screen displaying the enemy, which will be a Goblin, Skeleton, Wolf, or Dragon. Depending on the specific enemy, the damage and debuff outputs will be different. However, what is not reliant on the enemy class is the player’s current weapon, consumables, and character class. 
For example, a standard skeleton fighting an archer character will have the following screen:
```
A wild Skeleton appeared! 

> Attack
> Special Attack
> Inventory
> Flee
```
Upon choosing attack:
```
PLAYER shot an arrow ! Skeleton has resisted the attack !

10 Health has been depleted from Skeleton
40 Health remaining.

Skeleton has attacked !

20 Health has been depleted from PLAYER.
120 Heath remaining.
```

Upon choosing special attack:

```
PLAYER used Wind Arrow ! Skeleton has taken elemental damage !

25 Health has been depleted from Skeleton.
25 Health remaining.

Skeleton has attacked !

23 Health has been depleted from PLAYER.
117 Health remaining.
```
Successfully fleeing the battle will yield the screen:
```
You have fled the battle !
```
(Accessing the inventory will redirect you to the inventory screen.)

**Inventory:**  Inventory screens occur when the player accesses it during a combat scene, or if an item must be dropped for another item.

In combat, it displays consumables. For example, the Thief inventory would display:

```
Accessing Inventory…
Current Weapon: Simple Sword
> Throwing Knifes
> Exit Inventory
```
In weapon swapping, it would display as such:

```
Accessing Inventory…
Current Weapon: Simple Sword
Swap for Glowing Dagger ?
>Yes
>No
```
**Story:** General story decisions will describe a scenario in which a player, not in combat or decision making danger, will choose between presented options in order to progress the story itself. These types of screens serve as an intermediary between combat scenes for the player to ‘decide’ which combat situation they would like to enter into. For example, to progress towards a battle with goblins in a cave, the screen would resemble:
```
Ahead of you is a dark cave, dimly lit by torches along its walls. You see scratch marks on the wall and smell the distinct scent of rotting flesh. There are two paths in the cave, one lit and the other pitch black. Which do you choose?
> Lit path
> Dark path
```


## Class Diagram

Class Diagram Link
https://lucid.app/lucidchart/2588b390-7366-4480-a13d-4a7573269aac/edit?viewport_loc=-1482%2C-412%2C2121%2C1123%2C0_0&invitationId=inv_125d7603-efbc-41ee-9c68-4401348430da
<img width="781" alt="image" src="https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/80845813/e89d1e8c-4314-48ef-9e2a-dc1ff254cf21">


Class Diagram Description
**Character Class:** A base class that contains the character’s name and race as a string, base health as an int, and current weapon as a weapon class. 
There are three getter and setter functions that will get/set the IGN (in game name), race, and health of the character. There is also a function that allows the character to run away, and a getter function for setting the class (thief, warrior, & archer). The getter function is type void, and will be implemented along with setting the character class. 
 
**Thief, Warrior, & Archer Classes that inherit from Character Class:** The three classes will inherit from the Character class. These are the classes that the player will be able to choose from. In addition to the various attributes common among all the characters, these three classes will have their own special attacks and abilities. They will also have their own, unique consumable items.
 
**Thief Class that inherits from Character class:** The thief class will have additional protected attributes, such as the int of throwing knives (the consumable as mentioned above) and bool of is_invulnerable, which helps the character dodge. The three methods of the thief class correspond to its attributes.
 
**Warrior Class that inherits from Character class:** The warrior class will have an additional protected attribute called bomb_count (consumable), which is one of the character’s attacks. It has three methods, which are used to enact the warrior’s abilities.
 
**Archer Class that inherits from Character class:** The archer class will have a protected attribute called arrow_count(consumable), which is one of the attacks. There are two methods, which are related to the character’s attack.
 
**Wolf, Goblin, Skeleton, Dragon:** Similar to the player classes, these will inherit from the Character class. Unlike the player classes, however, these will be reserved for enemies that the player will face. The “enemies” will have methods that are only used for attacking the character. 
 
**Weapon Class:** A small class that will represent the weapons that each character will carry. Each weapon will have a name, a damage value, and a specific class that can wield a given weapon. It will be implemented in the character class.

**SOLID Principles:** 
S - Each of the classes we have written only really do one thing. Starting with the “biggest” class in scope, we have the Character class. This class is only responsible for storing basic information that is necessary for every class that inherits from it (such as health, name, weapons, etc.). For the other classes, such as Thief, Warrior, and Archer, they only implement the attacks that those characters can do. For example, an Archer can shoot arrows but not much more.
O - The easiest to see example of this principle can be seen in the way that the various character classes inherit from Character. For example, all the Warrior class does is add a few attacks. There is no need to modify the Character class in order to do this. This also goes for pretty much all the other classes, too. We add new functions for the derived classes without changing the original.
L - This principle holds true in our class system because all the functions that belong to Character also belong to the classes inheriting from it. The derived classes only add a few attack functions. This means that there should be no problem replacing instances of Character with instances of Thief, Warrior, Archer, etc.
I - We stayed true to this principle because the Character class contains only the necessary functionality for all characters in this game. In other words, it doesn’t implement any interfaces that are not being used by everyone. The classes that inherit from it also only implement exactly what they need, and nothing more.
D - We displayed this principle in the attack functions implemented by the derived classes. The parameters are Character references, meaning that we can actually attack any kind of character, as opposed to hard-coding attack functions for each of the enemy types.
 
  
 ## Screenshots
> <img width="1071" alt="image" src="https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/80845813/af7d3755-3af0-4e9c-8b34-ae4ff0e4f5a7">
<img width="1074" alt="image" src="https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/80845813/e38dd516-63bf-46d8-963c-ba36eb6cdfae">
<img width="1073" alt="image" src="https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/80845813/d0dc4b3d-20bc-4f47-bf2f-c1b8d05e5b30">


 ## Installation/Usage
 To install, make sure you have git. Clone this repository and run `git submodule init && git submodule update`. Make sure you have cmake and a c++ compiler installed. Then run `cmake . && make` in the terminal to compile. To run the game, run the command `./bin/runBuild`. From there, you can follow the instructions on the screen.
 ## Testing
We tested the code by running unit tests to ensure all the classes and functions run properly. Before we push new code, we made sure to pass all the tests first. We also played the game itself to make sure everything ran smoothly.
 
