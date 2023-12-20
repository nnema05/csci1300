#ifndef CANDY_STORE_H
#define CANDY_STORE_H

#include <iostream>
#include <string>
#include <vector>
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;


/* Candy struct for each candy in the game */
struct Candy {
    // description from file
    string name; // Name of candy
    string description; // Description of candy
    string effect_type;
    int effect_value;
    string candy_type; // Type of candy
    double price; // Price of candy
};

class CandyStore {
    public: 
        /* getters and setters */
        CandyStore();
        CandyStore(int, Candy[], string, int); // int tile number, Candy array of candies, int _store_name, int current_candies_in_store
        CandyStore(Candy candies[], int current_candies_in_store);
        int getTile() const;
        void setTile(int);
        void setCandies(Candy[], int);
        string getStoreName() const;
        void setStoreName(string);
        int getCurrentCandyAmount() const;
        void setCurrentCandyAmount(int);

        /* adding and removing candies from candy store*/
        bool addCandy(Candy);
        bool removeCandy(string candy_name);
        void displayListOfCandy();
        void displayWholeCandy(Candy candies[], int current_candies_in_store, int position);
        vector<Candy> displayThreeRandomCandies(Candy candies[], int current_candies_in_store);
        // finding a candy in the store 
        Candy findCandy(string candy_name, vector<Candy> candies);
        
    private:
        int _tile_num;
        Candy _candies[14];
        string _store_name;
        const static int _MAX_CANDIES_IN_STORE = 14;
        int _current_candies_in_store;
};

#endif
