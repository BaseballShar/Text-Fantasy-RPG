#include "shop.h"

// Display shop items status
// Output: Return the id of the item that player want to purchase
int Shop::DisplayItem(int purchase_choice) {
  string purchase_id;

  // To status armour status
  string armour_price = "";
  string armour_name = "";
  string armour_hp_bonus = "";
  string armour_str_bonus = "";
  string armour_def_bonus = "";
  string armour_agi_bonus = "";

  // To status weapon status
  string weapon_price = "";
  string weapon_name = "";
  string weapon_hp_bonus = "";
  string weapon_str_bonus = "";
  string weapon_def_bonus = "";
  string weapon_agi_bonus = "";

  if (purchase_choice == 1) {
    // Armour details
    for (int i = 1; i < armour.len; i++) {
      istringstream armour_str(armour.Extract(i));

      armour_str >> armour_price;
      armour_str >> armour_name;
      armour_str >> armour_hp_bonus;
      armour_str >> armour_str_bonus;
      armour_str >> armour_def_bonus;
      armour_str >> armour_agi_bonus;

      // output armour details
      cout << left;
      cout << setw(7) << "ID: " + to_string(i);
      cout << setw(16) << "Price: " +  armour_price;
      cout << setw(25) << "Name:" + armour_name;
      cout << "HP:" << setw(8);
      cout << (((stod(armour_hp_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(armour_hp_bonus) - 1) * 100)) + "%";

      cout << "STR:" << setw(6);
      cout << (((stod(armour_str_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(armour_str_bonus) - 1) * 100)) + "%";

      cout << "DEF:" << setw(8);
      cout << (((stod(armour_def_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(armour_def_bonus) - 1) * 100)) + "%";

      cout << "AGI:" << setw(6);
      cout << (((stod(armour_agi_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(armour_agi_bonus) - 1) * 100)) + "%" << endl;
    }

    // exit command
    cout << "Enter 0 to exit" << endl;
    
    // To gather what player wants to purchase
    cout << "Enter the ID of armour you want to purchase:";
    cin >> purchase_id;

    // To prevent invalid input
    if (purchase_id == "0") {
      return -1;
    } else if (!IsNum(purchase_id)) {
      cout << "Please enter valid input!" << endl;
      return -1;
    }
    return stoi(purchase_id);
  } else if (purchase_choice == 2) {
    // Weapon details
    for (int i = 1; i < weapon.len; i++) {
      istringstream weapon_str(weapon.Extract(i));

      // To store weapon status
      weapon_str >> weapon_price;
      weapon_str >> weapon_name;
      weapon_str >> weapon_hp_bonus;
      weapon_str >> weapon_str_bonus;
      weapon_str >> weapon_def_bonus;
      weapon_str >> weapon_agi_bonus;

      // output weapon details
      cout << left;
      cout << setw(7) << "ID: " + to_string(i);
      cout << setw(16) << "Price: " +  weapon_price;
      cout << setw(21) << "Name: " + weapon_name;
      cout << "HP:" << setw(8);
      cout << (((stod(weapon_hp_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(weapon_hp_bonus) - 1) * 100)) + "%";

      cout << "STR:" << setw(8);
      cout << (((stod(weapon_str_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(weapon_str_bonus) - 1) * 100)) + "%";

      cout << "DEF:" << setw(8);
      cout << (((stod(weapon_def_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(weapon_def_bonus) - 1) * 100)) + "%";

      cout << "AGI:" << setw(8);
      cout << (((stod(weapon_agi_bonus) - 1) * 100 >= 0) ? "+" : "") +
      to_string((int) ((stod(weapon_agi_bonus) - 1) * 100)) + "%" << endl;
      }

      // exit command
      cout << "Enter 0 to exit" << endl;

    // To gather what player wants to purchase
    cout << "Enter the ID of weapon you want to purchase:";
    cin >> purchase_id;
  }
    // To prevent invalid input
    if (purchase_id == "0") {
      return -1;
    } else if (!IsNum(purchase_id)) {
      cout << "Please enter valid input!" << endl;
      return -1;
    }
    return stoi(purchase_id);
}

// Purpose: Function for handling armour transaction
void MakePurchaseArmour(Player &player, Shop &shop, int purchase_id) {
  istringstream armour_str(shop.armour.Extract(purchase_id));
  string armour_cost_str;

  armour_str >> armour_cost_str; // string containing cost of armour
  int armour_cost = stoi(armour_cost_str); // cost of armour
  int cost_len = armour_cost_str.length(); // the length of the cost of armour

  if (player.money >= armour_cost) {
    player.money -= armour_cost; // pay 
    player.armour = shop.armour.Extract(purchase_id); // obtain item

    // make the item free so that player can switch equipment without extra fee
    if (armour_cost != 0) {
      string original_armour_str = shop.armour.Extract(purchase_id);

      string replaced_armour_str = "0 " +
      original_armour_str.substr(cost_len + 1,
                               original_armour_str.length() - cost_len - 1);

      shop.armour.DeleteIndex(purchase_id);
      shop.armour.Insert(purchase_id, replaced_armour_str);
    }

    cout << "Your purchase is successful" << endl;
  } else {
    cout << "Your money is insufficient to purchase this item" << endl;
  }
}

// Purpose: Function for handling weapon transaction
void MakePurchaseWeapon(Player &player, Shop &shop, int purchase_id) {
  istringstream weapon_str(shop.weapon.Extract(purchase_id));
  string weapon_cost_str;

  weapon_str >> weapon_cost_str; // string containing cost of weapon
  int weapon_cost = stoi(weapon_cost_str); // cost of weapon
  int cost_len = weapon_cost_str.length(); // the length of the cost of weapon

  if (player.money >= weapon_cost) {
    player.money -= weapon_cost; // pay 
    player.weapon = shop.weapon.Extract(purchase_id); // obtain item

    // make the item free so that player can switch equipment without extra fee
    if (weapon_cost != 0) {
      string original_weapon_str = shop.weapon.Extract(purchase_id);
      string replaced_weapon_str = "0 " +
      original_weapon_str.substr(cost_len + 1,
                               original_weapon_str.length() - cost_len - 1);
      shop.weapon.DeleteIndex(purchase_id);
      shop.weapon.Insert(purchase_id, replaced_weapon_str);
    }

    cout << "Your purchase is successful" << endl;
  } else {
    cout << "Your money is insufficient to purchase this item" << endl;
  }  
}

// Purpose: Function for handling armour luckydraw
void LuckyDrawArmour(Player &player, Shop &shop) {
  int num_of_armour = shop.luckydraw_armour.len; // number of avalibale armour

  srand(0);
  int random_index = rand() % num_of_armour;
  string armour_name;
  string armour_cost;
  string cost;
  string drawn_armour_str = shop.luckydraw_armour.Extract(random_index);
  istringstream armour_str(drawn_armour_str);

  // Extracting armour name and cost
  armour_str >> armour_cost;
  armour_str >> armour_name;

  // Player obtaining the item
  player.armour = drawn_armour_str;
  player.num_token -= 1;

  // Delete the drawn item from list of avaliable lucky draw items
  shop.luckydraw_armour.DeleteValue(drawn_armour_str);

  // Set the price of such item to 0, so that player can change equipment by
  // visiting the shop and equip it for free after drawing the item
    string replaced_armour_str = "0 " +
    drawn_armour_str.substr(armour_cost.length() + 1,
                        drawn_armour_str.length() - armour_cost.length() - 1);

    int item_id = shop.armour.Find(drawn_armour_str);
    shop.armour.DeleteIndex(item_id);
    shop.armour.Insert(item_id, replaced_armour_str);

  cout << "Congradulations, you have obtained " + armour_name << endl; 
}

// Purpose: Function for handling weapon luckydraw
void LuckyDrawWeapon(Player &player, Shop &shop) {
int num_of_weapon = shop.luckydraw_weapon.len; // number of avalibale weapon

  srand(0);
  int random_index = rand() % num_of_weapon;
  string weapon_name;
  string weapon_cost;
  string cost;
  string drawn_weapon_str = shop.luckydraw_weapon.Extract(random_index);
  istringstream weapon_str(drawn_weapon_str);

  // Extracting weapon name and cost
  weapon_str >> weapon_cost;
  weapon_str >> weapon_name;

  // Player obtaining the item
  player.weapon = drawn_weapon_str;
  player.num_token -= 1;

  // Delete the drawn item from list of avaliable lucky draw items
  shop.luckydraw_weapon.DeleteValue(drawn_weapon_str);

  // Set the price of such item to 0, so that player can change equipment by
  // visiting the shop and equip it for free after drawing the item
    string replaced_weapon_str = "0 " +
    drawn_weapon_str.substr(weapon_cost.length() + 1,
                        drawn_weapon_str.length() - weapon_cost.length() - 1);

    int item_id = shop.weapon.Find(drawn_weapon_str);
    shop.weapon.DeleteIndex(item_id);
    shop.weapon.Insert(item_id, replaced_weapon_str);

  cout << "Congradulations, you have obtained " + weapon_name << endl; 
}

// Purpose: Function for handling the luckydraw
void LuckyDraw(Player &player, Shop &shop) {
  if (player.num_token > 0) {
    int luckydraw_option = 0;
    
    cout << "[1]Draw Armour [2]Draw Weapon [3]Exit" << endl;
    cin >> luckydraw_option;

    switch(luckydraw_option) {
      case 1:
        LuckyDrawArmour(player, shop);
        break;
      case 2:
        LuckyDrawWeapon(player, shop);
        break;
      default:
        break;
    }
  } else {
    cout << "You do not have any token, fight managers to gain one" << endl;
  }
}

// Function for purchasing items
void MakePurchase(Player &player, Shop &shop) {
  string purchase_choice;
  int purchase_id;

  cout << "[0]Exit    [1]Armour   [2]Weapon   [3]Lucky draw" << endl;
  cin >> purchase_choice;
  
  // To handle purchasing of armour
  if (purchase_choice == "1") {
    purchase_id = shop.DisplayItem(1);
    // To prevent invalid input
    if (purchase_id != -1)
      MakePurchaseArmour(player, shop, purchase_id);
  // To handle purchasing of weapon
  } else if (purchase_choice == "2") {
    purchase_id = shop.DisplayItem(2);
    // To prevent invalid input
    if (purchase_id != -1)
      MakePurchaseWeapon(player, shop, purchase_id);
  // To handle lucky draw
  } else if (purchase_choice == "3") {
    LuckyDraw(player, shop);
  } else {
    if (purchase_choice != "0")
      cout << "Please enter valid input" << endl;
  }
}
