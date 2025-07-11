#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell; 
// #include "ASpell.hpp"

class ATarget
{
    private:
        std::string _type;

    public:
        ATarget() : _type(""){}
        ATarget(const std::string type) : _type(type){}
        ATarget(const ATarget& src);
        ATarget& operator=(const ATarget& src);
        virtual~ATarget(){}

        //getter
        std::string getType() const {return this->_type;}

        //pure virtual func
        virtual ATarget* clone() const = 0;

        //func
        void getHitBySpell(const ASpell* spell) const;
};

#endif