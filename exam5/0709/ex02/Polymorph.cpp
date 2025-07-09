#include "Polymorph.hpp"

Polymorph& Polymorph::operator=(const Polymorph& src)
{
    if (this!= &src)
    {
        *this = src;
    }
    return (*this);
}

ASpell* Polymorph::clone() const
{
    return (new Polymorph(*this));
}