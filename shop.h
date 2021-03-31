#ifndef SHOP_H
#define SHOP_H

#include "list.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Shop {

  // Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List weapon;

  // Cost Name Hp_bonus Str_bonus Def_bonus Agi_bonus
  List armour;

  // constructor for shop
  Shop() {
    //ordinary armour
    armour.AppendBack("50 LeatherArmour 1 1 1.1 1");
    armour.AppendBack("100 HardenLeatherArmour 1 1 1.15 1");
    armour.AppendBack("175 FurArmour 1 1 1.4 0.95");
    armour.AppendBack("500 BronzeArmour 1 1 1.6 0.93");
    armour.AppendBack("750 IronArmour 1 1 1.8 0.9");
    armour.AppendBack("1000 SteelArmour 1 1 2 0.88");
    armour.AppendBack("1500 DarksteelArmour 1 1 2.2 0.85");
    armour.AppendBack("2000 MithrilArmour 1 1 2.6 0.8");

    // lucky draw armour
    armour.AppendBack("99999999 DuckJacket 2 1 5 0.85");
    armour.AppendBack("99999999 YourSweatySuit 10 1 1 0.5");
    armour.AppendBack("99999999 InvisibleSuit 1 1 0.2 10");

    // ordinary weapon
    weapon.AppendBack("50 Stick 1 1.1 1 1");
    weapon.AppendBack("75 Spike 1 1.15 1 1");
    weapon.AppendBack("100 WoodenSword 1 1.4 1 0.95");
    weapon.AppendBack("100 BronzeSword 1 1.6 1 0.93");
    weapon.AppendBack("100 IronSword 1 1.8 1 0.9");
    weapon.AppendBack("100 SteelSword 1 2 1 0.88");
    weapon.AppendBack("100 DarksteelSword 1 2.2 1 0.85");
    weapon.AppendBack("100 MithrilSword 1 2.6 1 0.8");

    // lucky draw weapon
    weapon.AppendBack("99999999 Chair 1 10 0.2 2");
    weapon.AppendBack("99999999 Rabbit 1.5 2 1 5");
    weapon.AppendBack("99999999 Carrot 1.5 4 2 1.5");
  }

  void DisplayItem ();

};

void MakePurchase(Shop &shop, Player &player);
#endif