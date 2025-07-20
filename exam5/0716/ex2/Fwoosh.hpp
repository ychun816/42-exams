#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh() : ASpell("fwoosh", "fwooshed"){}
        virtual ~Fwoosh(){}

        virtual ASpell* clone() const;

};

#endif 