
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

// Question 5

// candy struct 
struct Candy {
    string name; // Name of candy
    string description; // Description of candy
    double price; // Price of candy
    string candy_type; // Type of candy
};

class Player {

    public:
        Player(); // constructor
        Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE); // Paramaterized constructor	
        int getCandyAmount() const;
        void setStamina(int);
        int getStamina() const;
        void setGold(double);
        double getGold() const;
        void setEffect(string);
        string getEffect() const;

        void printInventory();

        Candy findCandy(string);	
        bool addCandy(Candy);
        bool removeCandy(string candy_name);

    private:
        // define all data members
        const static int _MAX_CANDY_AMOUNT = 4; // The maximum number of candies the player can have in their inventory. Use the value of 4
        int	_stamina; // Current Energy
        double _gold; // Value of the player's current money
        string _effect; // Name of current effect
        Candy _inventory[4]; // Array to store the player's candy
            // set it to max_candy_amount to be 4
        int	_candy_amount; // Amount of initialized candy structs in the inventory array

};

#endif
