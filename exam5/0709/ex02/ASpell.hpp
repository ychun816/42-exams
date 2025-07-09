#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell 
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell() : _name(""), _effects(""){}
        ASpell(std::string const& name, std::string const& effects) : _name(name), _effects(effects){}
        ASpell(const ASpell& src); 
        ASpell& operator=(const ASpell& src);
        virtual ~ASpell(){}

        //getter
        std::string getName() const{return this->_name;}
        std::string getEffects() const{return this->_effects;}

        //Pure virtual method
        virtual ASpell* clone() const = 0;

        //func
        void launch(const ATarget& target) const;

} ;

#endif