#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

//- BrickWall: type = "Inconspicuous Red-brick Wall"

class Brickwall : public ATarget
{
    public:
        Brickwall();
        virtual ~Brickwall();
        virtual ATarget* clone() const;
};

#endif