#include "BrickWall.hpp"

BrickWall& BrickWall::operator=(const BrickWall& src)
{
    if (this != &src)
    {
        ATarget::operator=(src);
    }
    return (*this);
}

ATarget* BrickWall::clone() const
{
    return new BrickWall(*this);
}