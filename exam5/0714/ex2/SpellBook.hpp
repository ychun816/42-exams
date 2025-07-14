#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"

class SpellBook
{
    private:
        SpellBook(SpellBook& src);
        SpellBook& operator=(SpellBook& src);
        
        std::map<std::string, ASpell*> _spells; 


    public:
        SpellBook(){}
        ~SpellBook();


     void learnSpell(ASpell* spell);
     void forgetSpell(std::string const & spellName);
     ASpell* createSpell(std::string const & spellName);

};

#endif