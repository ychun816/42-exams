#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;

    public:
        ASpell(): _name(""), _effects(""){}
        ASpell(std::string name, std::string effect) : _name(name), _effects(effect){}
        ASpell(const ASpell& src);//assign
        ASpell& operator=(const ASpell& src);
        virtual~ASpell(){}

        //getter
        std::string getName() const {return this->_name;}
        std::string getEffects() const {return this->_effects;}

        //func
        virtual ASpell* clone() const = 0;

        void launch(const ATarget& target) const;

};

#endif