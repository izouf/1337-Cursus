#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const &name) : name(name), equiped(0), unequiped(0)
{
}

Character::Character(const Character &copy) : name(copy.name), equiped(0), unequiped(0)
{
    *this = copy;
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        this->name = src.name;
        for (int i = 0; i < this->equiped; i++)
            delete this->inventory[i];
        this->equiped = 0;
        for (int i = 0; i < src.equiped; i++)
            this->equip(src.inventory[i]->clone());
        for (int i = this->equiped; i < 4; i++)
            this->inventory[i] = nullptr;
    }
    return (*this);
}

std::string const &Character::getName(void) const
{
    return (this->name);
}

void    Character::equip(AMateria *m)
{
    if (equiped == 4 || m == nullptr)
        return;
    for (int i = 0; i < this->equiped; i++)
        if(this->inventory[i] == m)
            return ;
        this->inventory[this->equiped++] = m;
}

void    Character::use(int index, ICharacter &target)
{
    if (index < 0 || index >= this->equiped || this->inventory[index] == nullptr)
        return;
    this->inventory[index]->use(target);
}

void    Character::unequip(int index)
{
    if (index < 0 || index >= this->equiped || this->inventory[index] == nullptr)
        return;
    for (int i = index; i < 3; i++)
    {
        if (unequiped < 100)
            this->floor[unequiped++] = this->inventory[i];
        this->inventory[i] = this->inventory[i + 1];
        this->inventory[i + 1] = nullptr;
    }
    this->equiped--;
}

Character::~Character()
{
    for (int i = 0; i < this->equiped; i++)
        delete (this->inventory[i]);
    for (int i = 0; i < this->unequiped; i++)
        delete (this->floor[i]);
}
