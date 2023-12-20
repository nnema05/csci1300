
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CandyStore.h"
#include "Board.h"

using namespace std;

struct Character { 
    string character_name;
    int stamina;
    int gold;
    int candies_amount;
    const static int MAX_CANDY_AMOUNT = 9;
    Candy list_of_candies[MAX_CANDY_AMOUNT];
    bool skipTurn;
};

class Player {

    public:
        Player(); // constructor
        Player(int stamina, double gold, string effect, Candy candy_array[], int candies_amount, bool skipTurn, string player_name, string character_name, const int MAX_CANDY_ARR_SIZE, bool castle, int num_of_skip_turns, bool has_treasure_truffle); // Paramaterized constructor
            // parameterized constructor will make a player object based on the character chosen!	
        int getCandyAmount() const;
        void setCandyAmount(int);
        int addOneCandyAmount();
        void setStamina(int);
        int getStamina() const;
        void setGold(double);
        double getGold() const;
        bool getSkipTurn() const;
        void setSkipTurn(bool);
        int getNumOfSkipTurn() const;
        void setNumOfSkipTurn(int);
        bool getHasAntiRobberySheild() const;
        void setHasAntiRobberySheild(bool);
        bool getHasTreasureTruffle() const;
        void setHasTreasureTruffle(bool);
        void setCandyList(Candy[], int);
        void getCandyList(Character character) const;
        string getPlayerName() const;
        void setPlayerName(string player_name);
        string isImmunityCandy();
        bool isMagicalCandy();
        string returnsMagicalCandy();
        // int getBudget() const;
        // void setBudget(int);
        bool getCastleReached() const;
        void setCastleReached(bool);
        int getMaxCandyAmount() const;
        string getCharacterName() const;
        void setCharacterName(string character_name);

        void printInventory();

        Candy findCandy(string);	
        bool addCandy(Candy);
        bool removeCandy(string candy_name);
        bool substituteCandy(Candy candy_to_substitute, Candy candy_to_buy);

        void displayPlayerStats();
        void writeIntoFile(string file_name, Player players[], int numOfPlayers);


    private:
        // define all data members
        const static int _MAX_CANDY_AMOUNT = 9; // The maximum number of candies the player can have in their inventory. 
        int	_stamina; // Current Energy
        double _gold; // Value of the player's current money
        Candy _inventory[9]; // Array to store the player's candy
            // set it to max_candy_amount to be 9
        int	_candy_amount; // Amount of initialized candy structs in the inventory array
        bool _skipTurn;
        bool _has_anti_robbery_sheild;
        string _player_name;
        string _character_name;
        // int _budget;
        bool _castle_reached;
        int _num_of_skip_turns;
        bool _has_treasure_truffle;
};

#endif
