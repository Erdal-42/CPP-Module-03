#include "ScavTrap.hpp"

//ScavTrap Derived Default Constructor
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

//ScavTrap Derived Overload Constructor 
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

//ScavTrap Derived Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    guardMode = other.guardMode;
#ifdef TRACE 
    std::cout << "ScavTrap " << other.name << " is a copy, copied using the copy constructor." << std::endl;
#endif
}

//ScavTrap Derived Destructor
ScavTrap::~ScavTrap()
{
#ifdef TRACE
    std::cout << "ScavTrap " << name << " is destroyed." << RESET << std::endl;
#endif
}

//Derived assignment operator.
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

/*
 * This member function allows its object to attack 
 * its opponent. If the object was initially set to 
 * guard mode then it is automatically reverted to 
 * false. On every attack the object energy point 
 * is exausted by 1 unit. The object can attack as
 * long as it has energy points.
 * @param: Name of the opponent.
 * 
 * @return none
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

/*
 * This function sets the duty its object to guarding gate.
 * Whilst in this status the guard cannot defends the gate.
 * Once it is instructed to attack, it is relieved from its
 * guard duty and goes straight into attacking opponent.
 * 
 * @param none
 * 
 * @return none 
 * 
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