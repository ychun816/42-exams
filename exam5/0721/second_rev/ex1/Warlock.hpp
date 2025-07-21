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
        Warlock();
        Warlock(const std::string name, const std::string title);
        ~Warlock();

        //getter 
        std::string getName() const{return this->_name;}
        std::string getTitle() const{return this->_title;}

        //setter
        void setTitle(const std::string title){this->_title = title;}

        //func
        void introduce() const;


        void learnSpell(const ASpell* spell);
        void forgetSpell(const std::string spellName);
        void launchSpell(const std::string spellName, const ATarget& target);

};

#endif