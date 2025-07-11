#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy() : ATarget("Practice Target Dummy"){}
        virtual~Dummy(){}

        //func
        ATarget* clone() const;

};

#endif