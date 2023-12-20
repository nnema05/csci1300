

#include <iostream>
#include <string>
#include <vector>
#include "CandyStore.h"
#include "Board.h"

/* TESTING PLAYER CLASS CONSTRUCTOR, GETTERS AND SETTERS*/

int main() {
    Player player;
    Candy candy;
    Candy candy2;
    Candy candies[2] = {candy, candy2};
    Player player1(10, 10, "starting", candies, 2, 9, false);
    player.setCandyAmount(2);
    cout << player.getCandyAmount() << endl;
    player.setStamina(10);
    cout << player.getStamina() << endl;
    player.setGold(10);
    cout << player.getGold() << endl;
    player.setSkipTurn(false);
    cout << player.getSkipTurn() << endl;
    player.setHasAntiRobberySheild(false);
    cout << player.getHasAntiRobberySheild() << endl;
    player1.displayPlayerStats();

}