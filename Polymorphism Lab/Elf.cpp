#include "Character.h"
#include "Elf.h"

#include <iostream>
using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string famName) : Character(ELF, name, health, attackStrength) {
    this->famName = famName;
}

const string & Elf::getFamName() {
    return famName;
}

void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.getFamName() == famName) {
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << getFamName() << " family." << endl;
        }
        else {
            double damage = (health / MAX_HEALTH) * attackStrength;
            cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!"<<endl;
            opp.damage(damage);
            cout << opponent.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else {
        double damage = (health / MAX_HEALTH) * attackStrength;
        cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!"<<endl;
        opponent.damage(damage);
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
}