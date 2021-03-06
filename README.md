# ENGG 1340 Group 137 Game Project
## Proposal
### Team Members:
Chan Tsz Ho (3035785738)

Chan Yuk Yin (3035786574)

### Description:
- This is a text-based role-playing game which is set in a dark medieval fantasy world. You the player will act as an adventurer in the game. By acquiring strength and powerful equipment through combating monsters spread throughout the world, player will eventually be able to fight the Monster King and save mankind to win the game.

### Game Rule:
- As the game is text-based, the player will be providing instructions to the game by inputting commands in the terminal.
- Inputs will be mainly in the form of numerals, the player can specify actions/choices by inputting the corrosponding integers to the terminal. While a few inputs are text-based, for example, the name of the character.
- Player is advised to save the game regularly during the playthrough, upon death of the character, any unsaved progress will be lost.

### Game features:
1. **Shop and equipment system** (*Requirement 2 and 3*)

The data structure such as arrays and vectors ,and dynamic memory system will help to record the player equipment status. For example, record what the player has purchased and equipped. How much money the player got will also be saved to determine whether a purchase is successful.

2. **Lucky Draw system** (*Requirement 1*)

The random lucky draw systems apply the random code to randomly draw equipment for the player.

3. **Combat system** (*Requirement 1*)

When the player is in combat with the monster, the system will have a chance to randomly trigger events to make some changes to the current combat. For example, buffs such as damage reduction may be granted to the player.

4. **Skill points and level up system** (*Requirement 2*)

Data structure will be applied to store the skill points and numerous status of the player.

5. **Game saving and loading system** (*Requirement 4*)

The player can save or load the game by inputting an integer and the system will execute the operations accordingly.

### Multiple-File compilation (*Requirement 5*):
Different systems of the game will be packaged into functions and stored in respective files. For example, shop.cpp and shop.h for functions related to the shop systems. This is to view the game in a more organized manner which allows easy debugging and improving.
