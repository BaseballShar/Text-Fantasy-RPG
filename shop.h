#ifndef SHOP_H
#define SHOP_H

#include "list.h"
#include "character.h"
#include "useful_function.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Shop {

  // Dynamic memory for storing weapons avalible for purchase
  // Storage format: Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List weapon;

  // Dynamic memory for storing armours avalible for purchase
  // Storage format: Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List armour;

  // Dynamic memory for storing weapons avalible for luckydraw
  // Storage format: Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List luckydraw_weapon;

  // Dynamic memory for storing weapons avalible for luckydraw
  // Storage format: Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List luckydraw_armour;

  // Constructor for shop for initializing stop content
  Shop() {
    // ordinary armour
    armour.Append("List of armours: ");
    armour.Append("50 LeatherArmour 1 1 1.1 1");
    armour.Append("100 HardenLeatherArmour 1 1 1.15 1");
    armour.Append("175 FurArmour 1 1 1.4 0.95");
    armour.Append("500 BronzeArmour 1 1 1.6 0.93");
    armour.Append("750 IronArmour 1 1 1.8 0.9");
    armour.Append("1000 SteelArmour 1 1 2 0.88");
    armour.Append("1500 DarksteelArmour 1 1 2.2 0.85");
    armour.Append("2000 MithrilArmour 1 1 2.6 0.8");

    // lucky draw armour
    armour.Append("99999999 DuckJacket 2 1 5 0.85");
    armour.Append("99999999 YourSweatySuit 10 1 1 0.5");
    armour.Append("99999999 InvisibleSuit 1 1 0.2 10");

    luckydraw_armour.Append("99999999 DuckJacket 2 1 5 0.85");
    luckydraw_armour.Append("99999999 YourSweatySuit 10 1 1 0.5");
    luckydraw_armour.Append("99999999 InvisibleSuit 1 1 0.2 10");

    // ordinary weapon
    weapon.Append("List of armours:");
    weapon.Append("50 Stick 1 1.1 1 1");
    weapon.Append("75 Spike 1 1.15 1 1");
    weapon.Append("100 WoodenSword 1 1.4 1 0.95");
    weapon.Append("350 BronzeSword 1 1.6 1 0.93");
    weapon.Append("500 IronSword 1 1.8 1 0.9");
    weapon.Append("750 SteelSword 1 2 1 0.88");
    weapon.Append("1250 DarksteelSword 1 2.2 1 0.85");
    weapon.Append("2000 MithrilSword 1 2.6 1 0.8");

    // lucky draw weapon
    weapon.Append("99999999 Chair 1 10 0.2 2");
    weapon.Append("99999999 Rabbit 1.5 2 1 5");
    weapon.Append("99999999 Carrot 1.5 4 2 1.5");

    luckydraw_weapon.Append("99999999 Chair 1 10 0.2 2");
    luckydraw_weapon.Append("99999999 Rabbit 1.5 2 1 5");
    luckydraw_weapon.Append("99999999 Carrot 1.5 4 2 1.5");
  }

  int DisplayItem (int purchase_choice);

};

// Purpose: Function for handling armour transaction
void MakePurchaseArmour(Player &player, Shop &shop ,int purchase_id);

// Purpose: Function for handling weapon transaction
void MakePurchaseWeapon(Player &player, Shop &shop, int purchase_id);

// Purpose: Function for handling armour luckydraw
void LuckyDrawArmour(Player &player, Shop &shop);

// Purpose: Function for handling weapon luckydraw
void LuckyDrawWeapon(Player &player, Shop &shop);

// Purpose: Function for handling the luckydraw
void LuckyDraw(Player &player, Shop &shop);

// Function for purchasing items
void MakePurchase(Player &player, Shop &shop);

#endif
