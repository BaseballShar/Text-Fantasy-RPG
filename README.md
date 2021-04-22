# ENGG 1340 Group 137 Game Project

### Team Members:
Chan Tsz Ho (3035785738)

Chan Yuk Yin (3035786574)

### Description:
- This is a text-based role-playing game which is set in a dark medieval fantasy world. You the player will act as a teleported adventurer in the game. 
By acquiring strength and powerful equipment through combating monsters and subordinates of the INFINITE COMMENT CLIENT spread throughout the world, player will eventually be able to fight the 
INFINITE COMMENT CLIENT and return to the original world to win the game.

### Game Rule:
- As the game is text-based, the player will be providing instructions to the game by inputting commands in the terminal.
- Inputs will be mainly in the form of numerals, the player can specify actions/choices by inputting the corrosponding integers to the terminal. While a few inputs are text-based, for example, the name of the character.

### Game features:
1. **Shop and equipment system** (*Requirement 2 and 3*)
- Dynamic memory system such as linked list will help to record the player equipment status. For example, record what the player has purchased and equipped. How much money the player got will also be saved to determine whether a purchase is successful.

2. **Lucky Draw system** (*Requirement 1*)
- The random lucky draw systems apply the random function from cstdlib to randomly draw equipment for the player.

3. **Combat system** (*Requirement 1*)
- When the player is in combat with the monster, the system will have a chance to randomly trigger events to make some changes to the current combat. For example, buffs such as damage reduction may be granted to the player.

4. **Skill points and level up system** (*Requirement 2*)
- Data structure such as the player class will be applied to store the skill points and numerous status of the player.

5. **Game saving and loading system** (*Requirement 4*)
- Game will be saved automatically after every action. Load game option is provided at the start menu.

### Multiple-File compilation (*Requirement 5*):
Different systems of the game will be packaged into functions and stored in respective files. For example, shop.cpp and shop.h for functions related to the shop systems. This is to view the game in a more organized manner which allows easy debugging and improving.

### Assumption in gameplay
- Player is assumed to play logically, for example, valid inputs are always provided.

### Quick Start
1. Open terminal
2. Navigate to the game folder
3. Enter *make rpg*
4. Enter *./rpg*
5. Start playing

### Sample Input / Output 
- This could not be provided due to the random nature of the game
