#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}
ASpell::ASpell(std::string const& name, std::string const& effects) : _name(name), _effects(effects){}
ASpell::ASpell(ASpell const &src) : _name(src._name), _effects(src._effects) {}
ASpell::~ASpell(){}

ASpell& ASpell::operator=(ASpell const &src)
{
    this->_name = src._name;
    this->_effects = src._effects;
    return (*this);
}

std::string ASpell::getName() const {return this->_name;}
std::string ASpell::getEffects() const {return this->_effects;}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
