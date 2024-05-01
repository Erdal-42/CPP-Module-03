#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) : name("Anonymous"), hit_points(10), energy_points(10), attack_damage(0)
{   
#ifdef TRACE
    std::cout << "ClapTrap - Anonymous - Constructed." << std::endl;
#endif
}

ClapTrap::ClapTrap(std::string theName) : name(theName), hit_points(10), energy_points(10), attack_damage(0)
{
#ifdef TRACE2
    std::cout << "ClapTrap - " << name << " - Constructed." << std::endl;
#endif
}

//Copy constructor implementor.
ClapTrap::ClapTrap(const ClapTrap &other) 
{
    *this = other;
#ifdef TRACE 
    std::cout << "ClapTrap " << other.name << " copied using the copy constructor." << std::endl;
#endif
}

//Copy Assignment Operator
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

ClapTrap::~ClapTrap()
{
#ifdef TRACE2
    std::cout << "ClapTrap " << name << " destroyed." << RESET << std::endl;
#endif
}

void    ClapTrap::attack(const std::string &target)
{
    (std::string)target;
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
    if (!testLife())
        return ;
    if (!hit_points)
        beRepaired(amount);
}

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
        testLife();
}

bool    ClapTrap::hasEnergy(void)
{
    return (energy_points > 0);
}

bool    ClapTrap::hasHitPoints(void)
{
    return (hit_points > 0);
}

void        ClapTrap::setHitPoints(unsigned int amount)
{
    hit_points = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " was set " << amount << " hit points." << std::endl;
#endif    
}

void        ClapTrap::setEnergyPoints(unsigned int amount)
{
    energy_points = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " was set " << amount << " energy points."  << std::endl;
#endif
}

void        ClapTrap::setAttackDamage(unsigned int amount)
{
    attack_damage = amount;
#ifdef TRACE
        std::cout << "ClapTrap " << name << " attack damage is set to " << amount << "." << std::endl;
#endif
}

unsigned    ClapTrap::getHitPoints(void)
{
    return (hit_points);
}

unsigned    ClapTrap::getEnergyPoints(void)
{
    return (energy_points);
}

unsigned    ClapTrap::getAttackDamage(void)
{
    return (attack_damage);
}

std::string ClapTrap::getName(void)
{
    return (name);
}

bool        ClapTrap::testLife(void)
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