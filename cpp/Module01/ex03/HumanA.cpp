#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), weapon(Weapon){}

HumanA::~HumanA() {
}

void    HumanA::attack(void)
{
    std::cout << name << " attacks widh their " << weapon.getType() << std::endl;
}