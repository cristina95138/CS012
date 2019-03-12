#include "Character.h"
#include "Warrior.h"

#include <iostream>
using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength) {
    this->allegiance = allegiance;
}

const string & Warrior::getAllegiance() {
    return allegiance;
}

void Warrior::attack(Character &opponent) {
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.getAllegiance() == allegiance) {
            cout << "Warrior " << getName() << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << getAllegiance() << "." << endl;
        }
        else {
            double damage = (health / MAX_HEALTH) * attackStrength;
            cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            opp.damage(damage);
            cout << opponent.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else {
        double damage = (health / MAX_HEALTH) * attackStrength;
        cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!"<<endl;
        opponent.damage(damage);
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
}