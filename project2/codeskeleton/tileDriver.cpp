
#include <iostream>
#include <vector>
#include "CandyStore.h"
#include "Player.h"
#include "Tile.h"

using namespace std;

int main() {
    Tile tile;
    Tile tile2("brown", "regular", "magenta");
    tile.setColor("orange");
    cout << tile.getColor() << endl;
    tile.setTileType("regular");
    cout << tile.getTileType() << endl;
    tile.setTileName("blue");
    cout << tile.getTileName() << endl;
}