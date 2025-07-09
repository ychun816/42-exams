#ifndef TARGETGENERATOR_HPP 
#define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"

// * void learnTargetType(ATarget*), teaches a target to the generator
// * void forgetTargetType(string const &), that makes the generator forget a
//   target type if it's known
// * ATarget* createTarget(string const &), that creates a target of the
//   specified type



class TargetGenerator
{
    private:
        TargetGenerator(const TargetGenerator& src);
        TargetGenerator& operator=(const TargetGenerator& src);

        std::map<std::string, ATarget*> _targets;

    public:
        TargetGenerator(){}
        ~TargetGenerator();

        void learnTargetType(ATarget* targetType);
        void forgetTargetType(const std::string& targetType);
        ATarget* createTarget(const std::string& targetType); 
};

#endif