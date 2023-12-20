
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
/*TESTING GAME CONSTRUCTOR, SETTERS, CONSTRUCTORS*/

int main() {
    Game game; 
    Game game2(2, true);
    game.setNumberOfParticpants(2);
    cout << game.getNumberOfParticpants() << endl;
    game.setStartGame(true);
    cout << game.getStartGame() << endl;

}