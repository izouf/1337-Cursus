#include "Zombie.hpp"

void    Zombie::setName(const std::string str)
{
    name = str;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " Created " << std::endl;
}

Zombie::Zombie()
{
     std::cout << name << " Created " << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie  *zombie = new Zombie(name);
    return (zombie);
}

void    randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}

Zombie::~Zombie()
{
    std::cout << name << " Destroyed !" << std::endl;
}