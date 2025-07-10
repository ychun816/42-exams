#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const ATarget& src)//assign
{
    _type = src._type;
}

ATarget& ATarget::operator=(const ATarget& src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return (*this);
}

//<TYPE> has been <EFFECTS>!
void ATarget::getHitBySpell(const ASpell* spell) const
{
    std::cout <<  this->getType() << " has been " << spell->getEffects() << "!" << std::endl;
}
