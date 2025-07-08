#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

//- name = "Fwoosh"
//- effects = "fwooshed"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        virtual ~Fwoosh();
        
        virtual ASpell* clone() const;

};

#endif