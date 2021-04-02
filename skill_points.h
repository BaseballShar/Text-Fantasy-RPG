#ifndef SKILL_POINT_H
#define SKILL_POINT_H

#include <iostream>
#include "character.h"
#include "useful_function.h"
using namespace std;

// Purpose: To assign skill points to HP
void UpgradeHP(Player &player);

// Purpose: To assign skill points to STR
void UpgradeSTR(Player &player);

// Purpose: To assign skill points to DEF
void UpgradeDEF(Player &player);

// Purpose: To assign skill points to AGI
void UpgradeAGI(Player &player);

// Purpose: To be in charge of the skill point system
void SkillPoint(Player &player);

// Purpose: To update the level status of the player
void LevelUpdate(Player &player);

#endif
