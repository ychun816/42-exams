#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const ASpell& src)
{
    _name = src._name;
    _effects = src._effects;
}


ASpell& ASpell::operator=(const ASpell& src)
{
    if (this != &src)
    {
        _name = src._name;
        _effects = src._effects;
    }
    return (*this);
}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell((*this));
}
