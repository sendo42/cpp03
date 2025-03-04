#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
    std::cout << "ScavTrap is created" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    MaxHP = HitPoints;
}

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap Default Construvtor called!" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    MaxHP = HitPoints;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    std::cout << "ScavTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy assignment operator overloading Called!" << std::endl;
    if(this == &copy)
        return *this;
    this->AttackDamage = copy.AttackDamage;
    this->EnergyPoints = copy.EnergyPoints;
    this->HitPoints = copy.HitPoints;
    this->Name = copy.Name;
    return *this;
}

void ScavTrap::attack(const std::string& target)
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
        std::cout << "ScavTrap " << Name << " attacks, " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "ScavTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
    if(HitPoints <= 0)
    {
        std::cout << "ScavTrap died" << std::endl; 
        HitPoints = 0;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{

    if(HitPoints == 0)
    {
        std::cout << "ScavTrap No Hit Point" << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "ScavTrap No Energy Point" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << Name << " Repaired " << amount << " points of HitPoints!" << std::endl;
        EnergyPoints--;
        HitPoints += amount;
        if(HitPoints > MaxHP || HitPoints < 0)
            HitPoints = MaxHP;
    }
}