#include "ATarget.hpp"

//constructor
ATarget::ATarget(){}
ATarget::ATarget(const std::string& type) : _type(type){}
ATarget::ATarget(const ATarget& src) : _type(src._type){}
ATarget& ATarget::operator=(const ATarget& src)
{
    this->_type = src._type;
    return *this;
}

ATarget::~ATarget(){}

const std::string& ATarget::getType() const { return this->_type; }

//Output: <TYPE> has been <EFFECTS>!
void ATarget::getHitBySpell(const ASpell& spells) const 
{
    std::cout <<  this->getType() << " has been " << spells.getEffects() << " !" << std::endl;
}