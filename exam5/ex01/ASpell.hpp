#ifndef ASPELL_H
#define ASPELL_H

#include <iostream>
#include <string>
#include <map>

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        //constructor
        ASpell(std::string const& name, std::string const& effects);
        virtual~ASpell();

        //getter
        std::string getName() const;
        std::string getEffects() const;

        //pure virtual method
        virtual ASpell* clone() const = 0;
};

#endif