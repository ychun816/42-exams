#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

//using ASpell and ATarget as pointers or references
// keeps the header lightweight and avoids circular dependencies.
//Limitation: cannot:
//-Use ASpell or ATarget as by-value parameters or member variables.
//-Call their methods inside inline functions in the header.
class ASpell;
class ATarget;
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> _spells;

        SpellBook spellBook;

    public:
        Warlock() : _name(""), _title(""){};
        ~Warlock();
        Warlock(const std::string& name, const std::string& title);
        //No copy constructor or copy assignment

        //getter
        const std::string& getName() const{return this->_name;}
        const std::string& getTitle() const{return this->_title;}

        //Setter
        void setTitle(const std::string& title);

        //funcs
        void introduce() const;

        //ex1
        void learnSpell(const ASpell* spellName);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, const ATarget& target);
} ;

#endif

