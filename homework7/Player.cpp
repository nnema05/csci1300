
// Player.cpp
// implement the class defined in Player.h
#include <iostream>
#include <cctype>
#include "Player.h"

// default constructor
Player::Player() {
    // initialize all values to 0 
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _effect = "";
    // Empty inventory slots should contain candy structs with all members set to zero or empty.
    for(int i = 0; i < 4; i++){
        // inventory[i] is each candy object from struct in inventory array
        _inventory[i].name = "";
        _inventory[i].description = "";
        _inventory[i].price = 0;
        _inventory[i].candy_type = "";
    }
}

// parameterized constructor
Player::Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE) {
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    _candy_amount = 0;
    // If the input candy_array contains empty candies, _candy_amount should not be incremented.
    if(candy_array[0].name == "" && candy_array[0].description == "" && candy_array[0].price == 0 && candy_array[0].candy_type == "") {
        _candy_amount = 0;

    } else if (CANDY_ARR_SIZE < 4) {
        //if candy size array is less than inventory size
        // populate based on candy array size
        // populate _inventory with as many candies as possible.
            // iterating over array which has the least size
        for(int i = 0; i < CANDY_ARR_SIZE; i++){
            _inventory[i] = candy_array[i];
            _candy_amount ++;
        }
    } else {
        for(int i = 0; i < 4; i++){
            _inventory[i] = candy_array[i];
            _candy_amount++;
        }

    }

   
}

int Player::getCandyAmount() const 
{
    return _candy_amount;
}

void Player::setStamina(int stamina)
{
    _stamina = stamina;
}

int Player::getStamina() const
{
    return _stamina;
}

void Player::setGold(double gold)
{
    _gold = gold;
}

double Player::getGold() const 
{
    return _gold;
}

void Player::setEffect(string effect)
{
    _effect = effect;
}

string Player::getEffect() const 
{
    return _effect;
}


void Player::printInventory() {
    // if inventory is empty 
        // print empty grid 
    cout << "|";
    // cout << "inventory length " << _inventory[0].name.length() << endl;
    if(_inventory[0].name.length() == 0) {
        cout << "[" << "Empty" << "]";
    } else {
        cout << "[" << _inventory[0].name << "]";
    }
    cout << "|";
    if(_inventory[1].name.length() == 0) {
        cout << "[" << "Empty" << "]";
    } else {
        cout << "[" << _inventory[1].name << "]";
    }
    cout << "|";
    cout << endl;
    cout << "|";
    if(_inventory[2].name.length() == 0) {
        cout << "[" << "Empty" << "]";
    } else {
        cout << "[" << _inventory[2].name << "]";
    }
    cout << "|";
   //  cout << _inventory[3].name.length() << endl;
    if(_inventory[3].name.length() == 0) {
        cout << "[" << "Empty" << "]";
    } else {
        cout << "[" << _inventory[3].name << "]";
    }
    cout << "|";
    cout << endl;
    
    
}

Candy Player::findCandy(string candy_name) {
    // see if you can find candy name in inventory
        // boolean 
    bool found = false;
    for(int i = 0; i < _candy_amount; i++) {

        // CASE INSENVITY!
        string lower_case_inventory_name = "";
        // to go through every character in inventory name and change it to lower case
        for(int k = 0; k < _inventory[i].name.length(); k++) {
            // cout << "before" << _inventory[i].name[k];
            //_inventory[i].name[k] = tolower(_inventory[i].name[k]);
            lower_case_inventory_name += tolower(_inventory[i].name[k]);
        }

        // go through every character in candy name and change it to lower
        for(int k = 0; k < candy_name.length(); k++) {
            // cout << "before" << candy_name[k];
            candy_name[k] = tolower(candy_name[k]);
            // cout << "after" << candy_name[k];
        }

        // if you can find the name, return that struct! 
        if(candy_name == lower_case_inventory_name) {
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
    // only add new candy if size of current inventory is less than 4 (max candy amount)
    // cout << _candy_amount;
    if(_candy_amount < 4) {
        for(int i = 0; i < 4; i++) {
            if(_inventory[i].name == "") {
                _inventory[i] = candy;
                // cout << _inventory[i].name << endl;
                _candy_amount++;
                added = true;
                break;
            }
        }
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
        
        // CASE INSENVITY!
        // to go through every character in inventory name and change it to lower case
        for(int k = 0; k < _inventory[i].name.length(); k++) {
            // cout << "before" << _inventory[i].name[k];
            _inventory[i].name[k] = tolower(_inventory[i].name[k]);
            // cout << "after" << _inventory[i].name[k];
        }

        // go through every character in candy name and change it to lower
        for(int k = 0; k < candy_name.length(); k++) {
            // cout << "before" << candy_name[k];
            candy_name[k] = tolower(candy_name[k]);
            // cout << "after" << candy_name[k];
        }
 
        // if candy name is found 
        if(_inventory[i].name == candy_name && !removed) {
            removed = true; 
            // remove the candy name 
            for(int j = i; j < _candy_amount; j++) {
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


