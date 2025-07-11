#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"


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
    // std::map<std::string, ASpell*>::iterator it = _spells.begin();
    // std::map<std::string, ASpell*>::iterator itend= _spells.end();

    // for (; it != itend; ++it)
    // {
    //     delete it->second;
    // }
    // _spells.clear();

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
void Warlock::learnSpell(const ASpell* spell)
{
    this->spellBook.learnSpell(const_cast<ASpell*>(spell));
}

//find spell name ON the spell list first
//delete + erase
void Warlock::forgetSpell(const std::string spellName)
{
    this->spellBook.forgetSpell(spellName);
}

//find spell name ON the spell list first
//launch it (launch method on spell)
void Warlock::launchSpell(const std::string spellName, ATarget& target) const
{
    ASpell* spell = spellBook.createSpell(spellName);

    if (spell)
    {
        spell->launch(target);
        delete spell;
    }
    
}




//ex main 2
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
