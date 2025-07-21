#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

//<NAME>: This looks like another boring day.
Warlock::Warlock() : _name(""), _title("")
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const std::string name, const std::string title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

//<NAME>: My job here is done!
Warlock::~Warlock()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    std::map<std::string, ASpell*>::iterator itend = _spells.end();

    for (; it != itend; ++it)
    {
        delete it->second;
    }
    _spells.clear();
    
    
    std::cout << _name << ": My job here is done!" << std::endl;
}

//<NAME>: I am <NAME>, <TITLE> !
void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(const ASpell* spell)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell->getName());
    if (it == _spells.end())
    {
        _spells[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(const std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        it->second->launch(target);
    }
}