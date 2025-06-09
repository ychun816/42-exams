#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"
class ASpell;
//NEED full constructor set:
//subject allow targets to be created, cloned, and possibly stored/copied.
//ATarget objects (or derived ones like Dummy) are passed around and might be stored in containers in future tasks (e.g., a TargetGenerator

//BRIEF: ATarget is more flexible, supporting copying and assignment — possibly to be extended or used in containers in later modules

class ATarget
{
    protected:
        std::string _type;


    public:
        ATarget();
        ATarget(const ATarget& src);
        ATarget& operator=(const ATarget& src);
        ATarget(const std::string& type);
        virtual ~ATarget();

        //getter
        const std::string& getType() const;

        //pure virtual method
        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell& spell) const;
};

#endif