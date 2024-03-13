/*
 * Character.h
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

const char TERRAIN = '#';
const char EMPTY = ' ';
const char VEGETATION = 'T';
const char HERBIVORE = 'H';
const char OMNIVORE = 'O';
const char CARNIVORE = 'C';
const char RCharacter = 'R';

//The base class of all character.
class Character {
private:
    //label of character
    char label;

public:
    Character(char label);

    char getLabel() const;
};

class CharacterFactory {
public:
    static Character* createCharacter(char label);
};

#endif /* CHARACTER_H_ */
