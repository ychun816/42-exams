#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    std::map<std::string, ASpell*>::iterator itend = _spells.end();

    for (; it != itend; ++it)
        delete it->second;
    _spells.clear();
}

//find spell name on spells map list
//check if spell valid && found spell name at the end of map list 
//clone the spell fmr the spell list
void SpellBook::learnSpell(ASpell* spell)
{
    std::map<std::string, ASpell*>::iterator found = _spells.find(spell->getName());
    if (spell && found == _spells.end())
        _spells[spell->getName()] = spell->clone();
        //Use the spell's name ("Fireball", "Frostbolt", etc.) as the key.
        //Store a newly created clone of the spell (a new ASpell*) as the value.
        //when Warlock wants to cast "Fireball" -> He looks up _spells["Fireball"]. -> He uses the cloned copy, not the original you passed.
}

void SpellBook::forgetSpell(std::string const & spellName)
{
    std::map<std::string, ASpell*>::iterator found = _spells.find(spellName);
   
    if (found != _spells.end())
    {
        delete found->second; // Free the memory
        _spells.erase(found); //Remove the entry
    }
}

ASpell* SpellBook::createSpell(std::string const& spellName) const
{
    std::map<std::string, ASpell*>::const_iterator found = _spells.find(spellName);

    if (found != _spells.end())
        return found->second->clone();
    return NULL;
}


/*
┌────────────┐       clone()      ┌────────────────┐
│  Fireball  │ ─────────────────▶ │   Fireball*    │
│   Spell    │                    │  (on the heap) │
└────────────┘                    └────────────────┘
                                      ↓
                          _spells["Fireball"] = pointer to this copy


//LEARN SPELL
💡 Visual Analogy:
Imagine a wizard copying a spell scroll and storing it under a label:

Original Spell:     "Fireball Scroll"
Cloned Spell:       "Fireball Scroll (copy)"
Stored In Map:      _spells["Fireball"] = pointer to copy

📘 Internal _spells:
{
  "Fireball" → [clone of Fireball spell],
  "Frostbolt" → [clone of Frostbolt spell]
}


*/