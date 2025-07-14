#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh() : ASpell("Fwoosh", "Fwooshed"){}
        virtual~Fwoosh(){}

    //func
    ASpell* clone() const;


};

#endif