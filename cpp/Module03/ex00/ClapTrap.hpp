#pragma once

#include <iostream>

class   ClapTrap
{
    private:
        std::string name;
        int         hitPoints;
        int         EnergyPoints;
        int         AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const  ClapTrap &copy);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &src);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};