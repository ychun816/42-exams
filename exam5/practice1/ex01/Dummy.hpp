#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

//- type = "Target Practice Dummy"
class Dummy : public ATarget
{
    public:
        Dummy();
        virtual ~Dummy();
        virtual ATarget* clone() const;
};

#endif

/*

//Base class ATarget => MUST BE virtual!! for destructor and the pure virtual fuc
//Inherit class Dummy => Optional/Better practice to set virtual 

//i.e.
virtual ~Dummy();
virtual ATarget* clone() const;

- Even though you're overriding a virtual function, marking it virtual again improves readability and clarity.
- It's a common C++ convention to repeat virtual in derived classes for documentation purposes.
- It ensures that if the base ever stops being virtual (by mistake), the compiler catches it early.

*/