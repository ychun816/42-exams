#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"

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

//ex2
void Warlock::learnSpell(const ASpell* spell)
{
  this->spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
  this->spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target)
{
  ASpell* spell = spellBook.createSpell(spellName);
  if (spell)
  {
    spell->launch(target);
    delete spell;
  }

}



//exmple main
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, Hello, I'm Richard the Warlock!!$
// Inconspicuous Red-brick Wall has been turned into a critter!$
// Inconspicuous Red-brick Wall has been burnt to a crisp!$
// Richard: My job here is done!$
// ~$




