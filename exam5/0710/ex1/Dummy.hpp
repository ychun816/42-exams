#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy() : ATarget("Target Practice Dummy"){}
        // Dummy(const std::string& type) : ATarget("Target Practice Dummy"){}
        // Dummy(const Dummy& src) : ATarget(src){} 
        // Dummy& operator=(const Dummy& src);
        virtual~Dummy(){}

        ATarget* clone() const;

};

#endif