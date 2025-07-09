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
    this->spellBook.learnSpell(spellName);
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

//Example main():
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


