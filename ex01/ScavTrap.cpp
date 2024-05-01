#include "ScavTrap.hpp"

//
/**
 * @brief Derived Default Constructor for ScavTrap using inheritane.
 * 
 * Initializes ScavTrap with default values for hit points, energy points, and attack damage.
 * Sets guardMode to false.
 */
ScavTrap::ScavTrap() : ClapTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    guardMode = false;   
#ifdef TRACE
    std::cout << "New ScavTrap Constructed." << std::endl; 
#endif
}

/**
 * @brief Overloaded constructor for ScavTrap based on inheritance.
 * 
 * Initializes ScavTrap with a specified name and default values for hit points, energy points, and attack damage.
 * Sets guardMode to false.
 * 
 * @param name The name of the ScavTrap.
 */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    guardMode = false;     
#ifdef TRACE
    std::cout << "ScavTrap - " << name << " - Constructed." << std::endl; 
#endif
}

/**
 * @brief Copy constructor for ScavTrap using inheritance.
 * Copies the attributes of another ScavTrap instance to create a new instance.
 * 
 * @param other The ScavTrap instance to copy.
 */
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    guardMode = other.guardMode;
#ifdef TRACE 
    std::cout << "ScavTrap " << other.name << " is a copy, copied using the copy constructor." << std::endl;
#endif
}

/**
 * @brief Destructor for ScavTrap.
 * Destroys the ScavTrap instance.
 */
ScavTrap::~ScavTrap()
{
#ifdef TRACE
    std::cout << "ScavTrap " << name << " is destroyed." << RESET << std::endl;
#endif
}

/**
 * @brief Assignment operator for ScavTrap.
 * Assigns the values of one ScavTrap instance to another.
 * 
 * @param other The ScavTrap instance to assign from.
 * @return A reference to the assigned ScavTrap instance.
 */
ScavTrap &ScavTrap::operator=(const ScavTrap  &other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
        guardMode = other.guardMode;
    }
#ifdef TRACE
    std::cout << "ScavTrap " << other.name << " assigned using the assignment operator." << std::endl;
#endif
    return *this;
}

/**
 * @brief Attack function for ScavTrap.
 * 
 * Allows the ScavTrap to attack a target as long as it has energy. If the ScavTrap was in guard mode, it will
 * stop guarding and resume attacking. The ScavTrap's energy points are reduced by 1 with each attack.
 * 
 * @param target The name of the target.
 */
void    ScavTrap::attack(const std::string &target)
{
    if (guardMode)
    {
        guardMode = false;
#ifdef TRACE
        std::cout << name << " has stopped guarding and resumed attack on " << target << "." << std::endl;
#endif
    }
    if (energy_points > 0)
    {
        -- energy_points;
#ifdef TRACE
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " hit points damage!. Current energy points for " << name << " is " << energy_points << "." << std::endl;
#endif
    }
    else
    {
        ;
#ifdef TRACE        
        std::cout << "ScavTrap " << name << " has no energy points needed for an attack." << std::endl;
#endif
    }        
}

/**
 * @brief Guard gate function for ScavTrap.
 * 
 * Sets the ScavTrap's duty to guarding the gate. While in this mode, the ScavTrap
 * cannot attack. Once it is instructed to attack, it is relieved from guarding duty
 * and attacks the opponent.
 */
void ScavTrap::guardGate(void)
{
    if (!guardMode)
    {
        guardMode = true;
#ifdef TRACE 
        std::cout << GREEN << "ScavTrap " << name << " is now in gate keeper mode." << RESET << std::endl;
#endif
    }
    else
    {
        ;
#ifdef TRACE
        std::cout << "ScavTrap " << name << " is already in gate keeper mode." << std::endl;
#endif
    }
}