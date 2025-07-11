#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget; // Just tell compiler "ATarget exists somewhere"

class ASpell
{
    private:
        std::string _name;
        std::string _effects;

    public:
        ASpell() : _name(""), _effects(""){}
        ASpell(const std::string name, const std::string effect) : _name(name), _effects(effect){}
        ASpell(const ASpell& src);
        ASpell& operator=(const ASpell& src);
        virtual~ASpell(){}

        //getter
        std::string getName() const {return this->_name;}
        std::string getEffects() const {return this->_effects;}

        //pure virtual func
        virtual ASpell* clone() const = 0;

        //func
        void launch(const ATarget& target) const;
};

#endif

// Use const T& in function parameters whenever:
// - The object is large (like std::string, user-defined classes).
// - You don't need to copy or modify it.

// Use raw pointers (T*) only if:
// - You allow nullptr, or manage memory explicitly (e.g., for cloning).