#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh() : ASpell("Fwoosh", "fwooshed"){}
        // Fwoosh(const std::string& name, const std::string& effect) : ASpell("Fwoosh", "fwooshed"){}
        // Fwoosh(const Fwoosh& src) : ASpell(src){} 
        // Fwoosh& operator=(const Fwoosh& src);
        virtual~Fwoosh(){}

        ASpell* clone() const;

};

#endif