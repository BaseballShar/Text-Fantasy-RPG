#include <sstream>
#include "character.h"
#include "list.h"
    
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
  cout << name << " HP: " << hp_actual << " STR: " << str_actual 
  << " DEF: " << def_actual << " AGI: " << agi_actual << endl;
}

// Purpose: This function is to print the equipments of the player
void Player::PrintEquipment() {
  istringstream weapon_str(weapon);
  istringstream armour_str(armour);

  string weapon_name = "";
  string weapon_hp_bonus = "";
  string weapon_str_bonus = "";
  string weapon_def_bonus = "";
  string weapon_agi_bonus = "";

  string armour_name = "";
  string armour_hp_bonus = "";
  string armour_str_bonus = "";
  string armour_def_bonus = "";
  string armour_agi_bonus = "";
  

  if (weapon == "") {
    cout << "You have not purchased any weapon" << endl;
  } else {
    weapon_str >> weapon_name;
    weapon_str >> weapon_hp_bonus;
    weapon_str >> weapon_str_bonus;
    weapon_str >> weapon_def_bonus;
    weapon_str >> weapon_agi_bonus;

    cout << "Currently equiped weapon:" << endl;
    cout << "Name: " << weapon_name << " HP: +" << (stoi(weapon_hp_bonus) - 1) * 100 << "%";
    cout << " STR: +" << (stoi(weapon_str_bonus) - 1) * 100 << "%";
    cout << " DEF: +" << (stoi(weapon_def_bonus) - 1) * 100 << "%";
    cout << " AGI: +" << (stoi(weapon_agi_bonus) - 1) * 100 << "%";

    
  }
  if (armour == "") {
    cout << "You have not purchased any armour" << endl;
  } else {
    armour_str >> armour_name;
    armour_str >> armour_hp_bonus;
    armour_str >> armour_str_bonus;
    armour_str >> armour_def_bonus;
    armour_str >> armour_agi_bonus;
    
    cout << "Curently equiped wamour:" << endl;
    cout << "Name: " << weapon_name << " HP: +" << (stoi(armour_hp_bonus) - 1) * 100 << "%";
    cout << " STR: +" << (stoi(armour_str_bonus) - 1) * 100 << "%";
    cout << " DEF: +" << (stoi(armour_def_bonus) - 1) * 100 << "%";
    cout << " AGI: +" << (stoi(armour_agi_bonus) - 1) * 100 << "%";

  }  
  
}

// Purpose: Printing out the monster status
void Monster::PrintStatus() {
  cout << name << " HP: " << hp << " STR: " << str << " DEF: " 
  << def << " AGI: " << agi << endl;
}
