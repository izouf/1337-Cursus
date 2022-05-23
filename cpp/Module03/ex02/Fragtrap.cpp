#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Constructor Called !" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap Constructor Called !" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
{
    std::cout << "FragTrap Copy Constructor Called !" << std::endl;
    *this = copy;
}

FragTrap & FragTrap::operator=(FragTrap const &copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor Called !" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
        std::cout << "FragTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "FragTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << " attack " << target << ", causing " << this->AttackDamage << " point of damage !" << std::endl;
        this->EnergyPoints--;
    }
}

void    FragTrap::highFivesGuys( void )
{
    if (this->hitPoints <= 0)
        std::cout << "FragTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "FragTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << this->name <<" -------- HighFive Guys ! --------" << std::endl;
        this->EnergyPoints--;
    }
}