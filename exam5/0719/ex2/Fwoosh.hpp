#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh() : ASpell("Fwoosh", "Fwooshed"){}
        Fwoosh(const std::string name, const std::string effect) : ASpell(){}
        virtual~Fwoosh(){}

        //func
        ASpell* clone() const;
};

#endif