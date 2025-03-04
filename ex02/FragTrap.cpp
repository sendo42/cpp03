#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
    std::cout << "FragTrap is created" << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    MaxHP = HitPoints;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap Default Construvtor called!" << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    MaxHP = HitPoints;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap Copy assignment operator overloading Called!" << std::endl;
    if(this == &copy)
        return *this;
    this->AttackDamage = copy.AttackDamage;
    this->EnergyPoints = copy.EnergyPoints;
    this->HitPoints = copy.HitPoints;
    this->Name = copy.Name;
    return *this;
}

void FragTrap::attack(const std::string& target)
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
        std::cout << "FragTrap " << Name << " attacks, " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "FragTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
    if(HitPoints <= 0)
    {
        std::cout << "FragTrap died" << std::endl; 
        HitPoints = 0;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{

    if(HitPoints == 0)
    {
        std::cout << "FragTrap No Hit Point" << std::endl;
    }
    else if(EnergyPoints == 0)
    {
        std::cout << "FragTrap No Energy Point" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << Name << " Repaired " << amount << " points of HitPoints!" << std::endl;
        EnergyPoints--;
        HitPoints += amount;
        if(HitPoints > MaxHP || HitPoints < 0)
            HitPoints = MaxHP;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->Name << "high Fives !!" << std::endl;
}
