/*
 * Map.h
 */

#ifndef MAP_H_
#define MAP_H_

#include "Character.h"

class Map {
private:
    Character*** map; // an 2d array, the type of elements is pointer of Character (Character*).
    int rows; // rows of map
    int cols; // columns of map
public:
    //Constructor.
    //Creates a Y*X map for characters.
    Map(int Y, int X);

    //Destructor.
    ~Map();

    //Set the character of a position(row, col)
    void place(int row, int col, char label);

    // Return true if the position (row, col) is valid, false otherwise
    bool isValidPos(int row, int col);

    //Display all characters on map
    void display();

    //Random place some characters at empty locations
    void randomPlace(char label, int amount);

    //get label of a position
    char getXY(int row, int col);

    //get label of a position
    char getLabel(int row, int col);

    //get Character at a position
    Character* getCharacter(int row, int col);
private:
    //find a random empty location
    void getEmptyPosition(int* row, int* col);
};

#endif /* MAP_H_ */
#pragma once
