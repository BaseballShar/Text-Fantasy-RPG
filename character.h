#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "list.h"

using namespace std;

// Purpose: For storing various status of the player and providing useful 
// functions to set and print status of the player
class Player
{
  public:
    bool death = false; // Check the player is dead or not
    string name; // To save the player name
    string career; // To store the job selection of the player
    int num_map = 0; // To store the number of maps the player owns
    int num_token = 0; // To store the number of tokens the player owns

    long long hp_basic; // Variables for the hp
    double item_hp_multiplier = 1; 
    long long hp_actual;

    long long str_basic; // Variables for the strength
    double item_str_multiplier = 1;
    long long str_actual;

    long long def_basic; // Variables for the defense
    double item_def_multiplier = 1;
    long long def_actual;

    long long agi_basic;  // Variables for the agility
    double item_agi_multiplier = 1;
    long long agi_actual;

    int level = 1; // Variables for storing player xp levels and money
    int exp = 0;
    double xp_multiplier;
    int skill_pt = 0;
    int money = 0;
    int money_multiplier;
    

    int monster_name_len; // record the length of monster name for status print
    bool is_boss_defeated = false;

    // Memory for storing the player's armour status
    string armour = "";

    // Memory for storing player's weapon status
    string weapon = "";

    // Input: Basic status and career of the player
    // Purpose: This function is to initialize the status of the player
    void SetStatus(long long hp_basic, long long str_basic, 
                    long long def_basic, long long agi_basic, string career);

    // Purpose: This function is to print the status of the player
    void PrintStatus();

    // Purpise: This function is to print the equipment equipped by the player
    void PrintEquipment();
};

// Purpose: For storing various status of the monster and providing useful 
// functions to print status of the monster
class Monster {
  public:
    // Monster status
    string name = "Monster";
    int level;
    int hp; 
    int str; 
    int def; 
    int agi;
    
    int player_name_len; // record the length player name for status print

    bool is_boss; // whether the monster is a boss
    bool is_exit = false; // whether the player wants to exit combat
    // Purpose: Printing out the monster status
    void PrintStatus();
};

#endif
