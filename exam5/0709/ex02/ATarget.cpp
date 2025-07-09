#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const ATarget& src)
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
void ATarget::getHitBySpell(const ASpell& effects) const
{
    std::cout << this->_type << " has been " << effects.getEffects() << "!" << std::endl;
}
