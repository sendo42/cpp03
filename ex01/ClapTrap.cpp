#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("sendo"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Default Construvtor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << "ClapTrap Constructor Called!" << std::endl;
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    MaxHP = HitPoints;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy assignment operator overloading Called!" << std::endl;
    if(this == &copy)
        return *this;
    this->AttackDamage = copy.AttackDamage;
    this->EnergyPoints = copy.EnergyPoints;
    this->HitPoints = copy.HitPoints;
    this->Name = copy.Name;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if(HitPoints == 0)
    {
        std::cout << "No Hit Point" << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "No Energy Point" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " attacks, " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
    if(HitPoints <= 0)
    {
        std::cout << "ClapTrap died" << std::endl; 
        HitPoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if(HitPoints == 0)
    {
        std::cout << "ClapTrap No Hit Point" << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "ClapTrap No Energy Point" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " Repaired " << amount << " points of HitPoints!" << std::endl;
        EnergyPoints--;
        HitPoints += amount;
        if(HitPoints > MaxHP || HitPoints < 0)
            HitPoints = MaxHP;
    }
}