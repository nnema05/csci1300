
// Trainer.cpp
#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Trainer.h"

using namespace std;

// default constructor
Trainer::Trainer(){
    _name = "";
    // make sure vectors are empty 
    _pokemons.clear();
    _badges.clear();
}

Trainer::Trainer(string name){
    _name = name;
    // make sure vectors are empty 
    _badges.clear();
    _pokemons.clear();
}

Trainer::Trainer(string name, Pokemon p){
    _name = name;
    // make sure vectors are empty 
    _badges.clear();
    _pokemons.push_back(p); // adds pokemon p to the _pokemons vectopr
}

Trainer::Trainer(string name, vector<Pokemon> vec){
    _name = name;
    // make sure vectors are empty 
    _badges.clear();
    
    for(int i = 0; i < vec.size(); i++) {
         _pokemons.push_back(vec.at(i)); // adds pokemon p to the _pokemons vectopr
    }
}

string Trainer::getName() const {
    return _name;
}

bool Trainer::addPokemon(Pokemon) {
    // 1. Search the vector and check if p._name exists
        // OR you can use findPokemon(p.getName)
    // 2. If it exists then return false 
    // 3. else _pokemons.push_back(p)
   
}
int Trainer::findPokemon(string name) {
    int index = -1;
    // 1. search the vector and check if a Pokemon with name exists
    // 2. If it exisst then update index
    // 3. else nothing 
    return index;
}

Pokemon Trainer::getPokemonAt(int index) const {
    // 1. index --> 0 and getNumPokemons()
    if(index >= 0 && index < getNumPokemons()) {
        return _pokemons.at(index);
    } else {
        return Pokemon();
        // OR 
        // Pokemon p;
        // return p;
    }
    // else return empty pokemon instance Pokemon();
}

int Trainer::getNumPokemons() const {
    return _pokemons.size();
}