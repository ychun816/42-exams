#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const ASpell& src)
{
    this->_name = src._name;
    this->_effects = src._effects;
}

ASpell& ASpell::operator=(const ASpell& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_effects = src._effects;
    }
    return (*this);
}

//func
void ASpell::launch(const ATarget& target) const
{
    target.getHitbySpell(this);
}
