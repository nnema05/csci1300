
// Pokemon.cpp
// implement the class defined in Pokemon.h
#include <iostream>
#include "Pokemon.h"
// there is no main in this file

// default contrustor
Pokemon::Pokemon() {
    // initialize all values to 0 
    _HP = 0;
    _attack = 0;
    _defense = 0;
    _max = 0;
    _speed = 0;
    _name = "";
}

// Parameterized constructor
Pokemon::Pokemon(string name, double HP, int attack, int defense, int speed, int max) {
    _HP = HP;
    _name = name;
    _attack = attack;
    _defense = defense;
    _max = max;
    _speed = speed;
}

// set methods 
void Pokemon::setHP(double HP) {
    if(HP >= 0 && HP <= 100) {
        _HP = HP;
    }
    // could have an error message here 
}

void Pokemon::setAttack(int attack) {
    _attack = attack;
}

void Pokemon::setSpeed(int speed) {
    _speed = speed;
}

void Pokemon::setDefense(int defense) {
    _defense = defense;
}

void Pokemon::setMax(int max) {
    _max = max;
}

void Pokemon::setName(string name) {
    _name = name;
}

// get methods for each of our private vairbales
double Pokemon::getHP() const {
    return _HP;
}

int Pokemon::getAttack() const {
    return _attack;
}

int Pokemon::getSpeed() const {
    return _speed;
}

int Pokemon::getDefense() const {
    return _defense;
}

int Pokemon::getMax() const {
    return _max;
}

string Pokemon::getName() const {
    return _name;
}

void Pokemon::printPokemon() const {
    // display value for pokemon data members
    cout << "_____________" << endl;
    cout << "Name: " << _name << endl;
    cout << "HP: " << _HP << endl;
    cout << "Attack: " << _attack << endl;
    cout << "Defense: " << _defense << endl;
    cout << "Speed: " << _speed << endl;
    cout << "Max: " << _max << endl;
    cout << endl;

}