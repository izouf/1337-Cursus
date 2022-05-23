#pragma once

#include "ClapTrap.hpp"

class   ScavTrap : virtual public ClapTrap
{
    private:
    public:
        ScavTrap();
        ScavTrap(const ScavTrap  &copy);
        ScavTrap &operator=( const ScavTrap &src);
        ScavTrap(std::string name);
        ~ScavTrap();

        void    attack(const std::string &target);
        void    guardGate( void );    
};