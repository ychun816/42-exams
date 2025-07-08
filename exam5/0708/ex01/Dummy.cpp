#include "Dummy.hpp"

Dummy& Dummy::operator=(const Dummy& src)
{
    if (this != &src)
    {
        ATarget::operator=(src);
    }
    return (*this);
}

ATarget* Dummy::clone() const
{
    return new Dummy(*this);
}
