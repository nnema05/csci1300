------------------------------------
HOW TO COMPILE AND LEARN
------------------------------------
Compile: g++ mainDriver.cpp Player.cpp Board.cpp Game.cpp CandyStore.cpp Tile.cpp -o driver
Run: ./driver
------------------------------------
DEPENDENCIES
------------------------------------
Board.h, CandyStore.h, Game.h, Player.h, Tile.h must be included in the same directory as all 
the cpp files in order to Compile
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2023 Project 2
Author: Nandini Nema
Recitation: 202 - Srikrishna
Date: Dec 5, 2023
------------------------
ABOUT THIS PROJECT
------------------------
This project implements an interactive board game fashioned after the game
Candy Land. Two players go through the board with an attempt to get to the 
final castle to win the game. Across the board, the players encounter candy 
stores, hidden treasures, special tiles, and calamaities that might help that win
or might set them back on their path. The goal is to get to end of the castle before 
the other players do.
