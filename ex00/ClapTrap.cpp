#include "ClapTrap.hpp"


/**
 * @brief Default constructor for ClapTrap.
 * 
 * Initializes the ClapTrap with default values.
 */
ClapTrap::ClapTrap(void) : name("Anonymous"), hit_points(10), energy_points(10), attack_damage(0)
{   
#ifdef TRACE
    std::cout << "ClapTrap - Anonymous - Constructed. It is loaded with 10 hit points and 10 energy points to start with." << std::endl;
#endif
}

/**
 * @brief Constructor for ClapTrap with a specified name.
 * Initializes the ClapTrap with the specified name and default values.
 * 
 * @param theName The name of the ClapTrap.
 */
ClapTrap::ClapTrap(std::string theName) : name(theName), hit_points(10), energy_points(10), attack_damage(0)
{
#ifdef TRACE
    std::cout << "ClapTrap - " << name << " - Constructed. It is loaded with 10 hit points and 10 energy points to start with." << std::endl;
#endif
}

/**
 * @brief Copy constructor for ClapTrap.
 * Copies the values from another ClapTrap.
 * 
 * @param other The ClapTrap to copy from.
 */
ClapTrap::ClapTrap(const ClapTrap &other) 
{
    *this = other;
#ifdef TRACE 
    std::cout << "ClapTrap " << other.name << " copied using the copy constructor." << std::endl;
#endif
}

/**
 * @brief Copy assignment operator for ClapTrap.
 * Assigns the values from another ClapTrap.
 * 
 * @param other The ClapTrap to assign from.
 * @return A reference to the assigned ClapTrap.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap  &other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
#ifdef TRACE 
    std::cout << "ClapTrap " << other.name << " assigned using the assignment operator." << std::endl;
#endif
    return *this;
}

/**
 * @brief Destructor for ClapTrap.
 * Outputs a message indicating the destruction of the ClapTrap.
 */
ClapTrap::~ClapTrap()
{
#ifdef TRACE
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
#endif
}

/**
 * @brief Attack a target.
 * Reduces the energy points of the ClapTrap and outputs an attack message.
 * 
 * @param target The target of the attack.
 */
void    ClapTrap::attack(const std::string &target)
{
    if (energy_points > 0)
    {
        -- energy_points;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " hit points damage!. Current energy points for " << name << " is " << energy_points << "." << std::endl;
#endif
    }
    else
    {
        ;
#ifdef TRACE        
        std::cout << "ClapTrap " << name << " has no energy points needed for an attack." << std::endl;
#endif
    }
}

/**
 * @brief Take damage.
 * Reduces the hit points of the ClapTrap and checks if it needs to be repaired.
 * 
 * @param amount The amount of damage to take.
 */
void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    if (energy_points != 0)
        -- energy_points; 
#ifdef TRACE
    std::cout << "ClapTrap " << name << " has " << hit_points << " hit points and " << energy_points << " energy points left." << std::endl;
#endif
    if (!test_life())
        return ;
    if (!hit_points) 
        beRepaired(attack_damage);
}

/**
 * @brief Heal the ClapTrap.
 * Increases the hit points of the ClapTrap and reduces the energy points.
 * 
 * @param amount The amount to heal.
 */
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        -- energy_points;
        hit_points += amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " was repaired by transforming 1 energy point to " << amount << " hit points. Current energy points for " << name << " is " << energy_points << "." << std::endl;
#endif
    }
    else
        test_life();
}

/**
 * @brief Check if the ClapTrap has energy points.
 * 
 * @return True if the ClapTrap has energy points, false otherwise.
 */
bool    ClapTrap::hasEnergy(void)
{
    return (energy_points > 0);
}

/**
 * @brief Check if the ClapTrap has hit points.
 * 
 * @return True if the ClapTrap has hit points, false otherwise.
 */
bool    ClapTrap::hasHitPoints(void)
{
    return (hit_points > 0);
}

/**
 * @brief Set the hit points of the ClapTrap.
 * 
 * @param amount The amount to set as hit points.
 */
void        ClapTrap::setHitPoints(unsigned int amount)
{
    hit_points = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " was set " << amount << " hit points." << std::endl;
#endif    
}

/**
 * @brief Set the energy points of the ClapTrap.
 * 
 * @param amount The amount to set as energy points.
 */
void        ClapTrap::setEnergyPoints(unsigned int amount)
{
    energy_points = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " was set " << amount << " energy points."  << std::endl;
#endif
}

/**
 * @brief Set the attack damage of the ClapTrap.
 * 
 * @param amount The amount to set as attack damage.
 */
void        ClapTrap::setAttackDamage(unsigned int amount)
{
    attack_damage = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " attack damage is set to " << amount << "." << std::endl;
#endif
}

/**
 * @brief Get the hit points of the ClapTrap.
 * 
 * @return The hit points of the ClapTrap.
 */
unsigned    ClapTrap::getHitPoints(void)
{
    return (hit_points);
}

/**
 * @brief Get the energy points of the ClapTrap.
 * 
 * @return The energy points of the ClapTrap.
 */
unsigned    ClapTrap::getEnergyPoints(void)
{
    return (energy_points);
}

/**
 * @brief Get the attack damage of the ClapTrap.
 * 
 * @return The attack damage of the ClapTrap.
 */
unsigned    ClapTrap::getAttackDamage(void)
{
    return (attack_damage);
}

/**
 * @brief Test if the ClapTrap is still alive.
 * 
 * @return True if the ClapTrap is alive, false otherwise.
 */
bool        ClapTrap::test_life(void)
{
    if (!energy_points && !hit_points)
    {
#ifdef TRACE
        std::cout << "ClapTrap " << name << " has depleted hit points and energy points. It is a TKO!" << std::endl << std::endl;
#endif        
        return (false);
    }
    return (true);
}