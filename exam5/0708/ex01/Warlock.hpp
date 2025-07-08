#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> _spells;

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





