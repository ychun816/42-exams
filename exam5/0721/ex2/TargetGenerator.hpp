#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> _targets;

        TargetGenerator(const TargetGenerator& src);
        TargetGenerator& operator=(const TargetGenerator& src);
    
    public:
        TargetGenerator(){}
        ~TargetGenerator();

        //func
        void learnTargetType(const ATarget* target);
        void forgetTargetType(std::string const & targetType);
        ATarget* createTarget(std::string const & targetType);

};

#endif
