#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"

// * void learnSpell(ASpell*), that COPIES a spell in the book
// * void forgetSpell(string const &), that deletes a spell from the book, except
//   if it isn't there
// * ASpell* createSpell(string const &), that receives a string corresponding to
//   the name of a spell, creates it, and returns it.

class SpellBook
{
    private:
        SpellBook(const SpellBook& src);
        SpellBook& operator=(const SpellBook& src);
        std::map<std::string, ASpell*> _spells;

    public:
        SpellBook(){}
        ~SpellBook();

        void learnSpell(const ASpell* spellName);
        void forgetSpell(std::string const& spellName);
        ASpell* createSpell(std::string const& spellName);

};


#endif