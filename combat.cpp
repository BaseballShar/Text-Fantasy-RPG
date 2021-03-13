#include "combat.h"
using namespace std;

// Purpose: Pause the game for (time) miliseconds
void Pause(int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
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

// Purpose: To be in charge of the whole combat situation
// From monster creation, combating, to reward distribution
int Combat (Player &player/*, Shop shop*/) {   
    //bool auto_combat = player.setting[0].second ;
    
    // Backup character data 
    Player player_backup = player; // Disallow status to changing while recording item comsumption
    
    // Update player status 
    //player_equipment_effect(player, shop) ;

    // Creation of monster
    Monster monster = CombatLevelSelection(player);
    
    // Fighting with monster   
    while (player.hp_actual > 0 && monster.hp > 0) {   
      /*if (auto_combat == false) {   
        int player_option;
        cout << "What do you want to do next ? " << endl;
        cout << "Enter 1 for normal attack  " << endl;
        cout << "Enter 2 for using items  " << endl;
        cin >> player_option;

        switch(player_option) {
          case 1 :
            CombatPlayerAttack (player, monster);
            break ;
          case 2 :
            //combat_player_use_item (player, player_backup);
            break;
        }

      } else {*/
        CombatPlayerAttack(player, monster);
        //} 

        if (!(player.hp_actual > 0 && monster.hp > 0)) {
          break;
        }

        CombatMonsterAttack(player, monster);      
    }
    
    // Combat outcome
    if (player.hp_actual > 0) {   
        cout << "You have defeated the monster !!! " << endl;

        // regenerate character status
        player = player_backup;

        return monster.level;
    } else {   
        cout << "You have been defeated " << endl;
        return -1;
    }
}
