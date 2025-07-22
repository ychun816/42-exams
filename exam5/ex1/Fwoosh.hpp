#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh() : ASpell("Fwoosh", "fwooshed"){}
        virtual~Fwoosh(){}

        //func
        virtual ASpell* clone() const;
};

#endif