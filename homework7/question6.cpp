
// WORK ON THIS!!

#include "Player.h"

#include <iostream>

using namespace std;

void playRockPaperScissors(Player players[2]){
    string bet1 = "";
    string bet2 = "";
    string og_bet1 = "";
    string og_bet2 = "";


    // PLAYER 1
    // Print inventory player 1
    if(players[0].getCandyAmount() == 0 || players[1].getCandyAmount() == 0) {
        cout << "Not enough candy!" << endl;
        // cout << "Player 1 Inventory After:" << endl;
        // players[0].printInventory();
        // cout << "Player 2 Inventory After:" << endl;
        // players[1].printInventory();

        return;
    } 
    cout << "Player 1 Inventory" << endl;
    players[0].printInventory();

    // ask for user input 
    cout << "Player 1: Select candy to bet" << endl;
    // while bet 1 is empty
    while(bet1 == "") {
        // get the bet1
        getline(cin, bet1);
        // invalid selection

        // CASE INSENVITY!
        // to go through every bet1 and change it to lower case
            // save bet1 to og copy
        og_bet1 = bet1;
        for(int k = 0; k < bet1.length(); k++) {
            bet1[k] = tolower(bet1[k]);
        }

        while(cin.fail() || bet1 != players[0].findCandy(bet1).name) {
            cout << "players[0].findCandy(bet1).name " << players[0].findCandy(bet1).name << endl;
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)

            getline(cin, bet1);

            og_bet1 = bet1;
            for(int k = 0; k < bet1.length(); k++) {
                bet1[k] = tolower(bet1[k]);
            }
        }
        // cout << "bet1" << bet1 << endl;
    }

    // PLAYER 2
    // Print inventory player 2
    // cout << players[1].getCandyAmount() << endl;
    // if(players[1].getCandyAmount() == 0) {
    //     cout << "Not enough candy!" << endl;
    //     // cout << "Player 1 Inventory After:" << endl;
    //     // players[0].printInventory();
    //     // cout << "Player 2 Inventory After:" << endl;
    //     // players[1].printInventory();

    //     return;
    // } 

    cout << "Player 2 Inventory" << endl;
    players[1].printInventory();

    // ask for user input 
    cout << "Player 2: Select candy to bet" << endl;
    // while bet 1 is empty
    while(bet2 == "") {
        // get the bet1
        getline(cin, bet2);

        // CASE INSENVITY!
        // to go through every bet1 and change it to lower case
        // save bet1 to og copy
        og_bet2 = bet2;
        for(int k = 0; k < bet2.length(); k++) {
            bet2[k] = tolower(bet2[k]);
        }

        while(cin.fail() || bet2 != players[1].findCandy(bet2).name) {
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)

            getline(cin, bet2);
            og_bet2 = bet2;
            for(int k = 0; k < bet2.length(); k++) {
                bet2[k] = tolower(bet2[k]);
            }
        }

    }
    // cout << bet1 << " " << bet2 << endl;

    // Start game of rock paper scissors 
    char choice1 = '\0';
    char choice2 = '\0';
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

    cout << "Player 2: Enter r, p, or s" << endl;
    while(choice2 == '\0') { // while the choice 1 are null
        // get the first choice
        cin >> choice2;
        // invalid selection
        while(cin.fail() || (choice2 != 'r' && choice2 != 'p' && choice2 != 's')) {
            cout << "Invalid selection!" << endl;

            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

            cin >> choice2;
        }   
    }

    // Tie
    while(choice1 == choice2) {
        cout << "Tie! Play again" << endl;
        // reset choices 
        choice1 = '\0';
        choice2 = '\0';
        // cout << "choice1 " << choice1 << "choice2 " << choice2 << endl;

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

        cout << "Player 2: Enter r, p, or s" << endl;
        while(choice2 == '\0') { // while the choice 1 are null
            // get the first choice
            cin >> choice2;
            // invalid selection
            while(cin.fail() || (choice2 != 'r' && choice2 != 'p' && choice2 != 's')) {
                cout << "Invalid selection!" << endl;

                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                    // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

                cin >> choice2;
            }   
        }

       //  cout << "choice1 " << choice1 << " choice2 " << choice2 << endl;

    }

    // Conditionals - WORK ON THIS
    if(choice1 == 'r' && choice2 == 's') {
        // Player 1 wins!
        cout << "Player 1 has won " << og_bet2 << " from player 2!" << endl;
        // find the candy in player 2!
        Candy add_candy = players[1].findCandy(bet2);
        // remove candy from player 2
        players[1].removeCandy(bet2);
        // add candy to player 1 
        players[0].addCandy(add_candy);

    } else if(choice1 == 's' && choice2 == 'r') {
        // Player 2 wins!
        cout << "Player 2 has won " << og_bet1 << " from player 1!" << endl;
        // find the candy in player 1!
        Candy add_candy = players[0].findCandy(bet1);
        // remove candy from player 1
        players[0].removeCandy(bet1);
        // add candy to player 2 
        players[1].addCandy(add_candy);

    } else if(choice1 == 's' && choice2 == 'p') {
        // Player 1 wins!
        cout << "Player 1 has won " << og_bet2 << " from player 2!" << endl;
        // find the candy in player 2!
        Candy add_candy = players[1].findCandy(bet2);
        // remove candy from player 2
        players[1].removeCandy(bet2);
        // add candy to player 1 
        players[0].addCandy(add_candy);
        

    } else if(choice1 == 'p' && choice2 == 's') {
        // Player 2 wins!
        cout << "Player 2 has won " << og_bet1 << " from player 1!" << endl;
        // find the candy in player 1!
        Candy add_candy = players[0].findCandy(bet1);
        // remove candy from player 1
        players[0].removeCandy(bet1);
        // add candy to player 2
        players[1].addCandy(add_candy);

    } else if(choice1 == 'p' && choice2 == 'r') {
        // Player 1 wins!
        cout << "Player 1 has won " << og_bet2 << " from player 2!" << endl;
        // find the candy in player 2!
        Candy add_candy = players[1].findCandy(bet2);
        // remove candy from player 2
        players[1].removeCandy(bet2);
        // add candy to player 1 
        players[0].addCandy(add_candy);

    } else if(choice1 == 'r' && choice2 == 'p') {
        // Player 2 wins!
        cout << "Player 2 has won " << og_bet1 << " from player 1!" << endl;
        // find the candy in player 1!
        Candy add_candy = players[0].findCandy(bet1);
        // remove candy from player 1
        players[0].removeCandy(bet1);
        // add candy to player 2
        players[1].addCandy(add_candy);

    }


}

int main() {
    Candy test = {"brown candy", "candy born from mud", 1.01, "Buff"};
    Candy test2 = {"striped candy", "This candy dropped from the rainbow", 2.02, "Chance"};
    Candy candy_array[3] = {test, test2, test};
    Player player1 = Player(5, 100, "Start of game", candy_array, 3);
    Player player2 = Player(10, 200, "Start of game", candy_array, 3);
    Player players[2] = {player1, player2};
    players[1].removeCandy("Brown Candy");
    players[1].removeCandy("Brown Candy");
    players[1].removeCandy("Striped Candy");



    playRockPaperScissors(players);
}