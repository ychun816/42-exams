#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*> _spells;

        SpellBook(const SpellBook& src);
        SpellBook& operator=(const SpellBook& src);

    public:
        SpellBook(){}
        ~SpellBook();

        //func
        void learnSpell(const ASpell* spell);
        void forgetSpell(std::string const & spellName);
        ASpell* createSpell(std::string const & spellName);

};

#endif