#include "FragTrap.hpp"

/**
* @brief Default constructor for FragTrap.
*/
FragTrap::FragTrap(void) : ClapTrap()
{
#ifdef TRACE
    std::cout << "FragTrap default constructor called." << std::endl;
#endif
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

/**
* @brief Overloaded constructor for FragTrap.
* 
* @param name The name of the FragTrap instance.
*/
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
#ifdef TRACE
    std::cout << "FragTrap - " << name << " - Constructed." << std::endl;
#endif
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

/**
* @brief Copy constructor for FragTrap.
* 
* @param other The FragTrap instance to copy.
*/
FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
#ifdef TRACE
    std::cout << "FragTrap " << name << " is copy constructed." << std::endl;
#endif
}

/**
* @brief Destructor for FragTrap.
*/
FragTrap::~FragTrap()
{
#ifdef TRACE
    std::cout << "FragTrap " << name << " is destroyed." << RESET << std::endl;
#endif
}

/**
* @brief Assignment operator for FragTrap.
* 
* @param other The FragTrap instance to assign from.
* @return A reference to the assigned FragTrap instance.
*/
FragTrap    &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
#ifdef TRACE
    std::cout << "FragTrap " << other.name << " is assigned to " << name << std::endl;
#endif
    return (*this);
}

/**
* @brief Function for FragTrap to request a high five.
*/
void        FragTrap::highFiveGuys(void)
{
    std::cout << name << ": GIVE ME YOUR BEST HIGH FIVE GUYS!" << std::endl; 
}