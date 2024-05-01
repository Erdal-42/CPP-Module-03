
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include    <iostream>
#include    <string>

/*
 * 
 * ScavTrap inherits from the class ClapTrap. The new
 * class has an additioanl data member called 
 * guardMode which states whether the ScavTrap has 
 * taken guard. 
 * 
 * Besides the additional data member, the 
 * initialization values are diffrent to ClapTrap. 
 * There is an additional member function guardGate()  
 * 
 * The main function will include test cases for this 
 * class.
 */ 

#include "ClapTrap.hpp"   

#define TRACE   


/**
 * @brief ScavTrap class, inherits from ClapTrap.
 */
class ScavTrap : public ClapTrap
{
    private:
        bool guardMode;
        
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &);
        ~ScavTrap();

        ScavTrap &operator=(const ScavTrap &);
        void    attack(const std::string &);
        void    guardGate(void);
};

#endif