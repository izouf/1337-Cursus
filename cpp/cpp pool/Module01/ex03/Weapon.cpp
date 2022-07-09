  #include "Weapon.hpp"

    Weapon::Weapon(){}
    Weapon::Weapon(const std::string &weapon) : type(weapon){}
    Weapon::~Weapon(){}

    std::string Weapon::getType() const
    {
        return (type);
    }

    void    Weapon::setType(const std::string &weapon)
    {
        type = weapon;
    }