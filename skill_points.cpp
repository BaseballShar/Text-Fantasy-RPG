#include <iostream>
#include <cstdlib>
#include "skill_points.h"
using namespace std;

// Purpose: To assign skill points to HP
void UpgradeHP(Player &player) {
  string num_assign_skill_pt_str;
  int num_assign_skill_pt;

  cout << "How much skill points you would like to assign ?";
  cin >> num_assign_skill_pt_str;
              
  // Prevent invalid input
  if (IsNum(num_assign_skill_pt_str)) {
    num_assign_skill_pt = stoi(num_assign_skill_pt_str);

  // Check whether the player has sufficient skills points 
    if (num_assign_skill_pt <= player.skill_pt) {
      player.hp_basic *= pow(1.1, num_assign_skill_pt);
      player.skill_pt -= num_assign_skill_pt;
      cout << "You have successfully assigned "<< num_assign_skill_pt << " skill point to HP" << endl;
      cout << "Your new basic HP becomes " << player.hp_basic << endl;
    } else {
      cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
    }
    // Handle invalid input
  } else {
    cout << "Please enter valid input" << endl;
  } 
}

// Purpose: To assign skill points to STR
void UpgradeSTR(Player &player) {
  string num_assign_skill_pt_str;
  int num_assign_skill_pt;

  cout << "How much skill points you would like to assign ?";
  cin >> num_assign_skill_pt_str;
              
  // Prevent invalid input
  if (IsNum(num_assign_skill_pt_str)) {
    num_assign_skill_pt = stoi(num_assign_skill_pt_str);

  // Check whether the player has sufficient skills points 
    if (num_assign_skill_pt <= player.skill_pt) {
      player.str_basic *= pow(1.1, num_assign_skill_pt);
      player.skill_pt -= num_assign_skill_pt;
      cout << "You have successfully assigned "<< num_assign_skill_pt << " skill point to STR" << endl;
      cout << "Your new basic STR becomes " << player.str_basic << endl;
    } else {
      cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
    }
    // Handle invalid input
  } else {
    cout << "Please enter valid input" << endl;
  } 
}

// Purpose: To assign skill points to DEF
void UpgradeDEF(Player &player) {
  string num_assign_skill_pt_str;
  int num_assign_skill_pt;

  cout << "How much skill points you would like to assign ?";
  cin >> num_assign_skill_pt_str;
              
  // Prevent invalid input
  if (IsNum(num_assign_skill_pt_str)) {
    num_assign_skill_pt = stoi(num_assign_skill_pt_str);

  // Check whether the player has sufficient skills points 
    if (num_assign_skill_pt <= player.skill_pt) {
      player.def_basic *= pow(1.1, num_assign_skill_pt);
      player.skill_pt -= num_assign_skill_pt;
      cout << "You have successfully assigned "<< num_assign_skill_pt << " skill point to DEF" << endl;
      cout << "Your new basic DEF becomes " << player.def_basic << endl;
    } else {
      cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
    }
    // Handle invalid input
  } else {
    cout << "Please enter valid input" << endl;
  } 
}

// Purpose: To assign skill points to AGI
void UpgradeAGI(Player &player) {
  string num_assign_skill_pt_str;
  int num_assign_skill_pt;

  cout << "How much skill points you would like to assign ?";
  cin >> num_assign_skill_pt_str;
              
  // Prevent invalid input
  if (IsNum(num_assign_skill_pt_str)) {
    num_assign_skill_pt = stoi(num_assign_skill_pt_str);

  // Check whether the player has sufficient skills points 
    if (num_assign_skill_pt <= player.skill_pt) {
      player.agi_basic *= pow(1.1, num_assign_skill_pt);
      player.skill_pt -= num_assign_skill_pt;
      cout << "You have successfully assigned "<< num_assign_skill_pt << " skill point to AGI" << endl;
      cout << "Your new basic AGI becomes " << player.agi_basic << endl;
    } else {
      cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
    }
    // Handle invalid input
  } else {
    cout << "Please enter valid input" << endl;
  } 
}

// Purpose: To be in charge of the skill point system
void SkillPoint(Player &player) {   
  while (player.skill_pt > 0) {   
    string option; // variable for choosing skill point actions
    string assign_choice; // variable for choosing what status to upgrade
    string num_of_skill_pt_str;
    int num_of_skill_pt;
    
    cout << "[0] Exit    [1] Assign Skill Points" << endl;
    cin >> option;
    
    if (option == "1") {
        do {   
          cout << endl ;
          cout << "You currently have " << player.skill_pt << " skill points " << endl;
          cout << "Which Ability do you want to level up ?"  << endl ;
          cout << "[1] Assign a skill point to HP can increase your hp by 10% from " << player.hp_basic << " to " << floor(player.hp_basic*1.1) << endl;
          cout << "[2] Assign a skill point to Strength can increase your str by 5% from " << player.str_basic << " to " << floor(player.str_basic*1.05) << endl;
          cout << "[3] Assign a skill point to Defense can increase your def by 5% from " << player.def_basic << " to " << floor(player.def_basic*1.05) << endl;
          cout << "[4] Assign a skill point to Agility can increase your agi by 5% from " << player.agi_basic << " to " << floor(player.agi_basic*1.05) << endl;
          cout << "[5] Finish assignment" << endl;

          cin >> assign_choice ;

            // Upgrade HP
            if (assign_choice == "1") {
              UpgradeHP(player);
            // Upgrade STR
            } else if (assign_choice == "2") {
              UpgradeSTR(player);
            // Upgrade DEF
            } else if (assign_choice == "3") {
              UpgradeDEF(player);
            // Upgrade AGI
            } else if (assign_choice == "4") {
              UpgradeAGI(player);
            }
         } while (assign_choice != "5" && player.skill_pt > 0);
    } else if (option == "0") {
      return;
    } else {
      cout << "Please enter valid input!" << endl;
    }
  
    // When player has no skill points left
   if (player.skill_pt == 0) {
    cout << "You have no skill points to assign, fight some monsters to acquire skill points" << endl;
   }
  }
}

// Purpose: To update the level status of the player
void LevelUpdate (Player &player) {   
  while (player.exp >= 50 * player.level*player.level) {      
    player.exp -= 50 * player.level*player.level;
    player.level += 1;
    // Player gains skill points when leveling up
    player.skill_pt += 4 + player.level;

    cout << "You have acquired " << 4 + player.level <<" skill points" << endl;
    cout << "Your are now level " << player.level << endl;
  }
  cout << endl;
}
