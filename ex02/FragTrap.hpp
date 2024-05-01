#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

/**
 * @brief FragTrap class, inherits from ClapTrap.
 */
class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string);
        FragTrap(const FragTrap &);
        ~FragTrap();
        FragTrap        &operator=(const FragTrap &);
        void            highFiveGuys(void);
};

#endif