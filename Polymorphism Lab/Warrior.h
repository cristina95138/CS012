#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
using namespace std;

class Warrior : public Character {
    private:
        string allegiance;
    
    public:
        Warrior(const string &name, double health, double attackStrength, string allegiance);
        void attack(Character &);
        const string & getAllegiance();
};

#endif