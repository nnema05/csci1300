#include "Board.h"
#include "CandyStore.h"
#include <iostream>

using namespace std;

int main()
{
    /*TESTING BOARD CONSTURCTOR, GETTER AND SETTER*/
    Board board;
    board.resetBoard();
    CandyStore candyStore1;
    
    board.setPlayerPosition(5);
    board.movePlayer(6);
    board.addCandyStore(12);
    board.addCandyStore(17);
    cout << board.getCandyStoreCount() << endl;
    cout << board.getBoardSize() << endl;
    cout << board.getPlayerPosition() << endl;
    board.addActualCandyStore(candyStore1);
    vector<CandyStore> candies = board.getActualCandyStore();
    cout << candies[0].getCurrentCandyAmount() << endl;
    board.setActualCandyStore(candies);
    board.displayBoard();


    /*TO DISPLAY CANDIES!*/
    for(int i = 0; i < board.getBoardSize(); i++) {
        // setting the players position to an arry
        board.setPlayerPosition(i);
        // Is the player on a candy store position or not
        // if the player position exists in positions of candy store
        if(board.isPositionCandyStore(board.getPlayerPosition())) {

            // for loop through how every many candy stores there are (getCandyStoreCount)
            for(int j = 0; i < board.getCandyStoreCount(); j++) {
                // if the candy store in candy stores array 
                    // see if the tile in that candy store is equal to the whatever the tile the player position is on
                if(board.getActualCandyStore()[j].getTile() == board.getPlayerPosition()) {
                    // then display candies
                    board.getActualCandyStore()[j].displayListOfCandy();
                }
            }
        }

    }

    return 0;
}