#include "Brickwall.hpp"

Brickwall::Brickwall() : ATarget("Inconspicuous Red-brick Wall"){}
Brickwall::~Brickwall(){}

ATarget* Brickwall::clone() const
{
    return (new Brickwall(*this));
}