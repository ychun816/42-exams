#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>

#include "ASpell.hpp"

//name = "Fireball", effects = "burnt to a crisp"
class Fireball : public ASpell
{
    public:
        Fireball();
        virtual ~Fireball();
        virtual ASpell* clone() const;

};



#endif 