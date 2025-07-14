#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class Warlock
{
    private:
        std::string _name;
        std::string _title;

    

    public:
        Warlock();
        Warlock(const std::string name, const std::string title);
        ~Warlock();

        //getter
        std::string getName() const {return this->_name;}
        std::string getTitle() const {return this->_title;}

        //setter
        //The compiler uses std::string's built-in assignment operator.
        //do not need a custom operator= here.
        void setTitle(const std::string title) {this->_title = title;}

        //func
        void introduce() const;

};

#endif

//void setTitle(const std::string title) {this->_title = title;}
//=> NO NEED OPERATOR= FUNC

//void setTitle(const std::string title) const {this->_title = title;}
//void setTitle(std::string title) const {this->_title = title;}
//=> NEED OPERATOR= FUNC
//The const after the parameter list makes the entire method const
//This means: "This function will not modify the object’s member variables."

//When Do You Need operator=
//Your class has non-trivial copy behavior (e.g., deep copies, resources).
//You need to control how assignment behaves.