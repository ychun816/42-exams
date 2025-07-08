#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

//spell controler
// Create class SpellBook (canonical form, non-copyable):
// - void learnSpell(ASpell*)      // copies spell
// - void forgetSpell(const std::string&)
// - ASpell* createSpell(const std::string&) // returns new copy

class SpellBook
{
    private:
        std::map<std::string, ASpell*> _spells;

        SpellBook(const SpellBook& src); //copy
        SpellBook& operator=(const SpellBook& src); //assign op

    public:
        //constructor
        SpellBook();
        virtual ~SpellBook();

        void learnSpell(ASpell* spellName);                // copies spell
        void forgetSpell(const std::string& spellName);
        ASpell* createSpell(const std::string& spellName); // returns new copy

};

#endif