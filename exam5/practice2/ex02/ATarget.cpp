#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(const ATarget& src): _type(src._type){}
ATarget& ATarget::operator=(const ATarget& src)
{
    this->_type = src._type;
    return *this;
}

ATarget::ATarget(const std::string& type) : _type(type){}
ATarget::~ATarget(){}

//getter
const std::string& ATarget::getType() const{ return this->_type;}

//pure virtual method
// virtual ATarget* clone() const = 0;

// Output: <TYPE> has been <EFFECTS>!
void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}