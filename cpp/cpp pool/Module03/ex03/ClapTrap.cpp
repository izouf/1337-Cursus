#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Constructor Called !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Constructor Called !" << std::endl;
}
    
ClapTrap::ClapTrap(const  ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor Called !" << std::endl;
    *this = copy;
}
        
ClapTrap::~ClapTrap(){std::cout << "ClapTrap Destructor Called !" << std::endl;}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
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

void    ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->AttackDamage << " point of damage !" << std::endl;
        this->EnergyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " is Aleady dead !" << std::endl;
    else
    {
       std::cout << "ClapTrap " << this->name << " Has taken " << amount << " point of damage !" <<  std::endl;
       this->hitPoints -= amount;
    } 
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " is Aleady dead !" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " Has no energy !" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " Has repaired " << amount << " point of damage !" << std::endl;
        this->EnergyPoints--;
        this->hitPoints += amount;
    }
}

