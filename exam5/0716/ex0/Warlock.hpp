#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        // Warlock(const std::string name, const std::string title);


    public:
        Warlock();
        Warlock(const std::string name, const std::string title);
        ~Warlock();

        //getter
        std::string getName() const {return this->_name;}
        std::string getTitle() const {return this->_title;}

        //setter
        void setTitle(std::string title) {this->_title = title;}

        //func
        void introduce() const;

};

#endif