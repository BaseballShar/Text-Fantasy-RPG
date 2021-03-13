#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <thread>
#include <chrono>
#include "character.h"

Monster CombatLevelSelection(Player player);
  
// Purpose: Pause the game for (time) miliseconds
void Pause(int time);

// Purpose: Function for calculating the attack modifier 
// based on strength and defense
double CombatMultipler(int attack_str, int defend_def);

// Purpose: To determine whether a hit is successful or not
// Mechanism : Create a bound of a randomly generate number by the ratio of agility of both sides
// the higher the ratio, the more large the bound , hence a hit is more likely
bool CombatIsHit(int attack_agi, int defend_agi);

// Purpose: To calculate health reduction of monster(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatPlayerAttack(Player &player, Monster &monster);

// Purpose: To calculate health reduction of player(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatMonsterAttack(Player &player, Monster &monster);

// Purpose: To determine the outcome of the combat with the monster
// Experience point and money gained is calculated using the level
// of monster that the player defeated
void CombatReward(Player &player, int combat_result);

// Purpose: To be in charge of the whole combat situation
// From monster creation, combating, to reward distribution
int Combat (Player &player/*, Shop shop*/);

#endif