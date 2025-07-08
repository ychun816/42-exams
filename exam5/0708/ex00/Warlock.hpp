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
        Warlock() : _name(""), _title(""){};
        ~Warlock();
        Warlock(const std::string& name, const std::string& title);
        //No copy constructor or copy assignment

        //getter
        const std::string& getName() const{return this->_name;}
        const std::string& getTitle() const{return this->_title;}

        //Setter
        void setTitle(const std::string& title);

        //funcs
        void introduce() const;
} ;




#endif





