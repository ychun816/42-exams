#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy(): ATarget("Target Practice Dummy"){}
        Dummy(std::string const& typeName) : ATarget(typeName){}
        Dummy(const Dummy& src) : ATarget(src){}
        Dummy& operator=(const Dummy& src);
        virtual ~Dummy(){}

        //virtual func
        virtual ATarget* clone() const;


};


#endif