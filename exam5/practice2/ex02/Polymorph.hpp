#ifndef POLYMORPHY_HPP
#define POLYMORPHY_HPP

#include <iostream>

#include "ASpell.hpp"

//"Polymorph", effects = "turned into a critter"
class Polymorph : public ASpell
{
    public:
        Polymorph();
        virtual ~Polymorph();
        virtual ASpell* clone() const;
};


#endif