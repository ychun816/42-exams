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
        
        SpellBook(const SpellBook& src);//assign
        SpellBook& operator=(const SpellBook& src);

    public:
        SpellBook(){}
        virtual~SpellBook();

        //func
        ASpell* createSpell(const std::string spellName);
        void learnSpell(const ASpell* spell);
        void forgetSpell(const std::string spellName);


};


#endif