 #include "Character.h"

#include <iostream>
using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength) {}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::setHealth(double h) {
    health = h;
}

void Character::damage(double d) {
    health -= d;
}

 /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const {
    if (getHealth() > 0) {
        return true;
    }
    else {
        return false;
    }
}