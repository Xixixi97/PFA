/*
 * Character.cpp
 */

#include "Character.h"

Character::Character(char label) {
    this->label = label;
}

char Character::getLabel() const {
    return label;
}

Character* CharacterFactory::createCharacter(char label) {
    return new Character(label);
}
