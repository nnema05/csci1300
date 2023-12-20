// train the pokemon
// collection of pokemon - private data members
// collection of badges 
// add a badge after winning a battle 
// add a pokemon
// name 

// header guards 
#ifndef TRAINER_H
#define TRAINER_H

// trainer class defined here
#include <iostream>
#include <vector>
#include "Pokemon.h" // makes trainer class aware of Pokemon class
using namespace std;

// trainer can have 0, 1, many pokemon 
// badge - type, trainer_defeated 
struct Badge{
    string type;
    string trainer_defeated;

};
class Trainer{
    public:
        Trainer(); // default constructor
        Trainer(string); // instance of Trainer, name only 
        Trainer(string, Pokemon); // instance of Trainer, one Pokemon object
        Trainer(string, vector<Pokemon>); // instance of Trainer, vector of Pokemon

        string getName() const; // return the trainers name
        void setName(string);
        // how to design memebr function for array of vector of objects
        bool addPokemon(Pokemon); // void, vector, bool, int 
        bool removePokemon(string); // Pokemon, string, int
        int findPokemon(string); // returns the index of the pokemon whose name matches string paramter
        int getNumPokemons() const; // return the size of _pokemons
        // standard getter and setter
        // update pokemon at this index
        Pokemon getPokemonAt(int) const; // returns the Pokemon at the specifed index 
        bool setPokemonAt(int, Pokemon); // updates the Pokemonn at the specifed index

        // badge fucntions 
        bool addBadge(Badge);
        vector<Badge> getBadges(string) const;
        int getNumBadges() const;


    private:
        string _name; // trainers name
        vector<Badge> _badges;
        vector<Pokemon> _pokemons; 
        // add, remove, print, find/search for something, update, how many pokemons are there 
};
#endif