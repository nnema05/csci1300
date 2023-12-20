#include "Board.h"
#include "CandyStore.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
/* MOVES THE PERSON INTO TO THE RIGHT POSITION ON BOARD */

using namespace std;

Card drawACard(int correct_choice) {
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
    if (correct_choice == 1) {
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

int main() {
    Board board; // resets board with default constructor
    Card card;
    // board.tileName();
    // board.setPlayerPosition(0);
    // int position = board.setPlayerPosition(0);
    board.displayBoard();
    // cout << "starting position " << position << endl;
    cout << "Do you wanna draw a card, press 1" << endl;
    int choice;
    cin >> choice;
    // draw a card
    card = drawACard(choice);
    // card._card_color = "double-magenta";
    cout << "card color " << card._card_color << endl;
    bool isDouble = false;

    // get current position
    int position = board.getPlayerPosition();
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
        isDouble = true;

    } else if (card._card_color == "double-green") {
        cout << "double-green" << endl;
            // when its a double, add 3 to the move amount 
        move_amount = ((3 - position%3 + 1)%3) + 3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
        isDouble = true;

    } else if (card._card_color == "double-blue") {
        cout << "double-blue" << endl;
            // when its a double, add 3 to the move amount 
        move_amount = ((3 - position%3 + 2)%3) + 3;
        cout << "move_amount " << move_amount << endl;
        tile_to_move_to = position + move_amount;
        cout << "tile_to_move_to " << tile_to_move_to << endl;
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

    // move player accordingly 
    board.movePlayer(tile_to_move_to);
    board.displayBoard();
    
    return 0;
}