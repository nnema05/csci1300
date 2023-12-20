
#include <iostream>
#include <vector>
#include "CandyStore.h"
#include "Player.h"
#include "Tile.h"

Tile::Tile() {
    _color = "";
    _tile_type = "";
    _tile_name = "";
}

Tile::Tile(string color, string tile_type, string tile_name) {
    _color = color;
    _tile_type = tile_type;
    _tile_name = tile_name;
}

string Tile::getColor() const {
    return _color;
}
void Tile::setColor(string color) {
    _color = color;
}
string Tile::getTileType() const {
    return _tile_type;
}
void Tile::setTileType(string tile_type) {
    _tile_type = tile_type;
}

string Tile::getTileName() const {
    return _tile_name;
}
void Tile::setTileName(string tile_name) {
    _tile_name = tile_name;
}

