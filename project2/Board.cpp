#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "CandyStore.h"
#include "Tile.h"
#include "Player.h"

/* Constructors */
Board::Board(int numOfPlayers)
{
    resetBoard(numOfPlayers);
}

void Board::resetBoard(int numOfPlayers)
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;

    /* This board is adding the special tiles, hidden treasures, candy stores and calamities */
    vector<int> special_random_numbers;
    addingSpecialTiles(special_random_numbers);
    //  for(int k = 0; k < special_random_numbers.size(); k++) {
    //     cout <<  "special_random_numbers.at(k) " << special_random_numbers.at(k) << endl;
    // }
    vector <int> hidden_random_numbers;
    addingHiddenTreasures(special_random_numbers, hidden_random_numbers);
    // for(int k = 0; k < hidden_random_numbers.size(); k++) {
    //     cout <<  "hidden_random_numbers.at(k) " << hidden_random_numbers.at(k) << endl;
    // }
    vector <int> candy_stores_random_numbers;
    addingCandyStores(special_random_numbers, hidden_random_numbers, candy_stores_random_numbers);
    // for(int k = 0; k < candy_stores_random_numbers.size(); k++) {
    //     cout <<  "candy_stores_random_numbers.at(k) " << candy_stores_random_numbers.at(k) << endl;
    // }
    vector <int> calamity_random_numbers;
    addingCalamity(special_random_numbers, hidden_random_numbers, candy_stores_random_numbers, calamity_random_numbers);
    // for(int k = 0; k < calamity_random_numbers.size(); k++) {
    //     cout <<  "calamity_random_numbers.at(k) " << calamity_random_numbers.at(k) << endl;
    // }

    // make a whole vector combining all of the vectors from above to store where all the unqiue tiles are
        // Source: https://www.techiedelight.com/concatenate-multiple-vectors-in-cpp/ for .insert(), .end(), .begin()
        // .insert is used to insert elements in a container at a specified position, increasing the container size so it inserts it where the unique tile ends
    vector<int> where_all_unique_tiles_are = special_random_numbers;
    where_all_unique_tiles_are.insert(where_all_unique_tiles_are.end(), hidden_random_numbers.begin(), hidden_random_numbers.end());
    where_all_unique_tiles_are.insert(where_all_unique_tiles_are.end(), candy_stores_random_numbers.begin(), candy_stores_random_numbers.end());
    where_all_unique_tiles_are.insert(where_all_unique_tiles_are.end(), calamity_random_numbers.begin(), calamity_random_numbers.end());
    // for(int k = 0; k < where_all_unique_tiles_are.size(); k++) {
    //      cout <<  "where_all_unique_tiles_are.at(k) " << where_all_unique_tiles_are.at(k) << endl;
    // }
    _where_all_unique_tiles_are = where_all_unique_tiles_are;

    
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        // new_tile.color = current_color;
        // new_tile.tile_type = "regular tile"
        new_tile.setColor(current_color);
        /* SPECIAL TILE */
        /* While any of these tiles are a special tile */
        bool isSpecialTile = false;
        for(int k = 0; k < special_random_numbers.size(); k++) {
            if(i == special_random_numbers.at(k)) {
                isSpecialTile = true; // set special tile boolean to true 
            }
        }
        /* HIDDEN TILE */
        /* While any of these tiles are a hidden tile */
        bool isHiddenTile = false;
        for(int k = 0; k < hidden_random_numbers.size(); k++) {
            if(i == hidden_random_numbers.at(k)) {
                isHiddenTile = true;  // set hidden tile boolean to true 
            }
        }

        /* CANDY STORE TILE */
        /* While any of these tiles are a CANDY tile */
        bool isCandyStoreTile = false;
        for(int k = 0; k < candy_stores_random_numbers.size(); k++) {
            if(i == candy_stores_random_numbers.at(k)) {
                isCandyStoreTile = true; // set candy store tile boolean to true 
            }
        }

        // set the tile type for each accordingly in tile class
        if(isSpecialTile) {
            new_tile.setTileType("special tile");
        } else if(isHiddenTile) {
            new_tile.setTileType("hidden tile");
        } else if (isCandyStoreTile) {
            new_tile.setTileType("candy store tile");
        } else {
            new_tile.setTileType("regular tile");
        }
        

        // INPUTING IN REGULAR TILES!!
        /* CALAMITY TILE, only exists on regular tile*/
        if(new_tile.getTileType() == "regular tile") {
            bool isCalamityTile = false;
            for(int k = 0; k < calamity_random_numbers.size(); k++) {
                if(i == calamity_random_numbers.at(k)) {
                    isCalamityTile = true;
                }
            }
            if(isCalamityTile) {
                new_tile.setTileType("calamity regular tile");
            }

        }
       
        _tiles[i] = new_tile;
        // cout << new_tile.getTileType() << endl;
    }
    // new_tile.color = ORANGE;
    // new_tile.tile_type = "regular tile";
    new_tile.setColor(ORANGE);
    new_tile.setTileType("regular tile");
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    // create a player on board vector, creating a player 1 on board a player two on board
        // add it to vectors called players on board
    _player_position = 0;
    _move_back_to_0 = false;
    for(int i = 0; i < numOfPlayers; i++) {
        Player_On_Board player_on_board;
        int which_player = i+1;
        player_on_board._which_player_on_board = which_player;
        player_on_board._position_player_on_board = 0;
        player_on_board._status_player_on_board = "";
        player_on_board._lost_stamina = 0;
        players_on_board.push_back(player_on_board);
        // cout <<  players_on_board[i]._which_player_on_board << endl;
        // cout <<  players_on_board[i]._position_player_on_board << endl;
    }
    // cout << "players_on_board size" << players_on_board.size() << endl;
}

// READ RIDDLES, storing them in a riddle struct with question and answer
vector<Riddle> Board::readRiddlesFile() {
    string file_name = "riddles.txt";
    ifstream file;
    file.open(file_name); // opens a file
    // will hold the whole line
    string riddle_line;
    // riddle object 
    Riddle riddle;
    // create object from candy class
    vector<Riddle> riddles;

    if(file.is_open())
    {
        // while you read from each line
        while (!file.eof()) {
            
            // get whole riddle line
            getline(file, riddle_line);

            // put the riddle line in the string stream
            stringstream ss(riddle_line);
            // read each part into the right part of the struct using get line
                // delimeter by '|'

            // read into riddle question
            getline(ss, riddle._question, '|');
            // If there is no question, move on to next iteration - for empty lines text
            if(riddle._question == "") {
                continue;
            }
            // cout << "riddle._question " << riddle._question << endl;
            // read into riddle answer
            getline(ss, riddle._answer);
            // cout << "riddle._answer " << riddle._answer << endl;
            

            // add riddle into vector
            riddles.push_back(riddle);
            
        }

        // for(int i = 0; i < current_size; i++) {
        //         cout << candy_array[i].name << endl;
        // }
    } else {
            // if could not open file, return original vector
        cout << "Failed to open file" << endl;
    }
    file.close();
    return riddles;
}


/* Getters and setters */
void Board::setTile(int position, Tile new_tile) {
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        if(i == position) {
                _tiles[i] = new_tile;
                // cout << position << "  " << new_tile.getTileType() << endl;
            
        }
    }
}


void Board::setTileTypeOnBoard(int position, string tile_type) {
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
        {
            if(i == position) {
                 _tiles[i].setTileType(tile_type);
                 // cout << position << "  " << new_tile.getTileType() << endl;
                
            }
        }
}

void Board::getAllTileTypes() const {
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        cout << _tiles[i].getTileType() << endl;
    }
}

// string Board::getTileColor(int position) const { // get the color of a certain position
//     for (int i = 0; i < _BOARD_SIZE - 1; i++)
//     {
//         if(i == position) {
//             string color = _tiles[i].getColor();
//             cout << color << endl;
//             return color;
//         }
        
//     }
// }

// Function checks if the random number exists in a list of random numbers
    // functionality to make sure no random number for tiles candy store, hidden, treasure and calamities happen on the same number/tile
bool Board::doesRandomNumberExist(int random_number, vector<int> &random_numbers) {
    // cout << "random_number " << random_number << endl;
    bool found = false;
    // cout << "found before " << found;
    for(int i = 0; i < random_numbers.size(); i++) {
        if(random_number == random_numbers.at(i)) {
            found = true;
            return found;
        }
    }
    // cout << "found after " << found;
    return found;
}

// Generates numbers for special tules
void Board::addingSpecialTiles(vector<int> &random_numbers) {
    /* SPECIAL TILES - adding 4 */
    /* FOR TESTING */
    srand((unsigned)time(NULL));
    // get 4 unique random numbers from 1-81 (get numbers that correspond to index on the board )
        // ignore 82 and 0 because those are to be set to a regular tile
    int special_tile_r1 = rand() % 81 + 1;
    // special_tile_r1 = 10;
    while(doesRandomNumberExist(special_tile_r1, random_numbers)) { // if that number doe already exist in the vector of random numbers, keep regenerating until its a new one
        special_tile_r1 = rand() % 81 + 1;
    }
    random_numbers.push_back(special_tile_r1);
    // cout << special_tile_r1 << endl;
    int special_tile_r2 = rand() % 81 + 1;
    while(doesRandomNumberExist(special_tile_r2, random_numbers)) {
        special_tile_r2 = rand() % 81 + 1;
    }
    random_numbers.push_back(special_tile_r2);
    // cout << special_tile_r2 << endl;
    int special_tile_r3 = rand() % 81 + 1;
    while(doesRandomNumberExist(special_tile_r3, random_numbers)) {
        special_tile_r3 = rand() % 81 + 1;
    }
    random_numbers.push_back(special_tile_r3);
    // cout << special_tile_r3 << endl;
    int special_tile_r4 = rand() % 81 + 1;
    while(doesRandomNumberExist(special_tile_r4, random_numbers)) {
        special_tile_r4 = rand() % 81 + 1;
    }
    random_numbers.push_back(special_tile_r4);
    // cout << special_tile_r4 << endl;
    // add all special tiles to random numbers vector
}

void Board::addingHiddenTreasures(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers) {
     /* HIDDEN TILES */
    srand((unsigned)time(NULL));
    // get 3 unique random numbers from 1-81
    int hidden_tile_r1 = rand() % 81 + 1;
    // hidden_tile_r1 = 10; /* FOR TESTING */
    // cout << special_random_numbers.size() << endl;
    while(doesRandomNumberExist(hidden_tile_r1, special_random_numbers) || doesRandomNumberExist(hidden_tile_r1, hidden_random_numbers)) { // if that number does already exist in the vector of random numbers of special tiles and hidden treasures, keep regenerating until its a new one
        hidden_tile_r1 = rand() % 81 + 1;
    }
    hidden_random_numbers.push_back(hidden_tile_r1);
    // cout << hidden_tile_r1 << endl;
    int hidden_tile_r2 = rand() % 81 + 1;
    while(doesRandomNumberExist(hidden_tile_r2, special_random_numbers) || doesRandomNumberExist(hidden_tile_r2, hidden_random_numbers)) {
        hidden_tile_r2 = rand() % 81 + 1;
    }
    hidden_random_numbers.push_back(hidden_tile_r2);
    // cout << hidden_tile_r2 << endl;
    int hidden_tile_r3 = rand() % 81 + 1;
    while(doesRandomNumberExist(hidden_tile_r3, special_random_numbers) || doesRandomNumberExist(hidden_tile_r3, hidden_random_numbers)) {
        hidden_tile_r3 = rand() % 81 + 1;
    }
    hidden_random_numbers.push_back(hidden_tile_r3);
     // add all hidden tiles to random numbers vector
}

void Board::addingCalamity(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers, vector<int> &candy_stores_random_numbers, vector<int> &calamity_random_numbers) {
    /* CALAMITY  TILES */
    // After special tiles, hidden treasures and candy stores, there are 73 regular tiles left
        // 40% of these are calamities so 29 
    //  Generate 29 random tiles for calamities
        // get 29 unique random numbers from 1-81
    srand((unsigned)time(NULL)); // get seed for random number
        // this number has to be number%3 = 0
    int calamity_tile_r1 = rand() % 81 + 1;
    // calamity_tile_r1 = 10; // for testing 
    // if that number does already exist in the vector of random numbers of special tiles and hidden treasures or calamities or candy store keep regenerating until its a new one
    while(doesRandomNumberExist(calamity_tile_r1, special_random_numbers) || doesRandomNumberExist(calamity_tile_r1, hidden_random_numbers) ||  doesRandomNumberExist(calamity_tile_r1, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r1, calamity_random_numbers)) {
        calamity_tile_r1 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r1);
    // cout << calamity_tile_r1 << endl;
    int calamity_tile_r2 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r2, special_random_numbers) || doesRandomNumberExist(calamity_tile_r2, hidden_random_numbers) ||  doesRandomNumberExist(calamity_tile_r2, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r2, calamity_random_numbers)) {
        calamity_tile_r2 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r2);
    // cout << calamity_tile_r2 << endl;
    
    int calamity_tile_r3 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r3, special_random_numbers) || doesRandomNumberExist(calamity_tile_r3, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r3, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r3, calamity_random_numbers)) {
        calamity_tile_r3 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r3);

    int calamity_tile_r4 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r4, special_random_numbers) || doesRandomNumberExist(calamity_tile_r4, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r4, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r4, calamity_random_numbers)) {
        calamity_tile_r4 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r4);

    int calamity_tile_r5 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r5, special_random_numbers) || doesRandomNumberExist(calamity_tile_r5, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r5, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r5, calamity_random_numbers)) {
        calamity_tile_r5 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r5);

    int calamity_tile_r6 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r6, special_random_numbers) || doesRandomNumberExist(calamity_tile_r6, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r6, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r6, calamity_random_numbers)) {
        calamity_tile_r6 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r6);

    int calamity_tile_r7 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r7, special_random_numbers) || doesRandomNumberExist(calamity_tile_r7, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r7, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r7, calamity_random_numbers)) {
        calamity_tile_r7 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r7);

    int calamity_tile_r8 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r8, special_random_numbers) || doesRandomNumberExist(calamity_tile_r8, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r8, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r8, calamity_random_numbers)) {
        calamity_tile_r8 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r8);

    int calamity_tile_r9 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r9, special_random_numbers) || doesRandomNumberExist(calamity_tile_r9, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r9, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r9, calamity_random_numbers)) {
        calamity_tile_r9 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r9);

    int calamity_tile_r10 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r10, special_random_numbers) || doesRandomNumberExist(calamity_tile_r10, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r10, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r10, calamity_random_numbers)) {
        calamity_tile_r10 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r10);

    int calamity_tile_r11 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r11, special_random_numbers) || doesRandomNumberExist(calamity_tile_r11, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r11, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r11, calamity_random_numbers)) {
        calamity_tile_r11 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r11);

    int calamity_tile_r12 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r12, special_random_numbers) || doesRandomNumberExist(calamity_tile_r12, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r12, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r12, calamity_random_numbers)) {
        calamity_tile_r12 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r12);

    int calamity_tile_r13 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r13, special_random_numbers) || doesRandomNumberExist(calamity_tile_r13, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r13, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r13, calamity_random_numbers)) {
        calamity_tile_r13 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r13);

    int calamity_tile_r14 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r14, special_random_numbers) || doesRandomNumberExist(calamity_tile_r14, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r14, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r14, calamity_random_numbers)) {
        calamity_tile_r14 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r14);

    int calamity_tile_r15 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r15, special_random_numbers) || doesRandomNumberExist(calamity_tile_r15, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r15, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r15, calamity_random_numbers)) {
        calamity_tile_r15 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r15);

    int calamity_tile_r16 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r16, special_random_numbers) || doesRandomNumberExist(calamity_tile_r16, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r16, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r16, calamity_random_numbers)) {
        calamity_tile_r16 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r16);

    int calamity_tile_r17 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r17, special_random_numbers) || doesRandomNumberExist(calamity_tile_r17, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r17, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r17, calamity_random_numbers)) {
        calamity_tile_r17 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r17);

    int calamity_tile_r18 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r18, special_random_numbers) || doesRandomNumberExist(calamity_tile_r18, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r18, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r18, calamity_random_numbers)) {
        calamity_tile_r18 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r18);

    int calamity_tile_r19 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r19, special_random_numbers) || doesRandomNumberExist(calamity_tile_r19, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r19, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r19, calamity_random_numbers)) {
        calamity_tile_r19 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r19);

    int calamity_tile_r20 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r20, special_random_numbers) || doesRandomNumberExist(calamity_tile_r20, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r20, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r20, calamity_random_numbers)) {
        calamity_tile_r20 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r20);

    int calamity_tile_r21 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r21, special_random_numbers) || doesRandomNumberExist(calamity_tile_r21, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r21, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r21, calamity_random_numbers)) {
        calamity_tile_r21 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r21);

    int calamity_tile_r22 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r22, special_random_numbers) || doesRandomNumberExist(calamity_tile_r22, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r22, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r22, calamity_random_numbers)) {
        calamity_tile_r22 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r22);

    int calamity_tile_r23 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r23, special_random_numbers) || doesRandomNumberExist(calamity_tile_r23, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r23, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r23, calamity_random_numbers)) {
        calamity_tile_r23 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r23);

    int calamity_tile_r24 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r24, special_random_numbers) || doesRandomNumberExist(calamity_tile_r24, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r24, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r24, calamity_random_numbers)) {
        calamity_tile_r24 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r24);

    int calamity_tile_r25 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r25, special_random_numbers) || doesRandomNumberExist(calamity_tile_r25, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r25, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r25, calamity_random_numbers)) {
        calamity_tile_r25 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r25);

    int calamity_tile_r26 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r26, special_random_numbers) || doesRandomNumberExist(calamity_tile_r26, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r26, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r26, calamity_random_numbers)) {
        calamity_tile_r26 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r26);

    int calamity_tile_r27 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r27, special_random_numbers) || doesRandomNumberExist(calamity_tile_r27, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r27, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r27, calamity_random_numbers)) {
        calamity_tile_r27 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r27);

    int calamity_tile_r28 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r28, special_random_numbers) || doesRandomNumberExist(calamity_tile_r28, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r28, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r28, calamity_random_numbers)) {
        calamity_tile_r28 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r28);

    int calamity_tile_r29 = rand() % 81 + 1;
    while(doesRandomNumberExist(calamity_tile_r29, special_random_numbers) || doesRandomNumberExist(calamity_tile_r29, hidden_random_numbers) || doesRandomNumberExist(calamity_tile_r29, candy_stores_random_numbers) || doesRandomNumberExist(calamity_tile_r29, calamity_random_numbers)) {
        calamity_tile_r29 = rand() % 81 + 1;
    }
    calamity_random_numbers.push_back(calamity_tile_r29);
}

void Board::addingCandyStores(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers, vector<int> &candy_stores_random_numbers) {
    /* CANDY TILES */

    srand((unsigned)time(NULL)); // get random number
    // get first unique random number from 1-26 for first candy store
        // this number has to be number%3 = 0 (magenta)
    int candy_store_tile_r1 = rand() % 26 + 1;
    // candy_store_tile_r1 = 2;
    while(candy_store_tile_r1%3 != 0 || doesRandomNumberExist(candy_store_tile_r1, special_random_numbers) || doesRandomNumberExist(candy_store_tile_r1, hidden_random_numbers) ||  doesRandomNumberExist(candy_store_tile_r1, candy_stores_random_numbers)) {
        candy_store_tile_r1 = rand() % 26 + 1;
    }
    candy_stores_random_numbers.push_back(candy_store_tile_r1);
    // cout << candy_store_tile_r1 << endl;
    // get second unique random number from 27-53 for second candy store
        // this number has to be number%3 = 1 (green)
    int candy_store_tile_r2 = 27 + rand() % 26;
    while(candy_store_tile_r2%3 != 1 || doesRandomNumberExist(candy_store_tile_r2, special_random_numbers) || doesRandomNumberExist(candy_store_tile_r2, hidden_random_numbers) ||  doesRandomNumberExist(candy_store_tile_r2, candy_stores_random_numbers)) {
        candy_store_tile_r2 = 27 + rand() % 26;
    }
    candy_stores_random_numbers.push_back(candy_store_tile_r2);
    // cout << candy_store_tile_r2 << endl;
    // get third unique random number from 54-81 for second candy store
        // this number has to be number%3= 2 (blue)
    int candy_store_tile_r3 = 54 + rand() % 27;
    while(candy_store_tile_r3%3 != 2 || doesRandomNumberExist(candy_store_tile_r3, special_random_numbers) || doesRandomNumberExist(candy_store_tile_r3, hidden_random_numbers) || doesRandomNumberExist(candy_store_tile_r3, candy_stores_random_numbers)) {
        candy_store_tile_r3 = 54 + rand() % 27;
    }
    // cout << candy_store_tile_r3 << endl;
    candy_stores_random_numbers.push_back(candy_store_tile_r3);
}

void Board::displayTile(int position, vector<Player_On_Board> players_on_board)
{   
    // cout << "size in display tile" << players_on_board.size() << endl;
    // cout << "hi display tile" << endl;
    // cout << "  _move_back_to_0  " <<  _move_back_to_0;
    // cout << " _who_moved_back_to_0 " << _who_moved_back_to_0;
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.getColor() << " ";
    if(position == 0 && _move_back_to_0!= true) {
        cout << " "; 
        
    } else if (position == 0 && _move_back_to_0 == true) {
        if(position == players_on_board.at(_who_moved_back_to_0 - 1)._position_player_on_board) { // if position is 0 and if move back to 0 is true
            cout << _who_moved_back_to_0; // if someone was forced to move back to 0, cout move back to 0 
            _move_back_to_0 = false;
        }
        _move_back_to_0 = false;
    } else {
        bool playerFound = false;
        // cout << " players_on_board.size() in display tile" << players_on_board.size() << endl;
        
        for(int k = 0; k <players_on_board.size(); k++) {
            // if poistion = players on board position then, cout the player on the board
                // because of for loop it will cout both
            if(position == players_on_board.at(k)._position_player_on_board) {
                cout << players_on_board.at(k)._which_player_on_board; // when player found, cout the player on the board
                playerFound = true; // only set to true when the the position mactches the players tracked position
            }
        }
        if(!playerFound) {
            cout << " "; // cout a blank spot when position does not match
        }
    }
    cout << " " << RESET;
    /* WORKING FOR TWO*/
    // if (position == players_on_board.at(0)._position_player_on_board)
    // {
    //     cout << players_on_board.at(0)._which_player_on_board;
    // } else if (position == players_on_board.at(1)._position_player_on_board) {
    //     cout << players_on_board.at(1)._which_player_on_board;
    // }
    // else
    // {
    //     cout << " ";
    // }
    // cout << " " << RESET;


        // if (position < 0 || position >= _BOARD_SIZE)
        // {
        //     return;
        // }
        // Tile target = _tiles[position];
        // cout << target.getColor() << " ";
        // if(position == 0) {
        //     cout << " ";
        // }
        // else
        //     for(int i = 0; i < players_on_board.size(); i ++) {
        //     {
        //         if (position == players_on_board.at(i)._position_player_on_board)
        //             {
        //                 cout <<  players_on_board.at(i)._which_player_on_board;
        //             }
        //         else
        //             {
        //                 cout << " ";
        //             }
        //     }
            
            //else 
            // cout << " " << RESET;

    // }
}

void Board::displayBoard(vector<Player_On_Board> players_on_board)
{
    // First horizontal segment
    // cout << "hi display board" << endl;
    // cout << " players_on_board[0]._position_player_on_board " << players_on_board[0]._position_player_on_board;
    // cout << " players_on_board.size() " << players_on_board.size();
    for (int i = 0; i <= 23; i++)
    {
        // cout << " hi in i < 23";
        // for(int k == 0; k < players_on_board.size(); i)
        displayTile(i, players_on_board);
        // displayTile(i, players_on_board[1]);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        // cout << " hi in i < 28";
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i, players_on_board);
        // displayTile(i, players_on_board[1]);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        // cout << " hi in i < 28";
        displayTile(i, players_on_board);
        // displayTile(i, players_on_board[1]);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        // cout << " hi in i < 57";
        displayTile(i, players_on_board);
        // displayTile(i, players_on_board[1]);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        // cout << " hi in i < 58";
        displayTile(i, players_on_board);
        // displayTile(i, players_on_board[1]);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

/* MORE SETTERS AND GETTERS */
void Board::setMoveBackTo0(bool move_back_to_0) {
    _move_back_to_0 = move_back_to_0;
}

bool Board::getMoveBackTo0() {
    return _move_back_to_0;
}

void Board::setWhoMoveBackTo0(int who_moved_back_to_0) {
    _who_moved_back_to_0 = who_moved_back_to_0;
}

int Board::getWhoMoveBackTo0() {
    return _who_moved_back_to_0;
}

bool Board::setPlayerPosition(int new_position)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position = new_position;
        return true;
    }
    return false;
}

bool Board::setPlayerPositionOnBoard(int new_position, int player_number)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        players_on_board.at(player_number - 1)._position_player_on_board = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition() const
{
    return _player_position;
}

int Board::getPlayerPositionOnBoard(int player_number) const
{
    return players_on_board.at(player_number - 1)._position_player_on_board;
}

vector<Player_On_Board> Board::getPlayersVectorOnBoard()
{
    // cout << players_on_board.size();
    return players_on_board;
}

void Board::setPlayersVectorOnBoard(vector<Player_On_Board> passed_in_players_on_board)
{
    players_on_board = passed_in_players_on_board;
}

void Board::setPlayersOnBoardStatus(string status, int player_number)
{
    players_on_board.at(player_number-1)._status_player_on_board = status;
}

void Board::setPlayersOnBoardLostStamina(int lost_stamina, int player_number)
{
    players_on_board.at(player_number-1)._lost_stamina = lost_stamina;
}

int Board::getCandyStorePosition() const {
    for(int i = 0; i <_BOARD_SIZE; i++) {
        if(_tiles[i].getTileType() == "candy store tile") {
            // cout << " candy store position " << i << endl;
            return i;
        }
    }
    return -1;
}

int Board::getSpecialTilePosition() const {
    for(int i = 0; i <_BOARD_SIZE; i++) {
        if(_tiles[i].getTileType() == "special tile") {
            // cout << " special tile position " << i << endl;
            return i;
        }
    }
    return -1;
}

Tile Board::getTile(int position) const {
    return _tiles[position];
}

vector<int> Board::getWhereAllUniqueTilesAre() const {
    return _where_all_unique_tiles_are;
}

/* add a candy store on a certain position in an array that holds all the position on the candy store  */
bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

// see if a position is a position of a candy store
bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

// Add an actual actual candy class in a vector candy stores
vector<CandyStore> Board::addActualCandyStore(CandyStore candy_store)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return _candy_stores;
    }
    // add to candy store to vector of actual candy stores
    _candy_stores.push_back(candy_store);
    return _candy_stores;
}

vector<CandyStore> Board::getActualCandyStore() const {
    return _candy_stores;
}

void Board::setActualCandyStore(vector<CandyStore> candy_stores) {
    _candy_stores = candy_stores;
}


// bool Board::movePlayer(int tile_to_move_forward, int player_number)
// {
//     int new_player_position = tile_to_move_forward + _player_position;
//     if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
//     {
//         return false;
//     }
//     _player_position = new_player_position;
//     return true;
// }


// Move player by resetting the position based on the tile to move to and what player to move
int Board::movePlayer(int tile_to_move_to, int player_number)
{
    //  int new_player_position = tile_to_move_forward + players_on_board.at(player_number - 1)._position_player_on_board;
    int new_player_position = tile_to_move_to;
    if(new_player_position < 0)
    {
        return 0;

    } else if (tile_to_move_to >= _BOARD_SIZE - 1) {
        // if new position is beyond the board size (means game has ended)
        // cout << " hit end" << endl;
        new_player_position = _BOARD_SIZE -1;
        players_on_board.at(player_number - 1)._position_player_on_board = new_player_position;
        players_on_board.at(player_number - 1)._status_player_on_board = "end game"; // sets status for end game 
        return 1;
    }
    players_on_board.at(player_number - 1)._position_player_on_board = new_player_position; // set the position of the player on baord as the new players position
    // _tiles[new_player_position].getTileType() 
    return 2;
}

