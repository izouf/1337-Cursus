#include "Zombie.hpp"

int main()
{
    Zombie  *zombie = newZombie("New Zombie");
    zombie->announce();
    randomChump("Zombie");
    delete zombie;
    return (0);
}