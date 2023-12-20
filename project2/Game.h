
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "CandyStore.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

class Game {
    private: 
        const static int _num_of_tiles = 83;
        int _number_of_players;
        bool _start_game;
        Player players[2];

    public: 
        Game();
        Game(int, bool); // number of players, start of game
        int readCandyFile(Candy[], int, int);
        vector<Character> readCharactersFile(Candy candy_array[], int current_size);
        void removeCharacters(vector<Character> &characters, Character);
        void setNumberOfParticpants(int);
        int getNumberOfParticpants() const;
        void setStartGame(bool);
        bool getStartGame() const;
        
        bool riddles(char choice, Board &board);
        bool rockPaperScissors(Player[]);
        // int generateRandomNum(int);
        void visitCandyStore(Player &player, CandyStore &candy_store, string candy_to_buy, Candy candy_to_buy_sturct, Candy candies[], int &candy_current_size);

        void calamities(Player);
        void specialTile(Card &card, Board &board, Player &player, int &move_amount, int &tile_to_move_to, int &position, int player_number);
        void hiddenTreasure(bool, Player &player);
        Card drawACard(char correct_choice);
        bool moveThePlayer(Card, Board &board, int player_number, Player players[], bool &drawCardAgain);
        void printMenu();
        void useCandy(Board &board, Candy candy_to_use_struct, Player &player1, Player &opponent, vector<int> where_all_unique_tiles_are);
};

#endif
