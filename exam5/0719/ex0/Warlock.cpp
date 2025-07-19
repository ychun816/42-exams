#include "Warlock.hpp"

//<NAME>: This looks like another boring day.
Warlock::Warlock() : _name(""), _title("")
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const std::string name, const std::string title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

//<NAME>: My job here is done!
Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

//<NAME>: I am <NAME>, <TITLE> !
void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}