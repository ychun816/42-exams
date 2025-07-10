#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
    private:
        std::string _type;

    public:
        ATarget(): _type(""){}
        ATarget(std::string type) : _type(type){}
        ATarget(const ATarget& src);//assign
        ATarget& operator=(const ATarget& src);
        virtual~ATarget(){}

        //getter
        std::string getType() const {return this->_type;}

        //func
        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell* spell) const;
};

#endif