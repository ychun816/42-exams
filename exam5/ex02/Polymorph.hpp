#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

//- Polymorph: name = "Polymorph", effects = "turned into a critter"

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        virtual ~Polymorph();
        
        virtual ASpell* clone() const;

};

#endif
