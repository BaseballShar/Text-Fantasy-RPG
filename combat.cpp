#include "combat.h"
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cmath>

using namespace std;

// Purpose: To pause the game for (time) miliseconds
void Pause(int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

// Purpose: To allow player to select which level for monsters to fight
Monster CombatLevelSelection(Player player) {
  string monster_level; // To choose the level of monster to fight
  string monster_choice; // To choose whether to fight boss or normal monster
  Monster monster;

  bool confirm_choice = false; // To check whether the user comfirms
  string confirm_choice_str; // String version of the above to order to
  // not cause error when user does not follow instructions

    // Monster level selection
  while (confirm_choice == false && monster.is_exit == false) {

    // record the length of player name for status printing
    monster.player_name_len = player.name.length();

    cout << "[0]Exit" << "    ";
    cout << "[1]Fight monsters" << "    ";
    switch(player.num_map) {
      case 0:
        cout << "[2]Fight Manager" << "    ";
        break;
      case 1:
        cout << "[2] Fight Vice President" << "    ";
        break;
      case 2:
        cout << "[2] Fight President" << "    ";
        break;
      case 3:
        cout << "[2] Fight Infinite Comment Client" << "    ";
        break;
    }
    cout << endl;
    cout << "Enter the number in brackets to select the action: ";
    cin >> monster_choice;

    if (monster_choice == "0") {
      monster.level = 0; // for exiting combat, set monster lv = 0
      monster.is_exit = true;
      return monster;
    } else if (monster_choice == "1") {
      monster.is_boss = false;
      cout << "What level of monster you want to fight ? ";
      cin >> monster_level;

      // prevent invalid input
      for (int i = 0; i < monster_level.length(); i++) {
        if (!isdigit(monster_level[i])) {
          cout << "Please enter valid input!" << endl;
          monster.level = 0;
          monster.is_exit = true;
          return monster;
        }
      }
      monster.level = stoi(monster_level);
      monster.hp = 500 * monster.level;
      monster.str = 100 * log2(monster.level + 1);
      monster.def = 50 *  log2(monster.level + 1);
      monster.agi = 50 * log2(monster.level + 1);

      monster.name = "Monster";
      player.monster_name_len = 7;

      if(monster.level > 0) {
      cout << "Are you sure you want to fight level "
      << monster.level << " monster  " << endl;
      }
    } else if (monster_choice == "2") {
      monster.is_boss = true;
      switch(player.num_map) {
        case 0:
          monster.name = "Manager";
          monster.hp = 7500;
          monster.str = 500;
          monster.def = 200;
          monster.agi = 200;

          player.monster_name_len = 7;

          cout << "Are you sure you want to fight Manager ?" << endl;
          break;

        case 1:
          monster.name = "Vice president";
          monster.hp = 15000;
          monster.str = 750;
          monster.def = 300;
          monster.agi = 300;

          player.monster_name_len = 14;

          cout << "Are you sure you want to fight Vice Manager ? " << endl;
          break;

        case 2:
          monster.name = "President";
          monster.hp = 25000;
          monster.str = 1000;
          monster.def = 400;
          monster.agi = 400;

          player.monster_name_len = 9;

          cout << "Are you sure you want to fight President ?  " << endl;
          break;

        case 3:
          monster.name = "Boss";
          monster.hp = 100000;
          monster.str = 2500;
          monster.def = 1000;
          monster.agi = 1000;

          player.monster_name_len = 4;

          cout << "Are you sure you want to fight Boss ? " << endl;
          break;
      }
    } else {
      cout << "Please enter valid input!" << endl;
      monster.level = 0; // for exiting combat, set monster lv = 0
      monster.is_exit = true;
      return monster;
    }

    if (monster.level > 0 || monster.is_boss) {
      monster.PrintStatus();
      player.PrintStatus();

      cout << "[1]YES    [0]No" << endl;
      cout << "Enter the number in brackets to select the action: ";
      cin >> confirm_choice_str;

      if (confirm_choice_str != "0" && confirm_choice_str != "1") {
        cout << "Please enter valid input" << endl;
      }
      confirm_choice = (confirm_choice_str == "1")? true : false;
      cout << endl;

    } else {
      cout << "Level must be positive!" << endl;
      confirm_choice = false;
    }
  }
  return monster;
}

// Purpose: To calculate the attack modifier
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

// Purpose: To generate random event for player during combat
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

// Purpose: To generate random event for monster during combat
void CombatMonsterRandomEvent(Monster &monster) {
  srand(time(0));
  int rand_num = rand() % 100;

  if (rand_num >= 90) {
    cout << "Random event! Lightening strike" << endl;
    cout << monster.name + " received " << 0.025 * (rand_num - 89) * monster.hp;
    cout << " damage " << endl;

    monster.hp *= (1 - 0.025 * (rand_num - 89));
    monster.PrintStatus();

  } else if (rand_num >= 80) {
    cout << "Random event!: HEALING" << endl;
    cout << monster.name + " received " << 0.025 * (rand_num - 79) * monster.hp;
    cout << " healing " << endl;

    monster.hp *= (1 + 0.025 * (rand_num - 79));
    monster.PrintStatus();

  } else if (rand_num >= 77) {
    cout << "Random event!: Strength Buff" << endl;
    monster.str *= 1.25;
    cout << monster.name + " Strength increased to " << monster.str << endl;
    monster.PrintStatus();

  } else if (rand_num >= 74) {
    cout << "Random event!: Strength Debuff" << endl;
    monster.str *= 0.75;
    cout << monster.name + " Strength decreased to " << monster.str << endl;
    monster.PrintStatus();

  } else if (rand_num >= 71) {
    cout << "Random event!: Defense Buff" << endl;
    monster.def *= 1.25;
    cout << monster.name + " Defense increased to " << monster.def << endl;
    monster.PrintStatus();

  } else if (rand_num >= 68) {
    cout << "Random event!: Defense Debuff" << endl;
    monster.def *= 0.75;
    cout << monster.name + " Defense decreased to " << monster.def << endl;
    monster.PrintStatus();

  } else if (rand_num >= 65) {
    cout << "Random event!: Agility Buff" << endl;
    monster.agi *= 1.25;
    cout << monster.name << "Agility increased to " << monster.agi << endl;
    monster.PrintStatus();

  } else if (rand_num >= 62) {
    cout << "Random event!: Agility Debuff" << endl;
    monster.agi *= 0.75;
    monster.PrintStatus();

    cout << monster.name << "Agility decreased to " << monster.agi << endl;
  } else if (rand_num == 61) {
    cout << "Random event!: HELL 2 U !" << endl;
    cout << monster.name << " just got a heart attack..." << endl;
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
  if (combat_result > 0) {
    player.exp += 100 * combat_result;
    player.money += 50 * combat_result;

    cout << "You have acquried " << "$" << 100 * combat_result  << endl ;
    cout << "You have acquried " << 100 * combat_result
    << " XP points" << endl ;
    // if managers are defeated
  } else if (combat_result == -2) {
      // if INFINITE COMMENT CLIENT is defeated
      if (player.num_map == 3) {
        player.is_boss_defeated = true;
        player.death = true; // End of game
      } else {
        player.num_map += 1;
        player.num_token += 1;
      }
  } else if (combat_result == -1){
    player.death = true ;
    }
}

// Purpose: To be in charge of the whole combat situation
// From monster creation, combating, to reward distribution
// Output: Returns -2 if boss is defeated
//         Returns -1 if player is defeated
//         Returns 0 if player exited combat
int Combat (Player &player, Shop shop) {
    //bool auto_combat = player.setting[0].second ;

    // Backup character data
    Player player_backup = player; // Disallow status to changing while recording item comsumption

    // Creation of monster
    Monster monster = CombatLevelSelection(player);

    // For exiting combat
    if (monster.is_exit) {
      return 0;
    }

    // Fighting with monster
    while (player.hp_actual > 0 && monster.hp > 0) {

        CombatPlayerAttack(player, monster);


        if (!(player.hp_actual > 0 && monster.hp > 0)) {
          break;
        }

        CombatMonsterAttack(player, monster);
    }

    // Combat outcome
    if (player.hp_actual > 0) {
        cout << "You have defeated the " + monster.name + " !!! " << endl;

        // regenerate character status
        player = player_backup;

        if(!monster.is_boss) {
          return monster.level;
        } else {
          return -2;
        }
    } else {
        cout << "You have been defeated " << endl;
        return -1;
    }
}
