
#include "Player.h"

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    Candy test = {"test", "candy born from mud", 1.01, "Buff"};
    Candy test2 = {"test2", "This candy dropped from the rainbow", 2.02, "Chance"};
    Candy c[3] = {test, test, test2};
    Candy empty[3] = {};
    Player p = Player(5849, 123456, "987654321", c, 1);
    cout << "Inventory:" << endl;
    p.printInventory();
    p.addCandy(c[0]);
    p.addCandy(c[1]);
    cout << "Inventory:" << endl;
    p.printInventory();
    p.removeCandy("test");
    cout << "Inventory:" << endl;
    p.printInventory();
    p.removeCandy("test");
    p.removeCandy("test");
    cout << "Inventory:" << endl;
    p.printInventory();
    p.removeCandy("test");
    p.removeCandy("test");
    cout << "Inventory:" << endl;
    p.printInventory();
    // Candy empty[4] = {{}};
    // Player player = Player(5, 100, "No candy!", empty, 4);
    // // for(int i = 0; i < 3; i++) {
    // //     cout << candy_array[i].name << endl;
    // // }
    
     
    // //print stats before
    // cout << "Stamina before: " << player.getStamina() << endl;
    // cout << "Gold before: " << player.getGold() << endl;
    // cout << "Effect before: " << player.getEffect() << endl;
    // cout << "Inventory before: " << endl;
    // player.printInventory();

    // player.addCandy(candy_array[0]);
        
    // //print stats after
    // cout << "Stamina after: " << player.getStamina() << endl;
    // cout << "Gold after: " << player.getGold() << endl;
    // cout << "Effect after: " << player.getEffect() << endl;
    // cout << "Inventory after: " << endl;
    // player.printInventory();
}