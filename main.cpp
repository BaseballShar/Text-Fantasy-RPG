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
#include <fstream>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Purpose: For storing various status of the player and providing useful 
// functions to set and print status of the player
class Player
{
  public:
    bool death = false; // Check the player is dead or not
    string name; // To save the player name
    string career; // To store the job selection of the player

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
    
    // Input: Basic status and career of the player
    // Purpose: This function is to initialize the status of the player
    void SetStatus(long long hp_basic, long long str_basic, 
                    long long def_basic, long long agi_basic, string career) {   
      this -> hp_basic = hp_basic;
      this -> str_basic = str_basic;
      this -> def_basic = def_basic;
      this -> agi_basic = agi_basic;
      this -> career = career;
    }

    // Purpose: This function is to print the status of the player
    void PrintStatus() {
      cout << name << " hp: " << hp_actual << " strength: " << str_actual 
      << " defense: " << def_actual << " and agility: " << agi_actual << endl;
    }
};

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
bool IsOldPlayer() {   
  int has_played;

  cout << "Have you played this game before ?" << endl;
  cout << "Enter 1 if you haven't , 2 if you have : ";
  cin >> has_played ;

  switch(has_played) {
    case 1:
      return false;

    case 2:
      return true;

    default:
      return false;
  }   
}

// Purpose: Loading the saved progress of previous game
void LoadGame(Player &player) {
    ifstream file ("rpg_save");
    file >> player.name;
    file >> player.career;
    file >> player.hp_basic;
    file >> player.str_basic;
    file >> player.def_basic;
    file >> player.agi_basic;
    file >> player.level;
    file >> player.exp;
    file >> player.skill_pt;
    file >> player.money;
}

// Purpose: Function to get the name of the player
void GetName(Player &player) {   
    string name;
    cout << "What is your name adventurer ? ";
    cin >> name;
    cout << "Welcome " << name << "" << endl;
    player.name = name;
}

// Purpose: FUnction to get the career of the player
void GetCareer(int pause_career, Player &player) {   
  // Display avaliable choices
  int career_choice; 
  cout << "What do you want to do now ?" << endl;
  cout << "Here are the list of careers you can choose from" << endl;
  pause (pause_career);
  cout << "Adventurer Class : Human with average abilities " << endl;
  pause (pause_career);
  cout << "Warrior Class : Human with moderately high strength and superior defense but low mobility "<< endl;
  pause (pause_career);
  cout << "Assassin Class : Human with strong attack , rapid movement but lack defense "<< endl;
  cout << "Enter 1 for Adventurer Class , 2 for Warrior and 3 for Assassin" << endl;
  cin >> career_choice;
    

    // Assign character status
    switch (career_choice)
    {   
        // hp str def agi career
        case 1 :
            player.set_status(1000, 100, 100, 100, "Adventurer") ;
            break ;

        case 2 :
            player.set_status(2000, 150, 200, 50, "Warrior") ;
            break ;

        case 3 :
            player.set_status(800, 250, 50, 200, "Assassian") ;
            break ;
    }

}

// Purpose: Functions for displaying the welcome message
// If player has played before, saved progress will be loaded
// If player has not played before, new character profile will be created
void DisplayWelcomeMenu() {
  cout << "Welcome to Deep Dark Fantasy" << endl;
  
  if (IsOldPlayer()) {
    LoadGame(player);
  } else {  
    PrintStory(); 
    GetName(player);
    GetCareer(100, player); // 100 ms pause
  }
} 

//main function
int main() {
  
  Player player;
  return 0;
}


