
// main driver file
#include<iostream>
#include "Pokemon.h" // this makes file aware of Pokemon class
#include "Trainer.h" 

using namespace std;

void printPokemon(Pokemon p) {
     // display value for pokemon data members
    cout << "_____________" << endl;
    cout << "Name: " << p.getName() << endl;
    cout << "HP: " << p.getHP() << endl;
    cout << "Attack: " << p.getAttack() << endl;
    cout << "Defense: " << p.getDefense() << endl;
    cout << "Speed: " << p.getSpeed() << endl;
    cout << "Max: " << p.getMax() << endl;
    cout << endl;
}

int main() {
    // create a Pokemon
    Pokemon p; // creates a Pokemon object, using default constructor
    p.printPokemon();
    printPokemon(p);
    // update Pokemon values
    p.setName("albert");
    p.setAttack(10);
    p.setDefense(20);
    p.setSpeed(30);
    p.printPokemon();

    // create a Pokemon with paramterized constructor
    Pokemon eevee("eevee", 45.8, 20, 35, 10, 80);
    eevee.printPokemon();
    eevee.setAttack(40); // update eevee attack value
    cout << eevee.getAttack() << endl; // get methods return values
    eevee.printPokemon();

    // create an instance of 
    Trainer ash("Ash");
    Trainer brock("Brock", eevee);
    cout << ash.getName() << endl;
    cout << brock.getName() << endl;

    // array of vector of objects
    Pokemon pokedex[3] = {p, eevee}; // 3 pokemon empty objects --> empty --> default constructor
    
    // creating an object
        // class obejct = object
    Pokemon pikachu("pikachu", 35, 55, 30, 90, 50);
    // whatever is initizalized at line 50 will be stored in array
    pokedex[2] = pikachu;
    pikachu.setHP(45.7); 
    // need to change in actual array
    pokedex[2].setHP(30.5); 

    // print the stuff
    pikachu.printPokemon();

    // printing all pokemons in pokedex
    for (int i = 0; i < 3; i++) {
       pokedex[i].printPokemon(); 
    }

    vector<Trainer> trainerVector; // size 0
    trainerVector.push_back(ash); // whatever you are passing in has to be the correct type
    return 0;
}