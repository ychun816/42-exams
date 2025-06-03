#include "Warlock.hpp"

// Warlock::Warlock() : _name("default name"), _title("default title") {}

Warlock::Warlock(const std::string& name, const std::string& title)  : _name(name), _title(title)
{
    std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}    

////member func 
const std::string& Warlock::getName() const { return this->_name;}

const std::string& Warlock::getTitle() const {return this->_title;}

void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}


void Warlock::introduce() const
{
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << " !" << std::endl;
}

/////// MAIN ///////
int main() {
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}

/*
For Compile:
g++ -Wall -Wextra -Werror -std=c++98 -o Warlock Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp


Expected output:
Richard: This looks like another boring day.
Richard: I am Richard, the Titled!
Target Practice Dummy has been fwooshed!
Richard: My job here is done!
*/
