#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

//- BrickWall: type = "Inconspicuous Red-brick Wall"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        virtual ~BrickWall();
        virtual ATarget* clone() const;
};

#endif