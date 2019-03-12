#ifndef ELF_H
#define ELF_H

#include <iostream>
using namespace std;

class Elf : public Character {
    private:
        string famName;
    
    public:
        Elf(const string &name, double health, double attackStrength, string famName);
        void attack(Character &);
        const string & getFamName();
};

#endif