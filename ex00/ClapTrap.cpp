#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << "Constructor Called!" << std::endl;
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(EnergyPoints != 0 || HitPoints != 0)
    {
        std::cout << "ClapTrap " << Name << " attacks, " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "No Energy Point" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(EnergyPoints != 0 || HitPoints != 0)
    {
        std::cout << "ClapTrap " << Name << " Repaired " << amount << " points of HitPoints!" << std::endl;
        EnergyPoints--;
        HitPoints += amount;
        if(HitPoints > 10)
            HitPoints = 10;
        // std::cout << HitPoints << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "No Energy Point" << std::endl;
    }

}