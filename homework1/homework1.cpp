
#include <iostream>
#include <cmath>

using namespace std;

// int main() {
//     int numberOfIronCoins;
//     cout << "Enter the number of iron coins: " << endl;
//     cin >> numberOfIronCoins;
    
//     int ironCoinsInGold = 897;
    
//     // Get number of gold coins
//     int goldCoins = floor(numberOfIronCoins/ironCoinsInGold);
    
//     // Find remaining number of iron coins gold
//     int remainderOfGoldCoins = numberOfIronCoins%ironCoinsInGold;

//     // Get number of silver coins 
//     int silverCoins = floor(remainderOfGoldCoins/39);
    
//     // Find remaining number of iron from silver
//     int remainderOfSilverCoins = remainderOfGoldCoins%39;
    
//     // Get number of bronze coins
//     int bronzeCoins = floor(remainderOfSilverCoins/3);
    
//     int ironCoins = remainderOfSilverCoins%3;
    
//     cout << goldCoins << " gold coin(s) " << silverCoins << " silver coin(s) " << bronzeCoins << " bronze coin(s) " << ironCoins << " iron coin(s) ";


//     return 0;

// }

int main() {

    int hours;
    cout << "How many hours have passed? " << endl;
    cin >> hours;

    int initialIndoor = 10;
    double indoorWaterLevel = initialIndoor + ((.5-.2)*hours);

    int initialOutdoor = 14;
    double outdoorWaterLevel = initialOutdoor + ((.8-.3)*hours);

    cout << "The indoor pool has " << indoorWaterLevel << " inches of water, and the outdoor pool has " << outdoorWaterLevel << " inches of water.";

}