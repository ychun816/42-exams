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
        Warlock() : _name(""), _title(""){}
        Warlock(const std::string& _name, const std::string& _title);
        ~Warlock();

        //getter
        const std::string& getName() const {return _name;}
        const std::string& getTitle() const {return _title;}

        //setter
        void setTitle(const std::string& title){_title = title;}

        //func
         void introduce() const;

};

#endif