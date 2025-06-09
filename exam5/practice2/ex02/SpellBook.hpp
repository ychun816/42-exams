#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"

//(canonical form, non-copyable):
class SpellBook
{
    private:
        std::map<std::string, ASpell*> _spells;

        //constructor
        SpellBook(const SpellBook& src);
        SpellBook& operator=(SpellBook& src);
    
    public:
        //constructor
        SpellBook();
        virtual ~SpellBook();

        //method
        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spellName);
        ASpell* createSpell(const std::string& spellName);

};


#endif