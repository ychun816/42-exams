#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}
        BrickWall(const std::string type) : ATarget(){}
        virtual~BrickWall(){}

        //func
        virtual ATarget* clone() const;

};

#endif