
#include "CandyStore.h"

/* Default constructor */
CandyStore::CandyStore() {
    _tile_num = 0;
    for(int i = 0; i < 3; i++) {
        Candy candy;
        candy.name = "";
        candy.description = "";
        candy.effect_type = "";
        candy.effect_value = 0;
        candy.price = 0;
        candy.candy_type = "";
        _candies[i] = candy;
    }
    _store_name = "";
    _current_candies_in_store = 0;
}

/* parameterized constructor, making a candy store based on the list of candies given */
CandyStore::CandyStore(Candy candies[], int current_candies_in_store) {
    if(current_candies_in_store < _MAX_CANDIES_IN_STORE) {
        for(int i = 0; i < current_candies_in_store; i++) {
            _candies[i] = candies[i];
        }
    } else {
        for(int i = 0; i < _MAX_CANDIES_IN_STORE; i++) {
            _candies[i] = candies[i];
        }
    }
    _current_candies_in_store = current_candies_in_store;
}

/* parameterized constructor, making a candy in the candy store */
CandyStore::CandyStore(int tile_num, Candy candies[], string store_name, int current_candies_in_store) {
    _tile_num = tile_num;
    if(current_candies_in_store < _MAX_CANDIES_IN_STORE) {
        for(int i = 0; i < current_candies_in_store; i++) {
            _candies[i] = candies[i];
        }
    } else {
        for(int i = 0; i < _MAX_CANDIES_IN_STORE; i++) {
            _candies[i] = candies[i];
        }
    }
    _store_name = store_name;
    _current_candies_in_store = current_candies_in_store;
}

/* GETTERS AND SETTERS */
int CandyStore::getTile() const 
{
    return _tile_num;
}

void CandyStore::setTile(int tile_num)
{
    _tile_num = tile_num;
}

void CandyStore::setCandies(Candy candies[], int current_candies_in_store)
{
    /* if candies in store is less than max candies in store, add based on set the candies based on the current candies in store */
    if(current_candies_in_store <= _MAX_CANDIES_IN_STORE) {
        for(int i = 0; i < current_candies_in_store; i++) {
            _candies[i] = candies[i];
            // cout << _candies[i].name << endl;
        }
     /* if candies in store is greater than max candies in store, add based on set the candies based on the max candies in store 
     -so you dont for loop past the amoumt of candies in teh store
     */
    } else {
        for(int i = 0; i < _MAX_CANDIES_IN_STORE; i++) {
            _candies[i] = candies[i];
        }
    }
    _current_candies_in_store = current_candies_in_store;
}

string CandyStore::getStoreName() const 
{
    return _store_name;
}

void CandyStore::setStoreName(string store_name)
{
    _store_name = store_name;
}

int CandyStore::getCurrentCandyAmount() const {
    return _current_candies_in_store;
}

void CandyStore::setCurrentCandyAmount(int current_candies_in_store) {
    _current_candies_in_store = current_candies_in_store;
}

/* Display all candies by name */
void CandyStore::displayListOfCandy() 
{   
    for(int i = 0; i < _current_candies_in_store; i++) {
        cout << _candies[i].name << endl;
    }
}
/* Display the whole candy based on the position in the candy store */
void CandyStore::displayWholeCandy(Candy candies[], int current_candies_in_store, int position) {
    cout << candies[position].name << "|";
    cout << candies[position].description << "|";
    cout << candies[position].effect_type << "|";
    cout << candies[position].effect_value << "|";
    cout << candies[position].candy_type << "|";
    cout << candies[position].price << "|" << endl;
}

/* display three random candies in the candy store */
vector<Candy> CandyStore::displayThreeRandomCandies(Candy candies[], int current_candies_in_store) {
    // Generate 3 radnom unique numbers
    vector<Candy> three_random_candies;
    // The function srand(time(NULL)) seeds the random number generator. 
        // This means that the numbers will be different every time the program is run. 
    srand((unsigned)time(NULL));
    // get 3 unique random numbers from 0-current_candies_in_store
    int candy_r1 = rand() % current_candies_in_store;
    // cout << candy_r1 << endl;
    int candy_r2 = rand() % current_candies_in_store;
    while(candy_r2 == candy_r1) {
        candy_r2 = rand() % current_candies_in_store;
    }
    // cout << candy_r2 << endl;
    int candy_r3 = rand() % current_candies_in_store;
    while(candy_r3 == candy_r1 || candy_r3 == candy_r2) {
        candy_r3 = rand() % current_candies_in_store;
    }
    // cout << candy_r3 << endl;
    
    /* Display first candy */
    cout << "Name: " << candies[candy_r1].name << endl;
    cout << "Description: " << candies[candy_r1].description << endl;
    cout << "Effect " <<  candies[candy_r1].effect_type << endl;
    cout << "Effect value " << candies[candy_r1].effect_value << endl;
    cout << "Candy type " << candies[candy_r1].candy_type << endl;
    cout << "Price " << candies[candy_r1].price << endl;
    three_random_candies.push_back(candies[candy_r1]);
    
    /* Display second candy  */
    cout << "--------------" << endl;
    cout << "Name: " << candies[candy_r2].name << endl;
    cout << "Description: " << candies[candy_r2].description << endl;
    cout << "Effect " <<  candies[candy_r2].effect_type << endl;
    cout << "Effect value " << candies[candy_r2].effect_value << endl;
    cout << "Candy type " << candies[candy_r2].candy_type << endl;
    cout << "Price " << candies[candy_r2].price << endl;
    three_random_candies.push_back(candies[candy_r2]);
    
    /* Display third candy  */
    cout << "--------------" << endl;
    cout << "Name: " << candies[candy_r3].name << endl;
    cout << "Description: " << candies[candy_r3].description << endl;
    cout << "Effect " <<  candies[candy_r3].effect_type << endl;
    cout << "Effect value " << candies[candy_r3].effect_value << endl;
    cout << "Candy type " << candies[candy_r3].candy_type << endl;
    cout << "Price " << candies[candy_r3].price << endl;
    three_random_candies.push_back(candies[candy_r3]);
    // for(int i = 0; i < three_random_candies.size(); i++) {
    //     cout << three_random_candies[i].name << endl;
    // }
    cout << endl;
    return three_random_candies;
}

/* Find the candy in the store by looking through the candies in the store */
Candy CandyStore::findCandy(string candy_name, vector<Candy> candies) {
    // see if you can find candy name in inventory
        // boolean 
    bool found = false;
    for(int i = 0; i < candies.size(); i++) {

        // CASE INSENVITY!
        string lower_case_candy_array_name = "";
        // to go through every character in inventory name and change it to lower case
        for(int k = 0; k < candies[i].name.length(); k++) {
            // cout << "before" << _inventory[i].name[k];
            //_inventory[i].name[k] = tolower(_inventory[i].name[k]);
            lower_case_candy_array_name += tolower(candies[i].name[k]);
        }

        // go through every character in candy name and change it to lower
        for(int k = 0; k < candy_name.length(); k++) {
            // cout << "before" << candy_name[k];
            candy_name[k] = tolower(candy_name[k]);
            // cout << "after" << candy_name[k];
        }

        // if you can find the name, return that struct! 
        if(candy_name == lower_case_candy_array_name) {
            found = true;
            return candies[i];
        } 
    }
    // If not found, return an empty candy struct
    Candy empty_candy;
    if(found == false) {
        empty_candy.name = "";
        return empty_candy;
    }
    empty_candy.name = "";
    return empty_candy;
}

/* Add a candy in the store */
bool CandyStore::addCandy(Candy candy) {
    if(_current_candies_in_store < _MAX_CANDIES_IN_STORE) {
        _current_candies_in_store++;
        _candies[_current_candies_in_store - 1] = candy;
    }
    return true;
}

/* remove a candy in the store */
bool CandyStore::removeCandy(string candy_name) {
    bool removed = false;
    // find the candy name to remove - for case insensivity
    // cout << " _current_candies_in_store " << _current_candies_in_store << endl; 
    for(int i = 0; i < _current_candies_in_store && !removed; i++) {
        // if candy name is found 
        if(_candies[i].name == candy_name && !removed) {
            removed = true; 
            // remove the candy name 
            for(int j = i; j < _current_candies_in_store -1; j++) {
                // // if you are the last inventory, make it an empty candy struct
                // if(j == 4) {
                //      Candy empty = {"", "", 0, ""};
                //     _inventory[j] = empty;
                // } else {
                    _candies[j] = _candies[j + 1];
                    _candies[j + 1].name = "";
                    // cout << "i " << i << endl;
                    // cout << "j " << j << endl;
                //}
            }
            _current_candies_in_store--;
            // cout << " _current_candies_in_store after " << _current_candies_in_store << endl;   
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


