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


int main() 
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;
  return 0;
}

/*
For Compile:
g++ -o Warlock Warlock.cpp

Expected output:
Richard: This looks like another boring day.
Richard: I am Richard, Mistress of Magma!
Richard - Mistress of Magma
Jack: This looks like another boring day.
Jack: I am Jack, the Long!
Jack: I am Jack, the Mighty!
Jack: My job here is done!
Richard: My job here is done!
*/