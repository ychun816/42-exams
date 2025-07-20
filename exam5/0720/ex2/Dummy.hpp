#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy() : ATarget("Target Practice Dummy"){}
        Dummy(const std::string type) : ATarget(){}
        virtual~Dummy(){}

        //func
        virtual ATarget* clone() const;

};

#endif