#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)  : _name(name), _title(title)
{
    std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}    

////member func 
const std::string& Warlock::getName() const { return this->_name;}

const std::string& Warlock::getTitle() const {return this->_title;}

void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << " !" << std::endl;
}


////added for ex1

//ensures no duplicate spells are added
//if not learned yet -> add the cloned spell
//->Inserts the spell under its name if it’s not already present.
//->Stores a copy of the spell, not the original. -> Provides ownership and safety via deep copying.
void Warlock::learnSpell(ASpell* spell)
{
    if (spell && _spells.find(spell->getName()) == this->_spells.end())
        this->_spells[spell->getName()] = spell->clone();
}

//use std::map -> iterate to find spell name
//delete -> free the dynamtically alocated obj
//erase -> remove ptr frm the map (entry)
void Warlock::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = this->_spells.find(spellName);
    
    if (it != this->_spells.end())
    {
        delete it->second;
        this->_spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target)
{
    //use std::map -> iterate to find spell name -> launch it on target!
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);

    if (it != _spells.end())
        it->second->launch(target);
}

