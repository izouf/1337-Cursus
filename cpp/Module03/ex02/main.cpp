#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    p1("Player 1");
    ClapTrap    p2("Player 2");
    ClapTrap    p3("Player 3");
    ScavTrap    s1("Guard 1");
    FragTrap    f1("Frag 1");

    s1.guardGate();
    p1.attack("Player 2");
    p2.takeDamage(5);
    p1.attack("Player 2");
    p2.takeDamage(5);
    p2.attack("Player 3");
    p1.attack("Player 3");
    p3.takeDamage(1);
    p3.attack("Player 1");
    p1.takeDamage(7);
    for(int i = 0; i < 7; i++)
        p1.beRepaired(1);
    p1.attack("Player 3");

    s1.attack("Player 1");
    p1.takeDamage(20);
    for (int i = 0 ; i < 47 ; i++)
        s1.guardGate();
    s1.takeDamage(99);
    s1.beRepaired(1);
    s1.attack("Player 1");
    s1.beRepaired(1);
    s1.guardGate();
    s1.takeDamage(2);
    s1.attack("Player 1");
    s1.guardGate();
    s1.beRepaired(1);
    s1.attack("Player 1");

    f1.highFivesGuys();
    f1.attack("Player 3");
    p3.takeDamage(30);
    for (int i = 0; i < 97 ; i++)
        f1.highFivesGuys();
    p3.attack("Frag 1");
    p3.takeDamage(30);
    f1.takeDamage(99);
    f1.beRepaired(1);
    f1.takeDamage(1);
    f1.beRepaired(1);
    f1.highFivesGuys();
    f1.takeDamage(1);
    f1.beRepaired(1);
    f1.highFivesGuys();
    f1.attack("Player 1");
    return (0);
}