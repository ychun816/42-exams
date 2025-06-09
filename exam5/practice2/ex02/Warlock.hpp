#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

//- No default constructor. => must not allow!
//- No copy constructor or copy assignment => must not allow!
class Warlock
{
    private:
        std::string _name;                //variable -> store value (no '&'->reference)
        std::string _title;               //variable -> store value (no '&'->reference)
        
        Warlock();                        //declared private (forbidden)
        Warlock& operator=(Warlock& src); //declared private (forbidden)

        //ADDED FOR EX1
        std::map<std::string, ASpell*> _spells;

        //ADDED FOR EX2
        SpellBook spellBook;

    public:
        //constructor
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        
        //getter
        const std::string& getName() const;
        const std::string& getTitle() const;

        //setter
        void setTitle(const std::string&);
        void introduce() const;

        //ADDED FOR EX01
        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spellName);
        void launchSpell(const std::string& spellName, const ATarget& target);
};



#endif 

//const std::string name means you're passing by value (i.e., a copy is made when calling the constructor).
//const std::string& name means you're passing by reference, avoiding that copy.
// if you write const std::string name, you pay for two copies:
//1 When the argument is passed to the constructor.
//2 When you initialize _name from name.