#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph() : ASpell("Polymorph", "turned into critter"){}
        virtual~Polymorph(){}

        //func
        ASpell* clone() const;

};

#endif