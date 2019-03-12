#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
using namespace std;

class Wizard : public Character {
    private:
        double rank;
    
    public:
        Wizard(const string &name, double health, double attackStrength, double rank);
        void attack(Character &);
        const double & getRank();
};

#endif