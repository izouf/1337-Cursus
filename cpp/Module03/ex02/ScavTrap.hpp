#pragma once

#include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
    private:
    public:
        ScavTrap();
        ScavTrap(ScavTrap const &);
        ScavTrap &operator=( const ScavTrap &src);
        ScavTrap(std::string name);
        ~ScavTrap();

        void    attack(const std::string &target);
        void    guardGate( void );    
};