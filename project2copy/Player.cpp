
// Player.cpp
// implement the class defined in Player.h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"

// default constructor
Player::Player() {
    // initialize all values to 0 
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _player_name = "";
    _character_name = "";
    
    // Empty inventory slots should contain candy structs with all members set to zero or empty.
    for(int i = 0; i < 4; i++){
        // inventory[i] is each candy object from struct in inventory array
        _inventory[i].name = "";
        _inventory[i].description = "";
        _inventory[i].price = 0;
        _inventory[i].candy_type = "";
    }
    _skipTurn = false;
    _castle_reached = false;
    _num_of_skip_turns = 0;
    _has_treasure_truffle = false;
}

// parameterized constructor
Player::Player(int stamina, double gold, string effect, Candy candy_array[], int candies_amount, bool skipTurn, string player_name, string character_name, const int MAX_CANDY_ARR_SIZE, bool castle_reached, int num_of_skip_turns, bool has_treasure_truffle) {
    _stamina = stamina;
    _gold = gold;
    _candy_amount = candies_amount;
    // If the input candy_array contains empty candies, _candy_amount should not be incremented.
    if(candy_array[0].name == "" && candy_array[0].description == "" && candy_array[0].price == 0 && candy_array[0].candy_type == "") {
        _candy_amount = 0;

    } else if (candies_amount < MAX_CANDY_ARR_SIZE) {
        //if candy size array is less than inventory size
        // populate based on candy array size
        // populate _inventory with as many candies as possible.
            // iterating over array which has the least size
        for(int i = 0; i < candies_amount; i++){
            _inventory[i] = candy_array[i];
            _candy_amount ++;
        }
    } else {
        for(int i = 0; i < MAX_CANDY_ARR_SIZE; i++){
            _inventory[i] = candy_array[i];
            _candy_amount++;
        }

    }
    _player_name = player_name;
    _character_name = character_name;
    _skipTurn = skipTurn;
    _castle_reached = castle_reached;
    _num_of_skip_turns = num_of_skip_turns;
    _has_treasure_truffle = has_treasure_truffle;

}

int Player::getCandyAmount() const 
{
    return _candy_amount;
}

void Player::setCandyAmount(int candy_amount)
{
    _candy_amount = candy_amount;
} 

int Player::addOneCandyAmount()
{
    _candy_amount+=1;
    return _candy_amount;
} 

void Player::setStamina(int stamina)
{
    if(stamina < 0) {
        _stamina = 0;
    } else if (stamina > 100) {
        _stamina = 100;
    } else {
        _stamina = stamina;
    }
}

int Player::getStamina() const
{
    return _stamina;
}

void Player::setGold(double gold)
{
    if(gold < 0) {
        _gold = 0;
    } else if (gold > 100) {
        _gold = 100;
    } else {
        _gold = gold;
    }
}

bool Player::getSkipTurn() const 
{
    return _skipTurn;
}

void Player::setSkipTurn(bool skipTurn)
{
    _skipTurn = skipTurn;
}

int Player::getNumOfSkipTurn() const {
    return _num_of_skip_turns;
}
void Player::setNumOfSkipTurn(int num_of_skip_turns) {
    _num_of_skip_turns = num_of_skip_turns;
}

double Player::getGold() const 
{
    return _gold;
}

void Player::setCandyList(Candy inventory[], int candy_amount) {
    for(int i = 0; i < candy_amount; i++) {
        _inventory[i] = inventory[i];
    }
}

// get candy list with cout 
void Player::getCandyList(Character character) const {
    for(int i = 0; i < character.candies_amount; i++) {
        cout << character.list_of_candies[i].name << "|";
        cout << character.list_of_candies[i].description << "|";
        cout << character.list_of_candies[i].effect_type << "|";
        cout << character.list_of_candies[i].effect_value << "|";
        cout << character.list_of_candies[i].candy_type << "|";
        cout << character.list_of_candies[i].price << "|";
    }
}
string Player::getPlayerName() const {
    return _player_name;
}
void Player::setPlayerName(string player_name) {
    _player_name = player_name;
}

string Player::getCharacterName() const {
    return _character_name;
}
void Player::setCharacterName(string character_name) {
    _character_name = character_name;
}

// int Player::getBudget() const {
//     return _budget;
// }
// void Player::setBudget(int budget) {
//     _budget = budget;
// }

bool Player::getCastleReached() const {
    return _castle_reached;
}
void Player::setCastleReached(bool castle_reached) {
    _castle_reached = castle_reached;
}

bool Player::getHasTreasureTruffle() const {
    return _has_treasure_truffle;
}
void Player::setHasTreasureTruffle(bool has_treasure_truffle) {
    _has_treasure_truffle = has_treasure_truffle;
}

int Player::getMaxCandyAmount() const {
    return _MAX_CANDY_AMOUNT;
}

string Player::isImmunityCandy() {
    // searches for immunity candy
    for(int i = 0; i < _candy_amount; i++) {
        if(_inventory[i].candy_type == "immunity") {
            return _inventory[i].name;
        }
    }
}

bool Player::isMagicalCandy() {
    // searches for immunity candy
    for(int i = 0; i < _candy_amount; i++) {
        if(_inventory[i].candy_type == "magical") {
            return true;
        }
    }
}

string Player::returnsMagicalCandy() {
    // searches for immunity candy
    for(int i = 0; i < _candy_amount; i++) {
        if(_inventory[i].candy_type == "magical") {
            return _inventory[i].name;
        }
    }
}

void Player::printInventory() {
    // if inventory is empty 
        // print empty grid 
    // cout << "inventory length " << _inventory[0].name.length() << endl;
    for(int i = 0; i < _candy_amount; i++) {
        if(i != 0 && i%3 == 0) {
            cout << endl;
        }
        if(_inventory[i].name.length() == 0) {
        cout << "[" << "Empty" << "]";
        } else {
            cout << "[" << _inventory[i].name << "]";
        }
        cout << "   ";
    }
    cout << endl;
}

Candy Player::findCandy(string candy_name) {
    // see if you can find candy name in inventory
        // boolean 
    bool found = false;
    for(int i = 0; i < _candy_amount; i++) {

        // // CASE INSENVITY!
        // string lower_case_inventory_name = "";
        // // to go through every character in inventory name and change it to lower case
        // for(int k = 0; k < _inventory[i].name.length(); k++) {
        //     // cout << "before" << _inventory[i].name[k];
        //     //_inventory[i].name[k] = tolower(_inventory[i].name[k]);
        //     lower_case_inventory_name += tolower(_inventory[i].name[k]);
        // }

        // // go through every character in candy name and change it to lower
        // for(int k = 0; k < candy_name.length(); k++) {
        //     // cout << "before" << candy_name[k];
        //     candy_name[k] = tolower(candy_name[k]);
        //     // cout << "after" << candy_name[k];
        // }

        // if you can find the name, return that struct! 
        if(candy_name == _inventory[i].name) {
            found = true;
            return _inventory[i];
        } 
    }
    // If not found, return an empty candy struct
    if(found == false) {
        Candy empty_candy;
        return empty_candy;
    }
}

bool Player::addCandy(Candy candy) {
    // adding a player to inventory 
    bool added = false;
    // only add new candy if size of current inventory is less than 9 (max candy amount)
    // cout << _candy_amount;
    if(_candy_amount < _MAX_CANDY_AMOUNT) {
        for(int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
            if(_inventory[i].name == "" || i == _MAX_CANDY_AMOUNT - 1) {
                _inventory[i] = candy;
                cout << "_inventory[i].name " << _inventory[i].name << endl;
                _candy_amount++;
                added = true;
                break;
            }
        }
    } else {
        cout << "Sorry! You do not have enough space in your candy inventory for this new candy" << endl;
    }


    // return whatever boolean added is 
        // if nothing was added because inventory is full, it will return false
    return added;
}

bool Player::removeCandy(string candy_name) {
   
    // removing a player to inventory
    bool removed = false;
    // find the candy name to remove - for case insensivity 
    for(int i = 0; i < _candy_amount && !removed; i++) {
        
        // // CASE INSENVITY!
        // // to go through every character in inventory name and change it to lower case
        // for(int k = 0; k < _inventory[i].name.length(); k++) {
        //     // cout << "before" << _inventory[i].name[k];
        //     _inventory[i].name[k] = tolower(_inventory[i].name[k]);
        //     // cout << "after" << _inventory[i].name[k];
        // }

        // // go through every character in candy name and change it to lower
        // for(int k = 0; k < candy_name.length(); k++) {
        //     // cout << "before" << candy_name[k];
        //     candy_name[k] = tolower(candy_name[k]);
        //     // cout << "after" << candy_name[k];
        // }
 
        // if candy name is found 
        if(_inventory[i].name == candy_name && !removed) {
            removed = true; 
            // remove the candy name 
            for(int j = i; j < _candy_amount - 1; j++) {
                // // if you are the last inventory, make it an empty candy struct
                // if(j == 4) {
                //      Candy empty = {"", "", 0, ""};
                //     _inventory[j] = empty;
                // } else {
                    _inventory[j] = _inventory[j + 1];
                    _inventory[j + 1].name = "";
                    // cout << i << endl;
                    // cout << j << endl;
                //}
            }
            _candy_amount--;  
            // for(int i = 0; i < _candy_amount; i++) {
            //     cout << "inventory i " << _inventory[i].name << endl;
            // }
            // cout << removed;
            return true;
        }
        // return removed;

    }
    // if(_candy_amount == 0) {
    //     cout << "nothing in inventory" << endl;
    // }
    // for(int i = 0; i < _candy_amount; i++) {
    //     cout << "inventory i " << _inventory[i].name << endl;
    // }
    // cout << "removed " << removed << endl;

    // at end of for loop, if removed is still false, candy name was not found
    return removed; 
}

bool Player::substituteCandy(Candy candy_to_substitute, Candy candy_to_buy) {
    // removing a player to inventory
    bool replaced = false;
    // if candy name is found 
    // 
    for(int i = 0; i < _candy_amount && !replaced; i++) {
        if(_inventory[i].name == candy_to_substitute.name && !replaced) {
            replaced = true; 
            // replace the candy name 
            _inventory[i] = candy_to_buy;
           //  cout << "_inventory[i].name" << _inventory[i].name;
        }
    }
    return replaced;
}


void Player::displayPlayerStats() {
    cout << "Player name: " << _player_name << endl;
    cout << "Character: " << _character_name << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Gold: " << _gold << endl;
    for(int i = 0; i < _candy_amount; i++) {
        if(i != 0 && i%3 == 0) {
            cout << endl;
        }
        if(_inventory[i].name.length() == 0) {
        cout << "[" << "Empty" << "]";
        } else {
            cout << "[" << _inventory[i].name << "]";
        }
        cout << "   ";
    }
    cout << endl;
    // cout character name, stamina, gold
    // cout list of candies by for looping through the list (print with print inventory function)
}

void Player::writeIntoFile(string file_name, Player players[], int numOfPlayers) {
    ofstream file;
        // Source to do in append mode!
            // https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
    file.open(file_name);
    for (int k = 0; k < numOfPlayers; k++) {
        file << endl;
        file << "Player name: " << players[k]._player_name << endl;
        file << "Character: " << players[k]._character_name << endl;
        file << "Stamina: " <<players[k]._stamina << endl;
        file << "Gold: " << players[k]._gold << endl;
        for(int i = 0; i < players[k]._candy_amount; i++) {
            if(i != 0 && i%3 == 0) {
                file << endl;
            }
            if(players[k]._inventory[i].name.length() == 0) {
            file << "[" << "Empty" << "]";
            } else {
                file << "[" << players[k]._inventory[i].name << "]";
            }
            file << "   ";
        }
        file << endl;
    } 
    file.close();

}

bool Player::getHasAntiRobberySheild() const {
    return _has_anti_robbery_sheild;
}
void Player::setHasAntiRobberySheild(bool has_anti_robbery_sheild) {
    _has_anti_robbery_sheild = has_anti_robbery_sheild;
}