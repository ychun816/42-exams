#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

// Constructor:
// - Must take name and title (in that order).
// - No default constructor.
// - No copy constructor or copy assignment.

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        
        Warlock();
        // Warlock(Warlock const& copy);
        // Warlock& operator=(Warlock const& src);
        
    public:
        ////constructor & destructor
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        
        ////member func 
        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& title);
        void introduce() const;
};

#endif 