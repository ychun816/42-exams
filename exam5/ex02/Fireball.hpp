#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

//- Fireball: name = "Fireball", effects = "burnt to a crisp"

class Fireball : public ASpell
{
    public:
        Fireball();
        virtual ~Fireball();
        
        virtual ASpell* clone() const;

};

#endif