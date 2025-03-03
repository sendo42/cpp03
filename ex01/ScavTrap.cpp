#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}



ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap Default Construvtor called!" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    MaxHP = HitPoints;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
    std::cout << "ScavTrap is created" << std::endl;
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
    std::cout << "Copy Constructor Called!" << std::endl;
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
    if(EnergyPoints != 0 && HitPoints != 0)
    {
        std::cout << "ScavTrap " << Name << " attacks, " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "No Energy Point" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "ScavTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if(EnergyPoints != 0 || HitPoints != 0)
    {
        std::cout << "ScavTrap " << Name << " Repaired " << amount << " points of HitPoints!" << std::endl;
        EnergyPoints--;
        HitPoints += amount;
        if(HitPoints > MaxHP)
            HitPoints = MaxHP;
        std::cout << HitPoints << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "No Energy Point" << std::endl;
    }
    else if(HitPoints == 0)
    {
        std::cout << "No Hit Point" << std::endl;
    }

}