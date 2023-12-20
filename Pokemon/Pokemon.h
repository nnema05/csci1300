
// This is a  Pokemon header file
// It will define the pokemon class
// save your file with a .h extension, this is the convention for header files
//.hpp is also used sometimes for c++ header files

// header guards 
// if there is no definition for Pokemon
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

class Pokemon{
    public:
    // constructors 
    Pokemon(); // default constructo, no input paramters
    // paramterized constructor
    Pokemon(string, double, int, int, int, int);

    // need a public get and set method for each private variable
    // get is a public interface to access the private vairaible
    // set is a public interface
    void setHP(double); // arguement to this method is what we use to set the private _HP variable
    void setAttack(int);
    void setSpeed(int);
    void setDefense(int);
    void setMax(int);
    void setName(string);

    // get method 
    double getHP() const; // const keyword lets us know that method is read only 
    int getAttack() const;
    int getSpeed() const;
    int getDefense() const;
    int getMax() const;
    string getName() const;

    void printPokemon() const;
    
    private: 
        // Define all Pokemon statistics
        double _HP; 
        int _attack;
        int _speed;
        int _defense;
        int _max;
        string _name;

};

#endif
