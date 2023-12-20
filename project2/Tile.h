
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <vector>
#include "CandyStore.h"
#include "Player.h"

/* Class for each tile 
Each tile has a color and a type */
class Tile {
    private:
        string _color;
        string _tile_type;
        string _tile_name;
    public:
    /* Getters and setters and constructors  */
        Tile();
        Tile(string, string, string);
        string getColor() const;
        void setColor(string);
        string getTileType() const;
        void setTileType(string);
        string getTileName() const;
        void setTileName(string);
};

#endif
