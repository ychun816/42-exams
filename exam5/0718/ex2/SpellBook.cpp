#include "SpellBook.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    std::map<std::string, ASpell*>::iterator itend = _spells.end();

    for (; it != itend; ++it)
    {
        delete it->second;
    }
    _spells.clear();
    

}


void SpellBook::learnSpell(const ASpell* spell)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell->getName());
    if (it == _spells.end())
    {
        _spells[spell->getName()] = spell->clone();
    }
}
void SpellBook::forgetSpell(const std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        delete it ->second;
        _spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(const std::string spellName, const ATarget& target)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    if (it != _spells.end())
    {
        return it->second->clone();
    }
    return NULL;
}