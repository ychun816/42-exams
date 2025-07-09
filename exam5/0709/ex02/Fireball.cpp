#include "Fireball.hpp"

Fireball& Fireball::operator=(const Fireball& src)
{
    if (this!= &src)
    {
        *this = src;
    }
    return (*this);
}

ASpell* Fireball::clone() const
{
    return (new Fireball(*this));
}