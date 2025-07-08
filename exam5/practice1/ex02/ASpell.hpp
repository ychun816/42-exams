#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        //constructor
        ASpell();
        ASpell(ASpell const &src);
        ASpell(std::string const &name, std::string const &effects);
        ASpell& operator=(ASpell const &src);
        virtual ~ASpell();

        //getter
        std::string getName() const;
        std::string getEffects() const;

        //pure virtual method
        virtual ASpell* clone() const = 0;

        void launch(const ATarget& target) const;
};

#endif