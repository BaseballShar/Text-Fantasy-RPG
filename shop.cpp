#include "shop.h"


void Shop::DisplayItem() {
  int purchase_choice;

  string armour_price = "";
  string armour_name = "";
  string armour_hp_bonus = "";
  string armour_str_bonus = "";
  string armour_def_bonus = "";
  string armour_agi_bonus = "";

  string weapon_price = "";
  string weapon_name = "";
  string weapon_hp_bonus = "";
  string weapon_str_bonus = "";
  string weapon_def_bonus = "";
  string weapon_agi_bonus = "";

  cout << "[1]Armour [2]Weapon [3]Exit" << endl;
  cin >> purchase_choice;

  switch (purchase_choice) {
    case 1:
      for (int i = 0; i < armour.len; i++) {
        istringstream armour_str(armour.Extract(i));

        armour_str >> armour_price;
        armour_str >> armour_name;
        armour_str >> armour_hp_bonus;
        armour_str >> armour_str_bonus;
        armour_str >> armour_def_bonus;
        armour_str >> armour_agi_bonus;

        cout << left;
        cout << setw(16) << "Price: " +  armour_price;
        cout << setw(25) << "Name:" + armour_name;
        cout << "HP:" << setw(10) << (((stod(armour_hp_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(armour_hp_bonus) - 1) * 100)) + "%";
        cout << "STR:" << setw(10) << (((stod(armour_str_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(armour_str_bonus) - 1) * 100)) + "%";
        cout << "DEF:" << setw(10) << (((stod(armour_def_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(armour_def_bonus) - 1) * 100)) + "%";
        cout << "AGI:" << setw(10) << (((stod(armour_agi_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(armour_agi_bonus) - 1) * 100)) + "%" << endl;
      }
      break;
    case 2:
      for (int i = 0; i < weapon.len; i++) {
        istringstream weapon_str(weapon.Extract(i));

        weapon_str >> weapon_price;
        weapon_str >> weapon_name;
        weapon_str >> weapon_hp_bonus;
        weapon_str >> weapon_str_bonus;
        weapon_str >> weapon_def_bonus;
        weapon_str >> weapon_agi_bonus;

        cout << left;
        cout << setw(16) << "Price: " +  weapon_price;
        cout << setw(21) << "Name: " + weapon_name;
        cout << "HP:" << setw(10) << (((stod(weapon_hp_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(weapon_hp_bonus) - 1) * 100)) + "%";
        cout << "STR:" << setw(10) << (((stod(weapon_str_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(weapon_str_bonus) - 1) * 100)) + "%";
        cout << "DEF:" << setw(10) << (((stod(weapon_def_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(weapon_def_bonus) - 1) * 100)) + "%";
        cout << "AGI:" << setw(10) << (((stod(weapon_agi_bonus) - 1) * 100 > 0) ? "+" : "") + to_string((int) ((stod(weapon_agi_bonus) - 1) * 100)) + "%" << endl;
      }
      break;
    case 3:

    default:
      cout << endl;
  }
}

void MakePurchase(Shop &shop, Player &player) {
  
}
