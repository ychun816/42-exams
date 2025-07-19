#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

//<NAME>: This looks like another boring day.
Warlock::Warlock() : _name(""), _title("")
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const std::string name, const std::string title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

//<NAME>: My job here is done!
Warlock::~Warlock()
{

    
    std::cout << _name << ": My job here is done!" << std::endl;
}

//<NAME>: I am <NAME>, <TITLE> !
void Warlock::introduce() const
{   
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}



//func
void Warlock::learnSpell(const ASpell* spell)
{
    book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string spellName)
{
    book.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
    ASpell* spell = book.createSpell(spellName);
    if (spell)
    {
        spell->launch(target);
        delete spell;
    }

}