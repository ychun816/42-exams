#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph(): ASpell("Polymorph", "turned into critter"){}
        Polymorph(std::string const& name, std::string const& effects) : ASpell(name, effects){}
        Polymorph(const Polymorph& src) : ASpell(src){}
        Polymorph& operator=(const Polymorph& src);
        virtual~Polymorph(){}

        //virtual func
        ASpell* clone() const;

        
};


#endif