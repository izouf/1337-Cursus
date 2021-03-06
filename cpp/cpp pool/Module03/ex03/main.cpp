#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap    p1("Player 1");
    ClapTrap    p2("Player 2");
    ClapTrap    p3("Player 3");
    ClapTrap    p4("Player 4");
    ScavTrap    s1("Guard 1");
    FragTrap    f1("Frag 1");
    DiamondTrap d1("Diamond1");
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

    d1.whoAmI();
    d1.highFivesGuys();
    d1.guardGate();
    d1.attack("Player 4");
    p4.takeDamage(30);
    p4.attack("Diamond 1");
    d1.takeDamage(30);
    for (int i = 0 ; i < 50 ; i++)
        d1.beRepaired(1);
    d1.attack("Player 4");
    d1.highFivesGuys();
    d1.guardGate();
    d1.whoAmI();
    d1.takeDamage(200);
    d1.attack("Player 4");
    d1.beRepaired(1);
    d1.guardGate();
    d1.highFivesGuys();
    d1.whoAmI();
    return (0); 
}