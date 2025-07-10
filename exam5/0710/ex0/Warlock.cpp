#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

//
void Warlock::introduce() const
{
  std::cout << _name << ": I am "<< _name << ", " << this->_title << "!" << std::endl;
}  


//exmple main
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

  return (0);
}

// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, Mistress of Magma!$
// Richard - Mistress of Magma$
// Jack: This looks like another boring day.$
// Jack: I am Jack, the Long!$
// Jack: I am Jack, the Mighty!$
// Jack: My job here is done!$
// Richard: My job here is done!$
// ~$

