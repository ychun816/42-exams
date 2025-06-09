#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "Fwooshed"){}
Fwoosh::~Fwoosh(){}

//this refers to the current object
//new Fwoosh(*this) uses the copy constructor of Fwoosh to make a deep copy.
ASpell* Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}