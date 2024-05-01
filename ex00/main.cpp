#include "ClapTrap.hpp"


/**
 * @brief Main function to demonstrate ClapTrap functionality.
 * 
 * Creates two ClapTrap instances, sets their attack damage, and then enters a loop where
 * one ClapTrap attacks the other until it runs out of hit points or energy.
 * 
 * @return 0 if successful.
 */

int main()
{
    ClapTrap a("Ken");
    ClapTrap b("Lee");

    std::cout << std::endl;
    a.setAttackDamage(5);
    b.setAttackDamage(5);
    std::cout << std::endl;
    while (b.hasHitPoints() || b.hasEnergy())
    {
        a.attack("Lee");
        b.takeDamage(a.getAttackDamage());
    }

    return (0);
}