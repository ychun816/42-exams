#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

//<NAME>: This looks like another boring day.
Warlock::Warlock() : _name(""), _title("")
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::Warlock(const std::string name, const std::string title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    std::map<std::string, ASpell*>::iterator itend= _spells.end();

    for (; it != itend; ++it)
    {
        delete it->second;
    }
    _spells.clear();

    std::cout << _name << ": My job here is done!" << std::endl;
}


//func
//<NAME>: I am <NAME>, <TITLE> !
void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

//check spell exit
//find spell name on the end of spells map list 
//clone new spell onto the spells list
void Warlock::learnSpell(const ASpell* spell) const
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell->getName());

    if (spell && _spells.find(spell->getName()) == _spells.end())
    {
        _spells[spell->getName()] = spell->clone();
    }

}

//find spell name ON the spell list first
//delete + erase
void Warlock::forgetSpell(const std::string spellName) const
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);

    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

//find spell name ON the spell list first
//launch it (launch method on spell)
void Warlock::launchSpell(const std::string spellName, ATarget& target) const
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
    
    if (it != _spells.end())
        it->second->launch(target);
    
}






//ex main 1
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

// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$
// Richard: My job here is done!$
