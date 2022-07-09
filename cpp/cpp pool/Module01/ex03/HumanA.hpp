#include "Weapon.hpp"

class   HumanA
{
private:
    std::string name;
    Weapon      &weapon;
public:
    HumanA(std::string name, Weapon &Weapon);
    ~HumanA();
    void    attack(void);
};