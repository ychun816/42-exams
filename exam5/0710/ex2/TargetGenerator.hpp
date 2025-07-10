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
        
        TargetGenerator(const TargetGenerator& src);//assign
        TargetGenerator& operator=(const TargetGenerator& src);

    public:
        TargetGenerator(){}
        virtual~TargetGenerator();

        //func
        void learnTargetType(ATarget* target);
        void forgetTargetType(std::string const& targetType);
        ATarget* createTarget(std::string const& targetType);

};


#endif