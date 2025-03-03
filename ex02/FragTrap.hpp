#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap(const std::string &name);
        FragTrap();
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        
        void highFivesGuys(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};


#endif


/*

high fiveとはハイタッチのこと。
意味わからん！なにしろって？

*/