#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string const& name, std::string const& effects) : _name(name), _effects(effects){}
ASpell::~ASpell(){}

std::string ASpell::getName() const {return this->_name;}
std::string ASpell::getEffects() const {return this->_effects;}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
