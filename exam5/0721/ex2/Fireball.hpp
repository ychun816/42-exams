#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball() : ASpell("Fireball", "burnt to a crisp"){}
        Fireball(const std::string name, const std::string effect) : ASpell(){}
        virtual~Fireball(){}

        //func
        virtual ASpell* clone() const;
};

#endif