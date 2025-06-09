#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

#include "ATarget.hpp"
class ATarget;  // forward declaration

//NOT REALLY NEED full constructor set:
//subject only uses the parameterized constructor (new Fwoosh() calls ASpell("Fwoosh", "fwooshed")).
//ASpell is abstract (clone() is pure virtual), so you never create an instance of ASpell directly.
//Copying or assigning ASpell is not needed in the subject behavior, so it's cleaner to avoid declaring unnecessary operations.

//BRIEF: ASpell only needs the tools required to support its actual usage pattern — initialization via constructor, destruction, and cloning through clone()

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

        //canonical form
        // ASpell();
        // ASpell(ASpell& src);
        // ASpell& operator=(ASpell& src);

    public:
        //constructor 
        ASpell(std::string const& name, std::string const& effects);
        virtual ~ASpell();
        
        //getter
        std::string getName() const;
        std::string getEffects() const;

        //pure virtual method
        virtual ASpell* clone() const = 0;

        void launch(const ATarget& target) const;
};


#endif