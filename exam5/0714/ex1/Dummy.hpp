#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy() : ATarget("Target Practice Dummy"){}
        virtual ~Dummy(){}

    //func
    ATarget* clone() const;


};

#endif