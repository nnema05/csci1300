
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"

using namespace std;


bool Game::moveThePlayer(Card card, Board &board, int player_number, Player players[], bool &drawCardAgain) {
    bool isDouble = false;
    bool moved = false;
    cout << "card color " << card._card_color << endl;
    // get current position
    int position = board.getPlayerPositionOnBoard(player_number);
    cout << "position " << position << endl;
    int move_amount = 0;
    int tile_to_move_to = 0;

    // Move the position based on the card choice 
        // if the color we want to move to is magenta 
    if(card._card_color == "magenta") {
        // find amount we want tile to move and the position of the new tile we want to move to 
        move_amount = (3 - position%3)%3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
        
    } else if (card._card_color == "green") {
        move_amount = (3 - position%3 + 1)%3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;

    } else if (card._card_color == "blue") {
        move_amount = (3 - position%3 + 2)%3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;

    } else if (card._card_color == "double-magenta") {
        cout << "double-magenta" << endl;
            // when its a double, add 3 to the move amount 
        move_amount = ((3 - position%3)%3) + 3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
        // card._isDouble = true;
        isDouble = true;

    } else if (card._card_color == "double-green") {
        cout << "double-green" << endl;
            // when its a double, add 3 to the move amount 
        move_amount = ((3 - position%3 + 1)%3) + 3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
        // card._isDouble = true;
        isDouble = true;

    } else if (card._card_color == "double-blue") {
        cout << "double-blue" << endl;
            // when its a double, add 3 to the move amount 
        move_amount = ((3 - position%3 + 2)%3) + 3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
        // card._isDouble = true;
        isDouble = true;
    }

    // if move amount == 0, change it to equal 3 (this means it wants to move from magenta to magenta, green to green, or blue to blue)
    if(move_amount == 0 || (move_amount == 3 && isDouble == true)) {
        cout << "move amount is 0 " << endl;
        move_amount = 3;
        cout << "move_amount is 0 " << move_amount << endl;

        // check if its a double, if true, increase move amount by 3 more!
        if(isDouble) {
            move_amount = move_amount + 3;
            cout << "move_amount if double" << move_amount << endl;
        }

        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;

    }

    // move player accordingly - ACTUAL  
    // int movedfromboard = board.movePlayer(tile_to_move_to, player_number); // ACTUAL

    /* FOR TESTING */ 
    // tile_to_move_to = 10;
    int movedfromboard = board.movePlayer(tile_to_move_to, player_number);
    /* FOR TESTING */
    //  = board.getCandyStorePosition();
    // tile_to_move_to = board.getSpecialTilePosition();
    // tile_to_move_to = 42;
    // movedfromboard = board.movePlayer(tile_to_move_to, player_number);

    // cout << " board.getPlayerPositionOnBoard(player_number) " << board.getPlayerPositionOnBoard(player_number) << endl;

    
    /* ENDING THE GAME!*/
    if(movedfromboard == 1 && board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "end game") {
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        return true;
    } 
    
    /* DRAW A CARD CONDITION*/
    if(drawCardAgain == true) {
        drawCardAgain = false;
        board.setPlayersOnBoardStatus("draw card again", player_number);
        return true;
    }

    /* SAME TILE */
    // if player number is 1, then compare the position to player 2 so player number - 1 + 1 (index 1)
    // if player number is 2, then compare the position to player 1, so player number - 2 (index 0)
    // cout << "player 1 position" << board.getPlayersVectorOnBoard().at(0)._position_player_on_board << endl;
    // cout << "player 2 position" << board.getPlayersVectorOnBoard().at(1)._position_player_on_board << endl;
    // cout << player_number << endl;
    if(player_number == 1) { // we are on players 1 turn, that means player 1 moved to where player 2 is originally 
        if(board.getPlayersVectorOnBoard().at(player_number - 1)._position_player_on_board == board.getPlayersVectorOnBoard().at(player_number)._position_player_on_board) {
            board.setPlayersOnBoardStatus("same tile", player_number);
            cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            // both players are on same tile
            // cout << "same tile" << endl;

            // IF PLAYER 1 DOESN"T HAVE ROBBERS REPEL CANDY 
                // the gold is taken but the players stay on the smae tile
            Candy robbers_repel = players[player_number - 1].findCandy("Robbers Repel");
            if(robbers_repel.name == "") {
                // player 2 can steal random number of gold from player 1
                srand((unsigned)time(NULL));
                int r = 0;
                // get random number from 5-30
                r = 5 + rand() % 25;
                players[player_number - 1].setGold(players[player_number - 1].getGold() - r); // taking away radnom number of gold from player 1
                players[player_number].setGold(players[player_number].getGold() + r); // giving radnom number of gold to player 2
                cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " lost " << r << " amount of gold to player " << players[player_number].getPlayerName() << endl;
                // cout << "player 2 " << players[player_number].getGold();
                // cout << "player 1 " << players[player_number - 1].getGold();
            } else {
                // cout << " have robbers repel!" << endl;
                // if player 1 does have robbers repel
                    // then player 2 has to move back one tile
                cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " has robbers repel so player " << players[player_number].getPlayerName() << " has to move back one tile" << endl;
                board.movePlayer(tile_to_move_to - 1, player_number + 1); // tile to move to - 1
            }
            cout << " same tile display 1 " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            return true;

        }
    } else if (player_number == 2) { // we are on players 2 turn, that means player 2 moved to where player 1 is originally 
        if(board.getPlayersVectorOnBoard().at(player_number - 1)._position_player_on_board == board.getPlayersVectorOnBoard().at(player_number - 2)._position_player_on_board) {
            board.setPlayersOnBoardStatus("same tile", player_number);
            cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            // cout << "same tile" << endl;
            // IF PLAYER 2 DOESN"T HAVE ROBBERS REPEL CANDY 
                // the gold is taken but the players stay on the smae tile
            Candy robbers_repel = players[player_number - 1].findCandy("Robbers Repel");
            if(robbers_repel.name == "") {
                // both players are on same tile
                // player 1 can steal random number of gold from player 2
                srand((unsigned)time(NULL));
                int r = 0;
                // get random number from 5-30
                r = 5 + rand() % 25;
                players[player_number - 1].setGold(players[player_number - 1].getGold() - r); // taking away radnom number of gold from player 2
                players[player_number - 2].setGold(players[player_number -2].getGold() + r); // giving radnom number of gold to player 1
                cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " lost " << r << " amount of gold to player " << players[player_number - 2].getPlayerName() << endl;
                // cout << "player 2 " << players[player_number - 1].getGold() << endl;
                // cout << "player 1 " << players[player_number - 2].getGold() << endl;

            } else {
                // cout << " have robbers repel!" << endl;
                // if player 2 does have robbers repel
                    // then player 1 has to move back one tile
                board.movePlayer(tile_to_move_to - 1, player_number - 1); // tile to move to - 1
                cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " has robbers repel so player " << players[player_number - 2].getPlayerName() << " has to move back one tile" << endl;
            }
            cout << " same tile display 2 " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            return true;
        }
    }

    /* CANDY STORE */
    if(board.getTile(tile_to_move_to).getTileType() == "candy store tile") {
        // cout << " you are at a candy store" << endl;
        // cout << player_number << endl;
        board.setPlayersOnBoardStatus("candy store", player_number);
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        cout << " candy store display " << endl;
        board.displayBoard(board.getPlayersVectorOnBoard());
        return true;
    }

    /* SPECIAL TILE*/
    if(board.getTile(tile_to_move_to).getTileType() == "special tile") {
        // cout << "im in special tile" << endl; 
        board.setPlayersOnBoardStatus("special tile", player_number);
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        // board.displayBoard(board.getPlayersVectorOnBoard());

        // random number function between 1-4
        srand((unsigned)time(NULL));
        int r = rand() % 4 + 1;
        // cout << "r " << r << endl;

        /* FOR TESTING */
        // r = 4; 
        // r = 2;
        // If 1: It is a shortcut tile
            // move the player by 4 more 
        if(r == 1) {
            // cout << r << endl;
            cout << " before r = 1 display " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            cout << "Your spirits soar as you're propelled four tiles ahead, closing in on the Candy Castle." << endl;
            // If a player is less than 4 tiles from the castle when encountering this tile, the player will end up on the castle.
            if(tile_to_move_to + 4 >= 83) {
                tile_to_move_to = 82;
                board.setPlayersOnBoardStatus("end game", player_number);
                return true;
                

            } else {
                tile_to_move_to = tile_to_move_to + 4;
            }
            board.movePlayer(tile_to_move_to, player_number);

        } else if (r == 2) {
            // cout << r << endl;
            cout << " before r = 2 display 1 " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            cout << "Congrats! You get a chance to draw a card again." << endl;
            // If two, It is a ice cream stop tile
            // draw a card again by setting a status to draw a card
            board.setPlayersOnBoardStatus("special draw a card", player_number);
            cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            return true;

        } else if( r == 3) {
            cout << " before r = 3 display " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            // cout << r << endl;

            // If three, It is a gumdrop forest tile
            // move 4 tiles back
            // If a player is less than four tiles into the game and encounters this tile, they get sent back to the start of the game.
            if(tile_to_move_to - 4 <= 0) {
                tile_to_move_to = 0;
            } else {
                tile_to_move_to = tile_to_move_to - 4;
            }
            board.movePlayer(tile_to_move_to, player_number);

            // loose radnom amount of gold coins
            int player_current_gold = players[player_number - 1].getGold();
            // random number function between 5-10
            srand((unsigned)time(NULL));
            int gold = rand() % 10 + 5;
            players[player_number - 1].setGold(player_current_gold - gold);
            cout << "Oops, You head back 4 tiles and lose " << r << " gold." << endl; 

        } else if (r == 4) {
            //cout << r << endl;
            cout << " before r = 4 " << endl;
            board.displayBoard(board.getPlayersVectorOnBoard());
            cout << "It's a bittersweet return to your previous location, accompanied by the forfeiture of one immunity candy." << endl;
                // If 4, it is a gingerbread house tile
            // loose a immunity candiy
            // move back to old position 
            tile_to_move_to = position;
            if(position == 0) {
                bool movingBackTo0 = true;
                int who_moved_back_to_0 = player_number;
                board.setMoveBackTo0(true);
                board.setWhoMoveBackTo0(who_moved_back_to_0);
            }
            board.movePlayer(tile_to_move_to, player_number);
            string candyToRemove = players[player_number - 1].isImmunityCandy();
            cout << candyToRemove << endl;
            if(candyToRemove != "") {
                cout << "hi" << endl;
                players[player_number - 1].removeCandy(candyToRemove);
            }
            // board.displayBoard(board.getPlayersVectorOnBoard());
        }

        // IF the player moves again and happens to land on the same tile
        if(player_number == 1) { // we are on players 1 turn, that means player 1 moved to where player 2 is originally 
            if(board.getPlayersVectorOnBoard().at(player_number - 1)._position_player_on_board == board.getPlayersVectorOnBoard().at(player_number)._position_player_on_board) {
                // both players are on same tile
                // cout << "same tile" << endl;
                board.setPlayersOnBoardStatus("same tile", player_number);
                cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;

                // IF PLAYER 1 DOESN"T HAVE ROBBERS REPEL CANDY 
                Candy robbers_repel = players[player_number - 1].findCandy("Robbers Repel");
                if(robbers_repel.name == "") {
                    // player 2 can steal random number of gold from player 1
                    srand((unsigned)time(NULL));
                    int r = 0;
                    // get random number from 5-30
                    r = 5 + rand() % 25;
                    players[player_number - 1].setGold(players[player_number - 1].getGold() - r); // taking away radnom number of gold from player 1
                    players[player_number].setGold(players[player_number].getGold() + r); // giving radnom number of gold to player 2
                    cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " lost " << r << " amount of gold to player " << players[player_number].getPlayerName() << endl;
                    // cout << "player 2 " << players[player_number].getGold();
                    // cout << "player 1 " << players[player_number - 1].getGold();
                } else {
                    // cout << " have robbers repel!" << endl;
                    // if player 1 does have robbers repel
                        // then player 2 has to move back one tile
                    cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " has robbers repel so player " << players[player_number].getPlayerName() << " has to move back one tile" << endl;
                    board.movePlayer(tile_to_move_to - 1, player_number + 1); // tile to move to - 1
                }
                // cout << " same tile display 3 " << endl;
                board.displayBoard(board.getPlayersVectorOnBoard());
                return true;

            }
        } else if (player_number == 2) { // we are on players 2 turn, that means player 2 moved to where player 1 is originally 
            
            if(board.getPlayersVectorOnBoard().at(player_number - 1)._position_player_on_board == board.getPlayersVectorOnBoard().at(player_number - 2)._position_player_on_board) {
                board.setPlayersOnBoardStatus("same tile", player_number);
                cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
                cout << "same tile" << endl;
                // IF PLAYER 2 DOESN"T HAVE ROBBERS REPEL CANDY 
                Candy robbers_repel = players[player_number - 1].findCandy("Robbers Repel");
                if(robbers_repel.name == "") {
                    // both players are on same tile
                    // player 1 can steal random number of gold from player 2
                    srand((unsigned)time(NULL));
                    int r = 0;
                    // get random number from 5-30
                    r = 5 + rand() % 25;
                    players[player_number - 1].setGold(players[player_number - 1].getGold() - r); // taking away radnom number of gold from player 2
                    players[player_number - 2].setGold(players[player_number -2].getGold() + r); // giving radnom number of gold to player 1
                    cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << " lost " << r << " amount of gold to player " << players[player_number - 2].getPlayerName() << endl;
                    // cout << "player 2 " << players[player_number - 1].getGold() << endl;
                    // cout << "player 1 " << players[player_number - 2].getGold() << endl;

                } else {
                    // cout << " have robbers repel!" << endl;
                    // if player 2 does have robbers repel
                        // then player 1 has to move back one tile
                    board.movePlayer(tile_to_move_to - 1, player_number - 1); // tile to move to - 1
                    cout << "Landed on the same tile! Player " << players[player_number - 1].getPlayerName() << "has robbers repel so player " << players[player_number - 2].getPlayerName() << " has to move back one tile" << endl;
                }
                cout << " same tile display 4 " << endl;
                board.displayBoard(board.getPlayersVectorOnBoard());
                return true;
            }
        }

        cout << " over all display in special tile  " << endl;
        board.displayBoard(board.getPlayersVectorOnBoard());
        return true;
    }
    // board.displayBoard(board.getPlayersVectorOnBoard());

    /* REGULAR TILE */
    if(board.getTile(tile_to_move_to).getTileType() == "regular tile") {
        board.setPlayersOnBoardStatus("regular tile", player_number);
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        cout << " regular tile" << endl;
        return true;
    }

    /* CALAMITY TILE*/
    if(board.getTile(tile_to_move_to).getTileType() == "calamity regular tile") {
        board.setPlayersOnBoardStatus("calamity regular tile", player_number);
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        cout << "calamity regular tile" << endl;

        // random number function between 1-10
        srand((unsigned)time(NULL));
        int r = rand() % 20 + 1;
        // r = 18; /* FOR TESTING */
        // cout << "r " << r << endl;

        if(r < 6) {
            // Candy bandits
            cout << "Oh no! Candy Bandits have swiped your gold coins! " << endl;
            // random number function between 1-10
            srand((unsigned)time(NULL));
            // loose radnom amount of gold coins
            int player_current_gold = players[player_number - 1].getGold();
            // random number function between 5-10
            srand((unsigned)time(NULL));
            int gold = rand() % 10 + 1;
            players[player_number - 1].setGold(player_current_gold - gold);

        } else if (r >= 6 && r < 13) {
            // Lost in lollipop labryinth
            cout << "Oh dear! You got lost in the lollipop labyrinth!" << endl;
            board.setPlayersOnBoardStatus("lollipop labyrinth calamity", player_number);
            cout << "status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            return true;

        } else if (r >= 13 && r < 16) {
            cout << "Watch out! A candy avalanche has struck!" << endl;

            // Lose stamina 
            // random number function between 5-10
            srand((unsigned)time(NULL));
            // loose radnom amount of gold coins
            int player_current_stamina = players[player_number - 1].getStamina();
            // random number function between 5-10
            srand((unsigned)time(NULL));
            int lost_stamina = 5 + rand() % 5;
            players[player_number - 1].setStamina(player_current_stamina - lost_stamina);
            // cout << "stamina after loosing it " << players[player_number - 1].getStamina() << endl;
            players[player_number - 1].setSkipTurn(true);

            board.setPlayersOnBoardStatus("candy avalanche calamity", player_number);
            board.setPlayersOnBoardLostStamina(lost_stamina, player_number);

            cout << "status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            return true;

        } else if (r >= 16 && r <= 20) {
            cout << "Oops! You are stuck in a sticky taffy trap!" << endl;
            board.setPlayersOnBoardStatus("taffy trap calamity", player_number);
            cout << "status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
            return true;
        }

        return true;
    }

    /* GUMMY TILE */
    if(board.getTile(tile_to_move_to).getTileType() == "gummy tile") {
         board.setPlayersOnBoardStatus("gummy tile", player_number);
         cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        cout << "gummy tile" << endl;
         return true;
    }
    
    /* HIDDEN TILE*/
    if(board.getTile(tile_to_move_to).getTileType() == "hidden tile") {
        board.setPlayersOnBoardStatus("hidden tile", player_number);
        cout << " status " << board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board << endl;
        cout << "hidden tile" << endl;
        return true;
    }
}

Card Game::drawACard(char correct_choice) {
    Card card;
    string color;
    bool isDouble = false;
    srand((unsigned)time(NULL));
    int r = 0;
    // get random number from 0-8
    r = rand() % 9;
    cout << "r " << r << endl;
    // ADD IN ACCOUNT FOR MAKING SURE THAT THE SINGLES ARE TWICE AS LIKELY AS EVERYTHING ELSE 
    string cardColors[] = {"magenta", "green", "blue", "magenta", "green", "blue", "double-magenta", "double-green",  "double-blue"};
    if (correct_choice == 'D') {
        if(r == 0 || r == 3) {
            card._card_color = cardColors[0];
        } else if(r == 1 || r == 4) {
            card._card_color = cardColors[1];
        } else if (r == 2 || r == 5) {
            card._card_color = cardColors[2];
        } else if(r == 6) {
            card._card_color = cardColors[6];
            isDouble = true;
        } else if(r == 7) {
            card._card_color = cardColors[7];
            isDouble = true;
        } else if (r == 8) {
            card._card_color = cardColors[8];
            isDouble = true;
        }
    }
    return card;
}




Game::Game() {
    _number_of_players = 0;
    _start_game = false;
}

Game::Game(int number_of_players, bool start_game) {
    _number_of_players = number_of_players;
    _start_game = start_game;
}

int Game::readCandyFile(Candy candy_array[], int current_size, int max_size) {
    string file_name = "candies.txt";
    ifstream file;
    file.open(file_name); // opens a file
    // will hold each candy line from file
    string candy_line;
    // create object from candy class
    Candy candy;
    //vector<Candy> candies;
    string price;
    string effect_value;

    if(file.is_open())
    {
        // while you read from each line
        while (!file.eof()) {
            
            // get whole candy line
            getline(file, candy_line);
            // put the candy line in the string stream
            stringstream ss(candy_line);
            // read each part into the right part of the struct using get line
                // delimeter by '|'
            // read into candy name
            getline(ss, candy.name, '|');
            // If there is no name, move on to next iteration - for empty lines text
            if(candy.name == "" || candy.name == "Name") {
                continue;
            }
            // cout << "candy.name " << candy.name << endl;
            // read into candy description
            getline(ss, candy.description, '|');
            // cout << "candy.description " << candy.description << endl;
            // read into effect type
            getline(ss, candy.effect_type, '|');
            // cout << "candy.effect_type " << candy.effect_type << endl;
            // read effect value
            getline(ss, effect_value, '|');
            candy.effect_value = stoi(effect_value);
            // cout << "candy.effect_value " << candy.effect_value << endl;
            // read into candy type
            getline(ss, candy.candy_type, '|');
            // cout << "candy.candy_type " << candy.candy_type << endl;
            // cout << candy.candy_type << endl;
            // read into candy price
            getline(ss, price, '|');
            candy.price = stoi(price); // make string price to double and set it equal to candy price 
            // cout << "candy.price " << candy.price << endl;

            // add candy into the array
            if(current_size < max_size) {
                current_size++;
                candy_array[current_size - 1] = candy;
            }
            
        }

        // for(int i = 0; i < current_size; i++) {
        //         cout << candy_array[i].name << endl;
        // }
    } else {
            // if could not open file, return original vector
        cout << "Failed to open file" << endl;
    }
    file.close();

    return current_size;
            
}

vector<Character> Game::readCharactersFile(Candy candy_array[], int current_size) {
    string file_name = "characters.txt";
    ifstream file;
    file.open(file_name); // opens a file
    // will hold each candy line from file
    string character_line;
    // create object from candy class
    Character character;
    character.candies_amount = 0;
    vector<Character> characters;
    string stamina;
    string gold;
    string one_candy;
    // will hold each candy line from file
    string candy_line;
    Player player;
    vector<Candy> character_candies;
    Candy one_candy_struct;

    if(file.is_open())
    {
        // while you read from each line
        while (!file.eof()) {
            
            // get whole character line
            getline(file, character_line);
            // put the character line in the string stream
            stringstream ss(character_line);
            // read each part into the right part of the struct using get line
                // delimeter by '|'
            // read into character name
            getline(ss, character.character_name, '|');
            // If there is no name, move on to next iteration - for empty lines text
            if(character.character_name == "" || character.character_name == "character name") {
                continue;
            }
            // cout << "character.character_name " << character.character_name << endl;
            // read into character staimina
            getline(ss, stamina, '|');
            character.stamina = stoi(stamina);
            // cout << "character.stamina " << character.stamina << endl;
            // read into character gold
            getline(ss, gold, '|');
            character.gold = stoi(gold);
            // cout << "character.gold " << character.gold << endl;
            // read all candies
            getline(ss, candy_line);
            // cout << candy_line << endl;
            stringstream candy_string(candy_line);
            while(getline(candy_string, one_candy, ',')) {
                // find that candy string to be a candy struct!
                for(int i = 0; i < current_size; i++) {

                    // if you can find the name, add that to the list of candies  
                    if(one_candy == candy_array[i].name) {
                        one_candy_struct = candy_array[i];
                        // cout << " one_candy_struct.name " << one_candy_struct.name << endl;
                    } 

                }

                // // ADD ONE CANDY TO CHARACTER LIST OF CANDIES
                // if(character.candies_amount < character.MAX_CANDY_AMOUNT) {
                //     /* ADD 1 TO CANDY AND THEN ADD THE CANDY TO LIST*/
                //     character.candies_amount++;
                //     character.list_of_candies[character.candies_amount -1] = one_candy;
                // }

                // ADD ONE CANDY TO CHARACTER LIST OF CANDIES
                if(character.candies_amount < character.MAX_CANDY_AMOUNT) {
                    /* ADD 1 TO CANDY AMOUNT AND THEN ADD THE CANDY TO LIST*/
                    character.candies_amount++;
                    character.list_of_candies[character.candies_amount -1] = one_candy_struct;
                    // cout << " one_candy_struct.name " << one_candy_struct.name << endl;
                }
            }

            // for(int i = 0; i < character.candies_amount; i++) {
            //     cout << character.list_of_candies[i].name << endl;
            // }
            
            characters.push_back(character);
            
            // clear my list of candies
            Candy blankcandy = {
                "", // Name of candy
                "", // Description of candy
                "", 
                0,
                "", // Type of candy
                0 // Price of candy
            };

            for(int i = 0; i < character.candies_amount; i++) {
                character.list_of_candies[i] = blankcandy;
                // character.list_of_candies[i].name = "";
                // character.list_of_candies[i].description = "";
                // character.list_of_candies[i].effect_type = "";
                // character.list_of_candies[i].effect_value = 0;
                // character.list_of_candies[i].candy_type = "";
                // character.list_of_candies[i].price = 0;
            }
            character.candies_amount = 0;

            // for(int i = 0; i < character.candies_amount; i++) {
            //     cout << character.list_of_candies[i] << endl;
            // }
        }
    } else {
            // if could not open file, return original vector
        cout << "Failed to open file" << endl;
    }
    file.close();

    return characters;
}

void Game::removeCharacters(vector<Character> &copyOfCharacters, Character character) {
    for(int k = 0; k < copyOfCharacters.size(); k++) {
        if(character.character_name == copyOfCharacters[k].character_name) {
            for (int i = k + 1; i < copyOfCharacters.size(); i++) {
                copyOfCharacters[i-1] = copyOfCharacters[i];
            }
            copyOfCharacters.pop_back();
        }
    }
}

void Game::visitCandyStore(Player &player, CandyStore &candy_store, string candy_to_buy, Candy candy_to_buy_sturct, Candy candies[], int &candy_current_size) {
    cout << "Here is the list of candies in the store: " << endl;
            vector<Candy> three_random_candies = candy_store.displayThreeRandomCandies(candies, candy_current_size);
            // for(int i = 0; i < three_random_candies.size(); i++) {
            //     cout << three_random_candies[i].name << endl;
            // }
            
            // If player has 0 gold coins let them know!
            if(player.getGold() <= 0) {
                cout<< "You have 0 gold coins. You cannot buy any candy" << endl;
                return;
            }
            cout << "Which candy do you want to buy?" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n');
            getline(cin, candy_to_buy);

            candy_to_buy_sturct = candy_store.findCandy(candy_to_buy, three_random_candies);
            cout << "candy_to_buy_sturct.name " << candy_to_buy_sturct.name << endl;

            while(cin.fail() || candy_to_buy_sturct.name == "") {
                cout << "Invalid selection!" << endl;
                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                // cin.ignore(10000,'\n');
                getline(cin, candy_to_buy);
                cout << "candy_to_buy " << candy_to_buy << endl;
                candy_to_buy_sturct = candy_store.findCandy(candy_to_buy, three_random_candies);
                //cout << candy_to_buy_sturct.name;
            }
            
            // while(player.getGold() - candy_to_buy_sturct.price < 0) {
            //     cout << "You do not have the gold to buy this specific candy. Do you want to buy another? (y/n)" << endl;
            //     char buyAnotherCandy;
            //     cin >> buyAnotherCandy;
            //     while(cin.fail() || buyAnotherCandy != 'y' && buyAnotherCandy != 'n') {
            //         cout << "Invalid selection!" << endl;
            //         cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            //         cin.ignore(10000,'\n');
            //         cin >> buyAnotherCandy;
            //     }
            //     if(buyAnotherCandy == 'y') {
            //         cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            //         cin.ignore(10000,'\n');
            //         getline(cin, candy_to_buy);
            //         cout << "candy_to_buy " << candy_to_buy << endl;
            //         candy_to_buy_sturct = candy_store.findCandy(candy_to_buy, three_random_candies);
            //         //cout << candy_to_buy_sturct.name;
            //     } else {
            //         return;
            //     }
            // }

            // ACTUALLY BUY THE CANDY
                // check if the user can buy the candy based on inventory size 
            if(player.getCandyAmount() >= player.getMaxCandyAmount()) { 
                cout << "You do not have sufficent place in your candy inventory. Would you like to substitute your candy with an existing candy? (y/n)" << endl;
                char substitueCandy; 
                cin >> substitueCandy;
                while(cin.fail() || (substitueCandy != 'y' && substitueCandy != 'n')) {
                    cout << "Invalid selection!" << endl;
                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n');
                    cin >> substitueCandy;
                }
                if (substitueCandy == 'y')
                {
                    cout << "Which candy do you want to substitute?" << endl;
                    cout << "Here is your current inventory" << endl;
                    player.printInventory();
                    string candy_to_substitute; 
                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n');
                    getline(cin, candy_to_substitute);
                    Candy candy_to_substitute_struct = player.findCandy(candy_to_substitute);
                    // cout << " candy_to_substitute_struct.name " << candy_to_substitute_struct.name << endl;

                    // find candy 
                    while(cin.fail() || candy_to_substitute_struct.name == "") {
                        cout << "Invalid selection!" << endl;
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        // cin.ignore(10000,'\n');
                        getline(cin, candy_to_substitute);
                        candy_to_substitute_struct = player.findCandy(candy_to_substitute);
                        // cout << candy_to_substitute_struct.name;
                    }
                   // Run the subsitute candy function
                   player.substituteCandy(candy_to_substitute_struct, candy_to_buy_sturct);
                   cout << endl;
                   cout << "Here is your updated candy inventory: " << endl;
                   player.printInventory();
                   // remove candy you bought from store
                    // cout << candy_store.getCurrentCandyAmount() << endl;
                    candy_store.removeCandy(candy_to_buy_sturct.name);
                     // cout << candy_store.getCurrentCandyAmount() << endl;
                   // add candy you subsituted to candy store
                   candy_store.addCandy(candy_to_substitute_struct);
                    // cout << candy_store.getCurrentCandyAmount() << endl;
                   // candy_store.displayListOfCandy();

                   // Change gold inventory of player
                   player.setGold(player.getGold() - candy_to_buy_sturct.price);
                   player.setGold(player.getGold() + candy_to_substitute_struct.price);
                   cout << "player.getGold() " << player.getGold() << endl;

                }
            
            } else if (player.getGold() - candy_to_buy_sturct.price < 0) {
                cout << "You do not have the gold to buy this specific candy." << endl;
            } 
            
            else {
                // Add candy to inventory 
                cout << endl;
                cout << "Here is your updated candy inventory: " << endl;
                player.addCandy(candy_to_buy_sturct);
                // remove candy you bought from store
                // cout << candy_store.getCurrentCandyAmount() << endl;
                candy_store.removeCandy(candy_to_buy_sturct.name);
                // cout << candy_store.getCurrentCandyAmount() << endl;
                // candy_store.displayListOfCandy();
                player.printInventory();

                // change gold inventory of player 
                player.setGold(player.getGold() - candy_to_buy_sturct.price);
                cout << "player.getGold() " << player.getGold() << endl;

            }
            
}
void Game::setNumberOfParticpants(int number_of_players) {
    _number_of_players = number_of_players;
}
int Game::getNumberOfParticpants() const {
    return _number_of_players;
}
void Game::setStartGame(bool start_game) {
    _start_game = start_game;
} 
bool Game::getStartGame() const {
    return _start_game;
}

void Game::useCandy(Board &board, Candy candy_to_use_struct, Player &player1, Player &opponent, vector<int> where_all_unique_tiles_are) {
    
    /* IF MAGICAL CANDY */
    if( candy_to_use_struct.candy_type == "magical") {
        // int current_stamina = player.getStamina();
        player1.setStamina(player1.getStamina() + candy_to_use_struct.effect_value);
        cout << "You have used " << candy_to_use_struct.name << " candy. This has increased your stamina by " << candy_to_use_struct.effect_value << " points." << endl;
        player1.removeCandy(candy_to_use_struct.name);
    }
    
    /* IF POISON CANDY */
    else if ( candy_to_use_struct.candy_type == "poison") { 
        cout << "Do you want to use " << candy_to_use_struct.name << " against your opponent? " << endl;
        char useAgainstOpponent;
        cin >> useAgainstOpponent;
        while(cin.fail() || useAgainstOpponent != 'y' && useAgainstOpponent != 'n') {
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n');
            cin >> useAgainstOpponent;
        }

        if (useAgainstOpponent == 'y') {
            // See if any of the immunity candies exist for opponnet that can protect against poison
                Candy found_bubblegum_blast = opponent.findCandy("Bubblegum Blast"); // bubblegum blast protects against Lucky Licorice.
                Candy found_sparkling_sapphire = opponent.findCandy("Sparkling Sapphire"); // Sparkling Sapphire protects against Lucky Licorice and Venomous Vortex
                Candy found_caramel_comet = opponent.findCandy("Caramel Comet"); // Sparkling Sapphire protectsagainst all the poison candies: Lucky Licorice, Venomous Vortex, and Toxic Taffy

            /* Lucky licorice will Decreases opponents stamina by 10 units*/
            if(candy_to_use_struct.name == "Lucky Licorice") {
                if(found_bubblegum_blast.name == "Bubblegum Blast") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_bubblegum_blast.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                    opponent.removeCandy(found_bubblegum_blast.name); // immunity candy is also used from protecting
                } else if (found_sparkling_sapphire.name == "Sparkling Sapphire") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_sparkling_sapphire.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                    opponent.removeCandy(found_sparkling_sapphire.name); // immunity candy is also used from protecting
                } else if (found_caramel_comet.name == "Caramel Comet") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_caramel_comet.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                    opponent.removeCandy(found_caramel_comet.name); // immunity candy is also used from protecting
                } else {
                    cout << "  opponent.getStamina() " <<  opponent.getStamina() << endl;
                    // If none of the above candies were found, decrease the stamina of opponent by 10 
                    opponent.setStamina(opponent.getStamina() - 10);
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent and your opponent's stamina has decreased by 10 to " << opponent.getStamina() << " points" << endl;
                    player1.removeCandy(candy_to_use_struct.name);
                }
                
            } /* Venomous Vortex will Decreases opponents stamina by 15 units*/
            else if(candy_to_use_struct.name == "Venomous Vortex") {
                if (found_sparkling_sapphire.name == "Sparkling Sapphire") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_sparkling_sapphire.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                    opponent.removeCandy(found_sparkling_sapphire.name); // immunity candy is also used from protecting
                } else if (found_caramel_comet.name == "Caramel Comet") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_caramel_comet.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory
                    opponent.removeCandy(found_caramel_comet.name); // immunity candy is also used from protecting 
                } else {
                    // If none of the above candies were found, decrease the stamina of opponent by 15
                    opponent.setStamina(opponent.getStamina() - 15);
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent and your opponent's stamina has decreased by 15 to " << opponent.getStamina() << " points" << endl;
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                }

            } /* Toxic Taffy will Decreases opponents stamina by 20 units*/
            else if(candy_to_use_struct.name == "Toxic Taffy") {
                if (found_caramel_comet.name == "Caramel Comet") {
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent but your opponent has " << found_caramel_comet.name << " to protect them against your poison candy";
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                    opponent.removeCandy(found_caramel_comet.name); // immunity candy is also used from protecting
                    // opponent.displayPlayerStats();
                } else {
                    // If none of the above candies were found, decrease the stamina of opponent by 10 
                    opponent.setStamina(opponent.getStamina() - 20);
                    cout << "You have used " << candy_to_use_struct.name << " on your opponent and your opponent's stamina has decreased by 20 to " << opponent.getStamina() << " points" << endl;
                    player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
                }
            } 
        }
    } 
    
    /* IF GUMMY CANDY */
    else if(candy_to_use_struct.candy_type == "gummy") {
        cout << "Which tile do you want to place your " << candy_to_use_struct.name << " - gummy candy?" << endl;
        int tile_num_to_place_gummy_candy;
        cin >> tile_num_to_place_gummy_candy;
        while(cin.fail() || board.doesRandomNumberExist(tile_num_to_place_gummy_candy, where_all_unique_tiles_are) || tile_num_to_place_gummy_candy < 0 ||  tile_num_to_place_gummy_candy > 81) {
            // while cin fail or the number the user puts in is already one of the unique tiles
            cout << "Invalid selection. Your input fails, is already a unique tile that you can't put a gummy tile on, or is not on the board" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n');
            cin >> tile_num_to_place_gummy_candy;
        }

        // set type and color of gummy tile
        board.setTileTypeOnBoard(tile_num_to_place_gummy_candy, "gummy tile");
        board.getAllTileTypes();
        player1.removeCandy(candy_to_use_struct.name);
        // board.getAllTileTypes();

    } 
    /* IF TREASURE CANDY SPEFICALLY Treasure Hunter's Truffle */
    else if(candy_to_use_struct.candy_type == "treasure") { 
        cout << "You have used Treasure Hunter's Truffle which allows you to unlock another hidden treasure by playing riddle game" << endl;
        // cout << "player1.getCandyAmount() before removed " << player1.getCandyAmount() << endl;;
        player1.removeCandy(candy_to_use_struct.name); // loose the candy from your inventory 
        // cout << "player1.getCandyAmount() after removed " << player1.getCandyAmount() << endl;;
        player1.setHasTreasureTruffle(true);
        return;
    } 
    
    /* IF CANDY IS IMMUNITY CANDY */
    else if(candy_to_use_struct.candy_type == "immunity") { 
        cout << "You can only use immmunity candies like " << candy_to_use_struct.name << " when you find yourself under threat of poison. You get to save this candy for later" << endl;
       
    }

    /* IF CANDY IS ROBBERS REPEL CANDY */
    else if(candy_to_use_struct.candy_type == "robbers") { 
        cout << "You can only use Robber's Repel candy when you are on the same tile as another player. You get to save this candy for later" << endl;
       
    }
}

bool Game::rockPaperScissors(Player[]) {
    bool player_won;
    // Start game of rock paper scissors 
    char choice1 = '\0';
    char computer_choice = '\0';
    cout << "Player: Enter r, p, or s" << endl;
    while(choice1 == '\0') { // while the choice 1 are null
        // get the first choice
        cin >> choice1;
        // invalid selection
        while(cin.fail() || (choice1 != 'r' && choice1 != 'p' && choice1 != 's')) {
            cout << "Invalid selection!" << endl;

            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

            cin >> choice1;
        }   
    }

    // Generate random number between 1-3
    srand((unsigned)time(NULL));
    int r = 0;
    r = rand() % 3 + 1;
    if(r == 1) {
        computer_choice = 'r';
    } else if(r == 2) {
        computer_choice = 'p';
    } else if(r == 3) {
        computer_choice = 's';
    }
    // cout << "computer_choice " << computer_choice;
    cout << "choice1 " << choice1 << " computer_choice " << computer_choice << endl;

    // Tie
    while(choice1 == computer_choice) {
        cout << "Tie! Play again" << endl;
        // reset choices 
        choice1 = '\0';
        computer_choice = '\0';
        cout << "choice1 " << choice1 << "computer_choice " << computer_choice << endl;

        // ask player for their choice again
        cout << "Player 1: Enter r, p, or s" << endl;
        while(choice1 == '\0') { // while the choice 1 are null
            // get the first choice
            cin >> choice1;
            // invalid selection
            while(cin.fail() || (choice1 != 'r' && choice1 != 'p' && choice1 != 's')) {
                cout << "Invalid selection!" << endl;

                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                    // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

                cin >> choice1;
            }   
        }

        r = rand() % 3 + 1;
        if(r == 1) {
            computer_choice = 'r';
        } else if(r == 2) {
            computer_choice = 'p';
        } else if(r == 3) {
            computer_choice = 's';
        }
        // cout << "computer_choice " << computer_choice;
        

       cout << "choice1 " << choice1 << " computer_choice " << computer_choice << endl;

    }

    // Conditionals - WORK ON THIS
    if(choice1 == 'r' && computer_choice == 's') {
        // player wins 
        player_won = true;

    } else if(choice1 == 's' && computer_choice == 'r') {
        // computer wins 
        player_won = false;

    } else if(choice1 == 's' && computer_choice == 'p') {
        // player wins 
        player_won = true;
        

    } else if(choice1 == 'p' && computer_choice == 's') {
        // computer wins 
        player_won = false;

    } else if(choice1 == 'p' && computer_choice == 'r') {
       // player wins 
        player_won = true;

    } else if(choice1 == 'r' && computer_choice == 'p') {
        // computer wins 
        player_won = false;
    }

    return player_won;
}


bool Game::riddles(char choice, Board &board) {
    vector<Riddle> riddles = board.readRiddlesFile();
    // for(int i = 0; i < riddles.size(); i++) {
    //     cout << riddles[i]._question << endl;
    // }

    // randomly pick of riddle and ask the user this riddle 
    srand((unsigned)time(NULL));
    int r = 0;
    // get random number from 5-30
    r = rand() % 20;
    // r = 8; // FOR TESTING 
    string question = riddles[r]._question;
    string answer = riddles[r]._answer;

    cout << "Riddle: " << question << endl;
    // Check if the answer that the user inputted is the correct answer from the answer vector
    string user_answer;
    cin >> user_answer;
    if(user_answer == answer) {
        cout << "Correct. You get the hidden treasure!" << endl;
        return true;
    } else {
        cout << "Incorrect. You lose the hidden treasure" << endl;
        return false;
    }

}

int Game::generateRandomNum(int range) {
    srand((unsigned)time(NULL));
    int r = rand() % range + 1;
}

void Game::printMenu() {
    // Menu options for user 
    cout << "Please select a menu option: " << endl;
    cout << "1. Draw a card" << endl;
    cout << "2. Use Candy" << endl;
    cout << "3. Show Stats" << endl;
}


