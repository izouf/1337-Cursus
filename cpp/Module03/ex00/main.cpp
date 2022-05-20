#include "ClapTrap.hpp"

int main()
{
    ClapTrap  p1("Player 1");
    ClapTrap  p2("Player 2");

    p1.attack("Player 2");
    p2.takeDamage(5);
    p1.attack("Player 2");
    p2.takeDamage(5);
}