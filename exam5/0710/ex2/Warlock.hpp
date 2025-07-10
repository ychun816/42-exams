#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;
class ATarget;
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        //ex1
        std::map<std::string, ASpell*> _spells;

        //ex2
        SpellBook spellBook;

    public:
        Warlock() : _name(""), _title(""){}
        Warlock(const std::string& _name, const std::string& _title);
        ~Warlock();

        //getter
        const std::string& getName() const {return _name;}
        const std::string& getTitle() const {return _title;}

        //setter
        void setTitle(const std::string& title){_title = title;}

        //func
         void introduce() const;

        //ex1
        void learnSpell(const ASpell* spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, const ATarget& target);

};

#endif