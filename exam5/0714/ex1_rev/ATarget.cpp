#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget(const ATarget& src)
{
    this->_type = src._type;
}

ATarget& ATarget::operator=(const ATarget& src)
{
    if (this != &src)
    {
        this->_type = src._type;
    }
    return (*this);
}

//func
//<TYPE> has been <EFFECTS>!
void ATarget::getHitbySpell(const ASpell* spell) const
{
    std::cout << _type << " has been " << spell->getEffect() << "!" << std::endl;
}
