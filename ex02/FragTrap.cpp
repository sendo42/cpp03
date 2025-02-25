#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
    std::cout << "FragTrap constructor is called!" << std::endl;
    Name = name;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor is called!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "high Fives !!" << std::endl;
}
