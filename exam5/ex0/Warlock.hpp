#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string _name;
        std::string _title;

    public:
        Warlock();
        Warlock(std::string name, std::string title);
        ~Warlock();

        //getter
        std::string getName()const{return this->_name;}
        std::string getTitle() const{return this->_title;}

        //setter
        void setTitle(std::string title){this->_title = title;}

        //func
        void introduce()const;
};

#endif

/*
const std::string name means you're passing by value (i.e., a copy is made when calling the constructor).
const std::string& name means you're passing by reference, avoiding that copy.

if you write const std::string name, you pay for two copies:
1. When the argument is passed to the constructor.
2. When you initialize _name from name.
*/