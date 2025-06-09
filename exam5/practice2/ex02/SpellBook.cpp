#include "SpellBook.hpp"


SpellBook::SpellBook(){}

//delete one by one!
SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it)
        delete it->second;
    // this->_spells.clear();
}

//if spell exist && cannot find the spell (==.end())
//clone the spell
//It stores a copy of the spell (created using clone()) into the _spells map using the spell's name as the key.
void SpellBook::learnSpell(ASpell* spell)
{
    if (spell && _spells.find(spell->getName()) == _spells.end())
        _spells[spell->getName()] = spell->clone();
}

//define iterator 
//delete the spell name string : it->second (value)
//.erase() -> remove pointer
void SpellBook::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
  
    if (it != _spells.end())
        delete it->second;
    _spells.erase(it);
}

// returns a new copy of the spell found in the spells map
ASpell* SpellBook::createSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
  
    if (it != _spells.end())
        return (it->second->clone());
    return NULL;
}

/*

| Line                                   | Purpose                         | Modifies Map? | Returns Value? |
| -------------------------------------- | ------------------------------- | ------------- | -------------- |
| `_spells[spell->getName()] = clone();` | Adds a cloned spell to the map  | ✅ Yes         | ❌ No           |
| `return it->second->clone();`          | Returns a cloned spell from map | ❌ No          | ✅ Yes          |

*/