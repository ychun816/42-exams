#ifndef POLYMORPHY_HPP
#define POLYMORPHY_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph() : ASpell("Polymorph", "turned into critter"){}
        virtual~Polymorph(){}

        ASpell* clone() const;

};

#endif