// ENGG 1340 Group 137 Project
//
// Developers: Chan Tsz Ho  (3035785738)
//             Chan Yuk Yin (3035786574)
//
// Description: This is a text-based role-playing game which is set in 
// a dark medieval fantasy world. You the player will act as an adventurer 
// in the game. By acquiring strength and powerful equipment through combating
// monsters spread throughout the world, player will eventually be able to 
// fight the Monster King and save mankind to win the game.

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "combat.h" // for combat related functions and classes
#include "character.h" // for player and monster classes
#include "skill_points.h" // for handling skill points
#include "shop.h" // for handling shops
using namespace std;

// Input: char symbol: symbol that will be printed
//        int no noOfSym: number of symbols to be printed
// Purpose: Print out a line of user specified symbol and length
void Line(char symbol, int noOfSym = 75) {   
  string output;
  for (int i = 0; i < noOfSym; i++) {
    output.push_back(symbol) ;
  }
  cout << output << endl ;
}

// Purpose: Print out the game story
void PrintStory() {
  string story = "You were a hardworking programmer in an international IT\n"
  "company,you had contributed to the company with all your heart and soul.\n"
  "However, you recently discovered that your boss had been stealing your idea\n"
  "and presenting it to the central which brought him wealth and fame.\n"
  "You were so outraged that you grabbed a keyboard nearby and smashed it\n"
  "against your boss.\n\n"
  "Not knowing why you missed it!\n"
  "The keyboard crashed onto the monitor and the electrical wires inside\n"
  "were in contact with your hand. It was too late to retract your hands.\n"
  "Suddenly, a blue portal emerged near the desk and you were teleported to\n"
  "a strange new world.\n\n"   
  "And now! You are destinated to be the hero of this world!\n"
  "Fight the three most horrible Monsters to take their maps!\n"
  "The maps lead you to fight the King Of Boss \"Infinite Comments Client\"!\n"
  "The world needs your power!\n";
  cout << story << endl;
}

// Purpose: For checking whether the player has played the game before
// Output: true (if the player has played before)
//         false (if the player has not played before)
bool IsOldPlayer() {   
  string has_played;
  bool is_valid = false;

  while (!is_valid) {
    cout << "Have you played this game before ?" << endl;
    cout << "[0]Have not    [1]Have" << endl;
    cout << "Enter the number in brackets to select the action: ";
    cin >> has_played ;
    is_valid = true;
    if (has_played != "0" && has_played != "1") {
      is_valid = false;
      cout << "Please enter valid input!" << endl;
    }
  }
  return (has_played == "1")? true : false;
}

// Input: Player and shop object for outputing the data to file
// Purpose: Save progress of game
void SaveGame(Player player, Shop shop) {
  ofstream fileout("rpg_save");

  //saving player status
  fileout << player.name << endl;
  fileout << player.career << endl;
  fileout << player.hp_basic << endl;
  fileout << player.str_basic << endl;
  fileout << player.def_basic << endl;
  fileout << player.agi_basic << endl;
  fileout << player.level << endl;
  fileout << player.exp << endl;
  fileout << player.skill_pt << endl;
  fileout << player.money << endl;
  fileout << player.num_map << endl;
  fileout << player.num_token << endl;

  // saving player armour and weapon
  fileout << player.armour << endl;
  fileout << player.weapon << endl;

  // saving player armour status
  for (int i = 0; i < shop.armour.len; i++) {
    fileout << shop.armour.Extract(i) << endl;
  }

  // saving player weapon status
  for (int i = 0; i < shop.weapon.len; i++) {
    fileout << shop.weapon.Extract(i) << endl;
  }
}

// Input: Player and shop object for storing the retrieved data from file
// Purpose: Loading the saved progress of previous game
void LoadGame(Player &player, Shop &shop) {
  ifstream filein("rpg_save");
  // loading player status
  filein >> player.name;
  filein >> player.career;
  filein >> player.hp_basic;
  filein >> player.str_basic;
  filein >> player.def_basic;
  filein >> player.agi_basic;
  filein >> player.level;
  filein >> player.exp;
  filein >> player.skill_pt;
  filein >> player.money;
  filein >> player.num_map;
  filein >> player.num_token;

  int num_armour = shop.armour.len;
  int num_weapon = shop.weapon.len;
  string temp;

  getline(filein, temp);
  getline(filein, player.armour);
  getline(filein, player.weapon);

  // Load the armours that player has purchased
  // The cost of these armours will be sent to 0
  shop.armour.DeleteAll();

  for (int i = 0; i < num_armour; i++) {
    getline(filein, temp);
    shop.armour.Append(temp);
  }

  // Load the weapons that player has purchased
  // The cost of these weapons will be sent to 0
  shop.weapon.DeleteAll();
  for (int i = 0; i < num_weapon; i++) {
    getline(filein, temp);
    shop.weapon.Append(temp);
  }
}

// Input: Player and shop object for recording the name of the player
// Purpose: Function to get the name of the player
void GetName(Player &player) {   
  string name;

  cout << "What is your name adventurer ? ";
  getline(cin, name);
  getline(cin, name);
  cout << "Welcome " << name << endl;
  player.name = name;
}

// Input: int pause_career (Time to be paused between lines in ms)
//        Player player (Player object for storing the career)
// Purpose: Function to get the career of the player
void GetCareer(int pause_career, Player &player) {   
  // Display avaliable choices
  int career_choice; 
  
  cout << "Here are the list of careers that you can choose from" << endl;
  Pause(pause_career);
  cout << "Adventurer Class: Human with average abilities " << endl;
  Pause(pause_career);
  cout << "Warrior Class: Human with moderately high strength"
  << " and superior defense but low mobility " << endl;
  Pause(pause_career);
  cout << "Assassin Class: Human with strong attack, rapid movement" 
  << " but lack defense " << endl;
  cout << "[1]Adventurer    [2]Warrior    [3]Assassin" << endl;
  cout << "Enter the number in brackets to select the action: ";
  cin >> career_choice;
    

  // Assign character status
  switch (career_choice) {   
    // hp str def agi career
    case 1:
      player.SetStatus(1000, 100, 100, 100, "Adventurer");
      break;
    case 2:
      player.SetStatus(2000, 150, 200, 50, "Warrior");
      break;
    case 3:
      player.SetStatus(800, 250, 50, 200, "Assassian");
      break;
  }

}

// Purpose: Functions for displaying the welcome message and initializing game
// If player has played before, saved progress will be loaded
// If player has not played before, new character profile will be created
void DisplayWelcomeMenu(Player &player, Shop &shop) {
  cout << "Welcome to Deep Dark Fantasy" << endl;
  
  if (IsOldPlayer()) {
    LoadGame(player, shop);
  } else {  
    PrintStory(); 
    GetName(player);
    GetCareer(500, player); // 500 ms pause
  }
} 

// Input: Player player (Player object for retrieving data to print)
// Purpose: Printing the status and equipments owned by the player
void PrintPlayerDetailStatus(Player player) {
  Line('*'); // separator
  // printing status of player
  cout << "DEEP DARK FANTASY" << endl;
  cout << left;
  cout << setw(30) << "Name: " + player.name  << 
  "HP: " << player.hp_actual << "(Basic: " << player.hp_basic << ")" << endl;

  cout << setw(30) << "Career: " + player.career << "STR: ";
  cout << player.str_actual << "(Basic: " << player.str_basic << ")"<< endl;

  cout << setw(30) << "Level: " + to_string(player.level) + "(" + to_string(player.exp) + "/" 
  + to_string(50 * player.level * player.level) + ")" << "DEF: " 
  << player.def_actual << "(Basic: " << player.def_basic << ")" <<  endl;

  cout << setw(30) << "$" + to_string(player.money) << "AGI: " 
  << player.agi_actual << "(Basic: " << player.agi_basic << ")" << endl;

  cout << setw(30) << "Map(" + to_string(player.num_map) + "/3)" 
  << "Token: " + to_string(player.num_token) << endl;
  
  cout << "Skill Points: " << player.skill_pt << endl;

  // printing equipment weared by player
  player.PrintEquipment();

  Line('-'); // separator
  cout << setw(20) << "[1]Fight" << setw(20) << "[2]Shop";
  cout << setw(20) << "[3]Skill" << endl;
  cout << setw(20) << "[4]Help" << setw(20) << "[5]Quit" << endl;

  Line('*'); // separator

  cout << "Enter the number in brackets to select the action: ";
}

// Input: Player player (Player object for storing and loading data)
//        Shop shop (Shop object for storing and loading data)
// Purpose: Function to get the action requested by the player
void GetAction(Player &player, Shop shop) {   
  string action;
  int combat_result;

  PrintPlayerDetailStatus(player);

  cin >> action;
  cout << endl;

  // To determine which action to be taken
  if (action == "1") {  // Combat
      combat_result = Combat(player, shop);
      CombatReward(player, combat_result);
      SaveGame(player, shop);
  } else if (action == "2") { // Shop
      MakePurchase(player, shop);
      SaveGame(player, shop);
  } else if (action == "3") { // Skill points assignment
      SkillPoint(player);
      SaveGame(player, shop);
  } else if (action == "4") {
  } else if (action == "5") { // Quit game
      player.death = true;
  } else {
    cout << "Please enter valid input!" << endl;
  }
} 

// Input: Player player (Player object for storing the amended status)
// Purpose: To apply the effects of equipment on player
void PlayerEquipmentEffect (Player &player) {
  string cost; // storing irrelavent data
  string name; // storing irrelavent data

  // status multipliers associated with weared armour
  string armour_hp_bonus = "";
  string armour_str_bonus = "";
  string armour_def_bonus = "";
  string armour_agi_bonus = "";

  // status multipliers associated with equipped weapon
  string weapon_hp_bonus = "";
  string weapon_str_bonus = "";
  string weapon_def_bonus = "";
  string weapon_agi_bonus = "";

  // if player has not weared armour
  if (player.armour != "") {
  istringstream armour_str(player.armour);

  // Processing armour data
  armour_str >> cost;
  armour_str >> name;
  armour_str >> armour_hp_bonus;
  armour_str >> armour_str_bonus;
  armour_str >> armour_def_bonus;
  armour_str >> armour_agi_bonus;

  } else {
    // if player has not equipped any armour, there will be no bonus
    armour_hp_bonus = "1";
    armour_str_bonus = "1";
    armour_def_bonus = "1";
    armour_agi_bonus = "1";
  }

  // if the player has not equipped weapon
  if (player.weapon != "") {
  istringstream weapon_str(player.weapon);

  // Processing weapon data
  weapon_str >> cost;
  weapon_str >> name;
  weapon_str >> weapon_hp_bonus;
  weapon_str >> weapon_str_bonus;
  weapon_str >> weapon_def_bonus;
  weapon_str >> weapon_agi_bonus;
  } else {
    // if player has not equipped any weapon, there will be no bonus
    weapon_hp_bonus = "1";
    weapon_str_bonus = "1";
    weapon_def_bonus = "1";
    weapon_agi_bonus = "1";
  }
  
  // Adding armour and weapon effect to player's status
  player.hp_actual = player.hp_basic * stod(weapon_hp_bonus)
                    * stod(armour_hp_bonus);
  player.str_actual = player.str_basic * stod(weapon_str_bonus)
                    * stod(armour_str_bonus);
  player.def_actual = player.def_basic * stod(weapon_def_bonus)
                    * stod(armour_def_bonus);
  player.agi_actual = player.agi_basic * stod(weapon_agi_bonus)
                    * stod(armour_agi_bonus);
}

// Purpose: Print out the content after the boss is defeated
void DisplayEndGame () {
  cout << "Congradulation, you have defeated the Infinite Comment Client. ";
  cout << endl << "A portal emerged and you are teleported to the office ";
  cout << endl << "It's like nothing has happened, but upon ";
  cout << "closer observation" << endl << "You found both ";
  cout << "the boss and the annoying client has disappeared." << endl;
  cout << "Thank you for playing" << endl;
}

//main function
int main() {
  Player player;
  Shop shop;

  // Greeting and initializing game character and shop
  DisplayWelcomeMenu(player, shop);

  // Playing session
  while (player.death == false) {
    PlayerEquipmentEffect(player);
    GetAction(player, shop);
    // if player is still alive
    if (player.death == false && !player.is_boss_defeated) {
      LevelUpdate(player);
      SaveGame(player, shop);
    }
    // if the boss is defeated
    else if (player.is_boss_defeated) {
      DisplayEndGame();
      player.death = true;
    }
  }
    return 0;
}
