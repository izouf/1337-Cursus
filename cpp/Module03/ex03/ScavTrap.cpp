#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap Constructor  Called !" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Constructor Called !" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy Constructor  Called !" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor  Called !" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->EnergyPoints = src.EnergyPoints;
        this->AttackDamage = src.AttackDamage;
    }
    return (*this);
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints <= 0)
        std::cout << "ScavTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ScavTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->AttackDamage << " point of damage !" << std::endl;
        this->EnergyPoints--;
    }
}

void    ScavTrap::guardGate( void )
{
    if (this->hitPoints <= 0)
        std::cout << "ScavTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ScavTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << this->name <<" -------- Gate Keeper Mode On ! --------" << std::endl;
        this->EnergyPoints--;
    }
}