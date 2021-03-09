// ENGG 1340 Group 137 Project
//
// Developer: Chan Tsz Ho  (3035785738)
//            Chan Yuk Yin (3035786574)
//
// Description: This is a text-based role-playing game which is set in 
// a dark medieval fantasy world. You the player will act as an adventurer 
// in the game. By acquiring strength and powerful equipment through combating
// monsters spread throughout the world, player will eventually be able to 
// fight the Monster King and save mankind to win the game.

#include <iostream>
using namespace std;

// Purpose: For storing various status of the player and providing useful 
// functions to set and print status of the player
class Player
{
  public :
    bool death = false ; // Check the player is dead or not
    string name ; // To save the player name
    string career ; // To store the job selection of the player

    long long hp_basic ; //variables for the hp
    double item_hp_multiplier = 1 ; 
    long long hp_actual ;

    long long str_basic ; //variables for the strength
    double item_str_multiplier = 1 ;
    long long str_actual ;

    long long def_basic ; //variables for the defense
    double item_def_multiplier = 1 ;
    long long def_actual ;

    long long agi_basic ;  //variables for the agility
    double item_agi_multiplier = 1 ;
    long long agi_actual ;

    int level = 1 ; //variables for storing player xp levels and money
    int exp = 0 ;
    double xp_multiplier ;
    int skill_pt = 0 ;
    int money = 0 ;
    int money_multiplier ;
    
    // Purpose: This function is to initialize the status of the player
    void set_status(long long hp_basic, long long str_basic, 
                    long long def_basic, long long agi_basic, string career) {   
      this -> hp_basic = hp_basic ;
      this -> str_basic = str_basic ;
      this -> def_basic = def_basic ;
      this -> agi_basic = agi_basic ;
      this -> career = career ;
    }

    // Purpose: This function is to print the status of the player
    void print_status() {
      cout << name << " hp: "<< hp_actual << " strength: " << str_actual 
      << " defense: " << def_actual << " and agility: " << agi_actual << endl ;
    }
};

int main() {
  
  return 0;
}