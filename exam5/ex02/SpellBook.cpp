#include "SpellBook.hpp"

SpellBook::SpellBook(){}

// SpellBook::SpellBook(const SpellBook& src){}

// SpellBook& SpellBook::operator=(const SpellBook& src){}

//have to delete one by one!
//.clear() optional in the destructor 
// -> When the object is destroyed, the map itself is also destroyed. -> The destructor of std::map automatically clears its contents.
//In a non-destructor context, if you wanted to free up memory without destroying the object, you'd need clear().
SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it)
        delete it->second;
    // this->_spells.clear(); //maybe no need
}

void SpellBook::learnSpell(ASpell* spellName)
{
    if (spellName && _spells.find(spellName->getName()) == _spells.end())
        _spells[spellName->getName()] = spellName->clone();
}

void SpellBook::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
        return (it->second->clone());
    return NULL;
}