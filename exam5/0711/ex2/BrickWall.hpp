#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}
        virtual~BrickWall(){}

        //func
        ATarget* clone() const;

};

#endif