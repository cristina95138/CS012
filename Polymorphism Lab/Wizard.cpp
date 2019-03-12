#include "Character.h"
#include "Wizard.h"

#include <iostream>
using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, double rank) : Character(WIZARD, name, health, attackStrength) {
    this->rank = rank;
}

const double & Wizard::getRank() {
    return rank;
}

void Wizard::attack(Character &opponent) {
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double damage = attackStrength * (getRank() / opp.getRank());
        cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        opp.damage(damage);
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else if (opponent.getType() != WIZARD) {
        double damage = attackStrength;
        cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        opponent.damage(damage);
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
}