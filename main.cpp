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

// Purpose: For storing various status of the monster and providing useful 
// functions to print status of the monster
class Monster {
  public:
    int level;
    int hp; 
    int str; 
    int def; 
    int agi;
    
    // Purpose: Printing out the monster status
    void PrintStatus() {
      cout << "Monster  hp: "<< hp << " strength: " << str << " defense: " 
      << def << " and agility: " << agi << endl;
    }
} ;

// Purpose: Print out a line of user specified symbol and length
void Line(char symbol, int noOfSym = 85) {   
  string output;
  for (int i = 0; i < noOfSym; i++) {
    output.push_back(symbol) ;
  }
  cout << output << endl ;
}

// Purpose: Pause the game for (time) miliseconds
void Pause(int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
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

// Purpose: For saving the game
void SaveGame(Player player) {
  ofstream file("rpg_save");
  file << player.name;
  file << "\n";
  file << player.career;
  file << "\n";
  file << player.hp_basic;
  file << "\n";
  file << player.str_basic;
  file << "\n";
  file << player.def_basic;
  file << "\n";
  file << player.agi_basic;
  file << "\n";
  file << player.level;
  file << "\n";
  file << player.exp;
  file << "\n";
  file << player.skill_pt;
  file << "\n";
  file << player.money;
  file << "\n";
}

// Input: Player object for storing the retrieved data from file
// Purpose: Loading the saved progress of previous game
void LoadGame(Player &player) {
  ifstream file("rpg_save");
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

// Input: Player object for recording the name of the player
// Purpose: Function to get the name of the player
void GetName(Player &player) {   
  string name;
  cout << "What is your name adventurer ? ";
  cin >> name;
  cout << "Welcome " << name << endl;
  player.name = name;
}

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
  cout << "Enter 1 for Adventurer Class ,"
  << " 2 for Warrior and 3 for Assassin" << endl;
  cin >> career_choice;
    

  // Assign character status
  switch (career_choice) {   
    // hp str def agi career
    case 1:
      player.set_status(1000, 100, 100, 100, "Adventurer");
      break;
    case 2:
      player.set_status(2000, 150, 200, 50, "Warrior");
      break;
    case 3:
      player.set_status(800, 250, 50, 200, "Assassian");
      break;
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

Monster CombatLevelSelection(Player player) {
  int monster_level;
  Monster monster;
  bool confirm_choice = false;
    
    // Monster level selection
  while (confirm_choice == false) {   
    cout << "What level of monster you want to fight ? ";
    cin >> monster_level;
    
    monster.level = monster_level;
    monster.hp = 500 * monster_level;
    monster.str = 100 * log2(monster_level + 1);
    monster.def = 50 *  log2(monster_level + 1);
    monster.agi = 50 * log2(monster_level + 1);
    cout << "Are you sure you want to fight level " 
    << monster_level << " monster with " << endl;
    monster.PrintStatus();
    player.PrintStatus();

    cout << "YES[1] \t No[0] " << endl;
    cin >> confirm_choice;
    }

    return monster;
}

// Purpose: Function for calculating the attack modifier 
// based on strength and defense
double CombatMultipler(int attack_str, int defend_def) {
  double ratio = attack_str * 1.0 / defend_def;
  return 4 / (1 + exp(-ratio)) - 2;
}

// Purpose: To determine whether a hit is successful or not
// Mechanism : Create a bound of a randomly generate number by the ratio of agility of both sides
// the higher the ratio, the more large the bound , hence a hit is more likely
bool CombatIsHit(int attack_agi, int defend_agi) {    
  double max = attack_agi * 100 / defend_agi;

  if ( rand() % 100 + 1 <= max ) {
    return true;
  }
  return false;
}

// Purpose: To calculate health reduction of monster(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatPlayerAttack(Player &player, Monster &monster) {
  Pause(500);

  cout << endl;
  cout << "It is the player's turn to attack" << endl; 

  if (CombatIsHit(player.agi_actual * player.item_agi_multiplier,
      monster.agi)) {   
    int player_att = player.str_actual * player.item_str_multiplier 
    * CombatMultipler(player.str_actual
    * player.item_str_multiplier, monster.def);

    monster.hp -= player_att;

    cout << "You have dealt " << player_att 
    << " damage to the monster" << endl;

    cout << player.name << " HP : " << player.hp_actual << " Monster HP: " 
    << monster.hp << endl;
  } else {
    cout << "Monster evaded your attack" << endl;
    }
}

// Purpose: To calculate health reduction of player(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatMonsterAttack(Player &player, Monster &monster) {
    Pause(500);
    
    cout << "It is the Monster's turn to attack" << endl; 

    if (CombatIsHit(monster.agi, player.agi_actual 
        * player.item_agi_multiplier)) {   
      int monster_att = monster.str 
      * CombatMultipler(monster.str, player.def_actual 
      * player.item_def_multiplier);

      player.hp_actual -= monster_att;
      
      cout << "Monster have dealt " << monster_att 
      << " damage to you" << endl;

      cout << player.name << " HP : " << player.hp_actual 
      << " Monster HP: " << monster.hp << endl;

    } else {
      cout << "You have evaded monster's attack" << endl;
    }
}

// Purpose: To determine the outcome of the combat with the monster
// Experience point and money gained is calculated using the level
// of monster that the player defeated
void CombatReward(Player &player, int combat_result) {
  if (combat_result != -1) {
    player.exp += 100 * combat_result;
    player.money += 50 * combat_result;
    cout << "You have acquried " << "$" << 100 * combat_result  << endl ;
    cout << "You have acquried " << 100 * combat_result 
    << " XP points" << endl ;

  } else { 
    player.death = true ;
    }
}

// Purpose: Function to get the action take by the player
void GetAction(Player &player/*, Shop shop*/) {   
  int action;
  int combat_result;

  line('*');
  cout << "DEEP DARK FANTASY" << endl;
  cout << "Name : " << player.name 
  << "\t\t\t\t HP : " << player.hp_actual << endl;

  cout << "Career : " << player.career 
  << "\t\t\t STR : " << player.str_actual << endl;

  cout << "Level : " << player.level << "(" << player.exp << "/" 
  << 50*player.level*player.level << ")" << "\t\t\t DEF : " 
  << player.def_actual << endl;

  cout << "$" << player.money << "\t\t\t\t\t AGI : " 
  << player.agi_actual << endl;

  line('-');
  cout << "Quit[1] \t Fight[2] \t Shop[3] \t Skill[4]" << endl;
  cout << "Status[5]" << endl;
  line('*');

  cin >> action;
  
  //To determine which action to be taken
  switch(action) {   
    case 1:
      player.death = true;
      break;
    case 2: // Combat
      combat_result = Combat(player, shop);
      CombatReward(player, combat_result);
      SaveGame(player);
      break;
    /*case 3: // Shop
      shop_access(player , shop);
      SaveGame(player);
      break; */
    /*case 4: // Skill points assignment
      skill_pt(player);
      player_equipment_effect(player, shop);
      SaveGame(player);
      break;*/ 
    /*case 5: // Player status
      player_detail_status(player, shop);
      SaveGame(player);
      break;*/
  }
} 

//main function
int main() {
  Player player;

  DisplayWelcomeMenu();

  return 0;
}


