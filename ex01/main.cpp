#include "ScavTrap.hpp"

int main()
{
    // ClapTrap sendo("sendo");

    // sendo.attack("hirosuzu");
    // sendo.takeDamage(9);
    // sendo.beRepaired(10);

    ScavTrap DS3("3DS");

    DS3.attack("yamanaka");
    DS3.guardGate();
    DS3.takeDamage(30);
    DS3.beRepaired(20);

}