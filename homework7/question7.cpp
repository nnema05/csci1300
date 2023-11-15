
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;

#include "Player.h"

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
        string lower_candy_name_bet1 = "";
        for(int k = 0; k < players[0].findCandy(bet1).name.length(); k++) {
            lower_candy_name_bet1 += tolower(players[0].findCandy(bet1).name[k]);
        }

        while(cin.fail() || bet1 != lower_candy_name_bet1) {
            // cout << "players[0].findCandy(bet1).name " << players[0].findCandy(bet1).name << endl;
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)

            getline(cin, bet1);

            og_bet1 = bet1;
            for(int k = 0; k < bet1.length(); k++) {
                bet1[k] = tolower(bet1[k]);
            }
            lower_candy_name_bet1 = "";
            for(int k = 0; k < players[0].findCandy(bet1).name.length(); k++) {
                lower_candy_name_bet1 += tolower(players[0].findCandy(bet1).name[k]);
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
        string lower_candy_name_bet2 = "";
        for(int k = 0; k < players[1].findCandy(bet2).name.length(); k++) {
            lower_candy_name_bet2 += tolower(players[1].findCandy(bet2).name[k]);
        }

        while(cin.fail() || bet2 != lower_candy_name_bet2) {
            cout << "Invalid selection!" << endl;
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)

            getline(cin, bet2);
            og_bet2 = bet2;
            for(int k = 0; k < bet2.length(); k++) {
                bet2[k] = tolower(bet2[k]);
            }
            lower_candy_name_bet2 = "";
            for(int k = 0; k < players[1].findCandy(bet2).name.length(); k++) {
                lower_candy_name_bet2 += tolower(players[1].findCandy(bet2).name[k]);
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
    cout << setprecision(2) << fixed;
   
    // create variables
    int input = 0;
    int player = 0;
    // vector to hold candies
    vector<Candy> candies;

    // welcome the user 
    cout << "Welcome to rock-paper-scissors, candy edition!" << endl;
    // Candy empty_array[4];
    // Player player1 = Player(5, 10, "Start of game", empty_array, 3);
    // Player player2 = Player(10, 20, "Start of game", empty_array, 3);
    Player player1 = Player();
    Player player2 = Player();
    Player players[2] = {player1, player2};


    // Display the menu options
    // Your menu should run in a loop, offering the user every option until they choose to exit the program.
    while (input!=5) {
        // Menu options for user 
        cout << "Choose an option: " << endl;
        cout << "1. Load Candy" << endl;
        cout << "2. Display player stats" << endl;
        cout << "3. Edit player stats" << endl;
        cout << "4. Play rock-paper-scissors" << endl;
        cout << "5. Exit" << endl;

        // read in what user chooses as an input 
        cin >> input;
        // check if input is valid, if not prompt for their choice again
            // check for inputs that are not 1-4 or something that is outside of what is expected in cin
        while(cin.fail() || input < 1 || input > 5) { 
            
            cout << "Invalid input!" << endl; 
    
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

            // Menu options for user 
            cout << "Choose an option: " << endl;
            cout << "1. Load Candy" << endl;
            cout << "2. Display player stats" << endl;
            cout << "3. Edit player stats" << endl;
            cout << "4. Play rock-paper-scissors" << endl;
            cout << "5. Exit" << endl;
            /// Ask user again for input 
            cin >> input; // read what user selects into the input 
            
        }

        // Below are conditionals based on what user inputs 
        // If input is 1, read candy file!
        if(input == 1) {

            cout << "Enter file to read:" << endl;
            string file_name;
            cin >> file_name;
            ifstream file;
            file.open(file_name); // opens a file
            // will hold each candy line from file
            string candy_line;
            // create object from candy class
            Candy candy;
            string price;

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
                    if(candy.name == "") {
                        continue;
                    }
                    // cout << candy.name << endl;
                    // read into candy description
                    getline(ss, candy.description, '|');
                    // cout << candy.description << endl;
                    // read into candy price
                    getline(ss, price, '|');
                    candy.price = stod(price); // make string price to double and set it equal to candy price 
                    // read into candy type
                    getline(ss, candy.candy_type);
                    // cout << candy.candy_type << endl;

                    // push back candy into the vector
                    candies.push_back(candy);
                }
            } else {
                 // if could not open file, return original vector
                cout << "Failed to open file" << endl;
            }
            file.close();
            
        // ask to display player stats 
        } else if (input == 2) {
                // ask which player 
                cout << "Which player's stats do you want to display? Choose 1 or 2:" << endl;
                cin >> player; 
                // check for invalid input
                while(cin.fail() || player < 1 || player > 2) { 
                
                    cout << "Invalid input." << endl; 
            
                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                        // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                    cout << "Which player's stats do you want to display? Choose 1 or 2:" << endl;
                    cin >> player; 
                }
            
                // based on player choice, display stats
                if (player == 1) {
                    cout << "Player 1 stats:" << endl;
                    cout << "Stamina: " << players[0].getStamina() << endl;
                    cout << "Gold: " << players[0].getGold() << endl;
                    cout << "Effect: " << players[0].getEffect() << endl;
                    cout << "Inventory: " << endl;
                    players[0].printInventory();

                } else if (player == 2) {
                    cout << "Player 2 stats:" << endl;
                    cout << "Stamina: " << players[1].getStamina() << endl;
                    cout << "Gold: " << players[1].getGold() << endl;
                    cout << "Effect: " << players[1].getEffect() << endl;
                    cout << "Inventory: " << endl;
                    players[1].printInventory();
                }

        } else if (input == 3) {
            /* IF INPUT IS 3 EDIT STATS*/
            // ask which player 
            cout << "Which player's stats do you want to edit? Choose 1 or 2:" << endl;
            cin >> player; 

            // check for invalid input
            while(cin.fail() || player < 1 || player > 2) { 
            
                cout << "Invalid input." << endl; 
        
                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                    // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                cout << "Which player's stats do you want to edit? Choose 1 or 2:" << endl;
                cin >> player; 
            }

            // based on player choice, edit stats 
            int player_index = 0;
            if (player == 1) {
                player_index = 0; // set player choice to 0

            } else if (player == 2) {
                player_index = 1; // set player choice to 0
            }

            int edit_choice = 0;
            cout << "Editing player " << player <<  " stats:" << endl;
            cout << "1. Edit stamina" << endl;
            cout << "2. Edit gold" << endl;
            cout << "3. Edit effect" << endl;
            cout << "4. Add candy" << endl;
            cout << "5. Remove candy" << endl;
            cin >> edit_choice;

            // check for invalid input 
            while(cin.fail() || edit_choice < 1 || edit_choice > 5) { 
            
                cout << "Invalid input." << endl; 
        
                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                    // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.
                cout << "Editing player " << player <<  " stats:" << endl;
                cout << "1. Edit stamina" << endl;
                cout << "2. Edit gold" << endl;
                cout << "3. Edit effect" << endl;
                cout << "4. Add candy" << endl;
                cout << "5. Remove candy" << endl;
                cin >> edit_choice;
            }

            // conditionals for edit choice!
            if(edit_choice == 1) {
                    // edit stamina
                    cout << "Editing stamina. Enter a value between 1 and 10: " << endl;
                    int stamina;
                    cin >> stamina;
                    // check for valid input 
                    while(cin.fail() || stamina < 1 || stamina > 10) { 
                
                        cout << "Invalid input!" << endl; 
                
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                        
                        // re read a stamina
                        cin >> stamina;
                    }
                    
                    // add to stamina
                    players[player_index].setStamina(stamina);
                
            } else if (edit_choice == 2) {
                // check if file is read
                    // edit stamina
                    cout << "Editing gold. Enter a value between 0 and 1000: " << endl;
                    double gold;
                    cin >> gold;
                    // check for valid input 
                    while(cin.fail() || gold < 0 || gold > 1000) { 
                
                        cout << "Invalid input!" << endl; 
                
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                        
                        // re read a gold
                        cin >> gold;
                    }

                    // add to gold
                    players[player_index].setGold(gold);
                
            } else if (edit_choice == 3) {
               
                // edit effect
                cout << "Editing effect. Enter the name of an effect as a string: " << endl;
                string effect;
                cin.ignore(10000,'\n');
                getline(cin, effect);
                // check for valid input 
                while(cin.fail()) { 
            
                    cout << "Invalid input!" << endl; 
            
                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                    
                    // re read a effect
                    getline(cin, effect);
                }

                // add to gold
                players[player_index].setEffect(effect);

            } else if (edit_choice == 4) {
                // check if file is read
                if(candies.size() == 0) {
                    cout << "Cannot add candy! Read a candy file first" << endl;

                    // // Menu options for user 
                    // cout << "Choose an option: " << endl;
                    // cout << "1. Load Candy" << endl;
                    // cout << "2. Display player stats" << endl;
                    // cout << "3. Edit player stats" << endl;
                    // cout << "4. Play rock-paper-scissors" << endl;
                    // cout << "5. Exit" << endl;
                    // /// Ask user again for input 
                    // cin >> input; // read what user selects into the input 
                } else {
                    cout << "Adding candy. Enter one of the following options: " << endl;
                    for(int i = 0; i < candies.size(); i++) {
                        cout << "Name: " << candies[i].name << ". Description: " <<  candies[i].description << ". Price: " << candies[i].price << ". Type: " << candies[i].candy_type << endl;
                    }
                    string add_candy_name;
                    string lower_candy_name;
                    string lower_add_candy_name;
                    int index = 0;
                    cin.ignore(10000,'\n');
                    getline(cin, add_candy_name);
                    // check for valid input 
                    bool found = false; 
                    for(int i = 0; i < candies.size(); i++) {
                        lower_candy_name = "";
                        lower_add_candy_name = "";
                        // make lower case
                        for(int k = 0; k < candies[i].name.length(); k++) {
                            lower_candy_name += tolower(candies[i].name[k]);
                        }
                        // cout << "lower_candy_name" << lower_candy_name << endl;
                        for(int k = 0; k < add_candy_name.length(); k++) {
                            lower_add_candy_name += tolower(add_candy_name[k]);
                        }
                        // cout << "lower_add_candy_name" << lower_add_candy_name << endl;

                        // if the candy name exists in the candy vector/file
                        if(lower_candy_name == lower_add_candy_name) {
                            found = true;
                            index = i;
                            break;
                        }
                    }
                    while(cin.fail() || !found) { 
                
                        cout << "Invalid input!" << endl; 
                
                        cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                        
                        // re read a effect
                        getline(cin, add_candy_name);

                        for(int i = 0; i < candies.size(); i++) {
                        // make lower case
                            lower_candy_name = "";
                            lower_add_candy_name = "";
                            for(int k = 0; k < candies[i].name.length(); k++) {
                                lower_candy_name += tolower(candies[i].name[k]);
                            }
                            // cout << "lower_candy_name" << lower_candy_name << endl;
                            for(int k = 0; k < add_candy_name.length(); k++) {
                                lower_add_candy_name += tolower(add_candy_name[k]);
                            }
                            // cout << "lower_add_candy_name" << lower_add_candy_name << endl;

                            // if the candy name exists in the candy vector/file
                            if(lower_candy_name == lower_add_candy_name) {
                                found = true;
                                index = i;
                                break;
                            }
                            // cout << found;
                        }
                    }
                    // add to inventory
                    // then create a struct from that index 
                    Candy addCandy;
                    addCandy = candies[index];
                    cout << candies[index].name << endl;
                    // add that candy!
                    players[player_index].addCandy(addCandy);
                    players[player_index].printInventory();
                }
                
            } else if (edit_choice == 5) {
                bool removed = false;
                // check if file is read
                if(candies.size() == 0) {
                    cout << "Cannot remove candy! Read a candy file first" << endl;

                    // // Menu options for user 
                    // cout << "Choose an option: " << endl;
                    // cout << "1. Load Candy" << endl;
                    // cout << "2. Display player stats" << endl;
                    // cout << "3. Edit player stats" << endl;
                    // cout << "4. Play rock-paper-scissors" << endl;
                    // cout << "5. Exit" << endl;
                    // /// Ask user again for input 
                    // cin.ignore(10000,'\n');
                    // cin >> input; // read what user selects into the input 
                } else {
                    cout << "Removing candy. Enter the name of a candy in player " << player_index +1 << "'s inventory:" << endl;
                        // print inventory 
                        players[player_index].printInventory();
                        string removedCandy = "";
                        cin.ignore(10000,'\n');
                        getline(cin, removedCandy);
                        // print inventory 
                        removed = players[player_index].removeCandy(removedCandy);
                        // cout << removed;
                        while(cin.fail() || !removed) { 
                    
                            cout << "Invalid input!" << endl; 
                    
                            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                            
                            // re read a effect
                            getline(cin, removedCandy);
                            removed = players[player_index].removeCandy(removedCandy);
                        }
                }

            }
            
        } else if(input == 4) {
            // check if file is read
            if(candies.size() == 0) {
                cout << "Not enough candy!" << endl;

                // // Menu options for user 
                // cout << "Choose an option: " << endl;
                // cout << "1. Load Candy" << endl;
                // cout << "2. Display player stats" << endl;
                // cout << "3. Edit player stats" << endl;
                // cout << "4. Play rock-paper-scissors" << endl;
                // cout << "5. Exit" << endl;
                // /// Ask user again for input 
                // cin >> input; // read what user selects into the input 
            } else {
                playRockPaperScissors(players);
            }

        } else if (input == 5) {
            // exit program
            return 0;

        }
    }
}