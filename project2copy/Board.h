
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "CandyStore.h"
#include "Tile.h"
#include "Player.h"
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;


// struct Tile
// {
//     string color;
//     string tile_type;
//     string tile_name;
// };

struct Riddle {
    string _question;
    string _answer;
};

struct Card {
    string _card_color;
    bool _isDouble;
};

struct Player_On_Board {
    int _which_player_on_board;
    int _position_player_on_board;
    string _status_player_on_board;
    int _lost_stamina;
};

class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_position;
    vector<CandyStore> _candy_stores;
    vector<int> _where_all_unique_tiles_are;
    vector<Player_On_Board> players_on_board;
    bool _move_back_to_0;
    int _who_moved_back_to_0;

public:
    Board(int numOfPlayers);

    void resetBoard(int numOfPlayers);
    vector<Riddle> readRiddlesFile();
    void displayTile(int position, vector<Player_On_Board> players_on_board);
    void displayBoard(vector<Player_On_Board> players_on_board);
    void setMoveBackTo0(bool move_back_to_0);
    bool getMoveBackTo0();
    void setWhoMoveBackTo0(int who_move_back_to_0);
    int getWhoMoveBackTo0();
    bool setPlayerPosition(int);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition() const;
    int getCandyStorePosition() const;
    int getSpecialTilePosition() const;
    // string getTileColor(int position) const;
    void setTileTypeOnBoard(int position, string tile_type);
    Tile getTile(int position) const;
    vector<int> getWhereAllUniqueTilesAre() const;
    void setTile(int position, Tile new_tile);
    void getAllTileTypes() const;
    bool setPlayerPositionOnBoard(int new_position, int player_number);
    int getPlayerPositionOnBoard(int player_number) const;
    vector<Player_On_Board> getPlayersVectorOnBoard();
    void setPlayersVectorOnBoard(vector<Player_On_Board> passed_in_players_on_board);
    void setPlayersOnBoardStatus(string status, int player_number);
    void setPlayersOnBoardLostStamina(int lost_stamina, int player_number);




    bool addCandyStore(int);
    bool isPositionCandyStore(int); 
    int movePlayer(int tile_to_move_to, int player_number);
    bool doesRandomNumberExist(int random_number, vector<int> &random_numbers);
    void addingSpecialTiles(vector<int> &random_numbers);
    void addingHiddenTreasures(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers);
    void addingCandyStores(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers, vector<int> &candy_stores_random_numbers);
    void addingCalamity(vector<int> &special_random_numbers, vector<int> &hidden_random_numbers, vector<int> &candy_stores_random_numbers, vector<int> &calamity_random_numbers);

    vector<CandyStore> addActualCandyStore(CandyStore);
    vector<CandyStore> getActualCandyStore() const;
    void setActualCandyStore(vector<CandyStore>);

};

#endif