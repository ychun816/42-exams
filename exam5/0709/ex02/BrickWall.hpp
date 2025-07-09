#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

//Type: "Inconspicuous Red-brick Wall"
class BrickWall : public ATarget
{
    public:
        BrickWall(): ATarget("Inconspicuous Red-brick Wall"){}
        BrickWall(std::string const& typeName) : ATarget(typeName){}
        BrickWall(const BrickWall& src) : ATarget(src){}
        BrickWall& operator=(const BrickWall& src);
        virtual ~BrickWall(){}

        //virtual func
        virtual ATarget* clone() const;


};


#endif