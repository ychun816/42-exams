#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}
        virtual~BrickWall(){}

        ATarget* clone() const;

};

#endif