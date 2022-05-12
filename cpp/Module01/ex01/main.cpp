#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(5 , "Zombie");
    for (int i = 0; i < 5 ; i++)
        zombie->announce();
    delete [] zombie;
    return (0);
}