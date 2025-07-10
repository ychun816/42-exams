#include "Dummy.hpp"

// Dummy& Dummy::operator=(const Dummy& src)
// {
//     if (this != &src)
//     {
//         *this = src;
//     }
//     return (*this);
// }

ATarget* Dummy::clone() const
{
    return (new Dummy(*this));
}