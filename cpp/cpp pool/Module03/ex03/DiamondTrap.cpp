#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Constructor Called !" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    /*this->hitPoints = FragTrap::hitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;*/
    this->hitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 30;
    std::cout << "DiamondTrap Constructor Called !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap Copy Constructor Called !" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    this->ClapTrap::name = src.ClapTrap::name;
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->EnergyPoints = src.EnergyPoints;
    this->AttackDamage = src.AttackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor Called !" << std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "-------- I'm " << this->ClapTrap::name << " ! -------- " << std::endl;
}