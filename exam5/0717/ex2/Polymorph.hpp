#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph() : ASpell("Polymorph", "burnt to a crisp"){}
        Polymorph(const std::string name, const std::string effect) : ASpell(name, effect){}
        virtual~Polymorph(){}
    
        //func
        virtual ASpell* clone() const;

};

#endif