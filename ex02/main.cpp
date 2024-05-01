#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * @brief Main function demonstrating the use of ClapTrap, ScavTrap, and FragTrap classes.
 * 
 * @return int 
 */
int main(void)
{
    std::cout << std::endl;
    std::cout << BLUE <<"Create Player ClapTrap" << RESET << std::endl;
    ClapTrap clapTrap("Clap");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player ScavTrap" << RESET << std::endl;
    ScavTrap scavTrap("Scav");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player FragTrap" << RESET << std::endl;
    FragTrap fragTrap("Frag");

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

    std::cout << BLUE << "Player FragTrap" << RESET << std::endl;
    std::cout << "Name\t\t: " << fragTrap.getName() << std::endl;
    std::cout << "Hit Points\t: " << fragTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points\t: " << fragTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage\t: " << fragTrap.getAttackDamage() << std::endl;
    std::cout << std::endl;

    int i = 0;
    while (i < 4) 
    {
        scavTrap.attack("Clap");
        clapTrap.takeDamage(scavTrap.getAttackDamage());
        i++;
    }
    scavTrap.guardGate();
    while (clapTrap.testLife() && scavTrap.testLife())
    {
        scavTrap.attack("Clap");
        clapTrap.takeDamage(scavTrap.getAttackDamage());
    }
    std::cout << std::endl;
    scavTrap.attack("Frag");
    fragTrap.takeDamage(scavTrap.getAttackDamage());

    fragTrap.attack("Scav");
    fragTrap.takeDamage(fragTrap.getAttackDamage());

    fragTrap.highFiveGuys();

    return (0);
}