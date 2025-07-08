#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"


//con-destructor
Warlock::~Warlock()
{
    std::cout << this->_name << ": My job here is done!" << std::endl;
}
Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

//Setter
void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

//funcs
//<NAME>: I am <NAME>, <TITLE>!
void Warlock::introduce() const
{
    std::cout << _name << ": I am "<< _name << ", " << this->_title << "!" << std::endl;
}  


//ex1
void Warlock::learnSpell(const ASpell* spellName)
{
    if (spellName && _spells.find(spellName->getName()) == this->_spells.end())
        this->_spells[spellName->getName()] = spellName->clone();
}

void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);

    if (it != this->_spells.end())
    {
        delete it->second;
        this->_spells.erase(it);
    }
}

void Warlock::launchSpell(std::string spellName, const ATarget& target)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);

    if (it != _spells.end())
        it->second->launch(target);
}

//Example main():
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
