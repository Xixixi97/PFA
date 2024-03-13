/*
 * Map.cpp
 */

#include "Map.h"

#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor.
//Creates a Y*X map for characters.
Map::Map(int Y, int X) {
    if (Y < 1) {
        Y = 1;
    }
    if (X < 1) {
        X = 1;
    }

    rows = Y;
    cols = X;
    map = new Character * *[rows];
    for (int i = 0; i < rows; i++) {
        map[i] = new Character * [cols];
        for (int j = 0; j < cols; j++) {
            //set all elements to Empty
            map[i][j] = CharacterFactory::createCharacter(EMPTY);
        }
    }
}

//Destructor.
Map::~Map() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}

// Return true if the position (row, col) is valid, false otherwise
bool Map::isValidPos(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

//Set the character of a position(row, col)
void Map::place(int row, int col, char label) {
    //validate row and col
    if (isValidPos(row, col) && getLabel(row, col) == EMPTY) {
        delete map[row][col];
        map[row][col] = CharacterFactory::createCharacter(label);
    }
}

//Display all characters on map
void Map::display() {
    for (int j = 0; j < cols; j++) {
        cout << "----";
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "| " << map[i][j]->getLabel() << " ";
        }
        cout << "|" << endl;

        for (int j = 0; j < cols; j++) {
            cout << "----";
        }
        cout << endl;
    }
}

//Random place some characters at empty locations
void Map::randomPlace(char label, int amount) {
    for (int i = 0; i < amount; i++) {
        int row, col;
        getEmptyPosition(&row, &col);
        place(row, col, label);
    }
}

//get label of a position
char Map::getXY(int row, int col) {
    return getLabel(row, col);
}

//get label of a position
char Map::getLabel(int row, int col) {
    if (isValidPos(row, col)) {
        return map[row][col]->getLabel();
    }
    else {
        return -1;
    }
}

//get Character at a position
Character* Map::getCharacter(int row, int col) {
    if (isValidPos(row, col)) {
        return map[row][col];
    }
    else {
        return NULL;
    }
}

//find a random empty location
void Map::getEmptyPosition(int* row, int* col) {
    *row = rand() % rows;
    *col = rand() % cols;
    while (getLabel(*row, *col) != EMPTY) {
        *row = rand() % rows;
        *col = rand() % cols;
    }
}
