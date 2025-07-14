#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"

class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator& src);
        TargetGenerator& operator=(TargetGenerator& src);
        
        std::map<std::string, ATarget*> _targets; 


    public:
        TargetGenerator(){}
        ~TargetGenerator();


        void learnTargetType(ATarget* target);
        void forgetTargetType(std::string const & targetType);
        ATarget* createTarget(std::string const & targetType);


};

#endif