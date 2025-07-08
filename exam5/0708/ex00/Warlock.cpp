#include "Warlock.hpp"

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


//Example main():
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