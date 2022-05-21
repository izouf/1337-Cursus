#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
    /* data */
public:
    DiamondTrap();
    ~DiamondTrap();
};
