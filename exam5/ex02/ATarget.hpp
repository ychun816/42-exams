#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"
class ASpell; 

//- type = "Target Practice Dummy"
class ATarget
{
    protected: //private?
        std::string _type;

    public:
        //constructor
        ATarget();
        ATarget(const std::string& type);
        ATarget(const ATarget& src);//copy
        ATarget& operator=(const ATarget& src);//operator assignment
        virtual ~ATarget();    

        const std::string& getType() const;

        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell& effects) const;
};


#endif