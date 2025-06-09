#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    //<NAME>: This looks like another boring day.
    std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    //<NAME>: My job here is done!
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

//getter
const std::string& Warlock::getName() const {return this->_name;}
const std::string& Warlock::getTitle() const {return this->_title;}

//setter
void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    // Output: <NAME>: I am <NAME>, <TITLE>!
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}


//ADDED FOR EX01

// //check not null
// //check the matching spellName
// //find(...) == end() means not found
// //store the spell =>  clone it (spell->clone()) to store a copy (not the original pointer) ( in the Warlock’s spellbook)
// void Warlock::learnSpell(ASpell* spell)
// {
//     if (spell && this->_spells.find(spell->getName()) == this->_spells.end())
//         this->_spells[spell->getName()] = spell->clone();
// }

// //find existing spell in _spells map
// //it points to the found item
// //delete "the spell"
// //.erase -> Delete the dynamically allocated spell (to avoid memory leaks)
// void Warlock::forgetSpell(const std::string& spellName)
// {
//     std::map<std::string, ASpell*>::iterator it = this->_spells.find(spellName);

//     if (it != this->_spells.end())
//     {
//         delete it->second;
//         this->_spells.erase(it);
//     }
// }

// //find the exisitng spell in _spells map
// //it->first is the key (a spell name like "Fwoosh")
// //it->second is the value, which in this case is a pointer to an ASpell object (ASpell*)
// //ASpell* spell = it->second; //spell->launch(target);
// void Warlock::launchSpell(const std::string& spellName, const ATarget& target)
// {
//     std::map<std::string, ASpell*>::iterator it = this->_spells.find(spellName);

//     if (it != this->_spells.end())
//     {
//         it->second->launch(target); 
//     }

// }



//FOR EX2
void Warlock::learnSpell(ASpell* spell)
{
    this->spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string& spellName)
{
    this->spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target)
{
    ASpell* spell = spellBook.createSpell(spellName);

    if (spell)
    {
        spell->launch(target);
        delete spell;
    }
}