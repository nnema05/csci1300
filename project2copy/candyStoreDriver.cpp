
#include "Board.h"
#include "CandyStore.h"
#include <iostream>

using namespace std;

int main() {
    /*TESTING CANDY STORE CONSTRUCTOR, GETTER AND SETTER*/
    Candy candy;
    Candy candy2;
    Candy candies[2] = {candy, candy2};
    CandyStore candyStore1;
    CandyStore candyStore2(10, candies, "store", 2);
    candyStore1.setTile(10);
    cout << candyStore1.getTile() << endl;
    candyStore1.setCandies(candies, 2);
    candyStore1.setStoreName("candy store 1");
    cout << candyStore1.getStoreName() << endl;
    candyStore1.setCurrentCandyAmount(2);
    cout << candyStore1.getCurrentCandyAmount() << endl;
}