#include "combat.h"
#include <cstdlib>
#include <ctime>

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

  srand(time(0));
  if ( rand() % 100 + 1 <= max ) {
    return true;
  }
  return false;
}

void CombatPlayerRandomEvent(Player &player) {
  srand(time(0));
  int rand_num = rand() % 100;
    
  if (rand_num <= 9) {
    cout << "Random event!: Lightening strike" << endl;
    cout << player.name + " received " << (int) (0.025 * (rand_num + 1) * player.hp_actual); 
    cout << " damage " << endl;

    player.hp_actual *= (1 - 0.025 * (rand_num + 1));
    player.PrintStatus();

  } else if (rand_num <= 19) {
    cout << "Random event!: HEALING" << endl;
    cout << player.name + " received " << (int) (0.025 * (rand_num - 9) * player.hp_actual);
    cout << " healing " << endl;
      
    player.hp_actual *= (1 + 0.025 * (rand_num - 9));
    player.PrintStatus();

  } else if (rand_num <= 22) {
    cout << "Random event!: Strength Buff" << endl;
    player.str_actual *= 1.25;
    cout << player.name + " Strength increased to " << player.str_actual << endl;
    player.PrintStatus();

  } else if (rand_num <= 25) {
    cout << "Random event!: Strength Debuff" << endl;
    player.str_actual *= 0.75;
    cout << player.name + " Strength decreased to " << player.str_actual << endl;
    player.PrintStatus(); 

  } else if (rand_num <= 28) {
    cout << "Random event!: Defense Buff" << endl;
    player.def_actual *= 1.25;
    cout << player.name + " Defense increased to " << player.def_actual << endl;
    player.PrintStatus(); 

  } else if (rand_num <= 31) {
    cout << "Random event!: Defense Debuff" << endl;
    player.def_actual *= 0.75;
    cout << player.name + " Defense decreased to " << player.def_actual << endl; 
    player.PrintStatus();

  } else if (rand_num <= 34) {
    cout << "Random event!: Agility Buff" << endl;
    player.agi_actual *= 1.25;
    cout << player.name << "Agility increased to " << player.agi_actual << endl;
    player.PrintStatus();

  } else if (rand_num <= 38) {
    cout << "Random event!: Agility Debuff" << endl;
    player.agi_actual *= 0.75;
    cout << player.name << "Agility decreased to " << player.agi_actual << endl;
    player.PrintStatus();

  } else if (rand_num == 39) {
    cout << "Random event!: HELL 2 U !" << endl;
    cout << "You just got a heart attack..." << endl;
    player.hp_actual = 0;
  }
}

void CombatMonsterRandomEvent(Monster &monster) {
  srand(time(0));
  int rand_num = rand() % 100;
    
  if (rand_num <= 9) {
    cout << "Random event! Lightening strike" << endl;
    cout << monster.name + " received " << 0.025 * (rand_num + 1) * monster.hp; 
    cout << " damage " << endl;
      
    monster.hp *= (1 - 0.025 * (rand_num + 1));
    monster.PrintStatus();

  } else if (rand_num <= 19) {
    cout << "Random event!: HEALING" << endl;
    cout << monster.name + " received " << 0.025 * (rand_num - 9) * monster.hp;
    cout << " healing " << endl;
      
    monster.hp *= (1 + 0.025 * (rand_num - 9));
    monster.PrintStatus();

  } else if (rand_num <= 22) {
    cout << "Random event!: Strength Buff" << endl;
    monster.str *= 1.25;
    cout << monster.name + " Strength increased to " << monster.str << endl;
    monster.PrintStatus();

  } else if (rand_num <= 25) {
    cout << "Random event!: Strength Debuff" << endl;
    monster.str *= 0.75;
    cout << monster.name + " Strength decreased to " << monster.str << endl;
    monster.PrintStatus();

  } else if (rand_num <= 28) {
    cout << "Random event!: Defense Buff" << endl;
    monster.def *= 1.25;
    cout << monster.name + " Defense increased to " << monster.def << endl;
    monster.PrintStatus();

  } else if (rand_num <= 31) {
    cout << "Random event!: Defense Debuff" << endl;
    monster.def *= 0.75;
    cout << monster.name + " Defense decreased to " << monster.def << endl;
    monster.PrintStatus(); 

  } else if (rand_num <= 34) {
    cout << "Random event!: Agility Buff" << endl;
    monster.agi *= 1.25;
    cout << monster.name << "Agility increased to " << monster.agi << endl;
    monster.PrintStatus();

  } else if (rand_num <= 38) {
    cout << "Random event!: Agility Debuff" << endl;
    monster.agi *= 0.75;
    monster.PrintStatus();

    cout << monster.name << "Agility decreased to " << monster.agi << endl;
  } else if (rand_num == 39) {
    cout << "Random event!: HELL 2 U !" << endl;
    cout << "You just got a heart attack..." << endl;
    monster.hp= 0;
  }
}
    
// Purpose: To calculate health reduction of monster(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatPlayerAttack(Player &player, Monster &monster) {
  Pause(500);

  cout << endl;
  cout << "It is the player's turn to attack" << endl; 

  CombatPlayerRandomEvent(player);

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

    cout << endl;
}

// Purpose: To calculate health reduction of player(value of the attack) 
// by considering status(strength, defense and agility) of both sides
void CombatMonsterAttack(Player &player, Monster &monster) {
    Pause(500);
    
    cout << "It is the Monster's turn to attack" << endl; 

    CombatMonsterRandomEvent(monster);

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

    cout << endl;
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
