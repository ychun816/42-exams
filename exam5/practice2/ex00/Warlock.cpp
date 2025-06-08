#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    //<NAME>: This looks like another boring day.
    std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    //<NAME>: My job here is done!
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

//getter
const std::string& Warlock::getName() const {return this->_name;}
const std::string& Warlock::getTitle() const {return this->_title;}

//setter
void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    // Output: <NAME>: I am <NAME>, <TITLE>!
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
