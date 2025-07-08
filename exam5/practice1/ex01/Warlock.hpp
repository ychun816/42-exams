#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"

// Constructor:
// - Must take name and title (in that order).
// - No default constructor.
// - No copy constructor or copy assignment.

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        //added for ex1
        std::map<std::string, ASpell*> _spells;

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