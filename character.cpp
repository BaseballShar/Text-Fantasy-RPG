#include <sstream>
#include <iomanip>
#include "character.h"

    
// Input: Basic status and career of the player
// Purpose: This function is to initialize the status of the player
void Player::SetStatus(long long hp_basic, long long str_basic, 
                long long def_basic, long long agi_basic, string career) {   
  this -> hp_basic = hp_basic;
  this -> str_basic = str_basic;
  this -> def_basic = def_basic;
  this -> agi_basic = agi_basic;
  this -> career = career;
}

// Purpose: This function is to print the status of the player
void Player::PrintStatus() {
  cout << setw((name.length() > monster_name_len)? 
  name.length() + 2 : monster_name_len + 2) << name;

  cout << setw(12) << " HP: " + to_string(hp_actual);
  cout << setw(12) << " STR: " + to_string(str_actual);
  cout << setw(12) << " DEF: " + to_string(def_actual);
  cout << setw(12) << " AGI: " + to_string(agi_actual) << endl;
}

// Purpose: This function is to print the equipments of the player
void Player::PrintEquipment() {
  istringstream weapon_str(weapon);
  istringstream armour_str(armour);

  string cost;

  // variables for weapon status
  string weapon_name = "";
  string weapon_hp_bonus = "";
  string weapon_str_bonus = "";
  string weapon_def_bonus = "";
  string weapon_agi_bonus = "";

  // variables for armour status
  string armour_name = "";
  string armour_hp_bonus = "";
  string armour_str_bonus = "";
  string armour_def_bonus = "";
  string armour_agi_bonus = "";
  
  if (weapon == "") {
    cout << "You have not equipped any weapon" << endl;
  } else {
    weapon_str >> cost;
    weapon_str >> weapon_name;
    weapon_str >> weapon_hp_bonus;
    weapon_str >> weapon_str_bonus;
    weapon_str >> weapon_def_bonus;
    weapon_str >> weapon_agi_bonus;

    // handle the weapon status output
    cout << "Currently equipped weapon:" << endl;
    cout << weapon_name << "  ";
    cout << "HP:" << (((stod(weapon_hp_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(weapon_hp_bonus) - 1) * 100)) + "%" << "  ";   

    cout << "STR:" << (((stod(weapon_str_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(weapon_str_bonus) - 1) * 100)) + "%" << "  ";

    cout << "DEF:" << (((stod(weapon_def_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(weapon_def_bonus) - 1) * 100)) + "%" << "  ";

    cout << "AGI:" << (((stod(weapon_agi_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(weapon_agi_bonus) - 1) * 100)) + "%" << endl; 

    
  }
  if (armour == "") {
    cout << "You have not equipped any armour" << endl;
  } else {
    armour_str >> cost;
    armour_str >> armour_name;
    armour_str >> armour_hp_bonus;
    armour_str >> armour_str_bonus;
    armour_str >> armour_def_bonus;
    armour_str >> armour_agi_bonus;

    // handle the armour status output
    cout << "Curently equipped armour:" << endl;
    cout << armour_name << "  ";
    cout << "HP:" << (((stod(armour_hp_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(armour_hp_bonus) - 1) * 100)) + "%" << "  ";   

    cout << "STR:" << (((stod(armour_str_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(armour_str_bonus) - 1) * 100)) + "%" << "  ";

    cout << "DEF:" << (((stod(armour_def_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(armour_def_bonus) - 1) * 100)) + "%" << "  ";

    cout << "AGI:" << (((stod(armour_agi_bonus) - 1) * 100 >= 0) ? "+" : "") +
        to_string((int) ((stod(armour_agi_bonus) - 1) * 100)) + "%" << endl; 

  }  
  
}

// Purpose: Printing out the monster status
void Monster::PrintStatus() {
  cout << setw((name.length() > player_name_len)? 
  name.length() + 2 : player_name_len + 2) << name;

  cout << setw(12) << " HP: " + to_string(hp);
  cout << setw(12) << " STR: " + to_string(str);
  cout << setw(12) << " DEF: " + to_string(def);
  cout << setw(12) << " AGI: " + to_string(agi) << endl;
}
