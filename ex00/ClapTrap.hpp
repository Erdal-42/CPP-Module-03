
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include    <iostream>


/*
 * When ClapTrap attacks it causes its target to lose 
 * hit points (hence attack damage). When ClapTrap
 * repaires itself, it gets hit points back <amount>.
 *
 * Attacking and repairing cost 1 energy point each.
 * Ofcourse ClapTrap cant do anything if it has no
 * hitpoints or energy points left.
 * 
 * In all member functions, we print a message to
 * describe what has happened; ie
 *      ClapTrap <name> attacks <target>, 
 * causing <damage> points of damage!
 * The constructors and destructors all display a
 * message.
 * 
 * The main function will include test cases.
 */ 

#define TRACE   

class ClapTrap
{
    private:
        std::string name;
        unsigned    hit_points;
        unsigned    energy_points;
        unsigned    attack_damage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        //Copy Constructor
        ClapTrap (const ClapTrap &);
        //Copy assignment operator
        ClapTrap &operator=(const ClapTrap &);
        ~ClapTrap();
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        bool    hasEnergy(void);
        bool    hasHitPoints(void);
        void    setHitPoints(unsigned int);
        void    setEnergyPoints(unsigned int);
        void    setAttackDamage(unsigned int);
        unsigned    getHitPoints(void);
        unsigned    getEnergyPoints(void);
        unsigned    getAttackDamage(void);
        bool    test_life(void);
};

#endif