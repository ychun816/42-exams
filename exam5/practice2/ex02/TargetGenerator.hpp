#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> _targets;

        TargetGenerator(const TargetGenerator& src);
        TargetGenerator& operator=(const TargetGenerator& src);

    public:
        //constructor
        TargetGenerator();
        virtual ~TargetGenerator();

        //method
        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& targetType);
        ATarget* createTarget(const std::string& targetType);
};

#endif