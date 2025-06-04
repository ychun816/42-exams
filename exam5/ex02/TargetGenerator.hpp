#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <iostream>
#include <map>

#include "ATarget.hpp"

// Create TargetGenerator (canonical form, non-copyable):
// - void learnTargetType(ATarget*)
// - void forgetTargetType(const std::string&)
// - ATarget* createTarget(const std::string&)

//By placing them in the private section and not defining them (or sometimes defining them as deleted in modern C++), 
//the class is explicitly made non-copyable.

class TargetGenerator : public ATarget
{
    private:
        std::map<std::string, ATarget> _targets;

        // Copy constructor and copy assignment operator declared but not defined
        TargetGenerator(const TargetGerator &src);
        TargetGenerator& operator=(const TargetGenerator &src);

    public:
        TargetGenerator();
        virtual ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& targetType);
        ATarget* createTarget(const std::string& targetType); 

    
};

#endif 

/* NOTES

By declaring but not defining the copy constructor and assignment operator in the private section, you're doing two things:

1. Prevent external code from copying the object:
Any attempt to copy or assign will result in a compile-time error due to inaccessible (private) functions.

2. Avoid resource duplication issues:
Since this class likely manages dynamic memory (ATarget*), copying could cause double deletions, memory leaks, or dangling pointers.

//////////////////////////////////////////////////////
EX:
TargetGenerator tg1;
TargetGenerator tg2 = tg1;   // ❌ ERROR – copy constructor is private

tg2 = tg1;                   // ❌ ERROR – assignment operator is private

//////////////////////////////////////////////////////
In C++98, the standard way to make a class non-copyable is to:

Declare the copy constructor and assignment operator as private
Not provide any definitions for them
This is a safe, idiomatic approach for managing resources in pre-C++11 codebases.

*/