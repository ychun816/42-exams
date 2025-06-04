#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
// #include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

//for ex2
// Modify Warlock:
// - Owns a SpellBook
// - Delegates learnSpell, forgetSpell to SpellBook
// - Uses SpellBook in launchSpell to get the spell

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        //added for ex1
        // std::map<std::string, ASpell*> _spells;

        //added for ex2
        SpellBook spellBook;

        //constructor
        Warlock();        
        Warlock(const Warlock& src);//copy
        Warlock& operator=(const Warlock& src);//assign operator

    public:
        ///constructor & destructor
        Warlock(const std::string& name, const std::string& title);
        virtual ~Warlock();
        
        ////member func 
        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& title);
        void introduce() const;

        //added ex1
        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spell);
        void launchSpell(const std::string&, const ATarget& spell);
};

#endif 