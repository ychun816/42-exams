#include "Polymorph.hpp"

//- Polymorph: name = "Polymorph", effects = "turned into a critter"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter"){}
Polymorph::~Polymorph(){}

ASpell* Polymorph::clone() const
{
    return (new Polymorph(*this));
}