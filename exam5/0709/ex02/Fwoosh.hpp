#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh(): ASpell("Fwoosh", "Fwooshed"){}
        Fwoosh(std::string const& name, std::string const& effects) : ASpell(name, effects){}
        Fwoosh(const Fwoosh& src) : ASpell(src){}
        Fwoosh& operator=(const Fwoosh& src);
        virtual~Fwoosh(){}

        //virtual func
        ASpell* clone() const;

        
};


#endif