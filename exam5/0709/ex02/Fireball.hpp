#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

//Name: "Fireball", Effects: "burnt to a crisp"
class Fireball : public ASpell
{
    public:
        Fireball(): ASpell("Fireball", "burnt to a crisp"){}
        Fireball(std::string const& name, std::string const& effects) : ASpell(name, effects){}
        Fireball(const Fireball& src) : ASpell(src){}
        Fireball& operator=(const Fireball& src);
        virtual~Fireball(){}

        virtual ASpell*clone() const;
};



#endif