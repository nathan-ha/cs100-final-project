 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# A Very Fun Game

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
 
  
>   You also need to set up an empty project board using GitHub projects (board view with default columns). Make sure you add the board under your project 
> repository. You should also have a Product Backlog and In testing columns added. All columns should be in the right order.
 
  ## README.md Disclaimer
  * project description was collaborated via google docs file first before is agreed upon that project discription should be committed by 1 person for ease of upload for the initial commits.
 
  ## Phase II
    * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
  ## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

![nav diagram](https://github.com/cs100/final-project-nha023-nshin018-klian035-clu113/assets/130444120/31d1a4e1-5b16-48f3-9462-c29ebab99bc6)

The diagram starts where the user will chooose their IGN (in game name). They will choose a game difficulty, choose, their class (archer, thief, or warrior), then play the game. Whether they win, lose, or quit, they will be redirected to the restart page. If they choose to restart, they will be prompted to the game difficulty once more. If not, the program will end. At all points and choices in the game given, the user will be given the choice to quit.


### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram

Class Diagram Link
https://lucid.app/lucidchart/2588b390-7366-4480-a13d-4a7573269aac/edit?viewport_loc=-1482%2C-412%2C2121%2C1123%2C0_0&invitationId=inv_125d7603-efbc-41ee-9c68-4401348430da

Class Diagram Description
**Character Class:** A base class that contains the character’s name and race as a string, base health as an int, and current weapon as a weapon class. 
There are three getter and setter functions that will get/set the IGN (in game name), race, and health of the character. There is also a function that allows the character to run away, and a getter function for setting the class (thief, warrior, & archer). The getter function is type void, and will be implemented along with setting the character class. 
 
**Thief, Warrior, & Archer Classes that inherit from Character Class:** The three classes will inherit from the Character class. These are the classes that the player will be able to choose from. In addition to the various attributes common among all the characters, these three classes will have their own special attacks and abilities. They will also have their own, unique consumable items.
 
**Thief Class that inherits from Character class:** The thief class will have additional protected attributes, such as the int of throwing knives (the consumable as mentioned above) and bool of is_invulnerable, which helps the character dodge. The three methods of the thief class correspond to its attributes.
 
**Warrior Class that inherits from Character class:** The warrior class will have an additional protected attribute called bomb_count (consumable), which is one of the character’s attacks. It has three methods, which are used to enact the warrior’s abilities.
 
**Archer Class that inherits from Character class:** The archer class will have a protected attribute called arrow_count(consumable), which is one of the attacks. There are two methods, which are related to the character’s attack.
 
**Wolf, Goblin, Skeleton, Dragon:** Similar to the player classes, these will inherit from the Character class. Unlike the player classes, however, these will be reserved for enemies that the player will face. The “enemies” will have methods that are only used for attacking the character. 
 
**Weapon Class:** A small class that will represent the weapons that each character will carry. Each weapon will have a name, a damage value, and a specific class that can wield a given weapon. It will be implemented in the character class.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
