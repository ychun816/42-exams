#include "Fwoosh.hpp"

// Fwoosh& Fwoosh::operator=(const Fwoosh& src)
// {
//     if (this != &src)
//     {
//         *this = src;
//     }
//     return (*this);
// }

ASpell* Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}