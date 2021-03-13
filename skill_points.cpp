#include <iostream>
#include "skill_points.h"
using namespace std;

void SkillPoint(Player &player) {   
  while (player.skill_pt > 0) {   
    int option;
    int assign_choice;
    int num_of_skill_pt;
    
    cout << "[1] Assign skill points  [2] Exit skill point system" << endl;
    cin >> option;

  
  switch (option) {   
    case 1:
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

          switch(assign_choice) {
            case 1:
              cout << "How much skill points you would like to assign ?";
              cin >> num_of_skill_pt;

              if (num_of_skill_pt <= player.skill_pt) {
                player.hp_basic *= pow(1.1, num_of_skill_pt);
                player.skill_pt -= num_of_skill_pt;
                cout << "You have successfully assigned "<< num_of_skill_pt << " skill point to hp" << endl;
                cout << "Your new hp becomes " << player.hp_basic << endl;
              } else {
                cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
              }
              break;

            case 2:
              cout << "How much skill points you would like to assign ?";
              cin >> num_of_skill_pt;
              if (num_of_skill_pt <= player.skill_pt) {
                player.str_basic *= pow(1.05, num_of_skill_pt);
                player.skill_pt -= num_of_skill_pt;
                cout << "You have successfully assigned "<< num_of_skill_pt << " skill point to str" << endl;
                cout << "Your new str becomes " << player.str_basic << endl;
              } else {
                cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
                }
                break;

            case 3 :
              cout << "How much skill points you would like to assign ?";
              cin >> num_of_skill_pt;
              if (num_of_skill_pt <= player.skill_pt) {
                player.def_basic *= pow(1.05, num_of_skill_pt);
                player.skill_pt -= num_of_skill_pt;
                cout << "You have successfully assigned "<< num_of_skill_pt << " skill point to def" << endl;
                cout << "Your new def becomes " << player.def_basic << endl;
              } else {
                cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
                }
              break;

            case 4 :
              cout << "How much skill points you would like to assign ?";
              cin >> num_of_skill_pt;
              if (num_of_skill_pt <= player.skill_pt) {
                player.agi_basic *= pow(1.05, num_of_skill_pt);
                player.skill_pt -= num_of_skill_pt;
                cout << "You have successfully assigned "<< num_of_skill_pt << " skill point to agi" << endl;
                cout << "Your new agi becomes " << player.agi_basic << endl;
              } else {
                cout << "You have not enough skill points to assign, fight some monsters to acquire skill points" << endl;
                }
              break;
          }
         } while (assign_choice != 5 && player.skill_pt > 0);

    case 2:
      return;
  
  }

    if (player.skill_pt == 0) {
      cout << "You have no skill points to assign, fight some monsters to acquire skill points" << endl;
    return;
    }
  }
}

void LevelUpdate (Player &player) {   
  while (player.exp >= 50 * player.level*player.level) {      
    player.exp -= 50 * player.level*player.level;
    player.level += 1;
    player.skill_pt += 4 + player.level;

    cout << "You have acquired " << 4 + player.level <<" skill points" << endl;
  }

  cout << "Your are now level " << player.level << endl;
  cout << endl;
}
