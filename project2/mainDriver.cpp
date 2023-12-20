
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Game.h"
#include "Board.h"
#include "CandyStore.h"




// Card drawACard(int correct_choice) {
//     Card card;
//     string color;
//     bool isDouble = false;
//     srand((unsigned)time(NULL));
//     int r = 0;
//     // get random number from 0-8
//     r = rand() % 9;
//     cout << "r " << r << endl;
//     // ADD IN ACCOUNT FOR MAKING SURE THAT THE SINGLES ARE TWICE AS LIKELY AS EVERYTHING ELSE 
//     string cardColors[] = {"magenta", "green", "blue", "magenta", "green", "blue", "double-magenta", "double-green",  "double-blue"};
//     if (correct_choice == 1) {
//         if(r == 0 || r == 3) {
//             card._card_color = cardColors[0];
//         } else if(r == 1 || r == 4) {
//             card._card_color = cardColors[1];
//         } else if (r == 2 || r == 5) {
//             card._card_color = cardColors[2];
//         } else if(r == 6) {
//             card._card_color = cardColors[6];
//             isDouble = true;
//         } else if(r == 7) {
//             card._card_color = cardColors[7];
//             isDouble = true;
//         } else if (r == 8) {
//             card._card_color = cardColors[8];
//             isDouble = true;
//         }
//     }
//     return card;
// }

/* Hidden treasure!!, run when the player lands on a hidden treasure */
void hiddenTreasure(Game &game, Board &board, Player players[], int &player_index, Candy candies[], int candy_current_size) {
    char choice;
    cin >> choice;
    while(cin.fail() || (choice != 'y' && choice != 'n')) {
        cout << "Invalid selection!" << endl;
        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
        cin.ignore(10000,'\n');
        cin >> choice;
    }
    // create a candy store for hidden treasure of all candies
     CandyStore hidden_treasure_candy_store;
    hidden_treasure_candy_store.setCandies(candies, candy_current_size);
    vector<Candy> candies_vector;
    for(int i = 0; i < candy_current_size; i++) {
        candies_vector.push_back(candies[i]);
    }

    bool win; 
    // Ask person riddles!
    if(choice == 'y') {
        win = game.riddles('y', board);
        if(win) {
            srand((unsigned)time(NULL));
            // get random number from 1-10
            int r = rand() % 10 + 1;
            // r = 6;

            // BELOW ARE THE DIFFERENT PROBABLIES OF EACH TYPE OF HIDDEN TREASURE HAPPENED
            if(r < 3) {
                // Stamina Refill
                // int random_seed = (unsigned)time(NULL);
                // cout << "random_seed 1" << random_seed;
                srand((unsigned)time(NULL));
                // get random number from 10-30
                int stamina = 10 + rand() % 20;
                cout << "You get your stamina replinished by " << stamina << " points" << endl;
                players[player_index].setStamina(players[player_index].getStamina() + stamina);
                // cout << players[player_index].getStamina() << endl;

            } else if (r >= 3 && r <= 4) {
                // Gold Windfall
                srand((unsigned)time(NULL));
                // get random number from 10-30
                int gold = 20 + rand() % 20;
                cout << "You get your gold replinished by " << gold << " coins" << endl;
                players[player_index].setGold(players[player_index].getGold() + gold);
                // cout << players[player_index].getGold() << endl;

            } else if (r > 4 && r <= 7) {
                // Get Robbers Repel candy 
                cout << "You get a Robber's repel candy!" << endl;
                Candy candy = hidden_treasure_candy_store.findCandy("Robbers Repel", candies_vector);
                players[player_index].addCandy(candy);
                // cout <<  " players[player_index].getCandyAmount() " << players[player_index].getCandyAmount();
                cout << "Here is your updated inventory " << endl;
                players[player_index].printInventory();

            } else if (r > 7 && r <= 10) {

                srand((unsigned)time(NULL));
                // get random number from 1-10
                int candy = rand() % 10 + 1;
                // candy = 4;
                if(candy <= 3) {
                    cout << " You get a Jellybean of Vigor candy. If you use it you can restore 50 units of stamina." << endl;
                    Candy candy = hidden_treasure_candy_store.findCandy("Jellybean of Vigor", candies_vector);
                    cout << candy.name << endl;
                    players[player_index].addCandy(candy);
                    cout << "Here is your updated inventory " << endl;
                    players[player_index].printInventory();
                } else if (candy > 3) {
                    cout << " You get a Treasure Hunter's Truffle candy. If you use it you can lock another hidden treasure by playing riddles game!" << endl;
                    Candy candy = hidden_treasure_candy_store.findCandy("Treasure Hunter's Truffle", candies_vector);
                    cout << candy.name << endl;
                    players[player_index].addCandy(candy);
                    cout << "Here is your updated inventory " << endl;
                    players[player_index].printInventory();

                }
            }
            
        }
    }
    
}

int main() {

    bool characterExists;
    /* CREATES GAME OBJECT */ 
    Game game;

    /* READ IN CANDY FILE */
    Candy candies[14];
    int candy_current_size = 0;
    int max_size = 14;
    candy_current_size = game.readCandyFile(candies, candy_current_size, max_size);
    // for(int i = 0; i < candy_current_size; i++) {
    //     cout << candies[i].name << endl;
    // }

    /* READ IN CHARACTERS FILE */
    vector<Character> characters;
    characters = game.readCharactersFile(candies, candy_current_size);
    // for(int i = 0; i < characters.size(); i++) {
    //     // cout << characters[i].list_of_candies[i] << endl;
    //     Character character = characters[i];
    //     for(int k = 0; k < character.candies_amount; k++) {
    //         cout << character.list_of_candies[k].name << endl;
    //     }CandyStore::displayWholeCandy(Candy candies[], int current_candies_in_store, int position) {
    //     cout << character.character_name << endl;
    //     // cout << "hi" << endl;
    // }

    /* START THE GAME*/
    /* WELCOME PLAYERS TO CANDY LAND AND GET NUMBER OF PLAYERS */
    cout << "Welcome to the game of candyland. Please enter number of particpants " << endl;
    int numOfPlayers = 0;
    cin >> numOfPlayers;
    /* Fail cases */
    while(cin.fail() || numOfPlayers !=2) { // allow for two players
        cout << "Invalid selection!" << endl;
        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
        cin.ignore(10000,'\n');
        cin >> numOfPlayers;
    }
    game.setNumberOfParticpants(numOfPlayers);
    numOfPlayers = game.getNumberOfParticpants();
    // cout << " num of players " <<  numOfPlayers << endl; 
    /* SET UP THE BOARD */
    Board board(numOfPlayers); // resets board with default constructor
        // sets up regular, special, hidden treasures, candy store, and calamity tiles!
        // get where all of these are 
    /* FOR TESTING */
    // board.setPlayerPositionOnBoard(75, 1);
    // board.setPlayerPositionOnBoard(75, 2);
    vector<int> where_all_unique_tiles_are = board.getWhereAllUniqueTilesAre();
    // for(int k = 0; k < where_all_unique_tiles_are.size(); k++) {
    //      cout <<  "where_all_unique_tiles_are.at(k) " << where_all_unique_tiles_are.at(k) << endl;
    // }

    // cout << "num of players " << numOfPlayers;
    Player players[numOfPlayers];
    // Player player1;
    // Player player2;

    // create a copy of characters
    vector<Character> copyOfcharacters = characters;
    
    /* PLAYER SELECTS THEIR CHARACTER AND VISITS THE CANDY STORE*/
    for(int i = 0; i < numOfPlayers; i++) {
        // set budget to 100
        // players[i].setBudget(100);
        string playerName;
        /* PLAYER ENTERS THEIR NAME */
        cout << endl;
        cout << "Enter a player name: " << endl;
        cin >> playerName;
        while(cin.fail()) {
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n');
            cin >> playerName;
        }
        players[i].setPlayerName(playerName);
        

        /* PRINT CHARACTERS */  
        cout << "Awesome! Here is a list of characters a player can select from: " << endl;
        for(int k = 0; k < copyOfcharacters.size(); k++) {
            cout << "Name: " << copyOfcharacters[k].character_name << endl;
            cout << "Stamina: " << copyOfcharacters[k].stamina << endl;
            cout << "Gold: " << copyOfcharacters[k].gold << endl;
            cout << "Candies: " << endl;
            for(int  j= 0; j < copyOfcharacters[k].candies_amount; j++) {
                if(j!= 0 && j%3==0) {
                    cout << endl;
                }
                if(copyOfcharacters[k].list_of_candies[j].name.length() == 0) {
                cout << "[" << "Empty" << "]";
                } else {
                    cout << "[" << copyOfcharacters[k].list_of_candies[j].name << "]";
                }
                cout << "   ";
            }
            cout << endl;
            cout << "-----------------------------------" << endl;
        } 

        /* USER CHOOSES CHARACTER */
        // cout << "characters.size()" << characters.size() << endl;
        cout << "The selected character is " << endl;
        string selectedCharacter;
        characterExists = false;
        while(!characterExists) {
            // cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            // cin.ignore(10000,'\n');
            
            cin >> selectedCharacter;
            for(int k = 0; k < copyOfcharacters.size() && !characterExists; k++) {
                if(selectedCharacter == copyOfcharacters[k].character_name) {
                    characterExists = true;
                    // cout << "true";
                } 
                else {
                    characterExists = false;
                    // cout << "No match found";
                    // cout << "index" << k;
                }
            }
            if(!characterExists || cin.fail()) {
                cout << "Invalid selection!" << endl;
                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n');
            }
        }

        /* MAKE A PLAYER WITH THE CHARACTER ATTRIBUTES THEY SELECTED */
        // First get the character struct that corresponds with selected character
        Character selectedCharacterStruct;
        for(int k = 0; k < copyOfcharacters.size(); k++) {
            if(selectedCharacter == copyOfcharacters[k].character_name) {
                selectedCharacterStruct = copyOfcharacters[k];
                // cout << " selectedCharacterStruct.candies_amount " << selectedCharacterStruct.candies_amount << endl;
                // for(int j = 0; j < selectedCharacterStruct.candies_amount; j++) {
                //     cout << selectedCharacterStruct.list_of_candies[j].name << endl;
                // }
            }
        }
        players[i].setStamina(selectedCharacterStruct.stamina);
        players[i].setGold(selectedCharacterStruct.gold);
        players[i].setCandyAmount(selectedCharacterStruct.candies_amount);
        players[i].setCharacterName(selectedCharacterStruct.character_name);
        // ADD LIST OF CANIDES 
        players[i].setCandyList(selectedCharacterStruct.list_of_candies, selectedCharacterStruct.candies_amount);
        // players[i].getCandyList(selectedCharacterStruct);
        // cout << players[i].getStamina() << endl;

        /* REMOVE CHARACTER FROM LIST OF CHARACTER*/
        game.removeCharacters(copyOfcharacters, selectedCharacterStruct);

        /* VISIT THE CANDY STORE IN THE BEGINING OF THE GAME*/
        CandyStore before_game_candy_store;
        before_game_candy_store.setCandies(candies, candy_current_size);

        // before_game_candy_store.displayListOfCandy();
        cout << "Do you want to visit the candy store? (y/n)" << endl;
        char visitCandyStore; 
        cin >> visitCandyStore;
        while(cin.fail() || (visitCandyStore != 'y' && visitCandyStore != 'n')) {
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n');
            cin >> visitCandyStore;
        }

        /* CODE FOR VISITING CANDY STORE */
        string candy_to_buy;
        Candy candy_to_buy_sturct;
        if(visitCandyStore == 'y') {
            game.visitCandyStore(players[i], before_game_candy_store, candy_to_buy, candy_to_buy_sturct, candies, candy_current_size);
        }
    }

    /* START THE GAME!!! */
    bool anyone_castle_reached = false;
    bool isDrawCard = false;
    bool isUseCard = false;
    bool drawCardAgain = false;
    int numOfRounds = 0; // counter for number of rounds
    int player_number = 0;
    int player_index = 0;
    cout << endl;
    cout << "Let's begin the game. Here is the board: " << endl;
    // cout << " hi 0 " << endl;
    // cout << " num Of Players " << numOfPlayers << endl;
    // cout << " board.getPlayersVectorOnBoard().at(0)._position_player_on_board " << board.getPlayersVectorOnBoard().at(0)._position_player_on_board << endl;
    // cout << " board.getPlayersVectorOnBoard().size() " << board.getPlayersVectorOnBoard().size() << endl;
    board.displayBoard(board.getPlayersVectorOnBoard());
    // cout << " hi 1 first " << endl;
    while(!anyone_castle_reached) { // WHile the castle is not reached or end is not reached 
        numOfRounds++; // count the number of rounds!!
        // cout << " hi 1 " << endl;

        // for each player and as long as the castle is not reached, keep doing each players turn
        for(int i = 0; i < numOfPlayers && !anyone_castle_reached; i++) {
            // cout << " hi 2 " << endl;
            // track the player index and number we are on
            player_index = i;
            player_number = i + 1;

            // First check, does the player have a stamina of 0
                // if yes set num of skip turn to 0 
            if(players[i].getStamina() == 0) {
                cout << endl;
                cout << "Your stamina is 0. You have to skip 2 turns and then you regain 20 stamina points" << endl;
                players[i].setNumOfSkipTurn(2);
                players[i].setSkipTurn(true);
                // they also regain a stamina of 20 after these turns are skipped
                players[i].setStamina(players[i].getStamina() + 20);
                // cout << "players[i].getStamina() in 0  " << players[i].getStamina() << endl;
            }
            // cout << "player index before changing " << player_index << endl;
            // cout << " player number before changing "<< player_number << endl;
            cout << endl;
            // DECIDE WHOSE TURN IT IS BY SEEING IF THE PLAYER SKIPS A TURN
                // For skip turn, the player skips a turn and then the turns go back to the natural order like player a, player b, etc..
                // ex. Player a, then player a skips a turns, player b, player b goes again because player a skips a turn, then the natural order comes back so player b goes, then player a, then b, etc.. 
            if(players[i].getSkipTurn() == true) {
                if(i == 0) { // then it was originally players 1 turn but now its players 2, so change player index and player number!!
                    player_index = i + 1; 
                    // cout << "player index after changing " << player_index << endl;
                    player_number = i + 2;
                    // cout << " player number after changing "<< player_number << endl;
                    // players[i].setSkipTurn(false);
                    if(players[i].getNumOfSkipTurn() == 2) {
                        players[i].setSkipTurn(true);
                        cout << "Player " << players[i].getPlayerName() << " skips 2 turns. It's " << players[i + 1].getPlayerName() << " turn" << endl;
                        // If its next players turn, decrease that players stamina levels
                        players[i + 1].setStamina(players[i + 1].getStamina() - 1);
                        // cout << "players[i + 1].getStamina() in skip turn 2 " << players[i + 1].getStamina() << endl;
                        players[i].setNumOfSkipTurn(1);
                    } else if (players[i].getNumOfSkipTurn() == 1) { 
                        cout << "Player " << players[i].getPlayerName() << " skips a turn. It's " << players[i + 1].getPlayerName() << " turn" << endl;
                        players[i + 1].setStamina(players[i + 1].getStamina() - 1);
                        // cout << "players[i + 1].getStamina() in skip turn 1 " << players[i + 1].getStamina() << endl;
                        // players[i].setNumOfSkipTurn(0);
                        players[i].setSkipTurn(false);
                    } else {
                        cout << "Player " << players[i].getPlayerName() << " skips a turn. It's " << players[i + 1].getPlayerName() << " turn" << endl;
                        players[i + 1].setStamina(players[i + 1].getStamina() - 1);
                        // cout << "players[i + 1].getStamina() in skip turn 1 " << players[i + 1].getStamina() << endl;
                        players[i].setSkipTurn(false);
                    }

                } else if (i == 1) { // then it was originally players 2 turn but now its players 1
                    player_index = i - 1; // chnage player index and player number accordingly to skipping a turn!
                    // cout << "player index after changing " << player_index << endl;
                    player_number = i;
                    // cout << " player number after changing "<< player_number << endl;
                    // players[i].setSkipTurn(false);
                    if(players[i].getNumOfSkipTurn() == 2) {
                        // cout << "player_index in number of skips 2 " << player_index << endl;
                        // player_number = i + 1;
                        // cout << "player_number in number of skips  2" << player_number << endl;
                        players[i].setSkipTurn(true);
                        cout << "Player " << players[i].getPlayerName() << " skips 2 turns. It's " << players[i -1].getPlayerName() << "'s turn" << endl;
                        // player_index = i - 1;
                        // cout << "player_index in number of skips 2 after changing " << player_index << endl;
                        // player_number = i - 1;
                        // cout << "player_number in number of skips 2 after changing" << player_number << endl;
                        players[i - 1].setStamina(players[i - 1].getStamina() - 1);
                        // cout << "players[i - 1].getStamina() in skip turn 2 " << players[i - 1].getStamina() << endl;
                        players[i].setNumOfSkipTurn(1);
                    } else if (players[i].getNumOfSkipTurn() == 1) { 
                        // cout << " number of skips is 1 " << endl;
                        cout << "Player " << players[i].getPlayerName() << " skips a turn. It's " << players[i -1].getPlayerName() << "'s turn" << endl;
                        players[i - 1].setStamina(players[i - 1].getStamina() - 1);
                        // cout << "players[i - 1].getStamina() in skip turn 1 " << players[i - 1].getStamina() << endl;
                        // players[i].setNumOfSkipTurn(0);
                        players[i].setSkipTurn(false);
                    } else {
                        cout << "Player " << players[i].getPlayerName() << " skips a turn. It's " << players[i -1].getPlayerName() << "'s turn" << endl;
                        players[i - 1].setStamina(players[i - 1].getStamina() - 1);
                        // cout << "players[i - 1].getStamina() in skip turn 1 " << players[i - 1].getStamina() << endl;
                        players[i].setSkipTurn(false);
                    }
                }
            } else {
                player_index = i;
                cout << "It's " << players[i].getPlayerName() << "'s turn" << endl; // its a certain player name 
                player_number = i + 1;
            }
            // cout << "player_index " << player_index << endl;
            // cout << "player_number " << player_number << endl;
            // cout << " num of skip gturns " << players[i].getNumOfSkipTurn() << endl;

            // Bool to keep track if player drew card or used candy (if they did, that players turn is over so it will go into for loop and go into next for loop )
            isDrawCard = false;
            isUseCard = false;
            drawCardAgain = false;
            while(!isDrawCard && !isUseCard) { // 
                game.printMenu();
                int input = 0;
                cin >> input;
                while(cin.fail() || input < 1 || input > 3) { 
                    cout << "Invalid input!" << endl; 
                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                        // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                    /// Ask user again for input 
                    cin >> input; // read what user selects into the input 
                }

                /* DRAW CARD */
                if(input == 1) { 
                    Card card; 
                    // board.setPlayerPosition(0);
                    // int position = board.setPlayerPosition(0);
                    // cout << "starting position " << position << endl;
                    cout << "To draw a card, press D" << endl;
                    char choice;
                    cin >> choice;
                    while(cin.fail() || choice != 'D') { 
                        cout << "Invalid input!" << endl; 
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                            // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                        /// Ask user again for input 
                        cin >> choice; // read what user selects into the input 
                    
                    } 
                    // draw a card
                    card = game.drawACard(choice);
                    // cout << "card color " << card._card_color << endl;
                    // bool isDouble  = false;

                    // Players stamina drops by 1 every turn (if they select use a card, draw a card)
                    players[i].setStamina(players[i].getStamina() - 1);
                    // cout << "players[i].getStamina() in regular " << players[i].getStamina() << endl;
                    
                    // run move the player function based on the card they drew!
                    game.moveThePlayer(card, board, player_number, players, drawCardAgain);

                    // CHECK THE STATUS OF THE PLAYER ON THE BOARD
                    /* GAME ENDS CONDITION */
                    if(board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "end game") {
                        // endGame(players[player_index]], players, anyone_castle_reached, isDrawCard, numOfPlayers, i);
                        cout << endl;
                        cout << "Congratulations player " << players[player_index].getPlayerName() << " for your win" << endl; 
                        anyone_castle_reached = true; 
                        for(int k = 0; k < numOfPlayers; k++) {
                            if(k == player_index) {
                                cout << "Here are the winner " << players[k].getPlayerName() << " stats" << endl;
                                players[k].displayPlayerStats();
                                cout << endl;
                            } else {
                                cout << "Here are " << players[k].getPlayerName() << " stats" << endl;
                                players[k].displayPlayerStats();
                            }
                        }
                        players[player_index].writeIntoFile("result.txt", players, numOfPlayers); // write the final results into the file
                        isDrawCard = true;
                        return 0;
                    }           
                    
                    /* CANDY STORE CONDITION*/
                    else if(board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "candy store") {
                        // cout << " main candy store" << endl;
                        /* VISIT THE CANDY STORE DURING THE GAME*/
                        CandyStore candy_store;
                        candy_store.setCandies(candies, candy_current_size);
                        // cout << " candy store display again " << endl;
                        // board.displayBoard(board.getPlayersVectorOnBoard());

                        // before_game_candy_store.displayListOfCandy();
                        cout << "You are at a candy store. Do you want to visit the candy store? (y/n)" << endl;
                        char visitCandyStoreInGame; 
                        cin >> visitCandyStoreInGame;
                        while(cin.fail() || (visitCandyStoreInGame != 'y' && visitCandyStoreInGame != 'n')) {
                            cout << "Invalid selection!" << endl;
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            cin.ignore(10000,'\n');
                            cin >> visitCandyStoreInGame;
                        }

                        /* CODE FOR VISITING CANDY STORE */
                        string candy_to_buy;
                        Candy candy_to_buy_sturct;
                        if(visitCandyStoreInGame == 'y') {
                            game.visitCandyStore(players[player_index], candy_store, candy_to_buy, candy_to_buy_sturct, candies, candy_current_size);
                        }
                        isDrawCard = true;
                    }
                    
                    /* SPECIAL TILES */
                        // specifically if the status is a draw a card 
                    else if(board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "special draw a card") {

                        cout << "To draw a card again, press D" << endl;
                        char special_choice;
                        cin >> special_choice;
                        while(cin.fail() || special_choice != 'D') { 
                            cout << "Invalid input!" << endl; 
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                                // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                            /// Ask user again for input 
                            cin >> special_choice; // read what user selects into the input 
                        
                        } 
                        // draw a card and move again
                        card = game.drawACard(special_choice);
                        drawCardAgain = true;
                        game.moveThePlayer(card, board, player_number, players, drawCardAgain);
                        /* CHECK IF ITS MOVED TO A NEW SPECIAL TILE, CANDY STORE TILE OR HIDDEN TILE OR CALAMITY TILE*/
                            // Dont do anything if it lands on this 
                        if(board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "end game") {
                            // endGame(players[player_index]], players, anyone_castle_reached, isDrawCard, numOfPlayers, player_index);
                            cout << "Congratulations " << players[player_index].getPlayerName() << " for your win" << endl; 
                            anyone_castle_reached = true; 
                            for(int k = 0; k < numOfPlayers; k++) {
                                if(k == player_index) {
                                    cout << "Here are the winner " << players[k].getPlayerName() << " stats" << endl;
                                    players[k].displayPlayerStats();
                                } else {
                                    cout << "Here are " << players[k].getPlayerName() << " stats" << endl;
                                    players[k].displayPlayerStats();
                                }
                            }
                            players[player_index].writeIntoFile("result.txt", players, numOfPlayers);
                            isDrawCard = true;
                        } else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "draw card again") {
                            // cout << " draw card again " << endl;
                            board.displayBoard(board.getPlayersVectorOnBoard());
                            isDrawCard = true;
                        }
                        
                    } 
                    // all thpse functions are run in special tile and same tile are run in game.cpp
                    else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "special tile") {
                        // cout << "special tile display " << endl;
                        // board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    }
                    /* SAME TILE CONDITION */
                     else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "same tile") {
                        // cout << "same tile in main " << endl;
                        isDrawCard = true;

                    }
                    
                    /* CALAMITY CONDITION*/ 
                    else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "calamity regular tile") {
                        // cout << "calamity in main " << endl;
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    
                    } else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "lollipop labyrinth calamity") {
                        // cout << "lollipop labyrinth calamity in main " << endl;
                        // cout << "skip turn before " << players[player_index].getSkipTurn() << endl;
                        // cout << players[player_index].getSkipTurn() << endl;
                        players[player_index].setSkipTurn(true);
                        // cout << " skip turn after " << players[player_index].getSkipTurn() << endl;
                        cout << "You lost a turn but you can win it back by playing rock paper scissors. Do you want to play? (y/n)?" << endl;
                        char playRockPaperScissors; 
                        cin >> playRockPaperScissors;
                        while(cin.fail() || (playRockPaperScissors != 'y' && playRockPaperScissors != 'n')) {
                            cout << "Invalid selection!" << endl;
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            cin.ignore(10000,'\n');
                            cin >> playRockPaperScissors;
                        }
                        if(playRockPaperScissors == 'y') {
                            // play rock paper scissors on the game
                            bool win = game.rockPaperScissors(players);
                            if(win == true) { // if they win, give back the skip turn
                                cout << "You won rock paper scissors. You get your turn back" << endl;
                                players[player_index].setSkipTurn(false);
                            } else if (win == false) {
                                cout << "You lost rock paper scissors. You offically lost your turn" << endl;
                                players[player_index].setSkipTurn(true);
                            }
                        }
                        // cout << " skip turn after " << players[player_index].getSkipTurn() << endl;
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    }
                    else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "candy avalanche calamity") {
                        cout << "You lost a turn and stamina points but you can win it back by playing rock paper scissors. Do you want to play? (y/n)?" << endl;
                        char playRockPaperScissors; 
                        cin >> playRockPaperScissors;
                        while(cin.fail() || (playRockPaperScissors != 'y' && playRockPaperScissors != 'n')) {
                            cout << "Invalid selection!" << endl;
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            cin.ignore(10000,'\n');
                            cin >> playRockPaperScissors;
                        }
                        if(playRockPaperScissors == 'y') {
                            bool win = game.rockPaperScissors(players);
                            if(win == true) { // if they win, give back the skip turn
                                cout << "You won rock paper scissors. You get your turn back and your stamina back" << endl;
                                int lost_stamina = board.getPlayersVectorOnBoard().at(player_number - 1)._lost_stamina;
                                players[player_index].setSkipTurn(false);
                                players[player_index].setStamina(players[player_index].getStamina() + lost_stamina);
                            } else if (win == false) {
                                cout << "You lost rock paper scissors. You offically lost your turn and your stamina" << endl;
                            }
                        }
                        // cout << " skip turn after " << players[player_index].getSkipTurn() << endl;
                        // cout << " stamina after " << players[player_index].getStamina() << endl;
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;

                    } else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "taffy trap calamity") {
                        // cout << "taffy trap calamity in main " << endl;
                        // cout << "skip turn before " << players[player_index].getSkipTurn() << endl;
                        // cout << players[player_index].getSkipTurn() << endl;
                        players[player_index].setSkipTurn(true);

                        // SEE IF THEY HAVE A MAGICAL CANDY 
                        if(players[player_index].isMagicalCandy()) {
                            cout << "But, you have a magical candy to protect you from loosing a turn!" << endl;
                            // magical candy is removed
                            string magical_candy_to_remove = players[player_index].returnsMagicalCandy();
                            players[player_index].removeCandy(magical_candy_to_remove);

                            players[player_index].setSkipTurn(false);
                        } else {
                            cout << "You lost a turn because you have a no magical candy to protect you" << endl;
                        }
                        // cout << " skip turn after " << players[player_index].getSkipTurn() << endl;
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    }

                    /* GUMMY CONDITION */
                    else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "gummy tile") {
                        // random number function between 1-2
                        players[player_index].setSkipTurn(true);
                        srand((unsigned)time(NULL));
                        int num_of_skip_turns = rand() % 2 + 1;
                        // num_of_skip_turns = 1; /* FOR TESTING*/
                        players[player_index].setNumOfSkipTurn(num_of_skip_turns);
                        // cout << " helloo "; 
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    } 

                    /* HIDDEN TREASURE */
                    else if (board.getPlayersVectorOnBoard().at(player_number - 1)._status_player_on_board == "hidden tile") {
                        cout << "You have landed on a hidden treasure. To unlock the treasure, do you want to solve a riddle? (y/n)" << endl;
                        // call hidden treasure function!!
                        hiddenTreasure(game, board, players, player_index, candies, candy_current_size);
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    }
                    
                    else {
                        // cout << " another overall display! " << endl;
                        board.displayBoard(board.getPlayersVectorOnBoard());
                        isDrawCard = true;
                    }
                    // isDrawCard = true;

                /* USE CANDY*/
                } else if(input == 2) {  
                    // Players stamina drops by 1 every turn (if they select use a card, draw a card)
                    players[i].setStamina(players[i].getStamina() - 1);
                    //cout << "players[i].getStamina() in regular " << players[i].getStamina() << endl;

                    // if user does not have any candies to use let them know! 
                    if(players[player_index].getCandyAmount() == 0) {
                        cout << "You do not have any candies in your inventory to use! Your turn and stamina are still gone." << endl;
                    } else {

                        cout << "Here is a list of your candies " << endl;
                        players[player_index].printInventory();
                        
                        cout << "Enter a candy you wish to use" << endl;
                        string candy_to_use;
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                            // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                        getline(cin, candy_to_use);
                        Candy candy_to_use_struct = players[player_index].findCandy(candy_to_use);
                        // cout << candy_to_use_struct.name;

                        // find candy to use in the players inventory
                        while(cin.fail() || candy_to_use_struct.name == "") {
                            cout << "Invalid selection!" << endl;
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            // cin.ignore(10000,'\n');
                            getline(cin, candy_to_use);
                            candy_to_use_struct = players[player_index].findCandy(candy_to_use);
                            // cout << candy_to_use_struct.name;
                        }

                        /* PASS IN CANDY TO USE INTO A USE FUNCTION IN GAME*/
                        // Find player and opponent
                            // if player is 0 or player 1, opponent is player + 1
                            // if player is 1 or player 2, opponent is player - 1
                        if(player_index == 0) {
                            // cout << " players[player_index + 1].getGold( in main" << players[player_index + 1].getGold() << endl;
                            game.useCandy(board, candy_to_use_struct, players[player_index], players[player_index + 1], where_all_unique_tiles_are);
                            if(players[player_index].getHasTreasureTruffle()) {
                                cout << "You can play riddle again to unlock another hidden treasure. Do you want to? (y/n)" << endl;
                                hiddenTreasure(game, board, players, player_index, candies, candy_current_size);
                                
                            }
                        } else if (player_index == 1) {
                            // cout << " players[player_index - 1].getGold( in main" << players[player_index - 1].getGold() << endl;
                            game.useCandy(board, candy_to_use_struct, players[player_index],  players[player_index - 1], where_all_unique_tiles_are);
                            if(players[player_index].getHasTreasureTruffle()) {
                                cout << "You can play riddle again to unlock another hidden treasure. Do you want to? (y/n)" << endl;
                                hiddenTreasure(game, board, players, player_index, candies, candy_current_size);
                                
                            }
                        }

                    
                    }
                    // display player stats
                    // cout << endl;
                    // cout << "Here are your updated stats: " << endl;
                    // players[player_index].displayPlayerStats();
                    // cout << endl;
                    isUseCard = true;
                } 

                /* DISPLAY PLAYER STATS */
                else if(input == 3) { 
                    // cout << "Here are your stats: " << endl;
                    // players[player_index].displayPlayerStats();
                    // cout << endl;
                }
                // isDrawCard = true;
                // anyone_castle_reached = true;
            
            // Display the player stats after each turn!
            cout << endl;
            cout << "Player " << players[player_index].getPlayerName() << " here are your stats:" << endl;
            players[player_index].displayPlayerStats();
            } 
        }

    }
    
    
    
    
    return 0;
}

// compile line: 
// g++ mainDriver.cpp Player.cpp Board.cpp Game.cpp CandyStore.cpp Tile.cpp -o driver
// g++ -Wall -Werror -Wpedantic mainDriver.cpp Player.cpp Board.cpp Game.cpp CandyStore.cpp Tile.cpp -o driver
