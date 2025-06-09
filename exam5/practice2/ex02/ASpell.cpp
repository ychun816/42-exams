#include "ASpell.hpp"
#include "ATarget.hpp" // now you can include it for full definition

//constructor 
ASpell::ASpell(std::string const& name, std::string const& effects) : _name(name), _effects(effects)
{}

ASpell::~ASpell(){}
        
//getter
std::string ASpell::getName() const{return _name;}
std::string ASpell::getEffects() const{return _effects;}

//pure virtual method
// virtual ASpell* clone() const = 0;

// Calls target.getHitBySpell(*this)
void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
