#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    std::map<std::string, ASpell*>::iterator ite = _spells.end();
    
    while (it != ite)
    {
        delete it->second;
        ++it;
    }
    _spells.clear();
    
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

//
void Warlock::introduce() const
{
  std::cout << _name << ": I am "<< _name << ", " << this->_title << "!" << std::endl;
}  

//ex1
void Warlock::learnSpell(const ASpell* spell)
{
  if (spell && _spells.find(spell->getName()) == this->_spells.end())
    this->_spells[spell->getName()] = spell->clone();
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
  std::map<std::string, ASpell*>::iterator it = this->_spells.find(spellName);

  if (it != this->_spells.end())
  {
    it->second->launch(target);
  }
}



//exmple main
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


