#include "ScavTrap.hpp"

/**
 * @brief Main function to demonstrate ClapTrap and ScavTrap functionality.
 * 
 * Creates instances of ClapTrap and ScavTrap, sets their attributes, and simulates
 * interactions between the two traps.
 * 
 * @return 0 if successful.
 */
int main(void)
{
    std::cout << std::endl;
    std::cout << BLUE <<"Create Player ClapTrap" << RESET << std::endl;
    ClapTrap clapTrap("Clappy");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player ScavTrap" << RESET << std::endl;
    ScavTrap scavTrap("Scavy");

    std::cout << std::endl;
    std::cout << BLUE << "Player ClapTrap" << RESET << std::endl;
    std::cout << "Name\t\t: " << clapTrap.getName() << std::endl;
    std::cout << "Hit Points\t: " << clapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points\t: " << clapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage\t: " << clapTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Player ScavTrap" << RESET << std::endl;
    std::cout << "Name\t\t: " << scavTrap.getName() << std::endl;
    std::cout << "Hit Points\t: " << scavTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points\t: " << scavTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage\t: " << scavTrap.getAttackDamage() << std::endl;
    std::cout << std::endl;

    int i = 0;
    while (i < 4) 
    {
        scavTrap.attack("Clappy");
        clapTrap.takeDamage(scavTrap.getAttackDamage());
        i++;
    }
    scavTrap.guardGate();
    while (clapTrap.testLife() && scavTrap.testLife())
    {
        scavTrap.attack("Clappy");
        clapTrap.takeDamage(scavTrap.getAttackDamage());
    }
    std::cout << std::endl;

    return (0);
}