#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it)
        delete it->second;
        this->_spells.clear();
}

void SpellBook::learnSpell(const ASpell* spellName)
{
    if (spellName && _spells.find(spellName->getName()) == _spells.end())
        _spells[spellName->getName()] = spellName->clone();
}

void SpellBook::forgetSpell(std::string const& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
        return (it->second->clone());
    return NULL;
}