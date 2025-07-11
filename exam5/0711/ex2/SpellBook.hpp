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

    public:
        SpellBook(){}
        ~SpellBook();

        //func
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string const & spellName);
        ASpell* createSpell(std::string const& spellName) const;

};

#endif